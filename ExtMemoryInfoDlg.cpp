// ExtMemoryInfoDlg.cpp : implementation file
//

#include "stdafx.h"
#include "CPUBench2004.h"
#include "ExtMemoryInfoDlg.h"
#include "itembkdrawer.h"
#include "memoryinfo.h"



#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CExtMemoryInfoDlg dialog


CExtMemoryInfoDlg::CExtMemoryInfoDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CExtMemoryInfoDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CExtMemoryInfoDlg)
	m_memLoadVal = _T("");
	m_pageFreeVal = _T("");
	m_ramFreeVal = _T("");
	m_userFreeVal = _T("");
	m_pageSize = _T("");
	m_physMem = _T("");
	m_virtualSize = _T("");
	//}}AFX_DATA_INIT
}


void CExtMemoryInfoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CExtMemoryInfoDlg)
	DDX_Control(pDX, IDC_USERFREE, m_userFree);
	DDX_Control(pDX, IDC_TOTALLOAD, m_totalLoad);
	DDX_Control(pDX, IDC_RAMFREE, m_ramFree);
	DDX_Control(pDX, IDC_PAGEFILEFREE, m_pageFileFree);
	DDX_Text(pDX, IDC_MEMLOAD, m_memLoadVal);
	DDX_Text(pDX, IDC_PAGEFREE, m_pageFreeVal);
	DDX_Text(pDX, IDC_RAMFREEPERCENT, m_ramFreeVal);
	DDX_Text(pDX, IDC_USERFREEPERCENT, m_userFreeVal);
	DDX_Text(pDX, IDC_PAGESIZE, m_pageSize);
	DDX_Text(pDX, IDC_PHYSMEM, m_physMem);
	DDX_Text(pDX, IDC_VIRTUALSIZE, m_virtualSize);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CExtMemoryInfoDlg, CDialog)
	//{{AFX_MSG_MAP(CExtMemoryInfoDlg)
	ON_WM_ERASEBKGND()
	ON_WM_CTLCOLOR()
	ON_WM_PAINT()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CExtMemoryInfoDlg message handlers

BOOL CExtMemoryInfoDlg::OnEraseBkgnd(CDC* pDC) 
{
	return TRUE;
}

HBRUSH CExtMemoryInfoDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);
	
	if(nCtlColor == CTLCOLOR_STATIC){

			pDC->SetBkMode(TRANSPARENT);
		//pDC->SetTextColor(RGB(0,0x74,0xDC));
		return (HBRUSH)GetStockObject(NULL_BRUSH);
	}
	
	return hbr;
}

BOOL CExtMemoryInfoDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();

	CMemoryInfo memInfo;
	
	m_userFree.SetRange(0,100);
	m_ramFree.SetRange(0,100);
	m_totalLoad.SetRange(0,100);
	m_pageFileFree.SetRange(0,100);

	m_ramFree.SetAlertPos(30);

	m_totalLoad.SetAlertPos(80,FALSE);

	m_userFree.SetPos(12);
	m_ramFree.SetPos(memInfo.GetRAMAvailablePercent());
	m_totalLoad.SetPos(memInfo.GetMemLoadPercent());
	m_pageFileFree.SetPos(memInfo.GetPageFileAvailablePercent());
	m_userFree.SetPos(memInfo.GetVirtualAvailablePercent());

	m_memLoadVal.Format("%d%c",memInfo.GetMemLoadPercent(),'%');
	m_pageFreeVal.Format("%d%c",memInfo.GetPageFileAvailablePercent(),'%');
	m_ramFreeVal=memInfo.GetRAMAvailable();
	m_userFreeVal.Format("%d%c",memInfo.GetVirtualAvailablePercent(),'%');

	m_pageSize=memInfo.GetPageFileSize();
	m_physMem=memInfo.GetRAMSize();
	m_virtualSize=memInfo.GetVirtualSize();
	


	UpdateData(FALSE);

	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CExtMemoryInfoDlg::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
	
	CRect r;

	GetClientRect(&r);

	CItemBkDrawer::DrawBk(&dc,&r);
	
	// Do not call CDialog::OnPaint() for painting messages
}



void CExtMemoryInfoDlg::Update(){

	CMemoryInfo memInfo;
	


	m_ramFree.SetPos(memInfo.GetRAMAvailablePercent());
	m_totalLoad.SetPos(memInfo.GetMemLoadPercent());
	m_pageFileFree.SetPos(memInfo.GetPageFileAvailablePercent());
	m_userFree.SetPos(memInfo.GetVirtualAvailablePercent());

	m_memLoadVal.Format("%d%c",memInfo.GetMemLoadPercent(),'%');
	m_pageFreeVal.Format("%d%c",memInfo.GetPageFileAvailablePercent(),'%');
	m_ramFreeVal=memInfo.GetRAMAvailable();
	m_userFreeVal.Format("%d%c",memInfo.GetVirtualAvailablePercent(),'%');

	m_pageSize=memInfo.GetPageFileSize();

	UpdateData(FALSE);

	Invalidate();

}
