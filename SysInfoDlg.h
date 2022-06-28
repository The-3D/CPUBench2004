#if !defined(AFX_SYSINFODLG_H__CDF6F48B_A960_4E40_B093_73CCB2527204__INCLUDED_)
#define AFX_SYSINFODLG_H__CDF6F48B_A960_4E40_B093_73CCB2527204__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SysInfoDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CSysInfoDlg dialog
#include "sysinfoworkspace.h"

class CSysInfoDlg : public CDialog
{
// Construction
public:
	CSysInfoDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CSysInfoDlg)
	enum { IDD = IDD_SYSINFODLG_DIALOG };
	CFlexGUIButton	m_report;
	CFlexGUIButton	m_customize;
	CFlexGUIButton	m_ok;
	//}}AFX_DATA

	CSysInfoWorkspace w;


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSysInfoDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CSysInfoDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg void OnCreatereport();
	afx_msg void OnUpdate();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SYSINFODLG_H__CDF6F48B_A960_4E40_B093_73CCB2527204__INCLUDED_)
