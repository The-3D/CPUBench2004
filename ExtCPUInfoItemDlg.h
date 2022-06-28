#if !defined(AFX_EXTCPUINFOITEMDLG_H__846D9135_4BCA_41BA_A810_69C11607BE07__INCLUDED_)
#define AFX_EXTCPUINFOITEMDLG_H__846D9135_4BCA_41BA_A810_69C11607BE07__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ExtCPUInfoItemDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CExtCPUInfoItemDlg dialog

class CExtCPUInfoItemDlg : public CDialog
{
// Construction
public:
	CExtCPUInfoItemDlg(CWnd* pParent = NULL);   // standard constructor
	void Update();

// Dialog Data
	//{{AFX_DATA(CExtCPUInfoItemDlg)
	enum { IDD = IDD_EXTCPUINFOITEMDLG_DIALOG };
	CFlexGUIButton	m_cacheDetails;
	CFlexGUIButton	m_cpuFeatures;
	CString	m_vendorName;
	CString	m_cpuName;
	CString	m_codeName;
	CString	m_platform;
	CString	m_brandName;
	CString	m_frequency;
	CString	m_frequencyRange;
	CString	m_multiplier;
	CString	m_L1ICache;
	CString	m_L1DCache;
	CString	m_traceCache;
	CString	m_signature;
	CString	m_L2Cache;
	CString	m_defaultVCore;
	CString	m_HTsupport;
	CString	m_MMX;
	CString	m_PSE36;
	CString	m_SSE;
	CString	m_SSE2;
	CString	m_SSE3;
	CString	m_AMD64;
	//}}AFX_DATA
	CFont fntLbl;

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CExtCPUInfoItemDlg)
	public:
	virtual BOOL DestroyWindow();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CExtCPUInfoItemDlg)
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	virtual BOOL OnInitDialog();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnCachedetails();
	afx_msg void OnPaint();
	afx_msg void OnFeatures();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EXTCPUINFOITEMDLG_H__846D9135_4BCA_41BA_A810_69C11607BE07__INCLUDED_)
