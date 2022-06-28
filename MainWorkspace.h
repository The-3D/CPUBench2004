// MainWorkspace.h: interface for the CMainWorkspace class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MAINWORKSPACE_H__8DF204D3_2F7A_41B4_BD50_30DCAC1EE5A5__INCLUDED_)
#define AFX_MAINWORKSPACE_H__8DF204D3_2F7A_41B4_BD50_30DCAC1EE5A5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "FlexGUIWorkspace.h"

class CMainWorkspace : public CFlexGUIWorkspace  
{
public:
	CMainWorkspace();
	void BuildInterface();

	virtual ~CMainWorkspace();
private:
	CBenchmarkSettingsDlg m_settingsDlg;
	CCPUInfoItemDlg m_cpuDlg;
	COSInfoItemDlg m_osDlg;

	//items
	CDialogBasedItem i,i2,i3;
	CBenchmarkResultItem i4;

};

#endif // !defined(AFX_MAINWORKSPACE_H__8DF204D3_2F7A_41B4_BD50_30DCAC1EE5A5__INCLUDED_)
