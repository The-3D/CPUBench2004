// CPUFeaturesWorkspace.cpp: implementation of the CCPUFeaturesWorkspace class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "CPUBench2004.h"
#include "CPUFeaturesWorkspace.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CCPUFeaturesWorkspace::CCPUFeaturesWorkspace()
{

}

CCPUFeaturesWorkspace::~CCPUFeaturesWorkspace()
{

}


void CCPUFeaturesWorkspace::BuildInterface(){

	i.SetCaptionString("CPU Features description");

	CRect r;

	r.top=m_guiRect.top+8;
	r.left=m_guiRect.left+8;
	r.right=m_guiRect.right-8;
	r.bottom=m_guiRect.bottom-70;

	i.SetOriginAndSize(r.left,r.top,r.Width());

	i.SetSize(r.Height());


	AddItem(&i);

}
