#if !defined(AFX_BENCHMARKSTATUSDLG_H__6F27CEBC_1A3B_4ED9_AADF_4073A00FDC02__INCLUDED_)
#define AFX_BENCHMARKSTATUSDLG_H__6F27CEBC_1A3B_4ED9_AADF_4073A00FDC02__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// BenchmarkStatusDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CBenchmarkStatusDlg dialog

class CBenchmarkStatusDlg : public CDialog
{
// Construction
public:
	CBenchmarkStatusDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CBenchmarkStatusDlg)
	enum { IDD = IDD_BENCHMARKSTATUSDLG_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBenchmarkStatusDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CBenchmarkStatusDlg)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BENCHMARKSTATUSDLG_H__6F27CEBC_1A3B_4ED9_AADF_4073A00FDC02__INCLUDED_)
