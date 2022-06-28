// BenchmarkStatusDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Benchmarksintel.h"
#include "BenchmarkStatusDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CBenchmarkStatusDlg dialog


CBenchmarkStatusDlg::CBenchmarkStatusDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CBenchmarkStatusDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CBenchmarkStatusDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CBenchmarkStatusDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CBenchmarkStatusDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CBenchmarkStatusDlg, CDialog)
	//{{AFX_MSG_MAP(CBenchmarkStatusDlg)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CBenchmarkStatusDlg message handlers
