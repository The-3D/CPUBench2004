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
#include "..\\flexguibutton.h"


#define OUT_TARGET_MAIN_X_SIZE_SINGLE 800
#define OUT_TARGET_MAIN_X_SIZE_MULTI  500
#define OUT_TARGET_SUBWINDOW_X_SIZE   300
#define TITLE_X_POS 815
#define TEXT_X_POS 825

#define INFORMATIONS_AREA_START 117
#define TECHDETAILS_AREA_START INFORMATIONS_AREA_START+150

#define BENCHSTATUS_AREA_START INFORMATIONS_AREA_START+260


class CBenchmarkDlg : public CWnd
{
// Construction
public:

	enum OUT_MODE{SINGLE_WINDOW,MULTI_WINDOW};

	CBenchmarkDlg();

	
	void UpdateStatus(CString status){

		m_currStatus.SetWindowText(status);

		CRect r;

		m_currStatus.GetWindowRect(&r);

		RedrawWindow(&r,NULL);

	}

	void Step(int val) {

		m_currProgress.SetPos(val);

	}

	void StepTotalProgress(int val) {

		m_totalProgress.SetPos(val);

	}

	void SetOutMode(OUT_MODE m){


		switch(m){

		case MULTI_WINDOW:
			::SetWindowPos(m_outTargetLeftWnd1.m_hWnd,NULL,0,0,0,0,SWP_NOSIZE | SWP_NOMOVE | SWP_NOZORDER | SWP_SHOWWINDOW); 
			::SetWindowPos(m_outTargetLeftWnd2.m_hWnd,NULL,0,0,0,0,SWP_NOSIZE | SWP_NOMOVE | SWP_NOZORDER | SWP_SHOWWINDOW); 
			::SetWindowPos(m_outTargetMain.m_hWnd,NULL,OUT_TARGET_SUBWINDOW_X_SIZE,117,OUT_TARGET_MAIN_X_SIZE_MULTI,600,SWP_NOZORDER);
			break;

		case SINGLE_WINDOW:
			::SetWindowPos(m_outTargetLeftWnd1.m_hWnd,NULL,0,0,0,0,SWP_NOSIZE | SWP_NOMOVE | SWP_NOZORDER | SWP_HIDEWINDOW); 
			::SetWindowPos(m_outTargetLeftWnd2.m_hWnd,NULL,0,0,0,0,SWP_NOSIZE | SWP_NOMOVE | SWP_NOZORDER | SWP_HIDEWINDOW); 
			::SetWindowPos(m_outTargetMain.m_hWnd,NULL,0,117,OUT_TARGET_MAIN_X_SIZE_SINGLE,600,SWP_NOZORDER);
			break;
		}

		m_outMode = m;

	}

	OUT_MODE GetOutMode(){ return m_outMode;}

	bool StopExecutionRequested(){
		return m_stopExecutionRequested;
	}


	void SetTestInfo(CString testName,CString testDesc,CString techDetails){

		CString name="Test name: "+testName;

		CString desc="Description: "+testDesc;

		m_testName.SetWindowText(name);

		m_testDesc.SetWindowText(desc);

		m_techDetails.SetWindowText(techDetails);

		CRect r;

		m_testName.GetWindowRect(&r);

		RedrawWindow(&r,NULL);

		m_testDesc.GetWindowRect(&r);

		RedrawWindow(&r,NULL);

		m_techDetails.GetWindowRect(&r);

		RedrawWindow(&r,NULL);

	}



	void CleanOutTarget(){

		CRect r;

		m_outTargetMain.GetWindowRect(&r);
		RedrawWindow(&r,NULL);


		if(m_outMode == MULTI_WINDOW){

			m_outTargetLeftWnd1.GetWindowRect(&r);
			RedrawWindow(&r,NULL);

			m_outTargetLeftWnd2.GetWindowRect(&r);
			RedrawWindow(&r,NULL);

		}

	}

	CStatic *GetOutTarget(int targetIndex) { 

		ASSERT(targetIndex < 3 && targetIndex >= 0);
	
		if(m_outMode == SINGLE_WINDOW)
			return &m_outTargetMain;

		switch(targetIndex){

		case 0: //main window
			return &m_outTargetMain;
			break;
		case 1:
			return &m_outTargetLeftWnd1;
			break;
		case 2:
			return &m_outTargetLeftWnd2;
			break;

		}
	}

	void SetFinished(bool finished){ bFinished=finished;}

private:
	void BuildInterface();
	void ExcludeBkRepaint(CDC* pDC,CWnd* pWnd);

	CStatic m_outTargetMain;
	CStatic m_outTargetLeftWnd1;
	CStatic m_outTargetLeftWnd2;
	CFlexGUIButton m_btnCancel;


	CStatic m_currStatus;
	CStatic m_totalStatus;

	CExtProgressCtrl m_currProgress;

	CExtProgressCtrl m_totalProgress;


	CStatic m_infoTitle;
	CStatic m_statusTitle;
	CStatic m_techDetails;

	CStatic m_testName;
	CStatic m_testDesc;
	CStatic m_techDetailsTitle;
	CFont m_fntTitle,m_fntText,m_fntConsole;
	bool bFinished;
	OUT_MODE m_outMode;
	bool m_stopExecutionRequested;


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
	afx_msg void OnBnClickedStopExecution();
	afx_msg void OnSysKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BENCHMARKDLG_H__850943B0_3B0F_4B05_8FEC_904B78202486__INCLUDED_)
