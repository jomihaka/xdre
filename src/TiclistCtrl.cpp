#include "TiclistCtrl.hpp"
#include "xdre.hpp"


TiclistCtrl::TiclistCtrl(wxWindow* parent,
                         wxWindowID const id,
                         wxPoint const& pos,
                         wxSize const& size,
                         wxString const& name)
                        : wxListCtrl(parent, id, pos, size,
                                     wxLC_VIRTUAL|wxLC_REPORT|wxLC_NO_HEADER|wxLC_SINGLE_SEL,
                                     wxDefaultValidator, name) {
    wxListItem col;
    col.SetId(0);
    col.SetWidth(size.GetWidth() - 32);

    InsertColumn(0, col);
    SetItemCount(20);
}

wxString TiclistCtrl::OnGetItemText(long item, long column) const {
    return xdre::getTicString(item);
}
