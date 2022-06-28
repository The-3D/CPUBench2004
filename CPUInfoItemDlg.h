#if !defined(AFX_CPUINFOITEMDLG_H__8DF04711_D9A2_4A74_B43A_530DB3851FB3__INCLUDED_)
#define AFX_CPUINFOITEMDLG_H__8DF04711_D9A2_4A74_B43A_530DB3851FB3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// CPUInfoItemDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CCPUInfoItemDlg dialog

class CCPUInfoItemDlg : public CDialog
{
// Construction
public:
	CCPUInfoItemDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CCPUInfoItemDlg)
	enum { IDD = IDD_CPUINFOITEMDLG_DIALOG };
	CFlexGUIButton	m_cacheinfo;
	CFlexGUIButton	m_advinfo;
	CString	m_brandName;
	CString	m_codeName;
	CString	m_cpuName;
	CString	m_cpuVendor;
	CString	m_frequency;
	CString	m_L1DCache;
	CString	m_L1ICache;
	CString	m_L2Cache;
	CString	m_signature;
	CString	m_socket;
	CString	m_traceCache;
	CString	m_busType;
	CString	m_fsbSpeed;
	//}}AFX_DATA

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCPUInfoItemDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CCPUInfoItemDlg)
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	virtual BOOL OnInitDialog();
	afx_msg void OnAdvinfo();
	afx_msg void OnPaint();
	afx_msg void OnCacheinfo();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CPUINFOITEMDLG_H__8DF04711_D9A2_4A74_B43A_530DB3851FB3__INCLUDED_)
