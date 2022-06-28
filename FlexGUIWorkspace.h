// FlexGUIWorkspace.h: interface for the CFlexGUIWorkspace class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_FLEXGUIWORKSPACE_H__5A688EC9_2BBB_4998_A120_C1C340D1863D__INCLUDED_)
#define AFX_FLEXGUIWORKSPACE_H__5A688EC9_2BBB_4998_A120_C1C340D1863D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include <afxtempl.h>
#include "FlexGUIItem.h"
#include "osinfoitemdlg.h"
#include "cpuinfoitemdlg.h"
#include "benchmarksettingsdlg.h"
#include "benchmarkresultitem.h"
#include "benchmarksettingsitem.h"
#include "dialogbaseditem.h"
#include "workspacebkdrawer.h"



class CFlexGUIWorkspace  
{
public:
	CFlexGUIWorkspace();
	CFlexGUIWorkspace(CRect* r);


	void SetCtrlRect(CRect *r){
		
		m_guiRect.CopyRect(*r);
	}

/*	void SetBk(CString bk){

		m_bk=bk;

	}
	
*/


	void AddItem(CFlexGUIItem* i){

		m_items.Add(i);
	}

	void Draw(CDC* srcDC);
	
	
	
	virtual ~CFlexGUIWorkspace();

protected:
	CRect m_guiRect;
	CArray<CFlexGUIItem*,CFlexGUIItem*> m_items;
	CWorkspaceBkDrawer *m_bkDrawer;

};

#endif // !defined(AFX_FLEXGUIWORKSPACE_H__5A688EC9_2BBB_4998_A120_C1C340D1863D__INCLUDED_)
