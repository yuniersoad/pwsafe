/*
 * Copyright (c) 2003-2017 Rony Shapiro <ronys@pwsafe.org>.
 * All rights reserved. Use of the code is allowed under the
 * Artistic License 2.0 terms, as specified in the LICENSE file
 * distributed with this code, or available from
 * http://www.opensource.org/licenses/artistic-license-2.0.php
 */

/** \file passwordsafeframe.h
 *
 */

// Generated by DialogBlocks, Wed 14 Jan 2009 10:24:11 PM IST

#ifndef _PASSWORDSAFEFRAME_H_
#define _PASSWORDSAFEFRAME_H_

/*!
 * Includes
 */

////@begin includes
#include "wx/frame.h"
#include "wx/statusbr.h"
////@end includes
#include "wx/treebase.h" // for wxTreeItemId
#include "core/PWScore.h"
#include "core/UIinterface.h"
#include "core/RUEList.h"
#include "core/PWSFilters.h"
#include "./wxutils.h"
#include <tuple>

/*!
 * Forward declarations
 */

////@begin forward declarations
class PWSGrid;
class PWSTreeCtrl;
class CPWStatusBar;
////@end forward declarations
class SystemTray;
class GUIInfo;
struct SelectionCriteria;
class PWSDragBar;
class PasswordSafeSearch;

/*!
 * Control identifiers
 */

////@begin control identifiers
#define ID_PASSWORDSAFEFRAME 10001
#define ID_MENU_CLEAR_MRU 10011
#define ID_EXPORTMENU 10013
#define ID_EXPORT2OLD1XFORMAT 10013
#define ID_EXPORT2V2FORMAT 10014
#define ID_EXPORT2V4FORMAT 10015
#define ID_EXPORT2PLAINTEXT 10016
#define ID_EXPORT2XML 10017
#define ID_IMPORTMENU 10018
#define ID_IMPORT_PLAINTEXT 10019
#define ID_IMPORT_XML 10020
#define ID_IMPORT_KEEPASS 10021
#define ID_MERGE 10022
#define ID_COMPARE 10023
#define ID_EDIT 10024
#define ID_RENAME 10025
#define ID_DUPLICATEENTRY 10026
#define ID_ADDGROUP 10027
#define ID_CLEARCLIPBOARD 10028
#define ID_COPYPASSWORD 10029
#define ID_COPYUSERNAME 10030
#define ID_COPYNOTESFLD 10031
#define ID_COPYURL 10032
#define ID_BROWSEURL 10033
#define ID_AUTOTYPE 10034
#define ID_GOTOBASEENTRY 10035
#define ID_LIST_VIEW 10036
#define ID_TREE_VIEW 10037
#define ID_SHOWHIDE_TOOLBAR 10038
#define ID_SHOWHIDE_DRAGBAR 10039
#define ID_EXPANDALL 10040
#define ID_COLLAPSEALL 10041
#define ID_SHOWHIDE_UNSAVED 10002
#define ID_SHOW_ALL_EXPIRY 10125
#define ID_FILTERMENU 10042
#define ID_EDITFILTER 10043
#define ID_APPLYFILTER 10044
#define ID_MANAGEFILTERS 10045
#define ID_CUSTOMIZETOOLBAR 10046
#define ID_CHANGEFONTMENU 10047
#define ID_CHANGETREEFONT 10048
#define ID_CHANGEPSWDFONT 10049
#define ID_REPORTSMENU 10050
#define ID_REPORT_COMPARE 10051
#define ID_REPORT_FIND 10052
#define ID_REPORT_IMPORTTEXT 10053
#define ID_REPORT_IMPORTXML 10054
#define ID_REPORT_MERGE 10055
#define ID_REPORT_VALIDATE 10056
#define ID_CHANGECOMBO 10057
#define ID_BACKUP 10058
#define ID_RESTORE 10059
#define ID_PWDPOLSM 10215
#define ID_YUBIKEY_MNG 10010
#define ID_LANGUAGEMENU 10011
#define ID_VISITWEBSITE 10012
#define ID_MRUMENU 10061
#define ID_STATUSBAR 10000
#define SYMBOL_PASSWORDSAFEFRAME_STYLE wxCAPTION|wxRESIZE_BORDER|wxSYSTEM_MENU|wxMINIMIZE_BOX|wxMAXIMIZE_BOX|wxCLOSE_BOX
#define SYMBOL_PASSWORDSAFEFRAME_TITLE _("PasswordSafe")
#define SYMBOL_PASSWORDSAFEFRAME_IDNAME ID_PASSWORDSAFEFRAME
#define SYMBOL_PASSWORDSAFEFRAME_SIZE wxSize(400, 300)
#define SYMBOL_PASSWORDSAFEFRAME_POSITION wxDefaultPosition
////@end control identifiers
enum {
  ID_EDITMENU_FIND_NEXT  = 10220,
  ID_EDITMENU_FIND_PREVIOUS,
  ID_PASSWORDSUBSET,
  ID_COPYEMAIL,
  ID_RUNCOMMAND,
  ID_COPYRUNCOMMAND,
  ID_BROWSEURLPLUS,
  ID_SENDEMAIL,
  ID_CREATESHORTCUT,
  ID_EDITBASEENTRY,
  ID_SYSTRAY_RESTORE,
  ID_SYSTRAY_LOCK,
  ID_SYSTRAY_UNLOCK,
  ID_SYSTRAY_CLOSE,
  ID_SYSTRAY_EXIT,
  ID_SYSTRAY_CLEAR_RUE,
  ID_TRAYRECENT_ENTRY_HELP1,
  ID_TRAYRECENT_ENTRY_HELP2,
  ID_TOOLBAR_NEW,
  ID_TOOLBAR_CLASSIC,
  ID_SYNCHRONIZE,

  // languages
  ID_LANGUAGE_BEGIN,
  ID_LANGUAGE_CHINESE,
  ID_LANGUAGE_DANISH,
  ID_LANGUAGE_DUTCH,
  ID_LANGUAGE_ENGLISH,
  ID_LANGUAGE_FRENCH,
  ID_LANGUAGE_GERMAN,
  ID_LANGUAGE_ITALIAN,
  ID_LANGUAGE_KOREAN,
  ID_LANGUAGE_POLISH,
  ID_LANGUAGE_RUSSIAN,
  ID_LANGUAGE_SPANISH,
  ID_LANGUAGE_SWEDISH,
  ID_LANGUAGE_END
};

/*!
 * PasswordSafeFrame class declaration
 */

class PasswordSafeFrame: public wxFrame, public UIInterFace
{
    DECLARE_CLASS( PasswordSafeFrame )
    DECLARE_EVENT_TABLE()

public:
    /// Constructors
    PasswordSafeFrame(PWScore &core);
    PasswordSafeFrame(wxWindow* parent, PWScore &core,
                      wxWindowID id = SYMBOL_PASSWORDSAFEFRAME_IDNAME, const wxString& caption = SYMBOL_PASSWORDSAFEFRAME_TITLE, const wxPoint& pos = SYMBOL_PASSWORDSAFEFRAME_POSITION, const wxSize& size = SYMBOL_PASSWORDSAFEFRAME_SIZE, long style = SYMBOL_PASSWORDSAFEFRAME_STYLE );

    bool Create( wxWindow* parent, wxWindowID id = SYMBOL_PASSWORDSAFEFRAME_IDNAME, const wxString& caption = SYMBOL_PASSWORDSAFEFRAME_TITLE, const wxPoint& pos = SYMBOL_PASSWORDSAFEFRAME_POSITION, const wxSize& size = SYMBOL_PASSWORDSAFEFRAME_SIZE, long style = SYMBOL_PASSWORDSAFEFRAME_STYLE );

    /// Destructor
    ~PasswordSafeFrame();

    /// Initialises member variables
    void Init();

    /// Creates the controls and sizers
    void CreateControls();
    void CreateMenubar();

    ItemList::size_type GetNumEntries() const {return m_core.GetNumEntries();}

    // UIinterface concrete methods:
    virtual void DatabaseModified(bool bChanged);

    virtual void GUISetupDisplayInfo(CItemData &ci);

    virtual void UpdateGUI(UpdateGUICommand::GUI_Action ga,
                           const pws_os::CUUID &entry_uuid,
                           CItemData::FieldType ft = CItemData::START,
                           bool bUpdateGUI = true);

    virtual void GUIRefreshEntry(const CItemData &ci);

    virtual void UpdateWizard(const stringT &s);

  ////@begin PasswordSafeFrame event handler declarations

  /// wxEVT_CLOSE_WINDOW event handler for ID_PASSWORDSAFEFRAME
  void OnCloseWindow( wxCloseEvent& event );

  /// wxEVT_COMMAND_MENU_SELECTED event handler for wxID_NEW
  void OnNewClick( wxCommandEvent& event );

  /// wxEVT_COMMAND_MENU_SELECTED event handler for wxID_OPEN
  void OnOpenClick( wxCommandEvent& event );

  /// wxEVT_COMMAND_MENU_SELECTED event handler for wxID_CLOSE
  void OnCloseClick( wxCommandEvent& event );

  /// wxEVT_COMMAND_MENU_SELECTED event handler for wxID_SAVE
  void OnSaveClick( wxCommandEvent& event );

  /// wxEVT_COMMAND_MENU_SELECTED event handler for wxID_SAVEAS
  void OnSaveAsClick( wxCommandEvent& event );

  /// wxEVT_COMMAND_MENU_SELECTED event handler for wxID_PROPERTIES
  void OnPropertiesClick( wxCommandEvent& event );

  /// wxEVT_COMMAND_MENU_SELECTED event handler for wxID_EXIT
  void OnExitClick( wxCommandEvent& event );

  /// wxEVT_COMMAND_MENU_SELECTED event handler for wxID_ADD
  void OnAddClick( wxCommandEvent& event );

  /// wxEVT_COMMAND_MENU_SELECTED event handler for ID_EDIT
  void OnEditClick( wxCommandEvent& event );

  /// wxEVT_COMMAND_MENU_SELECTED event handler for wxID_DELETE
  void OnDeleteClick( wxCommandEvent& event );

  /// wxEVT_COMMAND_MENU_SELECTED event handler for ID_CLEARCLIPBOARD
  void OnClearclipboardClick( wxCommandEvent& event );

  /// wxEVT_COMMAND_MENU_SELECTED event handler for ID_COPYPASSWORD
  void OnCopypasswordClick( wxCommandEvent& event );

  /// wxEVT_COMMAND_MENU_SELECTED event handler for ID_COPYUSERNAME
  void OnCopyusernameClick( wxCommandEvent& event );

  /// wxEVT_COMMAND_MENU_SELECTED event handler for ID_COPYNOTESFLD
  void OnCopynotesfldClick( wxCommandEvent& event );

  /// wxEVT_COMMAND_MENU_SELECTED event handler for ID_COPYURL
  void OnCopyurlClick( wxCommandEvent& event );

  /// wxEVT_COMMAND_MENU_SELECTED event handler for ID_LIST_VIEW
  void OnListViewClick( wxCommandEvent& event );

  /// wxEVT_COMMAND_MENU_SELECTED event handler for ID_TREE_VIEW
  void OnTreeViewClick( wxCommandEvent& event );

  /// wxEVT_COMMAND_MENU_SELECTED event handler for ID_SHOWHIDE_UNSAVED
  void OnShowUnsavedEntriesClick( wxCommandEvent& event );

  /// wxEVT_COMMAND_MENU_SELECTED event handler for ID_SHOW_ALL_EXPIRY
  void OnShowAllExpiryClick( wxCommandEvent& event );

  /// wxEVT_COMMAND_MENU_SELECTED event handler for ID_CHANGECOMBO
  void OnChangePasswdClick( wxCommandEvent& event );

  /// wxEVT_COMMAND_MENU_SELECTED event handler for wxID_PREFERENCES
  void OnPreferencesClick( wxCommandEvent& event );

  /// wxEVT_COMMAND_MENU_SELECTED event handler for ID_PWDPOLSM
  void OnPwdPolsMClick( wxCommandEvent& event );

  /// wxEVT_COMMAND_MENU_SELECTED event handler for ID_LANGUAGEMENU
  void OnLanguageClick( wxCommandEvent& evt);

  /// wxEVT_COMMAND_MENU_SELECTED event handler for wxID_ABOUT
  void OnAboutClick( wxCommandEvent& evt);

#ifndef NO_YUBI
  /// wxEVT_COMMAND_MENU_SELECTED event handler for ID_YUBIKEY_MNG
  void OnYubikeyMngClick( wxCommandEvent& event );
#endif /* NO_YUBI */
////@end PasswordSafeFrame event handler declarations
  /// wxEVT_COMMAND_MENU_SELECTED event handler for wxEVT_FIND
  void OnFindClick( wxCommandEvent& evt);

  /// wxEVT_COMMAND_MENU_SELECTED event handler for ID_EDITMENU_FIND_NEXT
  void OnFindNext(wxCommandEvent& evt);

  /// wxEVT_COMMAND_MENU_SELECTED event handler for ID_EDITMENU_FIND_PREVIOUS
  void OnFindPrevious(wxCommandEvent& evt);

  /// wxEVT_COMMAND_MENU_SELECTED event handler for ID_BROWSEURL
  void OnBrowseURL(wxCommandEvent& evt);

  /// wxEVT_COMMAND_MENU_SELECTED event handler for ID_SENDEMAIL
  void OnSendEmail(wxCommandEvent& evt);

  /// wxEVT_COMMAND_MENU_SELECTED event handler for ID_COPYRUNCOMMAND
  void OnCopyRunCmd( wxCommandEvent& evt);

  /// wxEVT_COMMAND_MENU_SELECTED event handler for ID_RUNCOMMAND
  void OnRunCommand(wxCommandEvent& evt);

  /// wxEVT_COMMAND_MENU_SELECTED event handler for ID_AUTOTYPE
  void OnAutoType(wxCommandEvent& evt);

  /// wxEVT_COMMAND_MENU_SELECTED event handler for ID_BROWSEURLPLUS
  void OnBrowseUrlAndAutotype(wxCommandEvent& evt);

  /// wxEVT_COMMAND_MENU_SELECTED event handler for ID_GOTOBASEENTRY
  void OnGotoBase(wxCommandEvent& evt);

  /// wxEVT_COMMAND_MENU_SELECTED event handler for ID_EDITBASEENTRY
  void OnEditBase(wxCommandEvent& evt);

  /// wxEVT_COMMAND_MENU_SELECTED event handler for ID_CREATESHORTCUT
  void OnCreateShortcut(wxCommandEvent& evt);

  /// wxEVT_COMMAND_MENU_SELECTED event handler for ID_DUPLICATEENTRY
  void OnDuplicateEntry(wxCommandEvent& evt);

  /// wxEVT_COMMAND_MENU_SELECTED event handler for ID_MENU_CLEAR_MRU
  void OnClearRecentHistory(wxCommandEvent& evt);

  /// .wxEVT_COMMAND_MENU_SELECTED event handler for ID_IMPORT_PLAINTEXT
  void OnImportText(wxCommandEvent& evt);

  /// .wxEVT_COMMAND_MENU_SELECTED event handler for ID_IMPORT_XML
  void OnImportXML(wxCommandEvent& evt);

  /// .wxEVT_COMMAND_MENU_SELECTED event handler for ID_IMPORT_KEEPASS
  void OnImportKeePass(wxCommandEvent& evt);

  /// .wxEVT_COMMAND_MENU_SELECTED event handler for EXPORT2OLD1XFORMAT & ID_EXPORT2V[23]FORMAT
  void OnExportVx(wxCommandEvent& evt);

  /// .wxEVT_COMMAND_MENU_SELECTED event handler for ID_EXPORT2PLAINTEXT
  void OnExportPlainText(wxCommandEvent& evt);

  /// .wxEVT_COMMAND_MENU_SELECTED event handler for ID_EXPORT2XML
  void OnExportXml(wxCommandEvent& evt);

  /// called when one of the MRU db's is selected from File menu
  void OnOpenRecentDB(wxCommandEvent& evt);

  /// wxEVT_COMMAND_MENU_SELECTED event handler for ID_COPYEMAIL
  void OnCopyEmailClick( wxCommandEvent& evt);

  /// wxEVT_UPDATE_UI event handler for all command ids
  void OnUpdateUI(wxUpdateUIEvent& evt);

  /// wxEVT_UPDATE_UI event handler for ID_MENU_CLEAR_MRU
  void OnUpdateClearRecentDBHistory(wxUpdateUIEvent& evt);

  /// Handler for all EVT_MENU_OPEN types events for all menus
  void OnUpdateMenu(wxMenuEvent& evt);

  /// wxEVT_ICONIZE event handler
  void OnIconize(wxIconizeEvent& evt);

  /// wxEVT_COMMAND_MENU_SELECTED event handler for wxID_UNDO
  void OnUndo(wxCommandEvent& evt);

  /// wxEVT_COMMAND_MENU_SELECTED event handler for wxID_REDO
  void OnRedo(wxCommandEvent& evt);

  /// wxEVT_COMMAND_MENU_SELECTED event handler for ID_EXPANDALL
  void OnExpandAll(wxCommandEvent& /*evt*/);

  /// wxEVT_COMMAND_MENU_SELECTED event handler for ID_COLLAPSEALL
  void OnCollapseAll(wxCommandEvent& /*evt*/);

  void OnChangeTreeFont(wxCommandEvent& /*evt*/);
  void OnChangePasswordFont(wxCommandEvent& /*evt*/);

  void OnShowHideToolBar(wxCommandEvent& /*evt*/);
  void OnShowHideDragBar(wxCommandEvent& /*evt*/);

  void OnMergeAnotherSafe(wxCommandEvent& evt);
  void OnSynchronize(wxCommandEvent& evt);
  void OnCompare(wxCommandEvent& evt);

  /// wxEVT_COMMAND_MENU_SELECTED event handler for ID_TOOLBAR_CLASSIC and ID_TOOLBAR_NEW
  void OnChangeToolbarType(wxCommandEvent& /*evt*/);

  void OnBackupSafe(wxCommandEvent& evt);
  void OnRestoreSafe(wxCommandEvent& evt);
  
  void OnVisitWebsite(wxCommandEvent&);

  void OnPasswordSubset(wxCommandEvent& evt);

////@begin PasswordSafeFrame member function declarations

  /// Retrieves bitmap resources
  wxBitmap GetBitmapResource( const wxString& name );

  /// Retrieves icon resources
  wxIcon GetIconResource( const wxString& name );
////@end PasswordSafeFrame member function declarations

/// Should we show tooltips?
  static bool ShowToolTips();

  // Overridden virtuals
  virtual bool Show(bool show = true);
  virtual void SetTitle(const wxString& title);
  virtual void SetFocus();

  // PasswordSafe specifics:
  int Load(const StringX &passwd);

  // Highlights the item.  Used for search
  void SelectItem(const pws_os::CUUID& uuid);

  ItemListConstIter GetEntryIter() const {return m_core.GetEntryIter();}
  ItemListConstIter GetEntryEndIter() const {return m_core.GetEntryEndIter();}

  void Execute(Command *pcmd, PWScore *pcore = NULL);

  bool IsTreeView() const {return m_currentView == TREE;}
  void RefreshViews();
  void FlattenTree(OrderedItemList& olist);

  void DispatchDblClickAction(CItemData &item); // called by grid/tree
  void UpdateSelChanged(const CItemData *pci); // ditto

  /// Centralized handling of right click in the grid or the tree view
  void OnContextMenu(const CItemData* item);

  /// Called by wxTaskbarIcon derived class on clicking of system tray's Restore menu item
  void UnlockSafe(bool restoreUI, bool iconizeOnFailure);

  /// Called by app when the inactivity timer arrives
  void HideUI(bool lock);

  /// Called by system tray unlock the UI (and optionally restore the main window)
  void UnlockUI(bool restoreFrame);

  /// Returns true if the user enters the correct safe combination and presses OK
  bool VerifySafeCombination(StringX& password);

  void GetAllMenuItemStrings(std::vector<RUEntryData>& vec) const { m_RUEList.GetAllMenuItemStrings(vec); };
  void DeleteRUEntry(size_t index) { m_RUEList.DeleteRUEntry(index); }

  void ClearRUEList() { m_RUEList.ClearEntries(); }
  void OnUpdateClearRecentHistory();

  void ViewReport(CReport& rpt);

  CItemData *GetSelectedEntry() const;
  CItemData *GetSelectedEntry(const wxCommandEvent& evt, CItemData &rueItem) const;
  wxString GetCurrentSafe() const { return towxstring(m_core.GetCurFile()); }

  void SetTrayStatus(bool locked);
  void SetTrayClosed();
  void ShowTrayIcon();

  ////@begin PasswordSafeFrame member variables
  PWSGrid* m_grid;
  PWSTreeCtrl* m_tree;
  CPWStatusBar* m_statusBar;
  ////@end PasswordSafeFrame member variables
 private:
  enum SaveType {ST_INVALID = -1, ST_NORMALEXIT = 0, ST_SAVEIMMEDIATELY,
                 ST_ENDSESSIONEXIT, ST_WTSLOGOFFEXIT, ST_FAILSAFESAVE};

  //we need to restrict the size of individual text fields, to prevent creating
  //enormous databases.  See the comments in DboxMain.h
  enum {MAXTEXTCHARS = 30000};

  int New();
  int NewFile(StringX &fname);
  int DoOpen(const wxString& title);
  int Open(const wxString &fname); // prompt for password, try to Load.
  int SaveIfChanged();
  int SaveAs(void);
  int Save(SaveType st = ST_INVALID);
  int SaveImmediately();
  void ShowGrid(bool show = true);
  void ShowTree(bool show = true);
  void ClearData();
  bool ReloadDatabase(const StringX& password);
  bool SaveAndClearDatabase();
  void CleanupAfterReloadFailure(bool tellUser);
  Command *Delete(CItemData *pci);
  Command *Delete(wxTreeItemId tid); // for group delete
  CItemData* GetBaseOfSelectedEntry(); //traverses to the base item if the selected item is a shortcut
  void UpdateAccessTime(CItemData &ci);
  void CreateMainToolbar();
  void ReCreateMainToolbar();
  void ReCreateDragToolbar();
  long GetEventRUEIndex(const wxCommandEvent& evt) const;
  bool IsRUEEvent(const wxCommandEvent& evt) const;
  void RebuildGUI(const int iView = iBothViews);
  void RefreshEntryFieldInGUI(const CItemData& item, CItemData::FieldType ft);
  void RefreshEntryPasswordInGUI(const CItemData& item);
  void CreateDragBar();
  void RefreshToolbarButtons();
  PWSDragBar* GetDragBar();
  bool IsClosed() const;
  void SaveSettings() const;
  void LockDb();
  void TryIconize(int nAttempts = 5);

  void Merge(const StringX &sx_Filename2, PWScore *pothercore, const SelectionCriteria& selection);
  int MergeDependents(PWScore *pothercore, MultiCommands *pmulticmds,
                              uuid_array_t &base_uuid, uuid_array_t &new_base_uuid,
                              const bool bTitleRenamed, wxString &timeStr,
                              const CItemData::EntryType et,
                              std::vector<StringX> &vs_added);
  BOOL LaunchBrowser(const wxString &csURL, const StringX &sxAutotype,
                     const std::vector<size_t> &vactionverboffsets, bool bDoAutotype);

  // Do* member functions for right-click and menu-accessible actions
  void DoCopyPassword(CItemData &item);
  void DoCopyNotes(CItemData &item);
  void DoCopyUsername(CItemData &item);
  void DoCopyURL(CItemData &item);
  void DoCopyEmail(CItemData &item);
  void DoCopyRunCmd(CItemData &item);
  void DoEdit(CItemData item);
  void DoAutotype(CItemData &item);
  void DoAutotype(const StringX& sx_autotype, const std::vector<size_t>& vactionverboffsets);
  void DoBrowse(CItemData &item, bool bAutotype);
  void DoRun(CItemData &item);
  void DoEmail(CItemData &item);
  void DoPasswordSubset(CItemData &item);

  // These 3 fns are called via wxEvtHandler::CallAfter in sequence for autotyping
  void MinimizeOrHideBeforeAutotyping();
  void MaybeRestoreUI(bool autotype_err, wxString autotype_err_msg);

  template <class ExportType>
  void DoExportText();

  /// Adds a sub menu with all supported languages to a given wxMenu
  void AddLanguageMenu(wxMenu* parent);

  /// Adds a language to internal list of supported languages by this application
  void AddLanguage(int menu_id, wxLanguage lang_id, const wxString& lang_name);

  /// Update status bar - call when stuff changes:
  /// File open, double-click, modify, r-o r/w, filter...
  void UpdateStatusBar();
  PWScore &m_core;
  enum {TREE, GRID} m_currentView;
  PasswordSafeSearch* m_search;
  SystemTray* m_sysTray;
  bool m_exitFromMenu;
  bool m_bRestoredDBUnsaved;
  CRUEList m_RUEList;
  GUIInfo* m_guiInfo;
  bool m_bTSUpdated;
  wxString m_savedDBPrefs;
  enum {iListOnly = 1, iTreeOnly = 2, iBothViews = 3};
  // top-level windows that we hid while locking the UI
  wxWindowList hiddenWindows;

  /*
   * The map associates menu item id's with language specific data represented by a tuple.
   * The tuple consists of the wxWidgets language identifier, the language name as wxString
   * as it should appear in the menu and of an indicator whether the language can be
   * activated or not.
   */
  std::map<int, std::tuple<wxLanguage, wxString, bool> > m_languages;

  // The selected language menu id
  int m_selectedLanguage;
  void RegisterLanguageMenuItems();
  // we need to prevent multiple call to db (un)locker and UI hider
  // These mutexes must not be recursive!
  wxMutex m_dblockMutex, m_hideUIMutex;

  // Filter-related stuff
  PWSFilterManager m_FilterManager;
  // Current filter
  st_filters &CurrentFilter() {return m_FilterManager.m_currentfilter;}

  bool m_bShowExpiry, m_bShowUnsaved; // predefined filters
  bool m_bFilterActive;
  void ApplyFilters();
};

BEGIN_DECLARE_EVENT_TYPES()
DECLARE_EVENT_TYPE(wxEVT_DB_PREFS_CHANGE, -1)
DECLARE_EVENT_TYPE(wxEVT_GUI_DB_PREFS_CHANGE, -1)
END_DECLARE_EVENT_TYPES()

#endif
    // _PASSWORDSAFEFRAME_H_
