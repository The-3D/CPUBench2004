#if !defined(AFX_OSINFOITEMDLG_H__D9DA3304_E308_43F6_BCF4_284825015418__INCLUDED_)
#define AFX_OSINFOITEMDLG_H__D9DA3304_E308_43F6_BCF4_284825015418__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// OSInfoItemDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// COSInfoItemDlg dialog
#include "extprogressctrl.h"

class COSInfoItemDlg : public CDialog
{
// Construction
public:
	COSInfoItemDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(COSInfoItemDlg)
	enum { IDD = IDD_OSINFOITEMDLG_DIALOG };
	CExtProgressCtrl	m_memFree;
	CFlexGUIButton	m_osDetails;
	CString	m_memFreeVal;
	CString	m_osName;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(COSInfoItemDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(COSInfoItemDlg)
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	virtual BOOL OnInitDialog();
	afx_msg void OnMore();
	afx_msg void OnPaint();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_OSINFOITEMDLG_H__D9DA3304_E308_43F6_BCF4_284825015418__INCLUDED_)
