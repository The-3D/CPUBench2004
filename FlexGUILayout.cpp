// FlexGUILayout.cpp: implementation of the CFlexGUILayout class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "CPUBench2004.h"
#include "FlexGUILayout.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CFlexGUILayout::CFlexGUILayout()
{

}

CFlexGUILayout::~CFlexGUILayout()
{

}


void CFlexGUILayout::SetLayoutArea(CRect* r){

	m_layoutArea.CopyRect(r);

}
