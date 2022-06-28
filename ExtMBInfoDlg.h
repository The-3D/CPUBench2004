#if !defined(AFX_EXTMBINFODLG_H__BAA6B1F1_3CF4_490A_81DA_9BE91AA15FD9__INCLUDED_)
#define AFX_EXTMBINFODLG_H__BAA6B1F1_3CF4_490A_81DA_9BE91AA15FD9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ExtMBInfoDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CExtMBInfoDlg dialog

class CExtMBInfoDlg : public CDialog
{
// Construction
public:
	CExtMBInfoDlg(CWnd* pParent = NULL);   // standard constructor
	void Update();

// Dialog Data
	//{{AFX_DATA(CExtMBInfoDlg)
	enum { IDD = IDD_EXTMBINFODLG_DIALOG };
	CFlexGUIButton	m_OtherPCI;
	CString	m_biosDate;
	CString	m_biosName;
	CString	m_biosVersion;
	CString	m_chipsetID;
	CString	m_chipsetVendor;
	CString	m_chipsetName;
	CString	m_fsbSpeed;
	CString	m_pciLatency;
	CString	m_busType;
	//}}AFX_DATA

	CFont fntLbl;

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CExtMBInfoDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CExtMBInfoDlg)
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg void OnOtherpci();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EXTMBINFODLG_H__BAA6B1F1_3CF4_490A_81DA_9BE91AA15FD9__INCLUDED_)
