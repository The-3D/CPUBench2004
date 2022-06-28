// DialogBasedItem.cpp: implementation of the CDialogBasedItem class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "CPUBench2004.h"
#include "DialogBasedItem.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CDialogBasedItem::CDialogBasedItem()
{
	this->bRequireBk=false;

}

CDialogBasedItem::~CDialogBasedItem()
{

}

void CDialogBasedItem::DrawContent(CDC* pDC){

	//non si usa il DC - il controllo è legato alla dialog

	::SetWindowPos(m_hWnd, NULL,itemRect.left, itemRect.top, itemRect.Width()+1, itemRect.Height(),SWP_NOZORDER);

	if (!::IsWindowVisible(m_hWnd)) ::ShowWindow(m_hWnd, SW_SHOW);

}