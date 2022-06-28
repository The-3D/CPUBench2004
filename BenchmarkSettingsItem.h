// BenchmarkSettingsItem.h: interface for the CBenchmarkSettingsItem class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_BENCHMARKSETTINGSITEM_H__08E4DB9C_40AC_486B_A673_FE8942F064EB__INCLUDED_)
#define AFX_BENCHMARKSETTINGSITEM_H__08E4DB9C_40AC_486B_A673_FE8942F064EB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "flexguiitem.h"


class CBenchmarkSettingsItem : public CFlexGUIItem  
{
public:
	CBenchmarkSettingsItem();
	void SetControlHandle(HWND hWnd){ this->m_hWnd = hWnd; }
	void DrawContent(CDC* pDC);
	virtual ~CBenchmarkSettingsItem();

private:
	HWND m_hWnd;

};

#endif // !defined(AFX_BENCHMARKSETTINGSITEM_H__08E4DB9C_40AC_486B_A673_FE8942F064EB__INCLUDED_)
