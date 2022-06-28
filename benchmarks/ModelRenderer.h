// ModelRenderer.h: interface for the CModelRenderer class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MODELRENDERER_H__1216C629_792A_4C5A_B62E_965EC39C1202__INCLUDED_)
#define AFX_MODELRENDERER_H__1216C629_792A_4C5A_B62E_965EC39C1202__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "l3ds.h"

class CModelRenderer  
{
public:
	CModelRenderer();

	void LoadModel(CString model);
	virtual void Render(HDC renderDC) =0;


	virtual ~CModelRenderer();


protected:
	L3DS m_loader;


};

#endif // !defined(AFX_MODELRENDERER_H__1216C629_792A_4C5A_B62E_965EC39C1202__INCLUDED_)
