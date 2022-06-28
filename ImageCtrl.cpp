// ImageCtrl.cpp : implementation file
//

#include "stdafx.h"
#include "CPUBench2004.h"
#include "ImageCtrl.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CImageCtrl

CImageCtrl::CImageCtrl()
{
	bLoaded=false;
}

CImageCtrl::~CImageCtrl()
{

	bmp.DeleteObject();
}

void CImageCtrl::LoadImage(CString str) {

	if(!bLoaded) {
		bmp.LoadBitmap(str);
		bLoaded=true;
	}

}


BEGIN_MESSAGE_MAP(CImageCtrl, CStatic)
	//{{AFX_MSG_MAP(CImageCtrl)
	ON_WM_PAINT()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CImageCtrl message handlers

void CImageCtrl::OnPaint() 
{
	CPaintDC dc(this); // device context for painting

	CRect rect;

	GetWindowRect(&rect);


	dc.DrawState(CPoint(0,0),CSize(rect.Width(),rect.Height()),&bmp,DST_BITMAP);
	

	CPen p(PS_SOLID,1,RGB(128,128,141));

	CGdiObject *pOb=dc.SelectObject(&p);
	
	dc.MoveTo(0,0);
	dc.LineTo(rect.Width(),0);
	dc.LineTo(rect.Width(),rect.Height());
	dc.LineTo(0,rect.Height());
	dc.LineTo(0,0);

	dc.SelectObject(pOb);


	// Do not call CStatic::OnPaint() for painting messages
}
