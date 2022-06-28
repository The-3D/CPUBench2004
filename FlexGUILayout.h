// FlexGUILayout.h: interface for the CFlexGUILayout class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_FLEXGUILAYOUT_H__D0ECF41D_5061_4662_B1DE_DC76C1C0451B__INCLUDED_)
#define AFX_FLEXGUILAYOUT_H__D0ECF41D_5061_4662_B1DE_DC76C1C0451B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "FlexGUIItem.h"

class CFlexGUILayout  
{
public:
	CFlexGUILayout();

	virtual void AddItem(CFlexGUIItem* item) =0;
	virtual void Draw(CDC* pDC) =0;
	virtual ~CFlexGUILayout();
	void SetLayoutArea(CRect* r);


private:
	CRect m_layoutArea;

};

#endif // !defined(AFX_FLEXGUILAYOUT_H__D0ECF41D_5061_4662_B1DE_DC76C1C0451B__INCLUDED_)
