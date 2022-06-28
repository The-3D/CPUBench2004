// BenchmarkSettingsDlg.cpp : implementation file
//

#include "stdafx.h"
#include "CPUBench2004.h"
#include "BenchmarkSettingsDlg.h"
#include "gradient.h"
#include "itembkdrawer.h"

#ifdef _DEBUG

#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CBenchmarkSettingsDlg dialog

CBenchmarkSettingsDlg::CBenchmarkSettingsDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CBenchmarkSettingsDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CBenchmarkSettingsDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CBenchmarkSettingsDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CBenchmarkSettingsDlg)
	DDX_Control(pDX, IDC_CONFIGURE, m_configure);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CBenchmarkSettingsDlg, CDialog)
	//{{AFX_MSG_MAP(CBenchmarkSettingsDlg)
	ON_WM_ERASEBKGND()
	ON_WM_CTLCOLOR()
	ON_WM_MOUSEMOVE()
	ON_WM_PAINT()
	ON_BN_CLICKED(IDC_CONFIGURE, OnConfigure)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CBenchmarkSettingsDlg message handlers

BOOL CBenchmarkSettingsDlg::OnEraseBkgnd(CDC* pDC) 
{

	return TRUE;//CDialog::OnEraseBkgnd(pDC);
}

HBRUSH CBenchmarkSettingsDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);

	if(nCtlColor == CTLCOLOR_STATIC){

			pDC->SetBkMode(TRANSPARENT);
		//pDC->SetTextColor(RGB(0,0x74,0xDC));
		return (HBRUSH)GetStockObject(NULL_BRUSH);
	}

return hbr;
}

BOOL CBenchmarkSettingsDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	CFont *tempFont=new CFont;

		
	CFont *pFont=GetFont();

	LOGFONT lf;

	pFont->GetLogFont(&lf);

	lf.lfWeight=FW_BOLD;


	tempFont->CreateFontIndirect(&lf);

	GetDlgItem(IDC_TITLE1)->SetFont(tempFont);
	GetDlgItem(IDC_TITLE3)->SetFont(tempFont);
	GetDlgItem(IDC_TITLE4)->SetFont(tempFont);
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CBenchmarkSettingsDlg::OnMouseMove(UINT nFlags, CPoint point) 
{
	SetFocus();	
	CDialog::OnMouseMove(nFlags, point);
}

void CBenchmarkSettingsDlg::OnPaint() 
{
	
	CPaintDC dc(this); // device context for painting
	
	CRect r;

	GetClientRect(&r);

	CItemBkDrawer::DrawBk(&dc,&r);
	
	// Do not call CDialog::OnPaint() for painting messages
}

void CBenchmarkSettingsDlg::OnConfigure() 
{
	AfxMessageBox("This feature is available in the PRO version only. Visit www.realmark.it/proversion for more informations.",MB_OK | MB_ICONINFORMATION);
	
}
