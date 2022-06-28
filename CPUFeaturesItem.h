// CPUFeaturesItem.h: interface for the CCPUFeaturesItem class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CPUFEATURESITEM_H__B05CEA3D_0FE1_4F7E_85E6_F421C1D185B5__INCLUDED_)
#define AFX_CPUFEATURESITEM_H__B05CEA3D_0FE1_4F7E_85E6_F421C1D185B5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "FlexGUIItem.h"

class CCPUFeaturesItem : public CFlexGUIItem  
{
public:
	CCPUFeaturesItem();
	void DrawContent(CDC* pDC);
	virtual ~CCPUFeaturesItem();

private:
	CString *genericFeatures;
	CString *featureValues;
	CString title;

};

#endif // !defined(AFX_CPUFEATURESITEM_H__B05CEA3D_0FE1_4F7E_85E6_F421C1D185B5__INCLUDED_)
