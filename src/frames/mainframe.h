///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Jun  5 2014)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#ifndef __MAINFRAME_H__
#define __MAINFRAME_H__

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/string.h>
#include <wx/stattext.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/textctrl.h>
#include <wx/sizer.h>
#include <wx/button.h>
#include <wx/checkbox.h>
#include <wx/choice.h>
#include <wx/statbox.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/menu.h>
#include <wx/frame.h>

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class MainFrame
///////////////////////////////////////////////////////////////////////////////
class MainFrame : public wxFrame 
{
	private:
	
	protected:
		wxStaticText* m_staticText1;
		wxButton* m_button1;
		wxStaticText* m_staticText11;
		wxButton* m_button11;
		wxStaticText* m_staticText42;
		wxStaticText* m_staticText41;
		wxStaticText* m_staticText4;
		wxStaticText* m_staticText43;
		wxMenuBar* m_menubar1;
		wxMenu* m_menu2;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OpenInputFile( wxCommandEvent& event ) { event.Skip(); }
		virtual void OpenInputConfigFile( wxCommandEvent& event ) { event.Skip(); }
		virtual void RunProcess( wxCommandEvent& event ) { event.Skip(); }
		virtual void AboutMenuClicked( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		wxTextCtrl* m_textInput;
		wxTextCtrl* m_textConfigInput;
		wxCheckBox* m_cbSkipVis;
		wxCheckBox* m_cbSkipDLight;
		wxChoice* m_choiceMapSlot;
		wxChoice* m_choiceSamples;
		wxChoice* m_choiceSize;
		wxChoice* m_choiceThreads;
		wxButton* m_btnCompile;
		wxTextCtrl* m_outputLog;
		
		MainFrame( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Doom Vis and Light Compiler (Alpha)"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 384,512 ), long style = wxCAPTION|wxCLOSE_BOX|wxMINIMIZE_BOX|wxSYSTEM_MENU|wxTAB_TRAVERSAL );
		
		~MainFrame();
	
};

#endif //__MAINFRAME_H__
