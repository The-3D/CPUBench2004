// HeadWithColumnLayout.h: interface for the CHeadWithColumnLayout class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_HEADWITHCOLUMNLAYOUT_H__DF68D744_0AED_440A_AC49_1FEB682015DF__INCLUDED_)
#define AFX_HEADWITHCOLUMNLAYOUT_H__DF68D744_0AED_440A_AC49_1FEB682015DF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "FlexGUILayout.h"

class CHeadWithColumnLayout : public CFlexGUILayout  
{
public:
	CHeadWithColumnLayout();
	void AddItem(CFlexGUIItem* item);

	virtual ~CHeadWithColumnLayout();

};

#endif // !defined(AFX_HEADWITHCOLUMNLAYOUT_H__DF68D744_0AED_440A_AC49_1FEB682015DF__INCLUDED_)
