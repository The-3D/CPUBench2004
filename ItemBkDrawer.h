// ItemBkDrawer.h: interface for the CItemBkDrawer class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_ITEMBKDRAWER_H__B176392E_F190_47A6_833A_036C5A4621F6__INCLUDED_)
#define AFX_ITEMBKDRAWER_H__B176392E_F190_47A6_833A_036C5A4621F6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CItemBkDrawer  
{
public:
	CItemBkDrawer();

	static void DrawBk(CDC* dc,CRect *r);

	virtual ~CItemBkDrawer();


};

#endif // !defined(AFX_ITEMBKDRAWER_H__B176392E_F190_47A6_833A_036C5A4621F6__INCLUDED_)
