// CPUBench2004Dlg.h : header file
//

#if !defined(AFX_CPUBENCH2004DLG_H__51268E68_5154_4745_BCB1_D94455950B17__INCLUDED_)
#define AFX_CPUBENCH2004DLG_H__51268E68_5154_4745_BCB1_D94455950B17__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CCPUBench2004Dlg dialog
#include "mainworkspace.h"
#include "benchmarkresultitem.h"
#include "benchmarksettingsdlg.h"
#include "cpuinfoitemdlg.h"
#include "flexguibutton.h"
#include "dialogbaseditem.h"
#include "osinfoitemdlg.h"
#include "imagectrl.h"



class CCPUBench2004Dlg : public CDialog
{
// Construction
public:
	CCPUBench2004Dlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CCPUBench2004Dlg)
	enum { IDD = IDD_CPUBENCH2004_DIALOG };
	CImageCtrl	m_logo;
	CFlexGUIButton	m_exit;
	CFlexGUIButton	m_bHelp;
	CFlexGUIButton	m_bRun;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCPUBench2004Dlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;
	CMainWorkspace w;
	CDialogBasedItem i;
	CBenchmarkSettingsDlg dlg;
	CCPUInfoItemDlg cpuDlg;
	COSInfoItemDlg osDlg;

	// Generated message map functions
	//{{AFX_MSG(CCPUBench2004Dlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnExit();
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnRunbenchmark();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CPUBENCH2004DLG_H__51268E68_5154_4745_BCB1_D94455950B17__INCLUDED_)
