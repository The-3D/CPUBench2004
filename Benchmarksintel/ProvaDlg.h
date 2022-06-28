#if !defined(AFX_PROVADLG_H__E3725089_CD91_4EAA_BFC9_38293BF403FC__INCLUDED_)
#define AFX_PROVADLG_H__E3725089_CD91_4EAA_BFC9_38293BF403FC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ProvaDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CProvaDlg dialog

class CProvaDlg : public CDialog
{
// Construction
public:
	CProvaDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CProvaDlg)
	enum { IDD = IDD_PROVADLG_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CProvaDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CProvaDlg)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PROVADLG_H__E3725089_CD91_4EAA_BFC9_38293BF403FC__INCLUDED_)
