#include "MainWindow.hpp"


//(*InternalHeaders(MainWindow)
#include <wx/intl.h>
#include <wx/string.h>
//*)
#include <wx/valnum.h>
#include <wx/msgdlg.h>
#include <wx/filedlg.h>
#include <wx/ffile.h>
#include "BruteDialog.hpp"
#include "xdre.hpp"
#include "config.h"


//(*IdInit(MainWindow)
const long MainWindow::ID_STATICTEXT1 = wxNewId();
const long MainWindow::ID_STATICTEXT2 = wxNewId();
const long MainWindow::ID_STATICTEXT3 = wxNewId();
const long MainWindow::ID_STATICTEXT4 = wxNewId();
const long MainWindow::ID_STATICTEXT5 = wxNewId();
const long MainWindow::ID_STATICTEXT6 = wxNewId();
const long MainWindow::ID_STATICTEXT7 = wxNewId();
const long MainWindow::ID_STATICTEXT8 = wxNewId();
const long MainWindow::ID_STATICTEXT9 = wxNewId();
const long MainWindow::ID_STATICTEXT10 = wxNewId();
const long MainWindow::ID_STATICTEXT11 = wxNewId();
const long MainWindow::ID_STATICTEXT12 = wxNewId();
const long MainWindow::ID_STATICTEXT13 = wxNewId();
const long MainWindow::ID_STATICTEXT14 = wxNewId();
const long MainWindow::ID_STATICTEXT15 = wxNewId();
const long MainWindow::ID_STATICTEXT16 = wxNewId();
const long MainWindow::ID_STATICTEXT17 = wxNewId();
const long MainWindow::ID_STATICTEXT18 = wxNewId();
const long MainWindow::ID_STATICTEXT19 = wxNewId();
const long MainWindow::ID_STATICTEXT20 = wxNewId();
const long MainWindow::ID_INPUTFIELD = wxNewId();
const long MainWindow::ID_RNGINDEX = wxNewId();
const long MainWindow::ID_XPOS = wxNewId();
const long MainWindow::ID_YPOS = wxNewId();
const long MainWindow::ID_XMOM = wxNewId();
const long MainWindow::ID_YMOM = wxNewId();
const long MainWindow::ID_DISTANCEMOVED = wxNewId();
const long MainWindow::ID_DIRECTIONMOVED = wxNewId();
const long MainWindow::ID_PLAYERANGLE = wxNewId();
const long MainWindow::ID_LINEDEFINPUTFIELD = wxNewId();
const long MainWindow::ID_CROSSED = wxNewId();
const long MainWindow::ID_LINEDEFXV1 = wxNewId();
const long MainWindow::ID_LINEDEFYV1 = wxNewId();
const long MainWindow::ID_LINEDEFXV2 = wxNewId();
const long MainWindow::ID_LINEDEFYV2 = wxNewId();
const long MainWindow::ID_DISTANCEFROMLINE = wxNewId();
const long MainWindow::ID_NOBLOODBOX = wxNewId();
const long MainWindow::ID_USESUCCESS = wxNewId();
const long MainWindow::ID_DAMAGEDONE = wxNewId();
const long MainWindow::ID_TIME = wxNewId();
const long MainWindow::ID_CURRENTTIC = wxNewId();
const long MainWindow::ID_TICLIST = wxNewId();
const long MainWindow::ID_STATICTEXT21 = wxNewId();
const long MainWindow::ID_SAVEPOINTTIC = wxNewId();
const long MainWindow::ID_STYLECHOICE = wxNewId();
const long MainWindow::ID_PANEL = wxNewId();
const long MainWindow::IDM_LOAD = wxNewId();
const long MainWindow::IDM_SAVE = wxNewId();
const long MainWindow::IDM_EXIT = wxNewId();
const long MainWindow::IDM_BRUTE = wxNewId();
const long MainWindow::IDM_SETKEYS = wxNewId();
const long MainWindow::IDM_HEADER = wxNewId();
//*)
const long MainWindow::ID_STATICTEXT300 = wxNewId();
const long MainWindow::ID_STATICTEXT400 = wxNewId();
const long MainWindow::ID_ZPOS = wxNewId();
const long MainWindow::ID_ZMOM = wxNewId();

BEGIN_EVENT_TABLE(MainWindow, wxFrame)
	//(*EventTable(MainWindow)
	//*)
END_EVENT_TABLE()

MainWindow::MainWindow(wxWindow* parent, wxWindowID id, wxPoint const& pos, wxSize const& size)
{
    configToStringMap["Fire"] = config.Read("Fire", "f");
    configToStringMap["Use"] = config.Read("Use", "u");
    configToStringMap["TurnStepLeft"] = config.Read("TurnStepLeft", "-");
    configToStringMap["TurnStepRight"] = config.Read("TurnStepRight", "+");
    configToStringMap["PrevTic"] = config.Read("PrevTic", "j");
    configToStringMap["NextTic"] = config.Read("NextTic", "i");
    configToStringMap["CopyTic"] = config.Read("CopyTic", "c");
    configToStringMap["DeleteTic"] = config.Read("DeleteTic", "x");
    configToStringMap["NewTic"] = config.Read("NewTic", "n");
    configToStringMap["ToggleBlood"] = config.Read("ToggleBlood", "z");
    configToStringMap["SetSavepoint"] = config.Read("SetSavepoint", "ssp");
    configToStringMap["UnsetSavepoint"] = config.Read("UnsetSavepoint", "pss");
    configToStringMap["Load"] = config.Read("Load", "load");
    configToStringMap["Save"] = config.Read("Save", "save");
    configToStringMap["Exit"] = config.Read("Exit", "exit");

    configToStringMap["RunBwd"] = config.Read("RunBwd", "wq");
    configToStringMap["RunFwd"] = config.Read("RunFwd", "we");
    configToStringMap["StrafeLeft"] = config.Read("StrafeLeft", "sa");
    configToStringMap["StrafeRight"] = config.Read("StrafeRight", "sd");
    configToStringMap["TurnLeft"] = config.Read("TurnLeft", "re");
    configToStringMap["TurnRight"] = config.Read("TurnRight", "rt");
    configToStringMap["Weapon"] = config.Read("Weapon", "g");

    configToStringMap["BackwardDemo"] = config.Read("BackwardDemo", ",");
    configToStringMap["ForwardDemo"] = config.Read("ForwardDemo", ".");
    configToStringMap["ChangePlayer"] = config.Read("ChangePlayer", "v");

    stringToCommandMap[configToStringMap["Fire"]] = XdreCommand::Fire;
    stringToCommandMap[configToStringMap["Use"]] = XdreCommand::Use;
    stringToCommandMap[configToStringMap["TurnStepLeft"]] = XdreCommand::TurnStepLeft;
    stringToCommandMap[configToStringMap["TurnStepRight"]] = XdreCommand::TurnStepRight;
    stringToCommandMap[configToStringMap["PrevTic"]] = XdreCommand::PrevTic;
    stringToCommandMap[configToStringMap["NextTic"]] = XdreCommand::NextTic;
    stringToCommandMap[configToStringMap["CopyTic"]] = XdreCommand::CopyTic;
    stringToCommandMap[configToStringMap["DeleteTic"]] = XdreCommand::DeleteTic;
    stringToCommandMap[configToStringMap["NewTic"]] = XdreCommand::NewTic;
    stringToCommandMap[configToStringMap["ToggleBlood"]] = XdreCommand::ToggleBlood;
    stringToCommandMap[configToStringMap["SetSavepoint"]] = XdreCommand::SetSavepoint;
    stringToCommandMap[configToStringMap["UnsetSavepoint"]] = XdreCommand::UnsetSavepoint;
    stringToCommandMap[configToStringMap["Load"]] = XdreCommand::Load;
    stringToCommandMap[configToStringMap["Save"]] = XdreCommand::Save;
    stringToCommandMap[configToStringMap["Exit"]] = XdreCommand::Exit;

    stringToCommandMap[configToStringMap["RunBwd"]] = XdreCommand::RunBwd;
    stringToCommandMap[configToStringMap["RunFwd"]] = XdreCommand::RunFwd;
    stringToCommandMap[configToStringMap["StrafeLeft"]] = XdreCommand::StrafeLeft;
    stringToCommandMap[configToStringMap["StrafeRight"]] = XdreCommand::StrafeRight;
    stringToCommandMap[configToStringMap["TurnLeft"]] = XdreCommand::TurnLeft;
    stringToCommandMap[configToStringMap["TurnRight"]] = XdreCommand::TurnRight;
    stringToCommandMap[configToStringMap["Weapon"]] = XdreCommand::Weapon;

    stringToCommandMap[configToStringMap["BackwardDemo"]] = XdreCommand::BackwardDemo;
    stringToCommandMap[configToStringMap["ForwardDemo"]] = XdreCommand::ForwardDemo;
    stringToCommandMap[configToStringMap["ChangePlayer"]] = XdreCommand::ChangePlayer;

	//(*Initialize(MainWindow)
	Create(parent, id, "xdre " PACKAGE_VERSION, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("id"));
	SetClientSize(wxSize(640,520));
	Move(wxDefaultPosition);
	SetMinSize(wxSize(640,520));
	SetMaxSize(wxSize(640,520));
	panel = new wxPanel(this, ID_PANEL, wxDefaultPosition, wxDefaultSize, 0, _T("ID_PANEL"));
	StaticText1 = new wxStaticText(panel, ID_STATICTEXT1, _("Rng Index"), wxPoint(510,44), wxDefaultSize, 0, _T("ID_STATICTEXT1"));
	StaticText2 = new wxStaticText(panel, ID_STATICTEXT2, _("Input"), wxPoint(534,12), wxSize(27,16), 0, _T("ID_STATICTEXT2"));
	StaticText3 = new wxStaticText(panel, ID_STATICTEXT3, _("X pos"), wxPoint(355,84), wxDefaultSize, 0, _T("ID_STATICTEXT3"));
	StaticText4 = new wxStaticText(panel, ID_STATICTEXT4, _("Y pos"), wxPoint(499,84), wxDefaultSize, 0, _T("ID_STATICTEXT4"));
	StaticText5 = new wxStaticText(panel, ID_STATICTEXT5, _("X mom"), wxPoint(346,116), wxDefaultSize, 0, _T("ID_STATICTEXT5"));
	StaticText6 = new wxStaticText(panel, ID_STATICTEXT6, _("Y mom"), wxPoint(490,116), wxDefaultSize, 0, _T("ID_STATICTEXT6"));
	StaticText7 = new wxStaticText(panel, ID_STATICTEXT7, _("Distance moved"), wxPoint(444,148), wxDefaultSize, 0, _T("ID_STATICTEXT7"));
	StaticText8 = new wxStaticText(panel, ID_STATICTEXT8, _("Direction moved"), wxPoint(441,180), wxDefaultSize, 0, _T("ID_STATICTEXT8"));
	StaticText9 = new wxStaticText(panel, ID_STATICTEXT9, _("Player angle"), wxPoint(465,212), wxDefaultSize, 0, _T("ID_STATICTEXT9"));
	StaticText10 = new wxStaticText(panel, ID_STATICTEXT10, _("Linedef"), wxPoint(380,332), wxDefaultSize, 0, _T("ID_STATICTEXT10"));
	StaticText11 = new wxStaticText(panel, ID_STATICTEXT11, _("hit special"), wxPoint(512,331), wxDefaultSize, 0, _T("ID_STATICTEXT11"));
	StaticText12 = new wxStaticText(panel, ID_STATICTEXT12, _("Linedef X"), wxPoint(442,356), wxDefaultSize, 0, _T("ID_STATICTEXT12"));
	StaticText13 = new wxStaticText(panel, ID_STATICTEXT13, _("Linedef Y"), wxPoint(554,356), wxDefaultSize, 0, _T("ID_STATICTEXT13"));
	StaticText14 = new wxStaticText(panel, ID_STATICTEXT14, _("v1"), wxPoint(407,380), wxDefaultSize, 0, _T("ID_STATICTEXT14"));
	StaticText15 = new wxStaticText(panel, ID_STATICTEXT15, _("v2"), wxPoint(407,404), wxDefaultSize, 0, _T("ID_STATICTEXT15"));
	StaticText16 = new wxStaticText(panel, ID_STATICTEXT16, _("Distance from line"), wxPoint(433,428), wxDefaultSize, 0, _T("ID_STATICTEXT16"));
	StaticText17 = new wxStaticText(panel, ID_STATICTEXT17, _("Current tic"), wxPoint(69,428), wxDefaultSize, 0, _T("ID_STATICTEXT17"));
	StaticText18 = new wxStaticText(panel, ID_STATICTEXT18, _("Used a line"), wxPoint(221,364), wxDefaultSize, 0, _T("ID_STATICTEXT18"));
	StaticText19 = new wxStaticText(panel, ID_STATICTEXT19, _("Damage done"), wxPoint(204,396), wxDefaultSize, 0, _T("ID_STATICTEXT19"));
	StaticText20 = new wxStaticText(panel, ID_STATICTEXT20, _("Time"), wxPoint(251,428), wxDefaultSize, 0, _T("ID_STATICTEXT20"));
	inputField = new wxTextCtrl(panel, ID_INPUTFIELD, wxEmptyString, wxPoint(568,8), wxSize(52,21), wxTE_RIGHT, wxDefaultValidator, _T("ID_INPUTFIELD"));
	inputField->SetMaxLength(10);
	rngIndex = new wxTextCtrl(panel, ID_RNGINDEX, _("0"), wxPoint(568,40), wxSize(52,21), wxTE_READONLY|wxTE_RIGHT, wxDefaultValidator, _T("ID_RNGINDEX"));
	xPos = new wxTextCtrl(panel, ID_XPOS, _("0"), wxPoint(392,80), wxSize(84,21), wxTE_READONLY|wxTE_RIGHT, wxDefaultValidator, _T("ID_XPOS"));
	yPos = new wxTextCtrl(panel, ID_YPOS, _("0"), wxPoint(536,80), wxSize(84,21), wxTE_READONLY|wxTE_RIGHT, wxDefaultValidator, _T("ID_YPOS"));
	xMom = new wxTextCtrl(panel, ID_XMOM, _("0"), wxPoint(392,112), wxSize(84,21), wxTE_READONLY|wxTE_RIGHT, wxDefaultValidator, _T("ID_XMOM"));
	yMom = new wxTextCtrl(panel, ID_YMOM, _("0"), wxPoint(536,112), wxSize(84,21), wxTE_READONLY|wxTE_RIGHT, wxDefaultValidator, _T("ID_YMOM"));
	distanceMoved = new wxTextCtrl(panel, ID_DISTANCEMOVED, _("0"), wxPoint(536,144), wxSize(84,21), wxTE_READONLY|wxTE_RIGHT, wxDefaultValidator, _T("ID_DISTANCEMOVED"));
	directionMoved = new wxTextCtrl(panel, ID_DIRECTIONMOVED, _("0"), wxPoint(536,176), wxSize(84,21), wxTE_READONLY|wxTE_RIGHT, wxDefaultValidator, _T("ID_DIRECTIONMOVED"));
	playerAngle = new wxTextCtrl(panel, ID_PLAYERANGLE, _("0"), wxPoint(536,208), wxSize(84,21), wxTE_READONLY|wxTE_RIGHT, wxDefaultValidator, _T("ID_PLAYERANGLE"));
	linedefInputField = new wxTextCtrl(panel, ID_LINEDEFINPUTFIELD, _("0"), wxPoint(424,328), wxSize(84,21), wxTE_RIGHT, wxIntegerValidator<unsigned int>(), _T("ID_LINEDEFINPUTFIELD"));
	linedefInputField->SetMaxLength(10);
	crossed = new wxTextCtrl(panel, ID_CROSSED, _("false"), wxPoint(568,328), wxSize(52,21), wxTE_READONLY|wxTE_RIGHT, wxDefaultValidator, _T("ID_CROSSED"));
	linedefXV1 = new wxTextCtrl(panel, ID_LINEDEFXV1, _("0"), wxPoint(424,376), wxSize(84,21), wxTE_READONLY|wxTE_RIGHT, wxDefaultValidator, _T("ID_LINEDEFXV1"));
	linedefYV1 = new wxTextCtrl(panel, ID_LINEDEFYV1, _("0"), wxPoint(536,376), wxSize(84,21), wxTE_READONLY|wxTE_RIGHT, wxDefaultValidator, _T("ID_LINEDEFYV1"));
	linedefXV2 = new wxTextCtrl(panel, ID_LINEDEFXV2, _("0"), wxPoint(424,400), wxSize(84,21), wxTE_READONLY|wxTE_RIGHT, wxDefaultValidator, _T("ID_LINEDEFXV2"));
	linedefYV2 = new wxTextCtrl(panel, ID_LINEDEFYV2, _("0"), wxPoint(536,400), wxSize(84,21), wxTE_READONLY|wxTE_RIGHT, wxDefaultValidator, _T("ID_LINEDEFYV2"));
	distanceFromLine = new wxTextCtrl(panel, ID_DISTANCEFROMLINE, _("0"), wxPoint(536,424), wxSize(84,21), wxTE_READONLY|wxTE_RIGHT, wxDefaultValidator, _T("ID_DISTANCEFROMLINE"));
	noBloodBox = new wxCheckBox(panel, ID_NOBLOODBOX, _("No blood"), wxPoint(536,248), wxDefaultSize, 0, wxDefaultValidator, _T("ID_NOBLOODBOX"));
	noBloodBox->SetValue(false);
	useSuccess = new wxTextCtrl(panel, ID_USESUCCESS, _("false"), wxPoint(284,360), wxSize(68,21), wxTE_READONLY|wxTE_RIGHT, wxDefaultValidator, _T("ID_USESUCCESS"));
	damageDone = new wxTextCtrl(panel, ID_DAMAGEDONE, _("0"), wxPoint(284,392), wxSize(68,21), wxTE_READONLY|wxTE_RIGHT, wxDefaultValidator, _T("ID_DAMAGEDONE"));
	time = new wxTextCtrl(panel, ID_TIME, _("0"), wxPoint(284,424), wxSize(68,21), wxTE_READONLY|wxTE_RIGHT, wxDefaultValidator, _T("ID_TIME"));
	currentTic = new wxTextCtrl(panel, ID_CURRENTTIC, _("0"), wxPoint(132,424), wxSize(68,21), wxTE_READONLY|wxTE_RIGHT, wxDefaultValidator, _T("ID_CURRENTTIC"));
	ticlist = new TiclistCtrl(panel,ID_TICLIST,wxPoint(16,16),wxSize(184,368),_T("ID_TICLIST"));
	StaticText21 = new wxStaticText(panel, ID_STATICTEXT21, _("Savepoint"), wxPoint(72,396), wxDefaultSize, 0, _T("ID_STATICTEXT21"));
	savepointTic = new wxTextCtrl(panel, ID_SAVEPOINTTIC, _("0"), wxPoint(132,392), wxSize(68,21), wxTE_READONLY|wxTE_RIGHT, wxDefaultValidator, _T("ID_SAVEPOINTTIC"));
	styleChoice = new wxChoice(panel, ID_STYLECHOICE, wxPoint(16,392), wxSize(48,21), 0, 0, 0, wxDefaultValidator, _T("ID_STYLECHOICE"));
	styleChoice->SetSelection( styleChoice->Append(_("User")) );
	styleChoice->Append(_("Start"));
	styleChoice->Append(_("Auto"));
	menuBar = new wxMenuBar();
	menuFile = new wxMenu();
	MenuItem1 = new wxMenuItem(menuFile, IDM_LOAD, _("Load..."), wxEmptyString, wxITEM_NORMAL);
	menuFile->Append(MenuItem1);
	MenuItem2 = new wxMenuItem(menuFile, IDM_SAVE, _("Save..."), wxEmptyString, wxITEM_NORMAL);
	menuFile->Append(MenuItem2);
	MenuItem3 = new wxMenuItem(menuFile, IDM_EXIT, _("Exit"), wxEmptyString, wxITEM_NORMAL);
	menuFile->Append(MenuItem3);
	menuBar->Append(menuFile, _("File"));
	menuTools = new wxMenu();
	MenuItem4 = new wxMenuItem(menuTools, IDM_BRUTE, _("Bruteforce..."), wxEmptyString, wxITEM_NORMAL);
	menuTools->Append(MenuItem4);
	menuBar->Append(menuTools, _("Tools"));
	menuOptions = new wxMenu();
	MenuItem5 = new wxMenuItem(menuOptions, IDM_SETKEYS, _("Set keys..."), wxEmptyString, wxITEM_NORMAL);
	menuOptions->Append(MenuItem5);
	MenuItem5->Enable(false);
	menuBar->Append(menuOptions, _("Options"));
	Menu1 = new wxMenu();
	MenuItem6 = new wxMenuItem(Menu1, IDM_HEADER, _("Header..."), wxEmptyString, wxITEM_NORMAL);
	Menu1->Append(MenuItem6);
	MenuItem6->Enable(false);
	menuBar->Append(Menu1, _("Demo"));
	SetMenuBar(menuBar);
	Center();

	Connect(ID_INPUTFIELD,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&MainWindow::OnInputFieldText);
	Connect(ID_LINEDEFINPUTFIELD,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&MainWindow::OnLinedefInputFieldText);
	Connect(ID_NOBLOODBOX,wxEVT_COMMAND_CHECKBOX_CLICKED,(wxObjectEventFunction)&MainWindow::OnBloodBoxClick);
	Connect(ID_STYLECHOICE,wxEVT_COMMAND_CHOICE_SELECTED,(wxObjectEventFunction)&MainWindow::OnStyleChoiceSelect);
	Connect(IDM_LOAD,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&MainWindow::OnMenuLoad);
	Connect(IDM_SAVE,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&MainWindow::OnMenuSave);
	Connect(IDM_EXIT,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&MainWindow::OnMenuExit);
	Connect(IDM_BRUTE,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&MainWindow::OnMenuBrute);
	Connect(IDM_SETKEYS,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&MainWindow::OnMenuSetKeys);
	Connect(IDM_HEADER,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&MainWindow::OnMenuHeader);
	Connect(wxID_ANY,wxEVT_CLOSE_WINDOW,(wxObjectEventFunction)&MainWindow::OnClose);
	//*)
	Connect(wxID_ANY, wxEVT_IDLE, (wxObjectEventFunction)&MainWindow::OnIdle);

	zPos = new wxTextCtrl(panel, ID_ZPOS, _("0"), wxPoint(248,80), wxSize(84,21), wxTE_READONLY|wxTE_RIGHT, wxDefaultValidator, _T("ID_ZPOS"));
	zMom = new wxTextCtrl(panel, ID_ZMOM, _("0"), wxPoint(248,112), wxSize(84,21), wxTE_READONLY|wxTE_RIGHT, wxDefaultValidator, _T("ID_ZMOM"));
	StaticText300 = new wxStaticText(panel, ID_STATICTEXT300, _("Z pos"), wxPoint(211,84), wxDefaultSize, 0, _T("ID_STATICTEXT300"));
	StaticText400 = new wxStaticText(panel, ID_STATICTEXT400, _("Z mom"), wxPoint(202,116), wxDefaultSize, 0, _T("ID_STATICTEXT400"));

	xdre::init();
	RefreshStuff();
}

MainWindow::~MainWindow()
{
	//(*Destroy(MainWindow)
	//*)
}

void MainWindow::DoInput(XdreCommand cmd, unsigned int val)
{
    switch (cmd) {
    case XdreCommand::Fire:
        xdre::toggleFire();
        RefreshStuff();
        break;

    case XdreCommand::Use:
        xdre::toggleUse();
        RefreshStuff();
        break;

    case XdreCommand::TurnStepLeft:
        xdre::turnStepLeft();
        RefreshStuff();
        break;

    case XdreCommand::TurnStepRight:
        xdre::turnStepRight();
        RefreshStuff();
        break;

    case XdreCommand::PrevTic:
        xdre::seekDemo(-1);
        RefreshStuff();
        break;

    case XdreCommand::NextTic:
        xdre::seekDemo(1);
        RefreshStuff();
        break;

    case XdreCommand::CopyTic:
        xdre::copyTic();
        RefreshStuff();
        break;

    case XdreCommand::DeleteTic:
        xdre::deleteTic();
        RefreshStuff();
        break;

    case XdreCommand::NewTic:
        xdre::newTic();
        RefreshStuff();
        break;

    case XdreCommand::ToggleBlood:
        xdre::toggleBlood();
        noBloodBox->SetValue(!xdre::getBlood());
        break;

    case XdreCommand::SetSavepoint:
        xdre::setSavepoint();
        RefreshStuff();
        break;

    case XdreCommand::UnsetSavepoint:
        xdre::unsetSavepoint();
        RefreshStuff();
        break;

    case XdreCommand::Load:
        Load();
        break;

    case XdreCommand::Save:
        Save();
        break;

    case XdreCommand::Exit:
        Quit();
        break;

    case XdreCommand::RunBwd:
        xdre::run(-val);
        RefreshStuff();
        break;

    case XdreCommand::RunFwd:
        xdre::run(val);
        RefreshStuff();
        break;

    case XdreCommand::StrafeLeft:
        xdre::strafe(-val);
        RefreshStuff();
        break;

    case XdreCommand::StrafeRight:
        xdre::strafe(val);
        RefreshStuff();
        break;

    case XdreCommand::TurnLeft:
        xdre::turn(val);
        RefreshStuff();
        break;

    case XdreCommand::TurnRight:
        xdre::turn(-val);
        RefreshStuff();
        break;

    case XdreCommand::Weapon:
        xdre::changeWeapon(val);
        RefreshStuff();
        break;

    case XdreCommand::BackwardDemo:
        xdre::seekDemo(-val);
        RefreshStuff();
        break;

    case XdreCommand::ForwardDemo:
        xdre::seekDemo(val);
        RefreshStuff();
        break;

    case XdreCommand::ChangePlayer:
        xdre::changePlayerView(val);
        RefreshStuff();
        break;

    default:
        break;
    }
}

void MainWindow::RefreshStuff()
{
    rngIndex->ChangeValue(wxString::FromCDouble(xdre::getRngIndex()));
    xPos->ChangeValue(wxString::FromCDouble(xdre::getXPos(), 6));
    yPos->ChangeValue(wxString::FromCDouble(xdre::getYPos(), 6));
    zPos->ChangeValue(wxString::FromCDouble(xdre::getZPos(), 6));
    xMom->ChangeValue(wxString::FromCDouble(xdre::getXMom(), 6));
    yMom->ChangeValue(wxString::FromCDouble(xdre::getYMom(), 6));
    zMom->ChangeValue(wxString::FromCDouble(xdre::getZMom(), 6));
    distanceMoved->ChangeValue(wxString::FromCDouble(xdre::getDistanceMoved(), 6));
    directionMoved->ChangeValue(wxString::FromCDouble(xdre::getDirectionMoved(), 6));
    playerAngle->ChangeValue(wxString::FromCDouble(xdre::getAngle()));
    time->ChangeValue(wxString::FromCDouble(xdre::getTime(), 2));
    currentTic->ChangeValue(wxString::FromCDouble(xdre::getCurrentTic()));
    damageDone->ChangeValue(wxString::FromCDouble(xdre::getDoneDamage()));
    useSuccess->ChangeValue(xdre::getUseSuccess() ? "true" : "false");
    crossed->ChangeValue(xdre::getLinedefCrossed() ? "true" : "false");
    linedefXV1->ChangeValue(wxString::FromCDouble(xdre::getLinedefVertex(0, 0), 6));
    linedefYV1->ChangeValue(wxString::FromCDouble(xdre::getLinedefVertex(0, 1), 6));
    linedefXV2->ChangeValue(wxString::FromCDouble(xdre::getLinedefVertex(1, 0), 6));
    linedefYV2->ChangeValue(wxString::FromCDouble(xdre::getLinedefVertex(1, 1), 6));
    distanceFromLine->ChangeValue(wxString::FromCDouble(xdre::getDistanceFromLine(), 6));
    savepointTic->ChangeValue(wxString::FromCDouble(xdre::getSavepointTic()));
    noBloodBox->SetValue(!xdre::getBlood());
    styleChoice->SetSelection(xdre::getSavepointStyle());

    ticlist->SetItemCount(xdre::getTiclistSize());
    ticlist->SetItemState(xdre::getCurrentTic(), wxLIST_STATE_SELECTED, wxLIST_STATE_SELECTED);
    ticlist->EnsureVisible(xdre::getCurrentTic());
    ticlist->Refresh();
}

void MainWindow::Save()
{
    wxString filename = wxFileSelector(wxFileSelectorPromptStr,
                                       wxEmptyString,
                                       wxEmptyString,
                                       ".lmp",
                                       "LMP files (*.lmp)|*.[Ll][Mm][Pp]",
                                       wxFD_SAVE | wxFD_OVERWRITE_PROMPT);

    if (!filename.empty()) {
        wxFFile file;
        if (file.Open(filename, "wb")) {
            if (!xdre::save(file.fp())) {
                wxMessageBox("Couldn't write demo. That's really weird and shouldn't happen.",
                             "Couldn't write demo",
                             wxOK | wxCENTRE | wxICON_ERROR,
                             this);
            }
        } else {
            wxMessageBox("Couldn't open file for write: " + filename,
                         "Couldn't open file",
                         wxOK | wxCENTRE | wxICON_ERROR,
                         this);
        }
    }
}

void MainWindow::Load()
{
    wxString filename = wxFileSelector(wxFileSelectorPromptStr,
                                       wxEmptyString,
                                       wxEmptyString,
                                       ".lmp",
                                       "LMP files (*.lmp)|*.[Ll][Mm][Pp]",
                                       wxFD_OPEN | wxFD_FILE_MUST_EXIST);

    if (!filename.empty()) {
        wxFFile file;
        if (file.Open(filename, "rb")) {
            if (!xdre::load(file.fp())) {
                wxMessageBox("Couldn't load demo. Debug it yourself to see what went wrong.",
                             "Couldn't load demo",
                             wxOK | wxCENTRE | wxICON_ERROR,
                             this);
            } else {
                RefreshStuff();
            }
        } else {
            wxMessageBox("Couldn't open file for read: " + filename,
                         "Couldn't open file",
                         wxOK | wxCENTRE | wxICON_ERROR,
                         this);
        }
    }
}

void MainWindow::Quit(bool canVeto)
{
    if (canVeto) {
        int ync = wxMessageBox("Do you want to save before quit?", "Save before quit", wxYES_NO | wxCANCEL, this);
        if (ync == wxCANCEL) {
            return;
        } else if (ync == wxYES) {
            Save();
        }
    }

    for (auto& key : configToStringMap) {
        config.Write(key.first, key.second);
    }

    Destroy();
}

void MainWindow::OnIdle(wxCommandEvent& event)
{
    xdre::doSdlEvents();
}

void MainWindow::OnClose(wxCloseEvent& event)
{
    Quit(event.CanVeto());
}

void MainWindow::OnInputFieldText(wxCommandEvent& event)
{
    wxString input = inputField->GetValue();

    if (input.length() < 1) {
        return;
    }

    wxString strCmd = input;
    unsigned long val = 0;
    int numDigits = 0;
    bool space = false;
    // plain cmd or with value?
    for (unsigned int i = 1; i < input.length(); ++i) {
        if (wxIsdigit(input[i])) {
            numDigits = input.Mid(i).First(" ");
            if (numDigits == wxNOT_FOUND) {
                numDigits = 1;
            } else {
                space = true;
            }

            // there should be digits only, is there?
            if (input.Mid(i, numDigits).ToULong(&val)) {
                strCmd = input.Mid(0, i);
                break; // yes
            } else {
                return; // no
            }
        }
    }

    auto keyvalue = stringToCommandMap.find(strCmd);
    if (keyvalue == stringToCommandMap.end()) {
        return;
    }

    // final checks D:
    if (keyvalue->second > XdreCommand::Exit && numDigits < 1) {
        return;
    } else if (keyvalue->second > XdreCommand::Weapon && !space) {
        return;
    }

    inputField->ChangeValue("");
    DoInput(keyvalue->second, val);
}

void MainWindow::OnLinedefInputFieldText(wxCommandEvent& event)
{
    unsigned long val;
    if (linedefInputField->GetValue().ToULong(&val)) {
        xdre::setLinedefCheck(val);
    }
}

void MainWindow::OnBloodBoxClick(wxCommandEvent& event)
{
    xdre::toggleBlood();
}

void MainWindow::OnMenuExit(wxCommandEvent& event)
{
    Quit();
}

void MainWindow::OnMenuLoad(wxCommandEvent& event)
{
    Load();
}

void MainWindow::OnMenuSave(wxCommandEvent& event)
{
    Save();
}

void MainWindow::OnMenuBrute(wxCommandEvent& event)
{
    BruteDialog bruteDialog(this);
    bruteDialog.ShowModal();

    RefreshStuff();
}

void MainWindow::OnMenuSetKeys(wxCommandEvent& event)
{
}

void MainWindow::OnMenuHeader(wxCommandEvent& event)
{
}

void MainWindow::OnStyleChoiceSelect(wxCommandEvent& event)
{
    xdre::setSavepointStyle(styleChoice->GetSelection());
    RefreshStuff();
}
