// StaircaseRenderer.h: interface for the CStaircaseRenderer class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_STAIRCASERENDERER_H__4DD32F39_AE4F_4B5B_8D51_FEC349DE9CA4__INCLUDED_)
#define AFX_STAIRCASERENDERER_H__4DD32F39_AE4F_4B5B_8D51_FEC349DE9CA4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "ModelRenderer.h"
#include <GL\gl.h>
#include <GL\glu.h>
#include "benchmarkenvironment.h"

class CStaircaseRenderer : public CModelRenderer  
{
public:
	CStaircaseRenderer();


	void Render(HDC renderDC);
	void RenderUpView(HDC);
	void RenderLeftView(HDC);
	void RenderPerspectiveView(HDC);
	void RenderPerspectiveShadedView(HDC);



	virtual ~CStaircaseRenderer();

};

#endif // !defined(AFX_STAIRCASERENDERER_H__4DD32F39_AE4F_4B5B_8D51_FEC349DE9CA4__INCLUDED_)
