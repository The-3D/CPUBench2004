#if !defined(AFX_RESULTDLG_H__32D013F4_16EB_4C39_84C4_F7AE74FEFB5B__INCLUDED_)
#define AFX_RESULTDLG_H__32D013F4_16EB_4C39_84C4_F7AE74FEFB5B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ResultDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CResultDlg dialog
#include "flexguibutton.h"


class CResultDlg : public CDialog
{
// Construction
public:
	CResultDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CResultDlg)
	enum { IDD = IDD_RESULTDLG_DIALOG };
	CFlexGUIButton	m_benchDetails;
	CFlexGUIButton	m_cpuInfo;
	CFlexGUIButton	m_graphResult;
	CFlexGUIButton	m_saveProject;
	CFlexGUIButton	m_ok;
	//}}AFX_DATA
	CFont m_fntResult;
	CFont m_fntTime;
	CFont m_fnt;


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CResultDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CResultDlg)
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	virtual BOOL OnInitDialog();
	afx_msg void OnGraphofresult();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_RESULTDLG_H__32D013F4_16EB_4C39_84C4_F7AE74FEFB5B__INCLUDED_)
