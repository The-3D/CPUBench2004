// AllocationHierarchy.h: interface for the CAllocationHierarchy class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_ALLOCATIONHIERARCHY_H__7D1A12BC_EF41_4964_8890_F312830EC4DD__INCLUDED_)
#define AFX_ALLOCATIONHIERARCHY_H__7D1A12BC_EF41_4964_8890_F312830EC4DD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "d3danimatedmesh.h"

class CAllocationHierarchy: public ID3DXAllocateHierarchy
{
public:
    STDMETHOD(CreateFrame)(THIS_ LPCTSTR Name, LPD3DXFRAME *ppNewFrame);
    STDMETHOD(CreateMeshContainer)(THIS_ LPCTSTR Name, LPD3DXMESHDATA pMeshData,
                            LPD3DXMATERIAL pMaterials, LPD3DXEFFECTINSTANCE pEffectInstances, DWORD NumMaterials, 
                            DWORD *pAdjacency, LPD3DXSKININFO pSkinInfo, 
                            LPD3DXMESHCONTAINER *ppNewMeshContainer);
    STDMETHOD(DestroyFrame)(THIS_ LPD3DXFRAME pFrameToFree);
    STDMETHOD(DestroyMeshContainer)(THIS_ LPD3DXMESHCONTAINER pMeshContainerBase);
    CAllocationHierarchy(CD3DAnimatedMesh* pMesh) : m_pSourceMesh(pMesh) {}

protected:
	CD3DAnimatedMesh *m_pSourceMesh;

};

#endif // !defined(AFX_ALLOCATIONHIERARCHY_H__7D1A12BC_EF41_4964_8890_F312830EC4DD__INCLUDED_)
