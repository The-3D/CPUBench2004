// SysInfoWorkspace.h: interface for the CSysInfoWorkspace class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SYSINFOWORKSPACE_H__B4CD87BC_20CD_461C_BBE8_156BE53E0F88__INCLUDED_)
#define AFX_SYSINFOWORKSPACE_H__B4CD87BC_20CD_461C_BBE8_156BE53E0F88__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "FlexGUIWorkspace.h"
#include "extcpuinfoitemdlg.h"
#include "dialogbaseditem.h"
#include "extosinfodlg.h"
#include "extmemoryinfodlg.h"
#include "extmbinfodlg.h"





class CSysInfoWorkspace : public CFlexGUIWorkspace  
{
public:
	CSysInfoWorkspace();
	virtual ~CSysInfoWorkspace();
	void BuildInterface();
	void SetParent(CWnd* pParent){

		m_pParent=pParent;

	}

	void Update();

	CExtCPUInfoItemDlg cpuDlg;
	CExtOSInfoDlg osDlg;
	CExtMemoryInfoDlg memDlg;
	CExtMBInfoDlg mbDlg;
	CDialogBasedItem i;
	CDialogBasedItem i2;
	CDialogBasedItem i3;
	CDialogBasedItem i4;

	CWnd *m_pParent;




};

#endif // !defined(AFX_SYSINFOWORKSPACE_H__B4CD87BC_20CD_461C_BBE8_156BE53E0F88__INCLUDED_)
