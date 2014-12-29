//
// Copyright (c) 2014-2015 Samuel Villarreal
// svkaiser@gmail.com
// 
// This software is provided 'as-is', without any express or implied
// warranty. In no event will the authors be held liable for any damages
// arising from the use of this software.
// 
// Permission is granted to anyone to use this software for any purpose,
// including commercial applications, and to alter it and redistribute it
// freely, subject to the following restrictions:
// 
//    1. The origin of this software must not be misrepresented; you must not
//    claim that you wrote the original software. If you use this software
//    in a product, an acknowledgment in the product documentation would be
//    appreciated but is not required.
// 
 //   2. Altered source versions must be plainly marked as such, and must not be
 //   misrepresented as being the original software.
// 
//    3. This notice may not be removed or altered from any source
//    distribution.
// 

#include "wx/app.h"
#include "wx/log.h"
#include "wx/frame.h"
#include "wx/panel.h"
#include "wx/timer.h"
#include "wx/utils.h"
#include "wx/menu.h"
#include "wx/msgdlg.h"
#include "wx/textdlg.h"
#include "wx/filedlg.h"
#include "wx/choicdlg.h"
#include "wx/button.h"
#include "wx/checkbox.h"
#include "wx/stattext.h"
#include "wx/textctrl.h"
#include "wx/listbox.h"
#include "wx/sizer.h"
#include "wx/txtstrm.h"
#include "wx/numdlg.h"
#include "wx/textdlg.h"
#include "wx/ffile.h"
#include "wx/scopedptr.h"
#include "wx/stopwatch.h"
#include "wx/process.h"
#include "wx/mimetype.h"

#include "frames/mainframe.h"

//=============================================================================
//
// Enums
//
//=============================================================================

enum
{
    Exec_TimerIdle = 10
};

//=============================================================================
//
// DLightGuiFrame Class
//
//=============================================================================

class DLightGuiProcess;
WX_DEFINE_ARRAY_PTR(DLightGuiProcess*, processList_t);

class DLightGuiFrame : public MainFrame
{
public:
    DLightGuiFrame(wxWindow *parent);
    ~DLightGuiFrame(void);

    void            OnAsyncTermination(DLightGuiProcess *process);

    void            AboutMenuClicked(wxCommandEvent &event);
    void            OpenInputFile(wxCommandEvent &event);
    void            OpenInputConfigFile(wxCommandEvent &event);
    void            RunProcess(wxCommandEvent &event);
    void            OnIdleTimer(wxTimerEvent &event);
    void            OnIdle(wxIdleEvent &event);
    void            RunGLVis(void);
    void            RunDLight(void);
    void            StartProcess(const wxString &cmd);

    processList_t   processList;
    wxTimer         timer;
    bool            bRunningGLVis;
    bool            bRunningDLight;

    wxDECLARE_EVENT_TABLE();
};

//=============================================================================
//
// DLightGuiProcess Class
//
//=============================================================================

class DLightGuiProcess : public wxProcess
{
public:
    DLightGuiProcess(DLightGuiFrame *parent, const wxString &cmd) : wxProcess(parent), m_cmd(cmd)
    {
        m_parent = parent;
        Redirect();
    }

    virtual void    OnTerminate(int pid, int status);
    bool            HasInput(void);
    void            PrintStream(wxInputStream *stream);

protected:
    DLightGuiFrame  *m_parent;
    wxString        m_cmd;
};

//=============================================================================
//
// DLightGuiProcess Methods
//
//=============================================================================

//
// DLightGuiProcess::OnTerminate
//

void DLightGuiProcess::OnTerminate(int WXUNUSED(pid), int WXUNUSED(status))
{
    while(HasInput());
    m_parent->processList.Remove(this);

    if(m_parent->processList.IsEmpty())
    {
        m_parent->timer.Stop();

        if(m_parent->bRunningGLVis)
        {
            m_parent->bRunningGLVis = false;

            if(m_parent->m_cbSkipDLight->IsChecked() == false)
            {
                m_parent->RunDLight();
                return;
            }
        }
        else if(m_parent->bRunningDLight)
        {
            m_parent->bRunningDLight = false;
        }

        m_parent->m_btnCompile->Enable();
    }
}

//
// DLightGuiProcess::PrintStream
//

void DLightGuiProcess::PrintStream(wxInputStream *stream)
{
    static wxString prevMsg;

    wxTextInputStream tis(*stream);
    wxString msg = tis.ReadLine();

    if(msg.Length() <= 0)
    {
        return;
    }

    if(msg == prevMsg)
    {
        return;
    }

    prevMsg = msg;

    m_parent->m_outputLog->AppendText(msg);
    m_parent->m_outputLog->AppendText(wxT("\n"));
}

//
// DLightGuiProcess::HasInput
//

bool DLightGuiProcess::HasInput(void)
{
    bool hasInput = false;

    if(IsInputAvailable())
    {
        PrintStream(GetInputStream());
        hasInput = true;
    }

    if(IsErrorAvailable())
    {
        PrintStream(GetErrorStream());
        hasInput = true;
    }

    return hasInput;
}

//=============================================================================
//
// DLightGuiFrame Methods
//
//=============================================================================

//
// DLightGuiFrame::DLightGuiFrame
//

DLightGuiFrame::DLightGuiFrame(wxWindow *parent) : MainFrame(parent), timer(this, Exec_TimerIdle)
{
}

//
// DLightGuiFrame::~DLightGuiFrame
//

DLightGuiFrame::~DLightGuiFrame(void)
{
    for(size_t n = 0; n < processList.size(); n++)
    {
        delete processList[n];
    }
}

//
// DLightGuiFrame::AboutMenuClicked
//

void DLightGuiFrame::AboutMenuClicked(wxCommandEvent &WXUNUSED(event))
{
    wxMessageBox(wxString(wxT("(c)2014-2015 Samuel Villarreal\nsvkaiser@gmail.com\n\n")) <<
        wxT("https://doom64ex.wordpress.com/\nhttp://villsa.wordpress.com/"),
        wxT("About DLightGui"),
            wxOK | wxICON_INFORMATION, this);
}

//
// DLightGuiFrame::OpenInputFile
//

void DLightGuiFrame::OpenInputFile(wxCommandEvent &WXUNUSED(event))
{
    wxFileDialog dlg(this,
                     wxT("Choose File"),
                     wxEmptyString,
                     wxEmptyString,
                     wxT("Doom Wad Files (*.wad)|*.wad"),
                     wxFD_OPEN);

    if(dlg.ShowModal() == wxID_OK)
    {
        m_textInput->SetValue(dlg.GetPath());
    }
}

//
// DLightGuiFrame::OpenInputConfigFile
//

void DLightGuiFrame::OpenInputConfigFile(wxCommandEvent &WXUNUSED(event))
{
    wxFileDialog dlg(this,
                     wxT("Choose File"),
                     wxEmptyString,
                     wxEmptyString,
                     wxT("DLight Configuration Files (*.cfg)|*.cfg"),
                     wxFD_OPEN);

    if(dlg.ShowModal() == wxID_OK)
    {
        m_textConfigInput->SetValue(dlg.GetPath());
    }
}

//
// DLightGuiFrame::OnIdleTimer
//

void DLightGuiFrame::OnIdleTimer(wxTimerEvent &WXUNUSED(event))
{
    wxWakeUpIdle();
}

//
// DLightGuiFrame::StartProcess
//

void DLightGuiFrame::StartProcess(const wxString &cmd)
{
    DLightGuiProcess *process = new DLightGuiProcess(this, cmd);
    if(!wxExecute(cmd, wxEXEC_ASYNC, process))
    {
        wxLogError(wxT("Execution of '%s' failed."), cmd.c_str());
        m_btnCompile->Enable();
        delete process;
    }
    else
    {
        if(processList.IsEmpty())
        {
            timer.Start(10);
        }

        processList.Add(process);
    }
}

//
// DLightGuiFrame::RunGLVis
//

void DLightGuiFrame::RunGLVis(void)
{
    wxString cmd = wxT("glvis.exe");
    int map = m_choiceMapSlot->GetSelection() + 1;

    if(map <= 9)
    {
        cmd << wxT(" -mMAP0") << map;
    }
    else
    {
        cmd << wxT(" -mMAP") << map;
    }

    cmd << wxT(" ") << m_textInput->GetValue();
    bRunningGLVis = true;

    StartProcess(cmd);
}

//
// DLightGuiFrame::RunDLight
//

void DLightGuiFrame::RunDLight(void)
{
    wxString cmd = wxT("dlight.exe");

    cmd << wxT(" -map ") << (m_choiceMapSlot->GetSelection() + 1);
    cmd << wxT(" -threads ") << (m_choiceThreads->GetSelection() + 1);
    cmd << wxT(" -config ") << m_textConfigInput->GetValue();

    switch(m_choiceSamples->GetSelection())
    {
    case 0:
        cmd << wxT(" -samples 2 ");
        break;

    case 1:
        cmd << wxT(" -samples 4 ");
        break;

    case 2:
        cmd << wxT(" -samples 8 ");
        break;

    case 3:
        cmd << wxT(" -samples 16 ");
        break;
    }

    switch(m_choiceSize->GetSelection())
    {
    case 0:
        cmd << wxT(" -size 128 ");
        break;

    case 1:
        cmd << wxT(" -size 256 ");
        break;
    }

    cmd << wxT(" ") << m_textInput->GetValue();
    bRunningDLight = true;

    StartProcess(cmd);
}

//
// DLightGuiFrame::RunProces
//

void DLightGuiFrame::RunProcess(wxCommandEvent &WXUNUSED(event))
{
    wxString input = m_textInput->GetValue();

    bRunningGLVis = false;
    bRunningDLight = false;

    if(input.Length() <= 0 || !input.Contains(wxT(".wad")))
    {
        wxMessageBox(wxT("Please specify input wad"), wxT("Info"),
            wxOK | wxICON_INFORMATION, this);

        return;
    }

    m_outputLog->Clear();
    m_btnCompile->Disable();

    if(m_cbSkipVis->IsChecked() == false)
    {
        RunGLVis();
    }
    else if(m_cbSkipDLight->IsChecked() == false)
    {
        RunDLight();
    }
}

//
// DLightGuiFrame::OnAsyncTermination
//

void DLightGuiFrame::OnAsyncTermination(DLightGuiProcess *process)
{
    processList.Remove(process);
    delete process;
}

//
// DLightGuiFrame::OnIdle
//

void DLightGuiFrame::OnIdle(wxIdleEvent &event)
{
    size_t count = processList.GetCount();

    for(size_t n = 0; n < count; n++)
    {
        if(processList[n]->HasInput())
        {
            event.RequestMore();
        }
    }
}

//=============================================================================
//
// Events
//
//=============================================================================

wxBEGIN_EVENT_TABLE(DLightGuiFrame, wxFrame)
    EVT_IDLE(DLightGuiFrame::OnIdle)
    EVT_TIMER(Exec_TimerIdle, DLightGuiFrame::OnIdleTimer)
wxEND_EVENT_TABLE()

//=============================================================================
//
// MyApp Class
//
//=============================================================================

class MyApp : public wxApp
{
public:
    virtual bool OnInit();
};

IMPLEMENT_APP(MyApp)

//
// MyApp::OnInit
//

bool MyApp::OnInit(void)
{
    if(!wxApp::OnInit())
    {
        return false;
    }

    DLightGuiFrame *frame = new DLightGuiFrame(wxWindow::FindFocus());
    frame->Show(true);
    return true;
}
