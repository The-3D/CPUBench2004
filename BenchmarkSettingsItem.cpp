// BenchmarkSettingsItem.cpp: implementation of the CBenchmarkSettingsItem class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "CPUBench2004.h"
#include "BenchmarkSettingsItem.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CBenchmarkSettingsItem::CBenchmarkSettingsItem()
{

}

CBenchmarkSettingsItem::~CBenchmarkSettingsItem()
{

}


void CBenchmarkSettingsItem::DrawContent(CDC* pDC){

	//non si usa il DC - il controllo è legato alla dialog

	::SetWindowPos(m_hWnd, NULL,itemRect.left, itemRect.top, itemRect.Width(), itemRect.Height(), SWP_NOZORDER);

	if (!::IsWindowVisible(m_hWnd)) ::ShowWindow(m_hWnd, SW_SHOW);
	
	this->bRequireBk=false;

}