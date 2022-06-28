#if !defined(AFX_CACHEINFODLG_H__B7F6CD56_2E7C_4F09_B6F1_6A2F3918421F__INCLUDED_)
#define AFX_CACHEINFODLG_H__B7F6CD56_2E7C_4F09_B6F1_6A2F3918421F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// CacheInfoDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CCacheInfoDlg dialog

class CCacheInfoDlg : public CDialog
{
// Construction
public:
	CCacheInfoDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CCacheInfoDlg)
	enum { IDD = IDD_CACHEINFODLG_DIALOG };
	CFlexGUIButton	m_cacheLatency;
	CFlexGUIButton	m_ok;
	CString	m_title;
	CString	m_L1ITLB4M_entries;
	CString	m_L1ITLB4M_ass;
	CString	m_L1DTLB4M_entries;
	CString	m_L1DTLB4M_ass;
	CString	m_L1D_Ass;
	CString	m_L1D_CacheSize;
	CString	m_L1D_LineSize;
	CString	m_L1D_LinesPerTag;
	CString	m_L1I_CacheSize;
	CString	m_L1I_LineSize;
	CString	m_L1I_Ass;
	CString	m_L1I_LinesPerTag;
	CString	m_L1I_TLB4K_Ass;
	CString	m_L1D_TLB4K_Ass;
	CString	m_L1D_TLB4K_Entries;
	CString	m_L1I_TLB4K_Entries;
	CString	m_L2_Ass;
	CString	m_L2_CacheSize;
	CString	m_L2_LineSize;
	CString	m_L2_LinesPerTag;
	CString	m_L2D_TLB4K_Ass;
	CString	m_L2D_TLB4K_Entries;
	CString	m_L2D_TLB4M_Ass;
	CString	m_L2D_TLB4M_Entries;
	CString	m_L2I_TLB4K_Ass;
	CString	m_L2I_TLB4K_Entries;
	CString	m_L2I_TLB4M_Ass;
	CString	m_L2I_TLB4M_Entries;
	//}}AFX_DATA

	CFont m_fntLbl;
	CFont m_fntTitle;


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCacheInfoDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CCacheInfoDlg)
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	virtual BOOL OnInitDialog();
	afx_msg void OnCachelatency();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CACHEINFODLG_H__B7F6CD56_2E7C_4F09_B6F1_6A2F3918421F__INCLUDED_)
