// FlexGUIWorkspace.cpp: implementation of the CFlexGUIWorkspace class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "CPUBench2004.h"
#include "FlexGUIWorkspace.h"
#include "workspacebkdrawer.h"




#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CFlexGUIWorkspace::CFlexGUIWorkspace()
{

	m_bkDrawer=new CWorkspaceBkDrawer(".\\skindata\\skindata2.bmp");

}

CFlexGUIWorkspace::~CFlexGUIWorkspace()
{

	delete m_bkDrawer;
}

void CFlexGUIWorkspace::Draw(CDC* srcDC){

	CDC memDC;

	memDC.CreateCompatibleDC(srcDC);

	CBitmap memBitmap;

	memBitmap.CreateCompatibleBitmap(srcDC,m_guiRect.Width(),m_guiRect.Height());


	memDC.SelectObject(&memBitmap);


	m_bkDrawer->DrawBk(&memDC,&m_guiRect);

	for(int i=0; i<m_items.GetSize(); i++){

		m_items[i]->DrawItem(&memDC);
	}

	srcDC->BitBlt(m_guiRect.left,m_guiRect.top,m_guiRect.right,m_guiRect.bottom,&memDC,0,0,SRCCOPY);

}





