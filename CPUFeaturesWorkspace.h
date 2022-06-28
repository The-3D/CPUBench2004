// CPUFeaturesWorkspace.h: interface for the CCPUFeaturesWorkspace class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CPUFEATURESWORKSPACE_H__C029E86F_0A4F_4A68_9684_95501D96DE8A__INCLUDED_)
#define AFX_CPUFEATURESWORKSPACE_H__C029E86F_0A4F_4A68_9684_95501D96DE8A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "FlexGUIWorkspace.h"
#include "cpufeaturesitem.h"

class CCPUFeaturesWorkspace : public CFlexGUIWorkspace  
{
public:
	CCPUFeaturesWorkspace();

	void BuildInterface();

	virtual ~CCPUFeaturesWorkspace();

private:
	CCPUFeaturesItem i;

};

#endif // !defined(AFX_CPUFEATURESWORKSPACE_H__C029E86F_0A4F_4A68_9684_95501D96DE8A__INCLUDED_)
