// ItemBkDrawer.cpp: implementation of the CItemBkDrawer class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "CPUBench2004.h"
#include "ItemBkDrawer.h"
#include "gradient.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CItemBkDrawer::CItemBkDrawer()
{

}

CItemBkDrawer::~CItemBkDrawer()
{

}


void CItemBkDrawer::DrawBk(CDC* pDC,CRect *r){


//	CDC memDC;


//	pDC->CreateCompatibleDC(pDC);

//	CBitmap memBitmap;

//	memBitmap.CreateCompatibleBitmap(pDC,r->Width(),r->Height());


//	pDC->SelectObject(&memBitmap);

	CGradient g;

	g.SetGradientColors(RGB(0xE3,0xE3,0xEC),RGB(255,255,255));

	g.SetDirection(g.BTT);

	g.DrawLinearGradient(pDC,*r);

	CGdiObject *pOb=pDC->SelectObject(new CPen(PS_SOLID,1,RGB(0x70,0x6F,0x91)));

	pDC->MoveTo(r->left,r->top);
	pDC->LineTo(r->left,r->bottom-1);
	pDC->LineTo(r->right-1,r->bottom-1);
	pDC->LineTo(r->right-1,r->top-1);

//	pDC->BitBlt(r->left,r->top,r->Width(),r->Height(),&memDC,0,0,SRCCOPY);

}

