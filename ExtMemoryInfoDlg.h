#if !defined(AFX_EXTMEMORYINFODLG_H__D64F00E0_63E0_4E00_B5F8_B7EBF0114AE8__INCLUDED_)
#define AFX_EXTMEMORYINFODLG_H__D64F00E0_63E0_4E00_B5F8_B7EBF0114AE8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ExtMemoryInfoDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CExtMemoryInfoDlg dialog
#include "extprogressctrl.h"

class CExtMemoryInfoDlg : public CDialog
{
// Construction
public:
	CExtMemoryInfoDlg(CWnd* pParent = NULL);   // standard constructor

	void Update();

// Dialog Data
	//{{AFX_DATA(CExtMemoryInfoDlg)
	enum { IDD = IDD_EXTMEMORYINFODLG_DIALOG };
	CExtProgressCtrl	m_userFree;
	CExtProgressCtrl	m_totalLoad;
	CExtProgressCtrl	m_ramFree;
	CExtProgressCtrl	m_pageFileFree;
	CString	m_memLoadVal;
	CString	m_pageFreeVal;
	CString	m_ramFreeVal;
	CString	m_userFreeVal;
	CString	m_pageSize;
	CString	m_physMem;
	CString	m_virtualSize;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CExtMemoryInfoDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CExtMemoryInfoDlg)
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EXTMEMORYINFODLG_H__D64F00E0_63E0_4E00_B5F8_B7EBF0114AE8__INCLUDED_)
