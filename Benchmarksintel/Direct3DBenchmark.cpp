// Direct3DBenchmark.cpp: implementation of the CDirect3DBenchmark class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Benchmarksintel.h"
#include "Direct3DBenchmark.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
CDirect3DBenchmark::~CDirect3DBenchmark()
{
    if( m_pMeshMaterials != NULL ) 
        delete[] m_pMeshMaterials;

    if( m_pMeshTextures )
    {
        for( DWORD i = 0; i < m_dwNumMaterials; i++ )
        {
            if( m_pMeshTextures[i] )
                m_pMeshTextures[i]->Release();
        }
        delete[] m_pMeshTextures;
    }
    if( m_pMesh != NULL )
        m_pMesh->Release();
    
    if( m_pd3dDevice != NULL )
        m_pd3dDevice->Release();

    if( m_pD3D != NULL )
        m_pD3D->Release();

	delete m_font;
}

void CDirect3DBenchmark::InitBenchmarkData(CBenchmarkEnvironment *e){
  
	if( NULL == ( m_pD3D = Direct3DCreate9( D3D_SDK_VERSION ) ) )
       throw new CInitFailureException();


	//creating font


	m_font=new CD3DFont( _T("Arial"), 12, D3DFONT_BOLD );

	//creating D3D Device...
    D3DPRESENT_PARAMETERS d3dpp; 
    ZeroMemory( &d3dpp, sizeof(d3dpp) );
    d3dpp.Windowed = TRUE;
    d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
    d3dpp.BackBufferFormat = D3DFMT_UNKNOWN;
    d3dpp.EnableAutoDepthStencil = TRUE;
    d3dpp.AutoDepthStencilFormat = D3DFMT_D16;


    if( FAILED( m_pD3D->CreateDevice( D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, e->GetOutTarget()->GetSafeHwnd(),
                                      D3DCREATE_SOFTWARE_VERTEXPROCESSING,
                                      &d3dpp, &m_pd3dDevice ) ) )
    {
		throw new CInitFailureException();
    }

	
	

    //setting device states
    m_pd3dDevice->SetRenderState( D3DRS_ZENABLE, TRUE );
	m_pd3dDevice->SetRenderState( D3DRS_CULLMODE, D3DCULL_CCW );

	m_pd3dDevice->SetRenderState( D3DRS_NORMALIZENORMALS, TRUE );
	m_pd3dDevice->SetRenderState( D3DRS_DITHERENABLE, TRUE );

    m_pd3dDevice->SetSamplerState( 0, D3DSAMP_MAGFILTER, D3DTEXF_LINEAR );
    m_pd3dDevice->SetSamplerState( 0, D3DSAMP_MINFILTER, D3DTEXF_LINEAR );
	m_pd3dDevice->SetSamplerState( 0, D3DSAMP_MAGFILTER, D3DTEXF_LINEAR );
    m_pd3dDevice->SetSamplerState( 0, D3DSAMP_MINFILTER, D3DTEXF_LINEAR );
    m_pd3dDevice->SetSamplerState( 0, D3DSAMP_MIPFILTER, D3DTEXF_LINEAR );
	m_pd3dDevice->SetSamplerState( 0, D3DSAMP_MIPMAPLODBIAS, 2 );


    // Turn on ambient lighting 
    m_pd3dDevice->SetRenderState( D3DRS_AMBIENT, 0x33333333);
	m_pd3dDevice->SetFVF(D3DFVF_XYZ | D3DFVF_NORMAL | D3DFVF_TEX1);

  
	m_font->InitDeviceObjects( m_pd3dDevice );
	m_font->RestoreDeviceObjects();


	LPD3DXBUFFER pD3DXMtrlBuffer;
	LPDIRECT3DVERTEXBUFFER9 pVB = NULL;
	void*      pVertices = NULL;

    // Load the mesh from the specified file
    if( FAILED( D3DXLoadMeshFromX( "C:\\documents and settings\\emilio.PORTATILE\\desktop\\prova.x", D3DXMESH_SYSTEMMEM, 
                                   m_pd3dDevice, NULL, 
                                   &pD3DXMtrlBuffer, NULL, &m_dwNumMaterials, 
                                   &m_pMesh ) ) )
    {

		throw new CInitFailureException();

    }

 /*  // Lock the vertex buffer, to generate a simple bounding sphere
    HRESULT hr = m_pMesh->GetVertexBuffer( &pVB );
    if( FAILED(hr) )
        return;

    hr = pVB->Lock( 0, 0, &pVertices, 0 );
    if( FAILED(hr) )
    {
        pVB->Release();

        return;
    }

    hr = D3DXComputeBoundingSphere( (D3DXVECTOR3*)pVertices, m_pMesh->GetNumVertices(), 
                                    D3DXGetFVFVertexSize(m_pMesh->GetFVF()), &center, 
                                    &radius );
    if( FAILED(hr) )
    {
        pVB->Unlock();
        return;
    }

	pVB->Unlock();
	pVB=NULL;
*/


	//init mesh

    D3DXMATERIAL* d3dxMaterials = (D3DXMATERIAL*)pD3DXMtrlBuffer->GetBufferPointer();
    m_pMeshMaterials = new D3DMATERIAL9[m_dwNumMaterials];
    m_pMeshTextures  = new LPDIRECT3DTEXTURE9[m_dwNumMaterials];

    for( DWORD i=0; i<m_dwNumMaterials; i++ )
    {
        // Copy the material
        m_pMeshMaterials[i] = d3dxMaterials[i].MatD3D;

        // Set the ambient color for the material (D3DX does not do this)
        m_pMeshMaterials[i].Ambient = m_pMeshMaterials[i].Diffuse;

        m_pMeshTextures[i] = NULL;
        if( d3dxMaterials[i].pTextureFilename != NULL && 
            lstrlen(d3dxMaterials[i].pTextureFilename) > 0 )
        {
            // Create the texture
            if( FAILED( D3DXCreateTextureFromFile( m_pd3dDevice, 
                                                d3dxMaterials[i].pTextureFilename, 
                                                &m_pMeshTextures[i] ) ) )
            {
                // If texture is not in current folder, try parent folder
                const TCHAR* strPrefix = TEXT("C:\\documents and settings\\emilio.PORTATILE\\desktop\\");
                const int lenPrefix = lstrlen( strPrefix );
                TCHAR strTexture[MAX_PATH];
                lstrcpyn( strTexture, strPrefix, MAX_PATH );
                lstrcpyn( strTexture + lenPrefix, d3dxMaterials[i].pTextureFilename, MAX_PATH - lenPrefix );
                // If texture is not in current folder, try parent folder
                if( FAILED( D3DXCreateTextureFromFile( m_pd3dDevice, 
                                                    strTexture, 
                                                    &m_pMeshTextures[i] ) ) )
                {
                    MessageBox(NULL, "Could not find texture map", "Meshes.exe", MB_OK);
                }
            }
        }
    }

    // Done with the material buffer
    pD3DXMtrlBuffer->Release();

    // Device state would normally be set here

}


void CDirect3DBenchmark::SetMatrices(){

	    // For our world matrix, we will just leave it as the identity
    D3DXMATRIXA16 matWorld;
    D3DXMatrixRotationYawPitchRoll( &matWorld,-0.4, 0, 0);

	//D3DXMatrixIdentity(&matWorld);
    m_pd3dDevice->SetTransform( D3DTS_WORLD, &matWorld );
	
	D3DXVECTOR3 vEyePt( -50.0f, 40.0f,-45.0f );
    D3DXVECTOR3 vLookatPt( 0.0f, 0.0f, 150.0f );
    D3DXVECTOR3 vUpVec( 0.0f, 1.0f, 0.0f );
    D3DXMATRIXA16 matView,matView2;
    D3DXMatrixLookAtLH( &matView, &vEyePt, &vLookatPt, &vUpVec );
    m_pd3dDevice->SetTransform( D3DTS_VIEW, &matView );


	D3DXMATRIXA16 matProj;
    // FLOAT fAspect = (FLOAT) m_d3dsdBackBuffer.Width / (FLOAT) m_d3dsdBackBuffer.Height;
    D3DXMatrixPerspectiveFovLH( &matProj, D3DX_PI/4,  800.0f/600.0f,1, 1100 );

    m_pd3dDevice->SetTransform( D3DTS_PROJECTION, &matProj );


}


void CDirect3DBenchmark::StartBenchmark(CBenchmarkEnvironment *e){

	 if( NULL == m_pd3dDevice )
        return;

	 for(int i=0; i<20; i++){
		// Clear the backbuffer to a blue color
		m_pd3dDevice->Clear( 0, NULL, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER, D3DCOLOR_XRGB(0,0,255), 1.0f, 0 );
    
		// Begin the scene
		if( SUCCEEDED( m_pd3dDevice->BeginScene() ) )
		{
			int start=timeGetTime();
			// Rendering of scene objects can happen here
			SetMatrices();



       		D3DLIGHT9 light;

			D3DUtil_InitLight( light, D3DLIGHT_DIRECTIONAL, 0.0f,-50.0f, 730.0f );


			m_pd3dDevice->SetLight(0, &light);
			m_pd3dDevice->LightEnable(0, TRUE );



			for( DWORD k=0; k<m_dwNumMaterials; k++ )
			{
				// Set the material and texture for this subset
				m_pd3dDevice->SetMaterial( &m_pMeshMaterials[k] );
				m_pd3dDevice->SetTexture( 0, m_pMeshTextures[k] );
        
				// Draw the mesh subset
				m_pMesh->DrawSubset(k );
			}


			int stop=timeGetTime();

			float time=stop-start;

            m_font->DrawText(   2, 20, 0xffffff00, "Using software Vertex Processing" );

			CString str;

			str.Format("NumVertices: %d",m_pMesh->GetNumVertices());
          
			m_font->DrawText(   2, 40, 0xffffff00, str );

			
			str.Format("Frame rate: %1.2f fps",1000.0f/time);
          
			m_font->DrawText(   2, 60, 0xffffff00, str );

			
			str.Format("Rendering frame: %d of 20",i);
          
			m_font->DrawText(   2, 80, 0xffffff00, str );
	


			// End the scene
			m_pd3dDevice->EndScene();
		}

		// Present the backbuffer contents to the display
		m_pd3dDevice->Present( NULL, NULL, NULL, NULL );

	 }
}