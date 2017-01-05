/*
 * Copyright (c) 2003-2017 Rony Shapiro <ronys@pwsafe.org>.
 * All rights reserved. Use of the code is allowed under the
 * Artistic License 2.0 terms, as specified in the LICENSE file
 * distributed with this code, or available from
 * http://www.opensource.org/licenses/artistic-license-2.0.php
 */

#ifndef __SAFECOMBINATIONCTRL_H__
#define __SAFECOMBINATIONCTRL_H__

#include <wx/sizer.h> // Base class: wxBoxSizer
#include <wx/event.h> // Base class: wxEvtHandler
#include "../../core/StringX.h"

//without this class, we get 'pointer to member conversion via virtual base' error
class CommandEventHandler : public wxEvtHandler {
public:
  void HandleCommandEvent(wxCommandEvent& evt);
};

class CSafeCombinationCtrl : virtual public wxBoxSizer, virtual CommandEventHandler {

public:
  CSafeCombinationCtrl(wxWindow* parent, wxWindowID textCtrlID = wxID_ANY, StringX* valPtr = 0,
                        const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize)
    : wxBoxSizer(wxHORIZONTAL), textCtrl(0)
    {Init(parent, textCtrlID, valPtr, pos, size);}
  // Following c'tor for code autogenerated by DialogBlocks
 CSafeCombinationCtrl(wxWindow* parent, wxWindowID textCtrlID, const wxString &, const wxPoint& pos, const wxSize& size, int)
   : wxBoxSizer(wxHORIZONTAL), textCtrl(0)
    {Init(parent, textCtrlID, NULL, pos, size);}
  // following common c'tor code for both above
  void Init(wxWindow* parent, wxWindowID textCtrlID, StringX* valPtr, const wxPoint& pos, const wxSize& size);
  ~CSafeCombinationCtrl();
  
  StringX GetCombination() const;
  void SetValidatorTarget(StringX* str);
  void SelectCombinationText() const;
  void AllowEmptyCombinationOnce(); // for YubiKey, one-shot for use in YubiBtn event handlers

private:
  wxTextCtrl* textCtrl;

};

#endif // __SAFECOMBINATIONCTRL_H__
