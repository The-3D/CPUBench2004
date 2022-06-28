// HeadRenderer.h: interface for the CHeadRenderer class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_HEADRENDERER_H__1EF6EF5D_A09D_430F_B468_C3C5C171050C__INCLUDED_)
#define AFX_HEADRENDERER_H__1EF6EF5D_A09D_430F_B468_C3C5C171050C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "ModelRenderer.h"

#include <GL\gl.h>
#include <GL\glu.h>

class CHeadRenderer : public CModelRenderer  
{
public:
	CHeadRenderer();
	
	void Render(HDC renderDC);

	virtual ~CHeadRenderer();


protected:
	void RenderWireframeWithAmbient(HDC renderDC);
	void RenderShadedWithLight(HDC renderDC);
	void RenderShadedWithSpecular(HDC renderDC);

};

#endif // !defined(AFX_HEADRENDERER_H__1EF6EF5D_A09D_430F_B468_C3C5C171050C__INCLUDED_)
