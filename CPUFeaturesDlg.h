#if !defined(AFX_CPUFEATURESDLG_H__4A613DBA_015A_4B69_AA6B_2CC83645C936__INCLUDED_)
#define AFX_CPUFEATURESDLG_H__4A613DBA_015A_4B69_AA6B_2CC83645C936__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// CPUFeaturesDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CCPUFeaturesDlg dialog
#include "cpufeaturesworkspace.h"

class CCPUFeaturesDlg : public CDialog
{
// Construction
public:
	CCPUFeaturesDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CCPUFeaturesDlg)
	enum { IDD = IDD_CPUFEATURESDLG_DIALOG };
	CFlexGUIButton	m_ok;
	//}}AFX_DATA

	CCPUFeaturesWorkspace w;

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCPUFeaturesDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CCPUFeaturesDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CPUFEATURESDLG_H__4A613DBA_015A_4B69_AA6B_2CC83645C936__INCLUDED_)
