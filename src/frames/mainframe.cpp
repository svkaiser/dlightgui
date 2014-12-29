///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Jun  5 2014)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "mainframe.h"

///////////////////////////////////////////////////////////////////////////

MainFrame::MainFrame( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxSize( 384,512 ), wxSize( 384,512 ) );
	this->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_MENU ) );
	
	wxBoxSizer* bSizer1;
	bSizer1 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer5;
	bSizer5 = new wxBoxSizer( wxVERTICAL );
	
	m_staticText1 = new wxStaticText( this, wxID_ANY, wxT("Input Wad File"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText1->Wrap( -1 );
	bSizer5->Add( m_staticText1, 0, wxALL, 5 );
	
	wxBoxSizer* bSizer4;
	bSizer4 = new wxBoxSizer( wxHORIZONTAL );
	
	wxBoxSizer* bSizer3;
	bSizer3 = new wxBoxSizer( wxVERTICAL );
	
	m_textInput = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer3->Add( m_textInput, 0, wxALL|wxEXPAND, 5 );
	
	
	bSizer4->Add( bSizer3, 1, wxEXPAND, 5 );
	
	m_button1 = new wxButton( this, wxID_ANY, wxT("Browse"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer4->Add( m_button1, 0, wxALL, 5 );
	
	
	bSizer5->Add( bSizer4, 0, wxEXPAND, 5 );
	
	m_staticText11 = new wxStaticText( this, wxID_ANY, wxT("DLight Config File"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText11->Wrap( -1 );
	bSizer5->Add( m_staticText11, 0, wxALL, 5 );
	
	wxBoxSizer* bSizer41;
	bSizer41 = new wxBoxSizer( wxHORIZONTAL );
	
	wxBoxSizer* bSizer31;
	bSizer31 = new wxBoxSizer( wxVERTICAL );
	
	m_textConfigInput = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer31->Add( m_textConfigInput, 0, wxALL|wxEXPAND, 5 );
	
	
	bSizer41->Add( bSizer31, 1, wxEXPAND, 5 );
	
	m_button11 = new wxButton( this, wxID_ANY, wxT("Browse"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer41->Add( m_button11, 0, wxALL, 5 );
	
	
	bSizer5->Add( bSizer41, 1, wxEXPAND, 5 );
	
	
	bSizer1->Add( bSizer5, 0, wxEXPAND|wxRIGHT|wxLEFT, 5 );
	
	
	bSizer1->Add( 0, 16, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer13;
	bSizer13 = new wxBoxSizer( wxHORIZONTAL );
	
	bSizer13->SetMinSize( wxSize( -1,128 ) ); 
	wxStaticBoxSizer* sbSizer1;
	sbSizer1 = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, wxT("Options") ), wxVERTICAL );
	
	sbSizer1->SetMinSize( wxSize( 176,-1 ) ); 
	m_cbSkipVis = new wxCheckBox( this, wxID_ANY, wxT("Skip GLVis"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer1->Add( m_cbSkipVis, 0, wxALL, 5 );
	
	m_cbSkipDLight = new wxCheckBox( this, wxID_ANY, wxT("Skip DLight"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer1->Add( m_cbSkipDLight, 0, wxALL, 5 );
	
	wxBoxSizer* bSizer19;
	bSizer19 = new wxBoxSizer( wxHORIZONTAL );
	
	wxString m_choiceMapSlotChoices[] = { wxT("1"), wxT("2"), wxT("3"), wxT("4"), wxT("5"), wxT("6"), wxT("7"), wxT("8"), wxT("9"), wxT("10"), wxT("11"), wxT("12"), wxT("13"), wxT("14"), wxT("15"), wxT("16"), wxT("17"), wxT("18"), wxT("19"), wxT("20"), wxT("21"), wxT("22"), wxT("23"), wxT("24"), wxT("25"), wxT("26"), wxT("27"), wxT("28"), wxT("29"), wxT("30"), wxT("31"), wxT("32"), wxT("33"), wxT("34"), wxT("35"), wxT("36"), wxT("37"), wxT("38"), wxT("39"), wxT("40"), wxT("41"), wxT("42"), wxT("43"), wxT("44"), wxT("45"), wxT("46"), wxT("47"), wxT("48"), wxT("49"), wxT("50"), wxT("51"), wxT("52"), wxT("53"), wxT("54"), wxT("55"), wxT("56"), wxT("57"), wxT("58"), wxT("59"), wxT("60"), wxT("61"), wxT("62"), wxT("63"), wxT("64"), wxT("65"), wxT("66"), wxT("67"), wxT("68"), wxT("69"), wxT("70"), wxT("71"), wxT("72"), wxT("73"), wxT("74"), wxT("75"), wxT("76"), wxT("77"), wxT("78"), wxT("79"), wxT("80"), wxT("81"), wxT("82"), wxT("83"), wxT("84"), wxT("85"), wxT("86"), wxT("87"), wxT("88"), wxT("89"), wxT("90"), wxT("91"), wxT("92"), wxT("93"), wxT("94"), wxT("95"), wxT("96"), wxT("97"), wxT("98"), wxT("99") };
	int m_choiceMapSlotNChoices = sizeof( m_choiceMapSlotChoices ) / sizeof( wxString );
	m_choiceMapSlot = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxSize( 48,-1 ), m_choiceMapSlotNChoices, m_choiceMapSlotChoices, 0 );
	m_choiceMapSlot->SetSelection( 0 );
	bSizer19->Add( m_choiceMapSlot, 0, wxALL, 5 );
	
	m_staticText42 = new wxStaticText( this, wxID_ANY, wxT("Map Number"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText42->Wrap( -1 );
	bSizer19->Add( m_staticText42, 0, wxALIGN_CENTER_VERTICAL|wxALIGN_LEFT|wxALL, 5 );
	
	
	sbSizer1->Add( bSizer19, 0, 0, 5 );
	
	
	bSizer13->Add( sbSizer1, 0, wxEXPAND|wxLEFT, 5 );
	
	wxStaticBoxSizer* sbSizer2;
	sbSizer2 = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, wxT("DLight") ), wxVERTICAL );
	
	wxBoxSizer* bSizer15;
	bSizer15 = new wxBoxSizer( wxHORIZONTAL );
	
	wxString m_choiceSamplesChoices[] = { wxT("2"), wxT("4"), wxT("8"), wxT("16") };
	int m_choiceSamplesNChoices = sizeof( m_choiceSamplesChoices ) / sizeof( wxString );
	m_choiceSamples = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxSize( 64,-1 ), m_choiceSamplesNChoices, m_choiceSamplesChoices, 0 );
	m_choiceSamples->SetSelection( 2 );
	bSizer15->Add( m_choiceSamples, 0, wxALL, 5 );
	
	
	bSizer15->Add( 8, 0, 0, 0, 5 );
	
	m_staticText41 = new wxStaticText( this, wxID_ANY, wxT("Samples"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText41->Wrap( -1 );
	bSizer15->Add( m_staticText41, 0, wxALIGN_CENTER_VERTICAL|wxALIGN_LEFT|wxALL, 5 );
	
	
	sbSizer2->Add( bSizer15, 0, 0, 5 );
	
	wxBoxSizer* bSizer151;
	bSizer151 = new wxBoxSizer( wxHORIZONTAL );
	
	wxString m_choiceSizeChoices[] = { wxT("128"), wxT("256") };
	int m_choiceSizeNChoices = sizeof( m_choiceSizeChoices ) / sizeof( wxString );
	m_choiceSize = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxSize( 64,-1 ), m_choiceSizeNChoices, m_choiceSizeChoices, 0 );
	m_choiceSize->SetSelection( 1 );
	bSizer151->Add( m_choiceSize, 0, wxALL, 5 );
	
	
	bSizer151->Add( 8, 0, 0, 0, 5 );
	
	m_staticText4 = new wxStaticText( this, wxID_ANY, wxT("Texture Size"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText4->Wrap( -1 );
	bSizer151->Add( m_staticText4, 0, wxALIGN_CENTER_VERTICAL|wxALIGN_LEFT|wxALL, 5 );
	
	
	sbSizer2->Add( bSizer151, 0, 0, 5 );
	
	wxBoxSizer* bSizer1511;
	bSizer1511 = new wxBoxSizer( wxHORIZONTAL );
	
	wxString m_choiceThreadsChoices[] = { wxT("1"), wxT("2"), wxT("3"), wxT("4") };
	int m_choiceThreadsNChoices = sizeof( m_choiceThreadsChoices ) / sizeof( wxString );
	m_choiceThreads = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxSize( 64,-1 ), m_choiceThreadsNChoices, m_choiceThreadsChoices, 0 );
	m_choiceThreads->SetSelection( 1 );
	bSizer1511->Add( m_choiceThreads, 0, wxALL, 5 );
	
	
	bSizer1511->Add( 8, 0, 0, 0, 5 );
	
	m_staticText43 = new wxStaticText( this, wxID_ANY, wxT("Threads"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText43->Wrap( -1 );
	bSizer1511->Add( m_staticText43, 0, wxALIGN_CENTER_VERTICAL|wxALIGN_LEFT|wxALL, 5 );
	
	
	sbSizer2->Add( bSizer1511, 0, 0, 5 );
	
	
	bSizer13->Add( sbSizer2, 1, wxEXPAND|wxRIGHT, 5 );
	
	
	bSizer1->Add( bSizer13, 0, wxEXPAND, 5 );
	
	
	bSizer1->Add( 0, 16, 0, wxEXPAND, 5 );
	
	m_btnCompile = new wxButton( this, wxID_ANY, wxT("Compile"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer1->Add( m_btnCompile, 0, wxALIGN_CENTER_HORIZONTAL|wxEXPAND|wxALL, 5 );
	
	
	bSizer1->Add( 0, 16, 0, wxEXPAND, 5 );
	
	wxStaticBoxSizer* sbSizer3;
	sbSizer3 = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, wxT("Output Log") ), wxVERTICAL );
	
	m_outputLog = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxHSCROLL|wxTE_MULTILINE|wxTE_READONLY );
	sbSizer3->Add( m_outputLog, 1, wxEXPAND, 5 );
	
	
	bSizer1->Add( sbSizer3, 1, wxEXPAND|wxRIGHT|wxLEFT, 5 );
	
	
	this->SetSizer( bSizer1 );
	this->Layout();
	m_menubar1 = new wxMenuBar( 0 );
	m_menu2 = new wxMenu();
	wxMenuItem* m_menuItem1;
	m_menuItem1 = new wxMenuItem( m_menu2, wxID_ANY, wxString( wxT("About") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu2->Append( m_menuItem1 );
	
	m_menubar1->Append( m_menu2, wxT("Help") ); 
	
	this->SetMenuBar( m_menubar1 );
	
	
	this->Centre( wxBOTH );
	
	// Connect Events
	m_button1->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrame::OpenInputFile ), NULL, this );
	m_button11->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrame::OpenInputConfigFile ), NULL, this );
	m_btnCompile->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrame::RunProcess ), NULL, this );
	this->Connect( m_menuItem1->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrame::AboutMenuClicked ) );
}

MainFrame::~MainFrame()
{
	// Disconnect Events
	m_button1->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrame::OpenInputFile ), NULL, this );
	m_button11->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrame::OpenInputConfigFile ), NULL, this );
	m_btnCompile->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrame::RunProcess ), NULL, this );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrame::AboutMenuClicked ) );
	
}
