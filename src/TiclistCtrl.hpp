#ifndef __TICLIST_HPP
#define __TICLIST_HPP

#include <wx/listctrl.h>

class TiclistCtrl : public wxListCtrl {
public:
    TiclistCtrl(wxWindow* parent,
                wxWindowID const id,
                wxPoint const& pos = wxDefaultPosition,
                wxSize const& size = wxDefaultSize,
                wxString const& name = wxListCtrlNameStr);

    virtual wxString OnGetItemText(long item, long column) const override;
};

#endif // __TICLIST_HPP
