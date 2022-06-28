// SysInfoDlg.cpp : implementation file
//

#include "stdafx.h"
#include "CPUBench2004.h"
#include "SysInfoDlg.h"
#include "reportdlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSysInfoDlg dialog


CSysInfoDlg::CSysInfoDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CSysInfoDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSysInfoDlg)
	//}}AFX_DATA_INIT
}


void CSysInfoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSysInfoDlg)
	DDX_Control(pDX, IDC_CREATEREPORT, m_report);
	DDX_Control(pDX, IDC_UPDATE, m_customize);
	DDX_Control(pDX, IDOK, m_ok);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CSysInfoDlg, CDialog)
	//{{AFX_MSG_MAP(CSysInfoDlg)
	ON_WM_PAINT()
	ON_BN_CLICKED(IDC_CREATEREPORT, OnCreatereport)
	ON_BN_CLICKED(IDC_UPDATE, OnUpdate)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSysInfoDlg message handlers

BOOL CSysInfoDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	

	CRect r;

	GetClientRect(&r);


	w.SetCtrlRect(&r);

	w.SetParent(this);

	w.BuildInterface();

	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CSysInfoDlg::OnPaint() 
{
	CPaintDC dc(this); // device context for painting


	w.Draw(&dc);

	// Do not call CDialog::OnPaint() for painting messages
}

void CSysInfoDlg::OnCreatereport() 
{

	CReportDlg dlg;

	dlg.DoModal();
	
	
}

void CSysInfoDlg::OnUpdate() 
{


	w.Update();
	
}
