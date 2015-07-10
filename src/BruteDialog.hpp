#ifndef __BRUTEDIALOG_HPP
#define __BRUTEDIALOG_HPP

//(*Headers(BruteDialog)
#include <wx/stattext.h>
#include <wx/radiobox.h>
#include <wx/textctrl.h>
#include <wx/checkbox.h>
#include <wx/listbox.h>
#include <wx/statbox.h>
#include <wx/panel.h>
#include <wx/choice.h>
#include <wx/button.h>
#include <wx/dialog.h>
//*)
#include <wx/thread.h>
#include "xdre.hpp"

wxDECLARE_EVENT(EVT_BRUTE_DONE, wxThreadEvent);

class BruteDialog: public wxDialog, public wxThreadHelper
{
	public:

		BruteDialog(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~BruteDialog();

		//(*Declarations(BruteDialog)
		wxPanel* panel;
		wxCheckBox* damageCheckBox;
		wxChoice* speedChoice;
		wxChoice* xMomChoice;
		wxChoice* rngChoice;
		wxTextCtrl* xPosInput;
		wxTextCtrl* yMomInput;
		wxChoice* yMomChoice;
		wxStaticText* StaticText2;
		wxTextCtrl* speedInput;
		wxCheckBox* xPosCheckBox;
		wxButton* start;
		wxChoice* yPosChoice;
		wxCheckBox* useCheckBox;
		wxTextCtrl* runCmdInput;
		wxStaticText* workingText;
		wxTextCtrl* bruteTicInput;
		wxStaticText* StaticText1;
		wxCheckBox* xMomCheckBox;
		wxChoice* damageChoice;
		wxStaticText* StaticText3;
		wxStaticBox* StaticBox1;
		wxTextCtrl* turnCmdInput;
		wxTextCtrl* yPosInput;
		wxRadioBox* fireRadioBox;
		wxRadioBox* useRadioBox;
		wxListBox* bruteTicsBox;
		wxStaticBox* StaticBox2;
		wxTextCtrl* xMomInput;
		wxTextCtrl* checkTicInput;
		wxButton* removeButton;
		wxTextCtrl* damageInput;
		wxButton* cancel;
		wxChoice* xPosChoice;
		wxCheckBox* yPosCheckBox;
		wxButton* turnAngleButton;
		wxTextCtrl* strafeCmdInput;
		wxCheckBox* speedCheckBox;
		wxStaticText* StaticText4;
		wxCheckBox* rngCheckBox;
		wxTextCtrl* rngInput;
		wxButton* addButton;
		wxCheckBox* yMomCheckBox;
		//*)

        void OnBruteDone(wxThreadEvent& event);

	protected:

		//(*Identifiers(BruteDialog)
		static const long ID_CHECKTICINPUT;
		static const long ID_RNGINPUT;
		static const long ID_DAMAGEINPUT;
		static const long ID_XPOSINPUT;
		static const long ID_YPOSINPUT;
		static const long ID_XMOMINPUT;
		static const long ID_YMOMINPUT;
		static const long ID_SPEEDINPUT;
		static const long ID_RNGCHECKBOX;
		static const long ID_RNGCHOICE;
		static const long ID_DAMAGECHECKBOX;
		static const long ID_DAMAGECHOICE;
		static const long ID_XPOSCHECKBOX;
		static const long ID_XPOSCHOICE;
		static const long ID_YPOSCHECKBOX;
		static const long ID_YPOSCHOICE;
		static const long ID_XMOMCHECKBOX;
		static const long ID_XMOMCHOICE;
		static const long ID_YMOMCHECKBOX;
		static const long ID_YMOMCHOICE;
		static const long ID_SPEEDCHECKBOX;
		static const long ID_SPEEDCHOICE;
		static const long ID_USECHECKBOX;
		static const long ID_BRUTETICSBOX;
		static const long ID_ADDBUTTON;
		static const long ID_REMOVEBUTTON;
		static const long ID_BRUTETICINPUT;
		static const long ID_STRAFECMDINPUT;
		static const long ID_RUNCMDINPUT;
		static const long ID_TURNCMDINPUT;
		static const long ID_TURNANGLEBUTTON;
		static const long ID_FIRERADIOBOX;
		static const long ID_USERADIOBOX;
		static const long ID_CANCEL;
		static const long ID_START;
		static const long ID_WORKINGTEXT;
		static const long ID_STATICBOX1;
		static const long ID_STATICBOX2;
		static const long ID_STATICTEXT1;
		static const long ID_STATICTEXT2;
		static const long ID_STATICTEXT3;
		static const long ID_STATICTEXT4;
		static const long ID_PANEL;
		//*)

        virtual wxThread::ExitCode Entry();

	private:

        struct ListItem {
            wxString ticStr {"0"};
            wxString runStr {"0"};
            wxString strafeStr {"0"};
            wxString turnStr {"0"};
            int fire {0};
            int use {0};
            int turnOrAngle {0};
        };

        std::vector<ListItem> items;
        std::vector<BruteTic> bruteTics;
        BruteCheck bruteCheck;
        bool abortBrute {false};
        bool bruteSuccess {false};
        wxString turnAngleTexts[2] {"Turn cmds", "Angles"};

        // "," separates numbers, ":" separates start and end of range
        std::vector<signed char> ParseCmds(wxString str, bool parseAsUnsigned = false);
        std::vector<BruteTic> CreateBruteTics();
        BruteCheck CreateBruteCheck();

        void ShowData(int n);
        void EnableStuff();
        void DisableStuff();

		//(*Handlers(BruteDialog)
		void OnClose(wxCloseEvent& event);
		void OnCancelClick(wxCommandEvent& event);
		void OnTurnAngleButtonClick(wxCommandEvent& event);
		void OnAddButtonClick(wxCommandEvent& event);
		void OnRemoveButtonClick(wxCommandEvent& event);
		void OnBruteTicsBoxSelect(wxCommandEvent& event);
		void OnBruteTicInputText(wxCommandEvent& event);
		void OnRunCmdInputText(wxCommandEvent& event);
		void OnStrafeCmdInputText(wxCommandEvent& event);
		void OnTurnCmdInputText(wxCommandEvent& event);
		void OnFireRadioBoxSelect(wxCommandEvent& event);
		void OnUseRadioBoxSelect(wxCommandEvent& event);
		void OnStartClick(wxCommandEvent& event);
		//*)

		DECLARE_EVENT_TABLE()
};

#endif //__BRUTEDIALOG_HPP
