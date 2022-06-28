// ExtProgress.cpp : implementation file
//

#include "stdafx.h"
#include "ExtProgressCtrl.h"
#include "..\gradient.h"
#include "math.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CExtProgress

CExtProgressCtrl::CExtProgressCtrl()
{

	m_alertPos=0;
	m_bLessThan=TRUE;

}

CExtProgressCtrl::~CExtProgressCtrl()
{
}


BEGIN_MESSAGE_MAP(CExtProgressCtrl, CProgressCtrl)
	//{{AFX_MSG_MAP(CExtProgressCtrl)
	ON_WM_ERASEBKGND()
	ON_WM_DRAWITEM()
	ON_WM_NCPAINT()
	ON_WM_PAINT()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CExtProgress message handlers

BOOL CExtProgressCtrl::OnEraseBkgnd(CDC* pDC) 
{


	CRect r;

	GetClientRect(&r);


	CGradient g;

	g.SetGradientColors(RGB(255,255,255),RGB(255,255,255));

	g.SetDirection(CGradient::TTB);

	g.DrawLinearGradient(pDC,CRect(r.left+1,r.top+3,r.right-2,r.bottom-4));
	g.SetGradientColors(RGB(255,255,255),RGB(230,230,224));

	g.SetDirection(CGradient::TTB);

	g.DrawLinearGradient(pDC,CRect(r.left+1,r.bottom-4,r.right-2,r.bottom-2));

	g.SetGradientColors(RGB(200,200,194),RGB(255,255,255));
		
	g.SetDirection(CGradient::TTB);

	g.DrawLinearGradient(pDC,CRect(r.left+1,r.top,r.right-2,r.top+3));

	CPen p1(PS_SOLID,1,RGB(0,60,116));
	CPen p2(PS_SOLID,1,RGB(104,136,160));
	CPen p3(PS_SOLID,1,RGB(191,206,220));

	pDC->SelectObject(&p1);

	pDC->MoveTo(r.left+1,r.top);
	pDC->LineTo(r.right-2,r.top);
	pDC->SelectObject(&p2);
	pDC->LineTo(r.right-2,r.top);
	pDC->LineTo(r.right-2,r.top+1);
	pDC->LineTo(r.right-1,r.top+1);
	pDC->SelectObject(&p1);
	pDC->LineTo(r.right-1,r.bottom-2);
	pDC->SelectObject(&p2);
	pDC->LineTo(r.right-1,r.bottom-2);
	pDC->LineTo(r.right-2,r.bottom-2);
	pDC->LineTo(r.right-2,r.bottom-1);
	pDC->SelectObject(&p1);
	pDC->LineTo(r.left+1,r.bottom-1);
	pDC->SelectObject(&p2);
	pDC->LineTo(r.left+1,r.bottom-1);
	pDC->LineTo(r.left+1,r.bottom-2);
	pDC->LineTo(r.left,r.bottom-2);
	pDC->SelectObject(&p1);
	pDC->LineTo(r.left,r.top+1);
	pDC->SelectObject(&p2);
	pDC->LineTo(r.left,r.top+1);
	pDC->LineTo(r.left+1,r.top+1);
	pDC->LineTo(r.left+1,r.top);
	//angoli

	pDC->SetPixel(r.right-3,r.top+1,RGB(191,206,220));
	pDC->SetPixel(r.right-2,r.top+2,RGB(191,206,220));

	pDC->SetPixel(r.right-2,r.bottom-3,RGB(191,206,220));
	pDC->SetPixel(r.right-3,r.bottom-2,RGB(191,206,220));

	pDC->SetPixel(r.left+1,r.bottom-3,RGB(191,206,220));
	pDC->SetPixel(r.left+2,r.bottom-2,RGB(191,206,220));

	pDC->SetPixel(r.left+1,r.top+2,RGB(191,206,220));
	pDC->SetPixel(r.left+2,r.top+1,RGB(191,206,220));
	
	return TRUE;//CProgressCtrl::OnEraseBkgnd(pDC);
}

void CExtProgressCtrl::OnDrawItem(int nIDCtl, LPDRAWITEMSTRUCT lpDrawItemStruct) 
{
	// TODO: Add your message handler code here and/or call default
	
	CProgressCtrl::OnDrawItem(nIDCtl, lpDrawItemStruct);
}

void CExtProgressCtrl::OnNcPaint() 
{



	// Do not call CProgressCtrl::OnNcPaint() for painting messages
}

void CExtProgressCtrl::OnPaint() 
{
	CPaintDC dc(this); // device context for painting

	CRect r;

	GetClientRect(&r);


	CGradient g1,g2,g3,g4;

//	g1.SetGradientColors(RGB(171,237,172),RGB(46,211,49));
//	g2.SetGradientColors(RGB(46,211,49),RGB(171,237,172));

	g1.SetGradientColors(RGB(171,172,237),RGB(46,49,211));
	g2.SetGradientColors(RGB(46,49,211),RGB(171,172,237));

	g1.SetDirection(g1.TTB);
	g2.SetDirection(g2.TTB);

	g3.SetGradientColors(RGB(237,171,172),RGB(211,46,49));
	g4.SetGradientColors(RGB(211,46,49),RGB(237,171,172));

	g3.SetDirection(g3.TTB);
	g4.SetDirection(g4.TTB);


	int lower,upper,pos;

	GetRange(lower,upper);
	pos=GetPos();




	//normalizzo il range e la posizione

	int size=upper-lower;

	pos=pos-lower;

	int aPos=m_alertPos-lower;


	float percentage=(float)pos/(float)size;


	int totalCtrlSize=r.right-r.left-6; //9 pixel rimangono di spazio tra i 10 step
	float progressVal=totalCtrlSize*percentage;

	if((m_bLessThan && pos < aPos) || (!m_bLessThan) && (pos > aPos)){

		g3.DrawLinearGradient(&dc,CRect(r.left+3,r.top+3,(int)(r.left+3+progressVal),(r.bottom-2)/2));
		g4.DrawLinearGradient(&dc,CRect(r.left+3,(r.bottom-2)/2,(int)(r.left+3+progressVal),r.bottom-3));

	}

	else{

		g1.DrawLinearGradient(&dc,CRect(r.left+3,r.top+3,(int)(r.left+3+progressVal),(r.bottom-2)/2));
		g2.DrawLinearGradient(&dc,CRect(r.left+3,(r.bottom-2)/2,(int)(r.left+3+progressVal),r.bottom-3));
	}

}
