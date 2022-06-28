// MainWorkspace.cpp: implementation of the CMainWorkspace class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "CPUBench2004.h"
#include "MainWorkspace.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CMainWorkspace::CMainWorkspace()
{

}

CMainWorkspace::~CMainWorkspace()
{

}
void CMainWorkspace::BuildInterface(){

	// TODO: Add extra initialization here

	m_settingsDlg.Create(IDD_BENCHMARKSETTINGSDLG_DIALOG);


	i3.SetCaptionString("Benchmark settings");
	i3.SetControlHandle(m_settingsDlg.m_hWnd);
	i3.SetOriginAndSize(6,186,280);
	i3.SetSize(225);

	m_cpuDlg.Create(IDD_CPUINFOITEMDLG_DIALOG);

	i.SetCaptionString("CPU Informations");
	i.SetControlHandle(m_cpuDlg.m_hWnd);
	i.SetOriginAndSize(6+280+6,90,317);
	i.SetSize(383);

	m_osDlg.Create(IDD_OSINFOITEMDLG_DIALOG);

	i2.SetCaptionString("System details");
	i2.SetOriginAndSize(6,444,280);
	i2.SetSize(64);
	i2.SetControlHandle(m_osDlg.m_hWnd);




	i4.SetCaptionString("Benchmark results");
	i4.SetOriginAndSize(6,90,280);
	i4.SetSize(63);

	AddItem(&i);
	AddItem(&i2);
	AddItem(&i3);
	AddItem(&i4);

}
