// SysInfoWorkspace.cpp: implementation of the CSysInfoWorkspace class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "CPUBench2004.h"
#include "SysInfoWorkspace.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CSysInfoWorkspace::CSysInfoWorkspace()
{

}

CSysInfoWorkspace::~CSysInfoWorkspace()
{
}


void CSysInfoWorkspace::BuildInterface(){

	cpuDlg.Create(IDD_EXTCPUINFOITEMDLG_DIALOG,m_pParent);
	memDlg.Create(IDD_EXTMEMORYINFODLG_DIALOG,m_pParent);
	mbDlg.Create(IDD_EXTMBINFODLG_DIALOG,m_pParent);
	osDlg.Create(IDD_EXTOSINFODLG_DIALOG,m_pParent);


	i.SetCaptionString("Advanced CPU informations");

	i.SetControlHandle(cpuDlg.m_hWnd);

	CRect r2;

	r2.top=m_guiRect.top+8;
	r2.left=m_guiRect.left+8;
	r2.right=m_guiRect.right-300;
	r2.bottom=m_guiRect.bottom-203;

	i.SetOriginAndSize(r2.left,r2.top,r2.Width());

	i.SetSize(r2.Height());


	i2.SetCaptionString("Memory informations");

	i2.SetControlHandle(memDlg.m_hWnd);

	r2.top=m_guiRect.top+8;
	r2.left=m_guiRect.right-292;
	r2.right=m_guiRect.right-8;
	r2.bottom=m_guiRect.bottom-283;

	i2.SetOriginAndSize(r2.left,r2.top,r2.Width());

	i2.SetSize(r2.Height());


	i3.SetCaptionString("Motherboard informations");

	i3.SetControlHandle(mbDlg.m_hWnd);

	r2.top=m_guiRect.bottom-167;
	r2.left=m_guiRect.left+8;
	r2.right=m_guiRect.right-300;
	r2.bottom=m_guiRect.bottom-34;

	i3.SetOriginAndSize(r2.left,r2.top,r2.Width());

	i3.SetSize(r2.Height());

	i4.SetCaptionString("OS informations");

	i4.SetControlHandle(osDlg.m_hWnd);

	r2.top=m_guiRect.bottom-247;
	r2.left=m_guiRect.right-292;
	r2.right=m_guiRect.right-8;
	r2.bottom=m_guiRect.bottom-68;

	i4.SetOriginAndSize(r2.left,r2.top,r2.Width());

	i4.SetSize(r2.Height());



	AddItem(&i);
	AddItem(&i2);
	AddItem(&i3);
	AddItem(&i4);


}

void CSysInfoWorkspace::Update(){

	cpuDlg.Update();
	mbDlg.Update();
	memDlg.Update();

}