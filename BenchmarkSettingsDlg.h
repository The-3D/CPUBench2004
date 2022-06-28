#if !defined(AFX_BENCHMARKSETTINGSDLG_H__4B336C16_587C_4624_9C25_28DDFA37F805__INCLUDED_)
#define AFX_BENCHMARKSETTINGSDLG_H__4B336C16_587C_4624_9C25_28DDFA37F805__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// BenchmarkSettingsDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CBenchmarkSettingsDlg dialog

class CBenchmarkSettingsDlg : public CDialog
{
// Construction
public:
	CBenchmarkSettingsDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CBenchmarkSettingsDlg)
	enum { IDD = IDD_BENCHMARKSETTINGSDLG_DIALOG };
	CFlexGUIButton	m_configure;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBenchmarkSettingsDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CBenchmarkSettingsDlg)
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	virtual BOOL OnInitDialog();
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnPaint();
	afx_msg void OnConfigure();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BENCHMARKSETTINGSDLG_H__4B336C16_587C_4624_9C25_28DDFA37F805__INCLUDED_)
