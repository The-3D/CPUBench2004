#if !defined(AFX_BENCHMARKDLG_H__850943B0_3B0F_4B05_8FEC_904B78202486__INCLUDED_)
#define AFX_BENCHMARKDLG_H__850943B0_3B0F_4B05_8FEC_904B78202486__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// BenchmarkDlg.h : header file
//


/////////////////////////////////////////////////////////////////////////////
// CBenchmarkDlg window
#include "extprogressctrl.h"

class CBenchmarkDlg : public CWnd
{
// Construction
public:
	CBenchmarkDlg();

	CStatic m_consoleOutput;
	CStatic m_currStatus;

	CExtProgressCtrl m_currProgress;

	CStatic m_infoTitle;
	CStatic m_statusTitle;
	CStatic m_cpuName;
	CStatic m_cpuFreq;
	CStatic m_busSpeed;
	CStatic m_L1DCache;
	CStatic m_L1ICache;
	CStatic m_L2Cache;
	CStatic m_traceCache;
	CFont m_fntTitle,m_fntText;
	bool bFinished;

	
	void UpdateStatus(CString status){

		m_currStatus.SetWindowText(status);
		RedrawWindow(NULL,NULL,RDW_INVALIDATE | RDW_UPDATENOW | RDW_ERASE | RDW_ALLCHILDREN);


	}

	void Step(int val) {

		m_currProgress.SetPos(val);
	}

	CStatic *GetOutTarget() { return &m_consoleOutput; }

	void SetFinished(bool finished){ bFinished=finished;}

private:
	void BuildInterface();


	void ExcludeBkRepaint(CDC* pDC,CWnd* pWnd);
// Attributes
public:
// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBenchmarkDlg)
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CBenchmarkDlg();

	// Generated message map functions
protected:
	//{{AFX_MSG(CBenchmarkDlg)
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnShowWindow(BOOL bShow, UINT nStatus);
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BENCHMARKDLG_H__850943B0_3B0F_4B05_8FEC_904B78202486__INCLUDED_)
