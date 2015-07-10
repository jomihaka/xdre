#ifndef __MAINWINDOW_HPP
#define __MAINWINDOW_HPP

#include <functional>

//(*Headers(MainWindow)
#include <wx/stattext.h>
#include <wx/menu.h>
#include <wx/textctrl.h>
#include <wx/checkbox.h>
#include <wx/panel.h>
#include <wx/choice.h>
#include <wx/frame.h>
#include "TiclistCtrl.hpp"
//*)
#include <wx/fileconf.h>

enum class XdreCommand {
    //commands without value, let exit be last of these
    Fire,
    Use,
    TurnStepLeft,
    TurnStepRight,
    PrevTic,
    NextTic,
    CopyTic,
    DeleteTic,
    NewTic,
    ToggleBlood,
    SetSavepoint,
    UnsetSavepoint,
    Load,
    Save,
    Exit,
    //commands with one digit value, let weapon be last of these
    ChangePlayer,
    Weapon,
    //commands with char
    RunBwd,
    RunFwd,
    StrafeLeft,
    StrafeRight,
    TurnLeft,
    TurnRight,
    //commands with bigger value
    BackwardDemo,
    ForwardDemo
};

WX_DECLARE_STRING_HASH_MAP(XdreCommand, StringToCommandMap);


class MainWindow : public wxFrame {
public:
    MainWindow(wxWindow* parent = NULL, wxWindowID id = wxID_ANY, wxPoint const& pos = wxDefaultPosition, wxSize const& size = wxDefaultSize);
    virtual ~MainWindow();

    //(*Declarations(MainWindow)
    wxStaticText* StaticText10;
    wxStaticText* StaticText9;
    wxStaticText* StaticText20;
    wxPanel* panel;
    wxMenu* menuFile;
    wxTextCtrl* yPos;
    TiclistCtrl* ticlist;
    wxMenuItem* MenuItem5;
    wxStaticText* StaticText13;
    wxTextCtrl* damageDone;
    wxTextCtrl* linedefInputField;
    wxStaticText* StaticText2;
    wxMenuItem* MenuItem2;
    wxStaticText* StaticText14;
    wxStaticText* StaticText6;
    wxMenuItem* MenuItem1;
    wxMenuItem* MenuItem4;
    wxTextCtrl* currentTic;
    wxTextCtrl* linedefXV1;
    wxTextCtrl* distanceMoved;
    wxTextCtrl* xPos;
    wxStaticText* StaticText19;
    wxStaticText* StaticText8;
    wxStaticText* StaticText11;
    wxCheckBox* noBloodBox;
    wxStaticText* StaticText18;
    wxStaticText* StaticText1;
    wxStaticText* StaticText3;
    wxMenu* Menu1;
    wxStaticText* StaticText21;
    wxTextCtrl* xMom;
    wxMenuItem* MenuItem3;
    wxTextCtrl* crossed;
    wxTextCtrl* directionMoved;
    wxStaticText* StaticText5;
    wxStaticText* StaticText7;
    wxChoice* styleChoice;
    wxMenuItem* MenuItem6;
    wxMenu* menuTools;
    wxTextCtrl* distanceFromLine;
    wxTextCtrl* linedefYV1;
    wxTextCtrl* yMom;
    wxStaticText* StaticText15;
    wxStaticText* StaticText12;
    wxTextCtrl* linedefYV2;
    wxTextCtrl* time;
    wxMenu* menuOptions;
    wxStaticText* StaticText17;
    wxStaticText* StaticText4;
    wxTextCtrl* linedefXV2;
    wxTextCtrl* rngIndex;
    wxTextCtrl* useSuccess;
    wxTextCtrl* inputField;
    wxStaticText* StaticText16;
    wxTextCtrl* playerAngle;
    wxTextCtrl* savepointTic;
    wxMenuBar* menuBar;
    //*)
    wxStaticText* StaticText300;
    wxStaticText* StaticText400;
    wxTextCtrl* zPos;
    wxTextCtrl* zMom;

protected:

    //(*Identifiers(MainWindow)
    static const long ID_STATICTEXT1;
    static const long ID_STATICTEXT2;
    static const long ID_STATICTEXT3;
    static const long ID_STATICTEXT4;
    static const long ID_STATICTEXT5;
    static const long ID_STATICTEXT6;
    static const long ID_STATICTEXT7;
    static const long ID_STATICTEXT8;
    static const long ID_STATICTEXT9;
    static const long ID_STATICTEXT10;
    static const long ID_STATICTEXT11;
    static const long ID_STATICTEXT12;
    static const long ID_STATICTEXT13;
    static const long ID_STATICTEXT14;
    static const long ID_STATICTEXT15;
    static const long ID_STATICTEXT16;
    static const long ID_STATICTEXT17;
    static const long ID_STATICTEXT18;
    static const long ID_STATICTEXT19;
    static const long ID_STATICTEXT20;
    static const long ID_INPUTFIELD;
    static const long ID_RNGINDEX;
    static const long ID_XPOS;
    static const long ID_YPOS;
    static const long ID_XMOM;
    static const long ID_YMOM;
    static const long ID_DISTANCEMOVED;
    static const long ID_DIRECTIONMOVED;
    static const long ID_PLAYERANGLE;
    static const long ID_LINEDEFINPUTFIELD;
    static const long ID_CROSSED;
    static const long ID_LINEDEFXV1;
    static const long ID_LINEDEFYV1;
    static const long ID_LINEDEFXV2;
    static const long ID_LINEDEFYV2;
    static const long ID_DISTANCEFROMLINE;
    static const long ID_NOBLOODBOX;
    static const long ID_USESUCCESS;
    static const long ID_DAMAGEDONE;
    static const long ID_TIME;
    static const long ID_CURRENTTIC;
    static const long ID_TICLIST;
    static const long ID_STATICTEXT21;
    static const long ID_SAVEPOINTTIC;
    static const long ID_STYLECHOICE;
    static const long ID_PANEL;
    static const long IDM_LOAD;
    static const long IDM_SAVE;
    static const long IDM_EXIT;
    static const long IDM_BRUTE;
    static const long IDM_SETKEYS;
    static const long IDM_HEADER;
    //*)
    static const long ID_STATICTEXT300;
    static const long ID_STATICTEXT400;
    static const long ID_ZPOS;
    static const long ID_ZMOM;

private:
    void DoInput(XdreCommand cmd, unsigned int val = 0);
    void RefreshStuff();
    void Save();
    void Load();
    void Quit(bool canVeto = true);


#ifdef _WIN32
    wxFileConfig config {"xdre", "wxEmptyString"};
#else
    wxFileConfig config {"xdre", "wxEmptyString", ".xdre/xdre"};
#endif // _WIN32
    wxStringToStringHashMap configToStringMap {}; // config -> textCommand
    StringToCommandMap stringToCommandMap {}; // textCommand -> XdreCommand

    void OnIdle(wxCommandEvent& event);
    //(*Handlers(MainWindow)
    void OnClose(wxCloseEvent& event);
    void OnInputFieldText(wxCommandEvent& event);
    void OnLinedefInputFieldText(wxCommandEvent& event);
    void OnBloodBoxClick(wxCommandEvent& event);
    void OnMenuExit(wxCommandEvent& event);
    void OnMenuLoad(wxCommandEvent& event);
    void OnMenuSave(wxCommandEvent& event);
    void OnMenuBrute(wxCommandEvent& event);
    void OnMenuSetKeys(wxCommandEvent& event);
    void OnMenuHeader(wxCommandEvent& event);
    void OnStyleChoiceSelect(wxCommandEvent& event);
    //*)

    DECLARE_EVENT_TABLE()
};

#endif // __MAINWINDOW_HPP
