// D3DAnimatedMesh.h: interface for the CD3DAnimatedMesh class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_D3DANIMATEDMESH_H__25B00C55_2087_4FCD_84C6_F6FF18D34F11__INCLUDED_)
#define AFX_D3DANIMATEDMESH_H__25B00C55_2087_4FCD_84C6_F6FF18D34F11__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <d3dx9.h>
#include <d3dfile.h>
#include <d3dutil.h>
#include <dxutil.h>




// enum for various skinning modes possible
enum METHOD 
{
    D3DNONINDEXED,
    D3DINDEXED,
    SOFTWARE,
    D3DINDEXEDVS,
    D3DINDEXEDHLSLVS,
    NONE
};


//-----------------------------------------------------------------------------
// Name: struct D3DXFRAME_DERIVED
// Desc: Structure derived from D3DXFRAME so we can add some app-specific
//       info that will be stored with each frame
//-----------------------------------------------------------------------------
struct D3DXFRAME_DERIVED: public D3DXFRAME
{
    D3DXMATRIXA16        CombinedTransformationMatrix;
};


//-----------------------------------------------------------------------------
// Name: struct D3DXMESHCONTAINER_DERIVED
// Desc: Structure derived from D3DXMESHCONTAINER so we can add some app-specific
//       info that will be stored with each mesh
//-----------------------------------------------------------------------------
struct D3DXMESHCONTAINER_DERIVED: public D3DXMESHCONTAINER
{
    LPDIRECT3DTEXTURE9*  ppTextures;       // array of textures, entries are NULL if no texture specified    
                                
    // SkinMesh info             
    LPD3DXMESH           pOrigMesh;
    LPD3DXATTRIBUTERANGE pAttributeTable;
    DWORD                NumAttributeGroups; 
    DWORD                NumInfl;
    LPD3DXBUFFER         pBoneCombinationBuf;
    D3DXMATRIX**         ppBoneMatrixPtrs;
    D3DXMATRIX*          pBoneOffsetMatrices;
    DWORD                NumPaletteEntries;
    bool                 UseSoftwareVP;
    DWORD                iAttributeSW;     // used to denote the split between SW and HW if necessary for non-indexed skinning
};



class CD3DAnimatedMesh  
{

public:

	CD3DAnimatedMesh(LPDIRECT3DDEVICE9 d3dDevice);
    bool LoadMesh(CString meshName);
	void UpdateAnimationMatrices(LPD3DXMATRIX pWorldMatrix);
	void Render();
	void GenerateSkinnedMesh(D3DXMESHCONTAINER_DERIVED *pContainer);
	
	int GetNumVertices(){

		if(bLoaded)
			return m_pFrameRoot->pMeshContainer->MeshData.pMesh->GetNumVertices();
	
		return 0;

	}


	virtual ~CD3DAnimatedMesh();


private:
	HRESULT SetupBoneMatrixPointers(LPD3DXFRAME pFrame);
	HRESULT SetupBoneMatrixPointersOnMesh(LPD3DXMESHCONTAINER pMeshContainer);
	void DrawMeshContainer(LPD3DXMESHCONTAINER pMeshContainer,LPD3DXFRAME pFrame);
	void DrawFrame(LPD3DXFRAME pFrame);
	void UpdateFrameMatrices(LPD3DXFRAME pFrameBase, LPD3DXMATRIX pParentMatrix);
private:
	LPDIRECT3DDEVICE9 m_pd3dDevice;
	METHOD m_SkinningMethod;
	LPD3DXFRAME m_pFrameRoot;
	LPD3DXANIMATIONCONTROLLER m_pAnimController;
	D3DCAPS9 m_d3dCaps;
	bool bLoaded;

};


#endif // !defined(AFX_D3DANIMATEDMESH_H__25B00C55_2087_4FCD_84C6_F6FF18D34F11__INCLUDED_)
