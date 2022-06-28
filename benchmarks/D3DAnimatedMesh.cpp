// D3DAnimatedMesh.cpp: implementation of the CD3DAnimatedMesh class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "D3DAnimatedMesh.h"
#include "allocationhierarchy.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CD3DAnimatedMesh::CD3DAnimatedMesh(LPDIRECT3DDEVICE9 d3dDevice)
{

	m_pd3dDevice=d3dDevice;
	m_pd3dDevice->GetDeviceCaps(&m_d3dCaps);
	m_SkinningMethod=D3DNONINDEXED;
	bLoaded=false;

}

CD3DAnimatedMesh::~CD3DAnimatedMesh()
{
    CAllocationHierarchy Alloc(this);

    D3DXFrameDestroy(m_pFrameRoot, &Alloc);

	SAFE_RELEASE(m_pAnimController);
}

void CD3DAnimatedMesh::UpdateAnimationMatrices(LPD3DXMATRIX pWorldMatrix){

	if (m_pAnimController != NULL)
        m_pAnimController->SetTime(m_pAnimController->GetTime()+DXUtil_Timer( TIMER_GETELAPSEDTIME ));

	UpdateFrameMatrices(m_pFrameRoot,pWorldMatrix);
}

void CD3DAnimatedMesh::UpdateFrameMatrices(LPD3DXFRAME pFrameBase, LPD3DXMATRIX pParentMatrix)
{
    D3DXFRAME_DERIVED *pFrame = (D3DXFRAME_DERIVED*)pFrameBase;

    if (pParentMatrix != NULL)
        D3DXMatrixMultiply(&pFrame->CombinedTransformationMatrix, &pFrame->TransformationMatrix, pParentMatrix);
    else
        pFrame->CombinedTransformationMatrix = pFrame->TransformationMatrix;

    if (pFrame->pFrameSibling != NULL)
    {
        UpdateFrameMatrices(pFrame->pFrameSibling, pParentMatrix);
    }

    if (pFrame->pFrameFirstChild != NULL)
    {
        UpdateFrameMatrices(pFrame->pFrameFirstChild, &pFrame->CombinedTransformationMatrix);
    }
}


void CD3DAnimatedMesh::DrawMeshContainer(LPD3DXMESHCONTAINER pMeshContainerBase, LPD3DXFRAME pFrameBase)
{
    D3DXMESHCONTAINER_DERIVED *pMeshContainer = (D3DXMESHCONTAINER_DERIVED*)pMeshContainerBase;
    D3DXFRAME_DERIVED *pFrame = (D3DXFRAME_DERIVED*)pFrameBase;
    UINT iMaterial;
    UINT NumBlend;
    UINT iAttrib;
    DWORD AttribIdPrev;
    LPD3DXBONECOMBINATION pBoneComb;

    UINT iMatrixIndex;
    UINT iPaletteEntry;
    D3DXMATRIXA16 matTemp;

    // first check for skinning
    if (pMeshContainer->pSkinInfo != NULL)
    {
        if (m_SkinningMethod == D3DNONINDEXED)
        {
            AttribIdPrev = UNUSED32; 
            pBoneComb = reinterpret_cast<LPD3DXBONECOMBINATION>(pMeshContainer->pBoneCombinationBuf->GetBufferPointer());

            // Draw using default vtx processing of the device (typically HW)
            for (iAttrib = 0; iAttrib < pMeshContainer->NumAttributeGroups; iAttrib++)
            {
                NumBlend = 0;
                for (DWORD i = 0; i < pMeshContainer->NumInfl; ++i)
                {
                    if (pBoneComb[iAttrib].BoneId[i] != UINT_MAX)
                    {
                        NumBlend = i;
                    }
                }

                if (m_d3dCaps.MaxVertexBlendMatrices >= NumBlend + 1)
                {
                    // first calculate the world matrices for the current set of blend weights and get the accurate count of the number of blends
                    for (DWORD i = 0; i < pMeshContainer->NumInfl; ++i)
                    {
                        iMatrixIndex = pBoneComb[iAttrib].BoneId[i];
                        if (iMatrixIndex != UINT_MAX)
                        {
                            D3DXMatrixMultiply( &matTemp, &pMeshContainer->pBoneOffsetMatrices[iMatrixIndex], pMeshContainer->ppBoneMatrixPtrs[iMatrixIndex] );
                            m_pd3dDevice->SetTransform( D3DTS_WORLDMATRIX( i ), &matTemp );
                        }
                    }

                    m_pd3dDevice->SetRenderState(D3DRS_VERTEXBLEND, NumBlend);

                    // lookup the material used for this subset of faces
                    if ((AttribIdPrev != pBoneComb[iAttrib].AttribId) || (AttribIdPrev == UNUSED32))
                    {
                        m_pd3dDevice->SetMaterial( &pMeshContainer->pMaterials[pBoneComb[iAttrib].AttribId].MatD3D );
                        m_pd3dDevice->SetTexture( 0, pMeshContainer->ppTextures[pBoneComb[iAttrib].AttribId] );
                        AttribIdPrev = pBoneComb[iAttrib].AttribId;
                    }

                    // draw the subset now that the correct material and matrices are loaded
                    pMeshContainer->MeshData.pMesh->DrawSubset(iAttrib);
                }
            }

            // If necessary, draw parts that HW could not handle using SW
            if (pMeshContainer->iAttributeSW < pMeshContainer->NumAttributeGroups)
            {
                AttribIdPrev = UNUSED32; 
                m_pd3dDevice->SetSoftwareVertexProcessing(TRUE);
                for (iAttrib = pMeshContainer->iAttributeSW; iAttrib < pMeshContainer->NumAttributeGroups; iAttrib++)
                {
                    NumBlend = 0;
                    for (DWORD i = 0; i < pMeshContainer->NumInfl; ++i)
                    {
                        if (pBoneComb[iAttrib].BoneId[i] != UINT_MAX)
                        {
                            NumBlend = i;
                        }
                    }

                    if (m_d3dCaps.MaxVertexBlendMatrices < NumBlend + 1)
                    {
                        // first calculate the world matrices for the current set of blend weights and get the accurate count of the number of blends
                        for (DWORD i = 0; i < pMeshContainer->NumInfl; ++i)
                        {
                            iMatrixIndex = pBoneComb[iAttrib].BoneId[i];
                            if (iMatrixIndex != UINT_MAX)
                            {
                                D3DXMatrixMultiply( &matTemp, &pMeshContainer->pBoneOffsetMatrices[iMatrixIndex], pMeshContainer->ppBoneMatrixPtrs[iMatrixIndex] );
                                m_pd3dDevice->SetTransform( D3DTS_WORLDMATRIX( i ), &matTemp );
                            }
                        }

                        m_pd3dDevice->SetRenderState(D3DRS_VERTEXBLEND, NumBlend);

                        // lookup the material used for this subset of faces
                        if ((AttribIdPrev != pBoneComb[iAttrib].AttribId) || (AttribIdPrev == UNUSED32))
                        {
                            m_pd3dDevice->SetMaterial( &pMeshContainer->pMaterials[pBoneComb[iAttrib].AttribId].MatD3D );
                            m_pd3dDevice->SetTexture( 0, pMeshContainer->ppTextures[pBoneComb[iAttrib].AttribId] );
                            AttribIdPrev = pBoneComb[iAttrib].AttribId;
                        }

                        // draw the subset now that the correct material and matrices are loaded
                        pMeshContainer->MeshData.pMesh->DrawSubset(iAttrib);
                    }
                }
                m_pd3dDevice->SetSoftwareVertexProcessing(FALSE);
            }

            m_pd3dDevice->SetRenderState(D3DRS_VERTEXBLEND, 0);
        }
     }
    else  // standard mesh, just draw it after setting material properties
    {
        m_pd3dDevice->SetTransform(D3DTS_WORLD, &pFrame->CombinedTransformationMatrix);

        for (iMaterial = 0; iMaterial < pMeshContainer->NumMaterials; iMaterial++)
        {
            m_pd3dDevice->SetMaterial( &pMeshContainer->pMaterials[iMaterial].MatD3D );
            m_pd3dDevice->SetTexture( 0, pMeshContainer->ppTextures[iMaterial] );
            pMeshContainer->MeshData.pMesh->DrawSubset(iMaterial);
        }
    }
}


void CD3DAnimatedMesh::DrawFrame(LPD3DXFRAME pFrame){

	
    LPD3DXMESHCONTAINER pMeshContainer;

    pMeshContainer = pFrame->pMeshContainer;
    while (pMeshContainer != NULL)
    {
        DrawMeshContainer(pMeshContainer, pFrame);

        pMeshContainer = pMeshContainer->pNextMeshContainer;
    }

    if (pFrame->pFrameSibling != NULL)
    {
        DrawFrame(pFrame->pFrameSibling);
    }

    if (pFrame->pFrameFirstChild != NULL)
    {
        DrawFrame(pFrame->pFrameFirstChild);
    }




}


void CD3DAnimatedMesh::Render(){


	DrawFrame(m_pFrameRoot);


}

HRESULT CD3DAnimatedMesh::SetupBoneMatrixPointersOnMesh(LPD3DXMESHCONTAINER pMeshContainerBase)
{
    UINT iBone, cBones;
    D3DXFRAME_DERIVED *pFrame;

    D3DXMESHCONTAINER_DERIVED *pMeshContainer = (D3DXMESHCONTAINER_DERIVED*)pMeshContainerBase;

    // if there is a skinmesh, then setup the bone matrices
    if (pMeshContainer->pSkinInfo != NULL)
    {
        cBones = pMeshContainer->pSkinInfo->GetNumBones();

        pMeshContainer->ppBoneMatrixPtrs = new D3DXMATRIX*[cBones];
        if (pMeshContainer->ppBoneMatrixPtrs == NULL)
            return E_FAIL;

        for (iBone = 0; iBone < cBones; iBone++)
        {
            pFrame = (D3DXFRAME_DERIVED*)D3DXFrameFind(m_pFrameRoot, pMeshContainer->pSkinInfo->GetBoneName(iBone));
            if (pFrame == NULL)
                return E_FAIL;

            pMeshContainer->ppBoneMatrixPtrs[iBone] = &pFrame->CombinedTransformationMatrix;
        }
    }

	return S_OK;
}



HRESULT CD3DAnimatedMesh::SetupBoneMatrixPointers(LPD3DXFRAME pFrame){

	HRESULT hr;

    if (pFrame->pMeshContainer != NULL)
    {
        hr=SetupBoneMatrixPointersOnMesh(pFrame->pMeshContainer);
        if (FAILED(hr))
           return hr;
    }

    if (pFrame->pFrameSibling != NULL)
    {
        hr=SetupBoneMatrixPointers(pFrame->pFrameSibling);
        if (FAILED(hr))
           return hr;
    }

    if (pFrame->pFrameFirstChild != NULL)
    {
        hr=SetupBoneMatrixPointers(pFrame->pFrameFirstChild);
        if (FAILED(hr))
           return hr;
    }

	return S_OK;

}


bool CD3DAnimatedMesh::LoadMesh(CString meshName){


   CAllocationHierarchy Alloc(this);

   HRESULT hr;

 /*   // Load the mesh from the specified file
    hr = DXUtil_FindMediaFileCb( meshName, sizeof(strMeshPath), m_strMeshFilename );
    if (FAILED(hr))
        return;
*/
    hr=D3DXLoadMeshHierarchyFromX(meshName, D3DXMESH_MANAGED, m_pd3dDevice, &Alloc, NULL, &m_pFrameRoot, &m_pAnimController);
    if (FAILED(hr))
        return false;

    hr=SetupBoneMatrixPointers(m_pFrameRoot);
	if (FAILED(hr))
        return false;

	bLoaded=true;

	return true;


}
void CD3DAnimatedMesh::GenerateSkinnedMesh(D3DXMESHCONTAINER_DERIVED *pMeshContainer){

    HRESULT hr = S_OK;

    if (pMeshContainer->pSkinInfo == NULL)
        return;

    SAFE_RELEASE( pMeshContainer->MeshData.pMesh );
    SAFE_RELEASE( pMeshContainer->pBoneCombinationBuf );

    // if non-indexed skinning mode selected, use ConvertToBlendedMesh to generate drawable mesh
    if (m_SkinningMethod == D3DNONINDEXED)
    {

        hr = pMeshContainer->pSkinInfo->ConvertToBlendedMesh
                                   (
                                       pMeshContainer->pOrigMesh,
                                       D3DXMESH_SYSTEMMEM | D3DXMESH_SOFTWAREPROCESSING | D3DXMESHOPT_COMPACT |D3DXMESHOPT_VERTEXCACHE, 
                                       pMeshContainer->pAdjacency, 
                                       NULL, NULL, NULL, 
                                       &pMeshContainer->NumInfl,
                                       &pMeshContainer->NumAttributeGroups, 
                                       &pMeshContainer->pBoneCombinationBuf, 
                                       &pMeshContainer->MeshData.pMesh
                                   );
        if (FAILED(hr))
           return;


        /* If the device can only do 2 matrix blends, ConvertToBlendedMesh cannot approximate all meshes to it
           Thus we split the mesh in two parts: The part that uses at most 2 matrices and the rest. The first is
           drawn using the device's HW vertex processing and the rest is drawn using SW vertex processing. */
        LPD3DXBONECOMBINATION rgBoneCombinations  = reinterpret_cast<LPD3DXBONECOMBINATION>(pMeshContainer->pBoneCombinationBuf->GetBufferPointer());

        // look for any set of bone combinations that do not fit the caps
        for (pMeshContainer->iAttributeSW = 0; pMeshContainer->iAttributeSW < pMeshContainer->NumAttributeGroups; pMeshContainer->iAttributeSW++)
        {
            DWORD cInfl   = 0;

            for (DWORD iInfl = 0; iInfl < pMeshContainer->NumInfl; iInfl++)
            {
                if (rgBoneCombinations[pMeshContainer->iAttributeSW].BoneId[iInfl] != UINT_MAX)
                {
                    ++cInfl;
                }
            }

/*            if (cInfl > m_d3dCaps.MaxVertexBlendMatrices)
            {
                break;
            }
 */
		}

        // if there is both HW and SW, add the Software Processing flag
        if (pMeshContainer->iAttributeSW < pMeshContainer->NumAttributeGroups)
        {
            LPD3DXMESH pMeshTmp;

            hr = pMeshContainer->MeshData.pMesh->CloneMeshFVF(D3DXMESH_SOFTWAREPROCESSING|pMeshContainer->MeshData.pMesh->GetOptions(), 
                                                pMeshContainer->MeshData.pMesh->GetFVF(),
                                                m_pd3dDevice, &pMeshTmp);
            if (FAILED(hr))
            {
                return;
            }

            pMeshContainer->MeshData.pMesh->Release();
            pMeshContainer->MeshData.pMesh = pMeshTmp;
            pMeshTmp = NULL;
        }
    }
}