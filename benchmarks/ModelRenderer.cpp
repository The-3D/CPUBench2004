// ModelRenderer.cpp: implementation of the CModelRenderer class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
//#include "prova CAD benchmark.h"
#include "ModelRenderer.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CModelRenderer::CModelRenderer()
{

}

CModelRenderer::~CModelRenderer()
{

	
}

void CModelRenderer::LoadModel(CString model){

	m_loader.LoadFile(model);
}
