#if !defined(AFX_DEVICESLISTDLG_H__C282315E_F627_4569_ACFA_1CC1F3C62E0A__INCLUDED_)
#define AFX_DEVICESLISTDLG_H__C282315E_F627_4569_ACFA_1CC1F3C62E0A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DevicesListDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDevicesListDlg dialog

class CDevicesListDlg : public CDialog
{
// Construction
public:
	CDevicesListDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDevicesListDlg)
	enum { IDD = IDD_DEVICESLISTDLG_DIALOG };
	CFlexGUIButton	m_ok;
	CListCtrl	m_devicesList;
	//}}AFX_DATA
	CFont m_fntTitle;


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDevicesListDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDevicesListDlg)
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DEVICESLISTDLG_H__C282315E_F627_4569_ACFA_1CC1F3C62E0A__INCLUDED_)
