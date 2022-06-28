// Direct3DBenchmark.h: interface for the CDirect3DBenchmark class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_DIRECT3DBENCHMARK_H__034EC1AF_3C92_4EAE_8F13_5E653336975A__INCLUDED_)
#define AFX_DIRECT3DBENCHMARK_H__034EC1AF_3C92_4EAE_8F13_5E653336975A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "benchmark.h"
#include <d3d9.h>
#include <mmsystem.h>
#include <d3dx9.h>
#include <d3dfile.h>
#include <d3dutil.h>
#include <dxutil.h>
#include <d3dfont.h>


class CDirect3DBenchmark : public CBenchmark 
{
public:

	CDirect3DBenchmark(){

		m_name="Direct3D rendering benchmark";

		m_description="This benchmark measures CPU performance with Direct3D API using software vertex processing.";

	}

	

	void InitBenchmarkData(CBenchmarkEnvironment *e);

	void StartBenchmark(CBenchmarkEnvironment *e);

	float GetBenchmarkResult() { return result; }

	void EndBenchmark() {}



	virtual ~CDirect3DBenchmark();

private:
	LPDIRECT3D9       m_pD3D; 
	LPDIRECT3DDEVICE9 m_pd3dDevice;
	LPD3DXMESH        m_pMesh;
	D3DMATERIAL9*     m_pMeshMaterials ;
	LPDIRECT3DTEXTURE9*     m_pMeshTextures;
	DWORD             m_dwNumMaterials;
	CD3DFont*			  m_font;
	void SetMatrices();


	float result;
};

#endif // !defined(AFX_DIRECT3DBENCHMARK_H__034EC1AF_3C92_4EAE_8F13_5E653336975A__INCLUDED_)
