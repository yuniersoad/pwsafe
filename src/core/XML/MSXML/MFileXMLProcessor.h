/*
* Copyright (c) 2003-2012 Rony Shapiro <ronys@users.sourceforge.net>.
* All rights reserved. Use of the code is allowed under the
* Artistic License 2.0 terms, as specified in the LICENSE file
* distributed with this code, or available from
* http://www.opensource.org/licenses/artistic-license-2.0.php
*/
// MFileXMLProcessor.h : header file
//

#ifndef __MFILEXMLPROCESSOR_H
#define __MFILEXMLPROCESSOR_H

#include "../../UnknownField.h"
#include "../../Command.h"

#include "os/typedefs.h"
#include "os/UUID.h"

#include <vector>

class PWScore;

class MFileXMLProcessor
{
public:
  MFileXMLProcessor(PWScore *pcore, UUIDVector *pPossible_Aliases, 
                    UUIDVector *pPossible_Shortcuts, MultiCommands *p_multicmds,
                    CReport *prpt);
  ~MFileXMLProcessor();

  bool Process(const bool &bvalidation, const stringT &ImportedPrefix,
    const stringT &strXMLFileName, const stringT &strXSDFileName,
    const bool &bImportPSWDsOnly, int &nITER);

  stringT getXMLErrors() {return m_strXMLErrors;}
  stringT getSkippedList() {return m_strSkippedList;}
  stringT getRenameList() {return m_strRenameList;}
  stringT getPWHErrorList() {return m_strPWHErrorList;}

  int getNumEntriesValidated() {return m_numEntriesValidated;}
  int getNumEntriesImported() {return m_numEntriesImported;}
  int getNumEntriesSkipped() {return m_numEntriesSkipped;}
  int getNumEntriesRenamed() {return m_numEntriesRenamed;}
  int getNumEntriesPWHErrors() {return m_numEntriesPWHErrors;}
  int getNumNoPolicies() {return m_numNoPolicies;}
  int getNumRenamedPolicies() const {return m_numRenamedPolicies;}

private:
  PWScore *m_pXMLcore;
  UUIDVector *m_pPossible_Aliases;
  UUIDVector *m_pPossible_Shortcuts;
  MultiCommands *m_pmulticmds;
  CReport *m_prpt;

  stringT m_strXMLErrors, m_strSkippedList, m_strPWHErrorList, m_strRenameList;
  int m_numEntriesValidated, m_numEntriesImported, m_numEntriesSkipped;
  int m_numEntriesPWHErrors, m_numEntriesRenamed;
  int m_numRenamedPolicies, m_numNoPolicies;
  int m_MSXML_Version;
  TCHAR m_delimiter;
  bool m_bValidation;
};

#endif /* __MFILEXMLPROCESSOR_H */