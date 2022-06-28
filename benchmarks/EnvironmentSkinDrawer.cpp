// EnvironmentSkinDrawer.cpp: implementation of the CEnvironmentSkinDrawer class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "benchmarks.h"
#include "EnvironmentSkinDrawer.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CEnvironmentSkinDrawer::CEnvironmentSkinDrawer(int scrWidth, int scrHeight,int outWidth,int outHeight,int outWndY)
{
	m_screenWidth=scrWidth;
	m_screenHeight=scrHeight;
	m_outWndWidth=outWidth;
	m_outWndHeight=outHeight;
	m_outWndY=outWndY;


	
	m_header.LoadBitmap("header");
	m_right.LoadBitmap("right");
	m_down.LoadBitmap("down");

}


void CEnvironmentSkinDrawer::DrawSkin(CDC* pSrcDC){

	CDC memDC;

	CBitmap memBitmap;

	memBitmap.CreateCompatibleBitmap(pSrcDC,1024,768);

	memDC.CreateCompatibleDC(pSrcDC);

	memDC.SelectObject(&memBitmap);

	//disegno l'header
	memDC.DrawState(CPoint(0,0),CSize(m_screenWidth,m_outWndY),&m_header,DST_BITMAP);

	//disegno il lato di destra
	
	CBrush b;

	b.CreatePatternBrush(&m_right);

	memDC.DrawState(CPoint(0,m_outWndY+m_outWndHeight),CSize(m_outWndWidth+1,m_screenHeight),&m_down,DST_BITMAP);

	memDC.DrawState(CPoint(m_outWndWidth,m_outWndY),CSize(m_screenWidth,m_screenHeight),&m_right,DST_BITMAP);

	pSrcDC->BitBlt(0,0,1024,768,&memDC,0,0,SRCCOPY);

	b.DeleteObject();

	memBitmap.DeleteObject();
	memDC.DeleteDC();

}




CEnvironmentSkinDrawer::~CEnvironmentSkinDrawer()
{

	m_header.DeleteObject();
	m_right.DeleteObject();
	m_down.DeleteObject();

}
