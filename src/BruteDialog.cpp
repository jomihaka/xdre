#include "BruteDialog.hpp"

//(*InternalHeaders(BruteDialog)
#include <wx/intl.h>
#include <wx/string.h>
//*)
#include <wx/valnum.h>
#include <wx/valtext.h>
#include <wx/msgdlg.h>
#include <wx/tokenzr.h>

class BruteException : public std::exception {
public:
    BruteException(const char* str) : str{str} {
    }

    virtual const char* what() const noexcept {
        return str;
    }

    const char* str;
};

//(*IdInit(BruteDialog)
const long BruteDialog::ID_CHECKTICINPUT = wxNewId();
const long BruteDialog::ID_RNGINPUT = wxNewId();
const long BruteDialog::ID_DAMAGEINPUT = wxNewId();
const long BruteDialog::ID_XPOSINPUT = wxNewId();
const long BruteDialog::ID_YPOSINPUT = wxNewId();
const long BruteDialog::ID_XMOMINPUT = wxNewId();
const long BruteDialog::ID_YMOMINPUT = wxNewId();
const long BruteDialog::ID_SPEEDINPUT = wxNewId();
const long BruteDialog::ID_RNGCHECKBOX = wxNewId();
const long BruteDialog::ID_RNGCHOICE = wxNewId();
const long BruteDialog::ID_DAMAGECHECKBOX = wxNewId();
const long BruteDialog::ID_DAMAGECHOICE = wxNewId();
const long BruteDialog::ID_XPOSCHECKBOX = wxNewId();
const long BruteDialog::ID_XPOSCHOICE = wxNewId();
const long BruteDialog::ID_YPOSCHECKBOX = wxNewId();
const long BruteDialog::ID_YPOSCHOICE = wxNewId();
const long BruteDialog::ID_XMOMCHECKBOX = wxNewId();
const long BruteDialog::ID_XMOMCHOICE = wxNewId();
const long BruteDialog::ID_YMOMCHECKBOX = wxNewId();
const long BruteDialog::ID_YMOMCHOICE = wxNewId();
const long BruteDialog::ID_SPEEDCHECKBOX = wxNewId();
const long BruteDialog::ID_SPEEDCHOICE = wxNewId();
const long BruteDialog::ID_USECHECKBOX = wxNewId();
const long BruteDialog::ID_BRUTETICSBOX = wxNewId();
const long BruteDialog::ID_ADDBUTTON = wxNewId();
const long BruteDialog::ID_REMOVEBUTTON = wxNewId();
const long BruteDialog::ID_BRUTETICINPUT = wxNewId();
const long BruteDialog::ID_STRAFECMDINPUT = wxNewId();
const long BruteDialog::ID_RUNCMDINPUT = wxNewId();
const long BruteDialog::ID_TURNCMDINPUT = wxNewId();
const long BruteDialog::ID_TURNANGLEBUTTON = wxNewId();
const long BruteDialog::ID_FIRERADIOBOX = wxNewId();
const long BruteDialog::ID_USERADIOBOX = wxNewId();
const long BruteDialog::ID_CANCEL = wxNewId();
const long BruteDialog::ID_START = wxNewId();
const long BruteDialog::ID_WORKINGTEXT = wxNewId();
const long BruteDialog::ID_STATICBOX1 = wxNewId();
const long BruteDialog::ID_STATICBOX2 = wxNewId();
const long BruteDialog::ID_STATICTEXT1 = wxNewId();
const long BruteDialog::ID_STATICTEXT2 = wxNewId();
const long BruteDialog::ID_STATICTEXT3 = wxNewId();
const long BruteDialog::ID_STATICTEXT4 = wxNewId();
const long BruteDialog::ID_PANEL = wxNewId();
//*)

wxDEFINE_EVENT(EVT_BRUTE_DONE, wxThreadEvent);
BEGIN_EVENT_TABLE(BruteDialog,wxDialog)
	//(*EventTable(BruteDialog)
	//*)
END_EVENT_TABLE()

BruteDialog::BruteDialog(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{

	wxDialog::Create(parent, wxID_ANY, _("Bruteforce"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("wxID_ANY"));
	SetClientSize(wxSize(400,400));
	SetMinSize(wxSize(400,400));
	SetMaxSize(wxSize(400,-1));
    //WXSMITH WORKAROUND, MAKE SURE EVERYTHING IS FINE
    /*
	//(*Initialize(BruteDialog)
	Create(parent, wxID_ANY, _("Bruteforce"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("wxID_ANY"));
	SetClientSize(wxSize(400,400));
	SetMinSize(wxSize(400,400));
	SetMaxSize(wxSize(400,-1));
	*/
	panel = new wxPanel(this, ID_PANEL, wxDefaultPosition, wxSize(400,400), wxTAB_TRAVERSAL, _T("ID_PANEL"));
	checkTicInput = new wxTextCtrl(panel, ID_CHECKTICINPUT, wxEmptyString, wxPoint(288,56), wxSize(96,21), wxTE_RIGHT, wxIntegerValidator<unsigned int>(), _T("ID_CHECKTICINPUT"));
	rngInput = new wxTextCtrl(panel, ID_RNGINPUT, wxEmptyString, wxPoint(328,96), wxSize(56,21), wxTE_RIGHT, wxTextValidator(), _T("ID_RNGINPUT"));
	damageInput = new wxTextCtrl(panel, ID_DAMAGEINPUT, wxEmptyString, wxPoint(328,128), wxSize(56,21), wxTE_RIGHT, wxIntegerValidator<unsigned int>(), _T("ID_DAMAGEINPUT"));
	xPosInput = new wxTextCtrl(panel, ID_XPOSINPUT, wxEmptyString, wxPoint(328,160), wxSize(56,21), wxTE_RIGHT, wxFloatingPointValidator<double>(), _T("ID_XPOSINPUT"));
	yPosInput = new wxTextCtrl(panel, ID_YPOSINPUT, wxEmptyString, wxPoint(328,192), wxSize(56,21), wxTE_RIGHT, wxFloatingPointValidator<double>(), _T("ID_YPOSINPUT"));
	xMomInput = new wxTextCtrl(panel, ID_XMOMINPUT, wxEmptyString, wxPoint(328,224), wxSize(56,21), wxTE_RIGHT, wxFloatingPointValidator<double>(), _T("ID_XMOMINPUT"));
	yMomInput = new wxTextCtrl(panel, ID_YMOMINPUT, wxEmptyString, wxPoint(328,256), wxSize(56,21), wxTE_RIGHT, wxFloatingPointValidator<double>(), _T("ID_YMOMINPUT"));
	speedInput = new wxTextCtrl(panel, ID_SPEEDINPUT, wxEmptyString, wxPoint(328,288), wxSize(56,21), wxTE_RIGHT, wxFloatingPointValidator<double>(), _T("ID_SPEEDINPUT"));
	rngCheckBox = new wxCheckBox(panel, ID_RNGCHECKBOX, _("Rng index"), wxPoint(201,102), wxDefaultSize, wxALIGN_RIGHT, wxDefaultValidator, _T("ID_RNGCHECKBOX"));
	rngCheckBox->SetValue(false);
	rngChoice = new wxChoice(panel, ID_RNGCHOICE, wxPoint(280,96), wxSize(40,21), 0, 0, 0, wxDefaultValidator, _T("ID_RNGCHOICE"));
	rngChoice->SetSelection( rngChoice->Append(_("=")) );
	rngChoice->Append(_("!="));
	damageCheckBox = new wxCheckBox(panel, ID_DAMAGECHECKBOX, _("Dmg"), wxPoint(227,134), wxDefaultSize, wxALIGN_RIGHT, wxDefaultValidator, _T("ID_DAMAGECHECKBOX"));
	damageCheckBox->SetValue(false);
	damageChoice = new wxChoice(panel, ID_DAMAGECHOICE, wxPoint(280,128), wxSize(40,21), 0, 0, 0, wxDefaultValidator, _T("ID_DAMAGECHOICE"));
	damageChoice->SetSelection( damageChoice->Append(_("=")) );
	damageChoice->Append(_(">="));
	damageChoice->Append(_(">"));
	damageChoice->Append(_("<="));
	damageChoice->Append(_("<"));
	xPosCheckBox = new wxCheckBox(panel, ID_XPOSCHECKBOX, _("X pos"), wxPoint(224,166), wxDefaultSize, wxALIGN_RIGHT, wxDefaultValidator, _T("ID_XPOSCHECKBOX"));
	xPosCheckBox->SetValue(false);
	xPosChoice = new wxChoice(panel, ID_XPOSCHOICE, wxPoint(280,160), wxSize(40,21), 0, 0, 0, wxDefaultValidator, _T("ID_XPOSCHOICE"));
	xPosChoice->SetSelection( xPosChoice->Append(_("=")) );
	xPosChoice->Append(_(">="));
	xPosChoice->Append(_(">"));
	xPosChoice->Append(_("<="));
	xPosChoice->Append(_("<"));
	yPosCheckBox = new wxCheckBox(panel, ID_YPOSCHECKBOX, _("Y pos"), wxPoint(224,198), wxDefaultSize, wxALIGN_RIGHT, wxDefaultValidator, _T("ID_YPOSCHECKBOX"));
	yPosCheckBox->SetValue(false);
	yPosChoice = new wxChoice(panel, ID_YPOSCHOICE, wxPoint(280,192), wxSize(40,21), 0, 0, 0, wxDefaultValidator, _T("ID_YPOSCHOICE"));
	yPosChoice->SetSelection( yPosChoice->Append(_("=")) );
	yPosChoice->Append(_(">="));
	yPosChoice->Append(_(">"));
	yPosChoice->Append(_("<="));
	yPosChoice->Append(_("<"));
	xMomCheckBox = new wxCheckBox(panel, ID_XMOMCHECKBOX, _("X mom"), wxPoint(214,230), wxDefaultSize, wxALIGN_RIGHT, wxDefaultValidator, _T("ID_XMOMCHECKBOX"));
	xMomCheckBox->SetValue(false);
	xMomChoice = new wxChoice(panel, ID_XMOMCHOICE, wxPoint(280,224), wxSize(40,21), 0, 0, 0, wxDefaultValidator, _T("ID_XMOMCHOICE"));
	xMomChoice->SetSelection( xMomChoice->Append(_("=")) );
	xMomChoice->Append(_(">="));
	xMomChoice->Append(_(">"));
	xMomChoice->Append(_("<="));
	xMomChoice->Append(_("<"));
	yMomCheckBox = new wxCheckBox(panel, ID_YMOMCHECKBOX, _("Y mom"), wxPoint(214,262), wxDefaultSize, wxALIGN_RIGHT, wxDefaultValidator, _T("ID_YMOMCHECKBOX"));
	yMomCheckBox->SetValue(false);
	yMomChoice = new wxChoice(panel, ID_YMOMCHOICE, wxPoint(280,256), wxSize(40,21), 0, 0, 0, wxDefaultValidator, _T("ID_YMOMCHOICE"));
	yMomChoice->SetSelection( yMomChoice->Append(_("=")) );
	yMomChoice->Append(_(">="));
	yMomChoice->Append(_(">"));
	yMomChoice->Append(_("<="));
	yMomChoice->Append(_("<"));
	speedCheckBox = new wxCheckBox(panel, ID_SPEEDCHECKBOX, _("Speed"), wxPoint(221,294), wxDefaultSize, wxALIGN_RIGHT, wxDefaultValidator, _T("ID_SPEEDCHECKBOX"));
	speedCheckBox->SetValue(false);
	speedChoice = new wxChoice(panel, ID_SPEEDCHOICE, wxPoint(280,288), wxSize(40,21), 0, 0, 0, wxDefaultValidator, _T("ID_SPEEDCHOICE"));
	speedChoice->SetSelection( speedChoice->Append(_("=")) );
	speedChoice->Append(_(">="));
	speedChoice->Append(_(">"));
	speedChoice->Append(_("<="));
	speedChoice->Append(_("<"));
	useCheckBox = new wxCheckBox(panel, ID_USECHECKBOX, _("Use"), wxPoint(234,326), wxDefaultSize, wxALIGN_RIGHT, wxDefaultValidator, _T("ID_USECHECKBOX"));
	useCheckBox->SetValue(false);
	bruteTicsBox = new wxListBox(panel, ID_BRUTETICSBOX, wxPoint(16,40), wxSize(168,80), 0, 0, 0, wxDefaultValidator, _T("ID_BRUTETICSBOX"));
	addButton = new wxButton(panel, ID_ADDBUTTON, _("Add"), wxPoint(16,128), wxSize(74,-1), 0, wxDefaultValidator, _T("ID_ADDBUTTON"));
	removeButton = new wxButton(panel, ID_REMOVEBUTTON, _("Remove"), wxPoint(110,128), wxSize(74,-1), 0, wxDefaultValidator, _T("ID_REMOVEBUTTON"));
	removeButton->Disable();
	bruteTicInput = new wxTextCtrl(panel, ID_BRUTETICINPUT, wxEmptyString, wxPoint(88,160), wxSize(96,21), wxTE_RIGHT, wxIntegerValidator<unsigned int>(), _T("ID_BRUTETICINPUT"));
	bruteTicInput->Disable();
	strafeCmdInput = new wxTextCtrl(panel, ID_STRAFECMDINPUT, wxEmptyString, wxPoint(88,184), wxSize(96,21), wxTE_RIGHT, wxTextValidator(), _T("ID_STRAFECMDINPUT"));
	strafeCmdInput->Disable();
	runCmdInput = new wxTextCtrl(panel, ID_RUNCMDINPUT, wxEmptyString, wxPoint(88,208), wxSize(96,21), wxTE_RIGHT, wxTextValidator(), _T("ID_RUNCMDINPUT"));
	runCmdInput->Disable();
	turnCmdInput = new wxTextCtrl(panel, ID_TURNCMDINPUT, wxEmptyString, wxPoint(88,232), wxSize(96,21), wxTE_RIGHT, wxTextValidator(), _T("ID_TURNCMDINPUT"));
	turnCmdInput->Disable();
	turnAngleButton = new wxButton(panel, ID_TURNANGLEBUTTON, _("Turn cmds"), wxPoint(16,232), wxSize(67,23), 0, wxDefaultValidator, _T("ID_TURNANGLEBUTTON"));
	turnAngleButton->Disable();
	wxString __wxRadioBoxChoices_1[3] =
	{
		_("No"),
		_("Both"),
		_("Yes")
	};
	fireRadioBox = new wxRadioBox(panel, ID_FIRERADIOBOX, _("Fire"), wxPoint(72,256), wxSize(56,88), 3, __wxRadioBoxChoices_1, 3, wxRA_VERTICAL, wxDefaultValidator, _T("ID_FIRERADIOBOX"));
	fireRadioBox->SetSelection(0);
	fireRadioBox->Disable();
	wxString __wxRadioBoxChoices_2[3] =
	{
		_("No"),
		_("Both"),
		_("Yes")
	};
	useRadioBox = new wxRadioBox(panel, ID_USERADIOBOX, _("Use"), wxPoint(128,256), wxSize(56,88), 3, __wxRadioBoxChoices_2, 3, wxRA_VERTICAL, wxDefaultValidator, _T("ID_USERADIOBOX"));
	useRadioBox->SetSelection(0);
	useRadioBox->Disable();
	cancel = new wxButton(panel, ID_CANCEL, _("Cancel"), wxPoint(248,360), wxDefaultSize, 0, wxDefaultValidator, _T("ID_CANCEL"));
	start = new wxButton(panel, ID_START, _("Start"), wxPoint(80,360), wxDefaultSize, 0, wxDefaultValidator, _T("ID_START"));
	workingText = new wxStaticText(panel, ID_WORKINGTEXT, _("Working..."), wxPoint(176,364), wxDefaultSize, 0, _T("ID_WORKINGTEXT"));
	workingText->Hide();
	StaticBox1 = new wxStaticBox(panel, ID_STATICBOX1, _("Checks"), wxPoint(200,16), wxSize(192,336), 0, _T("ID_STATICBOX1"));
	StaticBox2 = new wxStaticBox(panel, ID_STATICBOX2, _("Tics to bruteforce"), wxPoint(8,16), wxSize(192,336), 0, _T("ID_STATICBOX2"));
	StaticText1 = new wxStaticText(panel, ID_STATICTEXT1, _("On tic"), wxPoint(248,60), wxDefaultSize, 0, _T("ID_STATICTEXT1"));
	StaticText2 = new wxStaticText(panel, ID_STATICTEXT2, _("Tic"), wxPoint(62,164), wxDefaultSize, 0, _T("ID_STATICTEXT2"));
	StaticText3 = new wxStaticText(panel, ID_STATICTEXT3, _("Run cmds"), wxPoint(26,212), wxDefaultSize, 0, _T("ID_STATICTEXT3"));
	StaticText4 = new wxStaticText(panel, ID_STATICTEXT4, _("Strafe cmds"), wxPoint(16,188), wxDefaultSize, 0, _T("ID_STATICTEXT4"));

	Connect(ID_BRUTETICSBOX,wxEVT_COMMAND_LISTBOX_SELECTED,(wxObjectEventFunction)&BruteDialog::OnBruteTicsBoxSelect);
	Connect(ID_BRUTETICINPUT,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&BruteDialog::OnBruteTicInputText);
	Connect(ID_STRAFECMDINPUT,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&BruteDialog::OnStrafeCmdInputText);
	Connect(ID_RUNCMDINPUT,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&BruteDialog::OnRunCmdInputText);
	Connect(ID_TURNCMDINPUT,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&BruteDialog::OnTurnCmdInputText);
	Connect(ID_FIRERADIOBOX,wxEVT_COMMAND_RADIOBOX_SELECTED,(wxObjectEventFunction)&BruteDialog::OnFireRadioBoxSelect);
	Connect(ID_USERADIOBOX,wxEVT_COMMAND_RADIOBOX_SELECTED,(wxObjectEventFunction)&BruteDialog::OnUseRadioBoxSelect);
	//*)
	Connect(wxID_ANY,wxEVT_CLOSE_WINDOW,(wxObjectEventFunction)&BruteDialog::OnClose);
	Connect(ID_CANCEL,wxEVT_BUTTON,(wxObjectEventFunction)&BruteDialog::OnCancelClick);
	Connect(ID_START,wxEVT_BUTTON,(wxObjectEventFunction)&BruteDialog::OnStartClick);
	Connect(ID_ADDBUTTON,wxEVT_BUTTON,(wxObjectEventFunction)&BruteDialog::OnAddButtonClick);
	Connect(ID_TURNANGLEBUTTON,wxEVT_BUTTON,(wxObjectEventFunction)&BruteDialog::OnTurnAngleButtonClick);
	Connect(ID_REMOVEBUTTON,wxEVT_BUTTON,(wxObjectEventFunction)&BruteDialog::OnRemoveButtonClick);


    (*checkTicInput) << static_cast<long>(xdre::getCurrentTic());
    rngInput->ChangeValue("0");
    damageInput->ChangeValue("0");
    xPosInput->ChangeValue("0");
    yPosInput->ChangeValue("0");
    xMomInput->ChangeValue("0");
    yMomInput->ChangeValue("0");
    speedInput->ChangeValue("0");
}

BruteDialog::~BruteDialog()
{
	//(*Destroy(BruteDialog)
	//*)
}

std::vector<signed char> BruteDialog::ParseCmds(wxString str, bool parseAsUnsigned) {
    long limitMax = 127;
    long limitMin = -128;
    if (parseAsUnsigned) {
        limitMax = 255;
        limitMin = 0;
    }

    std::vector<signed char> ret;

    auto cmds = wxStringTokenize(str, ",", wxTOKEN_STRTOK);

    for (auto& cmd : cmds) {
        auto range = wxStringTokenize(cmd, ":", wxTOKEN_STRTOK);

        if (range.GetCount() == 1) {
            long num;
            if (cmd.ToLong(&num)) {
                if (num > limitMax ||
                    num < limitMin) {
                    throw BruteException("Too big input value given");
                }
                ret.push_back(num);
            } else {
                throw BruteException("Invalid value");
            }
        } else if (range.GetCount() == 2) {
            long start;
            long end;
            if (!range[0].ToLong(&start) || !range[1].ToLong(&end)) {
                throw BruteException("Invalid range given");
            }

            if (start > limitMax ||
                start < limitMin ||
                end > limitMax ||
                end < limitMin) {
                throw BruteException("Too big input value given");
            }

            if (start <= end) {
                for (; start <= end; ++start) {
                    ret.push_back(start);
                }
            } else {
                for (; start >= end; --start) {
                    ret.push_back(start);
                }
            }
        } else {
            throw BruteException("Invalid range given");
        }
    }

    return ret;
}

std::vector<BruteTic> BruteDialog::CreateBruteTics() {
    std::vector<BruteTic> ret;
    for (auto& item : items) {
        BruteTic tic;
        long num;

        if (!item.ticStr.ToLong(&num)) {
            throw BruteException("Tic value not a number");
        } else if (num < 0) {
            throw BruteException("Tic value < 0");
        }

        tic.tic = num;
        tic.fire = item.fire - 1;
        tic.use = item.use - 1;


        if (tic.fire < -1 || tic.fire > 1 ||
            tic.use < -1 || tic.use > 1) {
            throw BruteException("Invalid fire/use choices");
        }

        if (item.turnOrAngle == 0) {
            tic.turnsAreAngles = false;
        } else {
            tic.turnsAreAngles = true;
        }

        tic.runCmds = ParseCmds(item.runStr);
        tic.strafeCmds = ParseCmds(item.strafeStr);
        tic.turnCmds = ParseCmds(item.turnStr);

        if (tic.runCmds.empty() || tic.strafeCmds.empty() || tic.turnCmds.empty()) {
            throw BruteException("Empty field");
        }

        ret.push_back(tic);
    }

    return ret;
}

BruteCheck BruteDialog::CreateBruteCheck() {
    BruteCheck check;

    long tic;
    if (!checkTicInput->GetValue().ToLong(&tic)) {
        throw BruteException("Checktic not a number");
    } else if (tic < 0) {
        throw BruteException("Checktic < 0");
    }

    check.tic = tic;

//TODO: refactor this shit
    if (rngCheckBox->GetValue()) {
        auto indexes = ParseCmds(rngInput->GetValue(), true);

        switch (rngChoice->GetSelection()) {
        case 0:
            check.rngFunc = [indexes](int val) {
                for (auto index : indexes) {
                    if (val == index) {
                        return true;
                    }
                }
                return false;
            };
            break;

        case 1:
            check.rngFunc = [indexes](int val) {
                for (auto index : indexes) {
                    if (val == index) {
                        return false;
                    }
                }
                return true;
            };
            break;
        }
    } else {
        check.rngFunc = [](int val){return true;};
    }


    if (damageCheckBox->GetValue()) {
        long num;
        if (!damageInput->GetValue().ToLong(&num)) {
            throw BruteException("Invalid damage target");
        }

        switch (damageChoice->GetSelection()) {
        case 0:
            check.damageFunc = [num](int val){return val == num;};
            break;

        case 1:
            check.damageFunc = [num](int val){return val >= num;};
            break;

        case 2:
            check.damageFunc = [num](int val){return val > num;};
            break;

        case 3:
            check.damageFunc = [num](int val){return val <= num;};
            break;

        case 4:
            check.damageFunc = [num](int val){return val < num;};
            break;
        }
    } else {
        check.damageFunc = [](int val){return true;};
    }

    if (xPosCheckBox->GetValue()) {
        double dbl;
        if (!xPosInput->GetValue().ToDouble(&dbl)) {
            throw BruteException("Invalid xpos target");
        }

        switch (xPosChoice->GetSelection()) {
        case 0:
            check.xPosFunc = [dbl](double val){return val == dbl;};
            break;

        case 1:
            check.xPosFunc = [dbl](double val){return val >= dbl;};
            break;

        case 2:
            check.xPosFunc = [dbl](double val){return val > dbl;};
            break;

        case 3:
            check.xPosFunc = [dbl](double val){return val <= dbl;};
            break;

        case 4:
            check.xPosFunc = [dbl](double val){return val < dbl;};
            break;
        }
    } else {
        check.xPosFunc = [](double val){return true;};
    }

    if (yPosCheckBox->GetValue()) {
        double dbl;
        if (!yPosInput->GetValue().ToDouble(&dbl)) {
            throw BruteException("Invalid ypos target");
        }

        switch (yPosChoice->GetSelection()) {
        case 0:
            check.yPosFunc = [dbl](double val){return val == dbl;};
            break;

        case 1:
            check.yPosFunc = [dbl](double val){return val >= dbl;};
            break;

        case 2:
            check.yPosFunc = [dbl](double val){return val > dbl;};
            break;

        case 3:
            check.yPosFunc = [dbl](double val){return val <= dbl;};
            break;

        case 4:
            check.yPosFunc = [dbl](double val){return val < dbl;};
            break;
        }
    } else {
        check.yPosFunc = [](double val){return true;};
    }

    if (xMomCheckBox->GetValue()) {
        double dbl;
        if (!xMomInput->GetValue().ToDouble(&dbl)) {
            throw BruteException("Invalid xmom target");
        }

        switch (xMomChoice->GetSelection()) {
        case 0:
            check.xMomFunc = [dbl](double val){return val == dbl;};
            break;

        case 1:
            check.xMomFunc = [dbl](double val){return val >= dbl;};
            break;

        case 2:
            check.xMomFunc = [dbl](double val){return val > dbl;};
            break;

        case 3:
            check.xMomFunc = [dbl](double val){return val <= dbl;};
            break;

        case 4:
            check.xMomFunc = [dbl](double val){return val < dbl;};
            break;
        }
    } else {
        check.xMomFunc = [](double val){return true;};
    }

    if (yMomCheckBox->GetValue()) {
        double dbl;
        if (!yMomInput->GetValue().ToDouble(&dbl)) {
            throw BruteException("Invalid ymom target");
        }

        switch (yMomChoice->GetSelection()) {
        case 0:
            check.yMomFunc = [dbl](double val){return val == dbl;};
            break;

        case 1:
            check.yMomFunc = [dbl](double val){return val >= dbl;};
            break;

        case 2:
            check.yMomFunc = [dbl](double val){return val > dbl;};
            break;

        case 3:
            check.yMomFunc = [dbl](double val){return val <= dbl;};
            break;

        case 4:
            check.yMomFunc = [dbl](double val){return val < dbl;};
            break;
        }
    } else {
        check.yMomFunc = [](double val){return true;};
    }

    if (speedCheckBox->GetValue()) {
        double dbl;
        if (!speedInput->GetValue().ToDouble(&dbl)) {
            throw BruteException("Invalid speed target");
        }

        switch (speedChoice->GetSelection()) {
        case 0:
            check.speedFunc = [dbl](double val){return val == dbl;};
            break;

        case 1:
            check.speedFunc = [dbl](double val){return val >= dbl;};
            break;

        case 2:
            check.speedFunc = [dbl](double val){return val > dbl;};
            break;

        case 3:
            check.speedFunc = [dbl](double val){return val <= dbl;};
            break;

        case 4:
            check.speedFunc = [dbl](double val){return val < dbl;};
            break;
        }
    } else {
        check.speedFunc = [](double val){return true;};
    }

    check.use = useCheckBox->GetValue();

    return check;
}

void BruteDialog::ShowData(int n)
{
    ListItem const& data = items.at(n);
    bruteTicInput->ChangeValue(data.ticStr);
    runCmdInput->ChangeValue(data.runStr);
    strafeCmdInput->ChangeValue(data.strafeStr);
    turnCmdInput->ChangeValue(data.turnStr);
    fireRadioBox->SetSelection(data.fire);
    useRadioBox->SetSelection(data.use);
    turnAngleButton->SetLabel(turnAngleTexts[data.turnOrAngle]);
}

void BruteDialog::EnableStuff()
{
    bruteTicInput->Enable();
    runCmdInput->Enable();
    strafeCmdInput->Enable();
    turnCmdInput->Enable();
    fireRadioBox->Enable();
    useRadioBox->Enable();
    turnAngleButton->Enable();
    removeButton->Enable();
}

void BruteDialog::DisableStuff()
{
    bruteTicInput->Disable();
    runCmdInput->Disable();
    strafeCmdInput->Disable();
    turnCmdInput->Disable();
    fireRadioBox->Disable();
    useRadioBox->Disable();
    turnAngleButton->Disable();
    removeButton->Disable();
}

void BruteDialog::OnClose(wxCloseEvent& event)
{
    if (GetThread() && GetThread()->IsRunning()) {
        return;
    }

    Destroy();
}

void BruteDialog::OnCancelClick(wxCommandEvent& event)
{
    if (GetThread() && GetThread()->IsRunning()) {
        abortBrute = true;
        GetThread()->Wait();
        return;
    }

    Close();
}

void BruteDialog::OnTurnAngleButtonClick(wxCommandEvent& event)
{
    auto item = bruteTicsBox->GetSelection();
    if (items[item].turnOrAngle) {
        items[item].turnOrAngle = 0;
    } else {
        items[item].turnOrAngle = 1;
    }

    turnAngleButton->SetLabel(turnAngleTexts[items[item].turnOrAngle]);
}

void BruteDialog::OnAddButtonClick(wxCommandEvent& event)
{
    items.push_back({});
    int last = items.size() - 1;
    bruteTicsBox->Append(items.at(last).ticStr);
    bruteTicsBox->SetSelection(last);

    items.at(last).ticStr = wxString::Format(wxT("%i"), xdre::getCurrentTic());
    bruteTicsBox->SetString(last, items.at(last).ticStr);
    EnableStuff();

    ShowData(last);
}

void BruteDialog::OnRemoveButtonClick(wxCommandEvent& event)
{
    int item = bruteTicsBox->GetSelection();
    if (item == wxNOT_FOUND) {
        return;
    }

    bruteTicsBox->Delete(item);
    items.erase(std::begin(items) + item);
    int sel = item < items.size() ? item : items.size() - 1;
    bruteTicsBox->SetSelection(sel);

    if (sel >= 0) {
        ShowData(sel);
    }

    if (bruteTicsBox->GetCount() < 1) {
        DisableStuff();
    }
}

void BruteDialog::OnBruteTicsBoxSelect(wxCommandEvent& event)
{
    ShowData(bruteTicsBox->GetSelection());
}

void BruteDialog::OnBruteTicInputText(wxCommandEvent& event)
{
    int item = bruteTicsBox->GetSelection();
    if (item == wxNOT_FOUND) {
        return;
    }
    items.at(item).ticStr = bruteTicInput->GetValue();
    if (items.at(item).ticStr.IsSameAs("")) {
        items.at(item).ticStr = "_";
    }
    bruteTicsBox->SetString(item, items.at(item).ticStr);
}

void BruteDialog::OnRunCmdInputText(wxCommandEvent& event)
{
    int item = bruteTicsBox->GetSelection();
    if (item == wxNOT_FOUND) {
        return;
    }
    items.at(item).runStr = runCmdInput->GetValue();
}

void BruteDialog::OnStrafeCmdInputText(wxCommandEvent& event)
{
    int item = bruteTicsBox->GetSelection();
    if (item == wxNOT_FOUND) {
        return;
    }
    items.at(item).strafeStr = strafeCmdInput->GetValue();
}

void BruteDialog::OnTurnCmdInputText(wxCommandEvent& event)
{
    int item = bruteTicsBox->GetSelection();
    if (item == wxNOT_FOUND) {
        return;
    }
    items.at(item).turnStr = turnCmdInput->GetValue();
}

void BruteDialog::OnFireRadioBoxSelect(wxCommandEvent& event)
{
    int item = bruteTicsBox->GetSelection();
    if (item == wxNOT_FOUND) {
        return;
    }
    items.at(item).fire = fireRadioBox->GetSelection();
}

void BruteDialog::OnUseRadioBoxSelect(wxCommandEvent& event)
{
    int item = bruteTicsBox->GetSelection();
    if (item == wxNOT_FOUND) {
        return;
    }
    items.at(item).use = useRadioBox->GetSelection();
}

wxThread::ExitCode BruteDialog::Entry()
{
    bruteSuccess = xdre::bruteForce(bruteTics, bruteCheck, abortBrute);

    wxQueueEvent(this, new wxThreadEvent(EVT_BRUTE_DONE));
    return static_cast<wxThread::ExitCode>(0);
}

void BruteDialog::OnBruteDone(wxThreadEvent& event)
{
    Disconnect(wxID_ANY, EVT_BRUTE_DONE, (wxObjectEventFunction)&BruteDialog::OnBruteDone);

    start->Enable();
    workingText->Hide();

    if (bruteSuccess) {
        wxMessageBox("Found it!",
                     "Success",
                     wxOK | wxCENTRE,
                     this);
        if (GetThread() && GetThread()->IsRunning()) {
            GetThread()->Wait();
        }
//        Close();
    } else if (!bruteSuccess && !abortBrute) {
        wxMessageBox("Whole range examined. No cigar.",
                     "No success",
                     wxOK | wxCENTRE,
                     this);
    }
}

void BruteDialog::OnStartClick(wxCommandEvent& event)
{
    if (GetThread() && GetThread()->IsRunning()) {
        return;
    }

    try {
        bruteTics = CreateBruteTics();
        if (bruteTics.empty()) {
            return;
        }
        bruteCheck = CreateBruteCheck();

        if (CreateThread(wxTHREAD_JOINABLE) == wxTHREAD_NO_ERROR) {
            Connect(wxID_ANY, EVT_BRUTE_DONE, (wxObjectEventFunction)&BruteDialog::OnBruteDone);
            start->Disable();
            abortBrute = false;
            bruteSuccess = false;
            if (GetThread()->Run() == wxTHREAD_NO_ERROR) {
                workingText->Show();
            } else {
                wxMessageBox("Couldn't start bruteforce thread",
                             "Bruteforce error",
                             wxOK | wxCENTRE | wxICON_ERROR,
                             this);
                Disconnect(wxID_ANY, EVT_BRUTE_DONE, (wxObjectEventFunction)&BruteDialog::OnBruteDone);
                start->Enable();
                workingText->Hide();
            }
        } else {
            wxMessageBox("Couldn't create bruteforce thread",
                         "Bruteforce error",
                         wxOK | wxCENTRE | wxICON_ERROR,
                         this);
        }
    } catch (BruteException& e) {
        wxMessageBox(e.what(),
                     "Bruteforce error",
                     wxOK | wxCENTRE | wxICON_ERROR,
                     this);
    }
}
