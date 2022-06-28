#if !defined(AFX_EXTOSINFODLG_H__098DBD70_D7CE_4C02_BF1C_37FDAF6DE8F1__INCLUDED_)
#define AFX_EXTOSINFODLG_H__098DBD70_D7CE_4C02_BF1C_37FDAF6DE8F1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ExtOSInfoDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CExtOSInfoDlg dialog

class CExtOSInfoDlg : public CDialog
{
// Construction
public:
	CExtOSInfoDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CExtOSInfoDlg)
	enum { IDD = IDD_EXTOSINFODLG_DIALOG };
	CString	m_Revision;
	CString	m_userName;
	CString	m_OSName;
	CString	m_computerName;
	CString	m_servicePack;
	CString	m_standBy;
	CString	m_mainDirectory;
	CString	m_bootMode;
	CString	m_resolution;
	//}}AFX_DATA
	CFont m_fntLbl;

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CExtOSInfoDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CExtOSInfoDlg)
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EXTOSINFODLG_H__098DBD70_D7CE_4C02_BF1C_37FDAF6DE8F1__INCLUDED_)
