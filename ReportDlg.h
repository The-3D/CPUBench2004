#if !defined(AFX_REPORTDLG_H__F1B6CE70_5CAD_45E3_A53C_995ADCE80917__INCLUDED_)
#define AFX_REPORTDLG_H__F1B6CE70_5CAD_45E3_A53C_995ADCE80917__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ReportDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CReportDlg dialog

class CReportDlg : public CDialog
{
// Construction
public:
	CReportDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CReportDlg)
	enum { IDD = IDD_REPORTDLG_DIALOG };
	CFlexGUIButton	m_cancel;
	CFlexGUIButton	m_ok;
	BOOL	m_cpuInfo;
	BOOL	m_cpuFeatures;
	BOOL	m_cacheInfo;
	BOOL	m_testerInfo;
	BOOL	m_mbInfo;
	BOOL	m_osInfo;
	BOOL	m_pciDevs;
	CString	m_sysDetails;
	CString	m_sysName;
	CString	m_testerName;
	BOOL	m_benchResults;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CReportDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CReportDlg)
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	afx_msg void OnIncludetesterinfo();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_REPORTDLG_H__F1B6CE70_5CAD_45E3_A53C_995ADCE80917__INCLUDED_)
