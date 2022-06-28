// OSInfoItemDlg.cpp : implementation file
//

#include "stdafx.h"
#include "CPUBench2004.h"
#include "OSInfoItemDlg.h"
#include "gradient.h"
#include "itembkdrawer.h"
#include "memoryinfo.h"
#include "sysinfodlg.h"
#include "osinformations.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// COSInfoItemDlg dialog


COSInfoItemDlg::COSInfoItemDlg(CWnd* pParent /*=NULL*/)
	: CDialog(COSInfoItemDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(COSInfoItemDlg)
	m_memFreeVal = _T("");
	m_osName = _T("");
	//}}AFX_DATA_INIT
}


void COSInfoItemDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(COSInfoItemDlg)
	DDX_Control(pDX, IDC_MEMFREE, m_memFree);
	DDX_Control(pDX, IDC_MORE, m_osDetails);
	DDX_Text(pDX, IDC_MEMFREEVAL, m_memFreeVal);
	DDX_Text(pDX, IDC_OSNAME, m_osName);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(COSInfoItemDlg, CDialog)
	//{{AFX_MSG_MAP(COSInfoItemDlg)
	ON_WM_ERASEBKGND()
	ON_WM_CTLCOLOR()
	ON_BN_CLICKED(IDC_MORE, OnMore)
	ON_WM_PAINT()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// COSInfoItemDlg message handlers

BOOL COSInfoItemDlg::OnEraseBkgnd(CDC* pDC) 
{



    return TRUE;

}

HBRUSH COSInfoItemDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);
	
	if(nCtlColor == CTLCOLOR_STATIC){

			pDC->SetBkMode(TRANSPARENT);
		//pDC->SetTextColor(RGB(0,0x74,0xDC));
		return (HBRUSH)GetStockObject(NULL_BRUSH);
	}	
	// TODO: Return a different brush if the default is not desired
	return hbr;
}

BOOL COSInfoItemDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	CMemoryInfo memInfo;
	COSInformations osInfo;

	m_memFree.SetRange(0,100);
	m_memFree.SetAlertPos(30);
	m_memFree.SetPos(memInfo.GetRAMAvailablePercent());
	m_memFreeVal=memInfo.GetRAMAvailable();
	m_osName=osInfo.GetOSName()+" ("+osInfo.GetOSRevision()+")";

	UpdateData(FALSE);

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void COSInfoItemDlg::OnMore() 
{
CSysInfoDlg dlg;

dlg.DoModal();	

}

void COSInfoItemDlg::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
	
	CRect r;

	GetClientRect(&r);

	CItemBkDrawer::DrawBk(&dc,&r);
	
	// Do not call CDialog::OnPaint() for painting messages
}
