// DialogBasedItem.h: interface for the CDialogBasedItem class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_DIALOGBASEDITEM_H__ED7AB747_F4F7_4C69_9700_25C5EE10EEDA__INCLUDED_)
#define AFX_DIALOGBASEDITEM_H__ED7AB747_F4F7_4C69_9700_25C5EE10EEDA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "FlexGUIItem.h"

class CDialogBasedItem : public CFlexGUIItem  
{
public:
	CDialogBasedItem();
	virtual ~CDialogBasedItem();
	void SetControlHandle(HWND hWnd){ this->m_hWnd = hWnd; }
	void DrawContent(CDC* pDC);

private:
	HWND m_hWnd;

};

#endif // !defined(AFX_DIALOGBASEDITEM_H__ED7AB747_F4F7_4C69_9700_25C5EE10EEDA__INCLUDED_)
