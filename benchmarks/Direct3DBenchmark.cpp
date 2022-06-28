// Direct3DBenchmark.cpp: implementation of the CDirect3DBenchmark class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Benchmarks.h"
#include "Direct3DBenchmark.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif


inline DWORD FtoDW( FLOAT f ) { return *((DWORD*)&f); }


//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
CDirect3DBenchmark::~CDirect3DBenchmark()
{

	delete  pMesh;
    
    if( m_pd3dDevice != NULL )
        m_pd3dDevice->Release();

    if( m_pD3D != NULL )
        m_pD3D->Release();

	delete m_font;
}

bool CDirect3DBenchmark::InitBenchmarkData(CBenchmarkEnvironment *e){


	e->UpdateStatus("Loading scene data, please wait...");
  
	if( NULL == ( m_pD3D = Direct3DCreate9( D3D_SDK_VERSION ) ) )
		return false;


	//creating font


	m_font=new CD3DFont( _T("Arial"), 8, D3DFONT_FILTERED );

	//creating D3D Device...
    D3DPRESENT_PARAMETERS d3dpp; 
    ZeroMemory( &d3dpp, sizeof(d3dpp) );
    d3dpp.Windowed = TRUE;
    d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
    d3dpp.BackBufferFormat = D3DFMT_UNKNOWN;
    d3dpp.EnableAutoDepthStencil = TRUE;
    d3dpp.AutoDepthStencilFormat = D3DFMT_D16;


    if( FAILED( m_pD3D->CreateDevice( D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, e->GetOutTarget(0)->GetSafeHwnd(),
                                      D3DCREATE_SOFTWARE_VERTEXPROCESSING,
                                      &d3dpp, &m_pd3dDevice ) ) )
    {
		return false;
    }

	
/*	if( SUCCEEDED(m_pD3D->CheckDeviceMultiSampleType( D3DADAPTER_DEFAULT, 
                     D3DDEVTYPE_HAL , D3DFMT_R8G8B8, FALSE, 
                     D3DMULTISAMPLE_2_SAMPLES, NULL ) ) ){

	    m_pd3dDevice->SetRenderState( D3DRS_MULTISAMPLEANTIALIAS , TRUE );
	}
*/
    //setting device states
    m_pd3dDevice->SetRenderState( D3DRS_ZENABLE, TRUE );
	m_pd3dDevice->SetRenderState( D3DRS_CULLMODE, D3DCULL_CCW );
	m_pd3dDevice->SetRenderState( D3DRS_SPECULARENABLE, TRUE );


	m_pd3dDevice->SetRenderState( D3DRS_NORMALIZENORMALS, TRUE );
	m_pd3dDevice->SetRenderState( D3DRS_DITHERENABLE, TRUE );

    m_pd3dDevice->SetSamplerState( 0, D3DSAMP_MAGFILTER, D3DTEXF_LINEAR );
    m_pd3dDevice->SetSamplerState( 0, D3DSAMP_MINFILTER, D3DTEXF_LINEAR );
//  m_pd3dDevice->SetSamplerState( 0, D3DSAMP_MIPFILTER, D3DTEXF_ANISOTROPIC );
//	m_pd3dDevice->SetSamplerState( 0, D3DSAMP_MIPMAPLODBIAS, -1);


    // Turn on ambient lighting 
    m_pd3dDevice->SetRenderState( D3DRS_AMBIENT, 0x44444444);
	m_pd3dDevice->SetFVF(D3DFVF_XYZ | D3DFVF_NORMAL | D3DFVF_TEX1);

  
	m_font->InitDeviceObjects( m_pd3dDevice );
	m_font->RestoreDeviceObjects();

	pMesh=new CD3DAnimatedMesh(m_pd3dDevice);


	if(!pMesh->LoadMesh(".\\data\\natura.x")){
		e->UpdateStatus("Failed to load geometry. Aborting...");
		return false;
	}

    // Device state would normally be set here

	return true;

}


void CDirect3DBenchmark::SetMatrices(){

	// For our world matrix, we will just leave it as the identity
    D3DXMATRIXA16 matWorld;
    D3DXMatrixRotationY( &matWorld,-0.5);

	//D3DXMatrixIdentity(&matWorld);
    m_pd3dDevice->SetTransform( D3DTS_WORLD, &matWorld );
	
	D3DXVECTOR3 vEyePt(-14.0f, 228.0f,-628.0f );
    D3DXVECTOR3 vLookatPt( 0.0f, 65.0f, 0.0f );
    D3DXVECTOR3 vUpVec( 0.0f, 1.0f, 0.0f );
    D3DXMATRIXA16 matView,matView2;
    D3DXMatrixLookAtLH( &matView, &vEyePt, &vLookatPt, &vUpVec );
    m_pd3dDevice->SetTransform( D3DTS_VIEW, &matView );


	D3DXMATRIXA16 matProj;
    D3DXMatrixPerspectiveFovLH( &matProj, D3DX_PI/4,  800.0f/600.0f,1, 2500 );

    m_pd3dDevice->SetTransform( D3DTS_PROJECTION, &matProj );

	pMesh->UpdateAnimationMatrices(&matWorld);


}


bool CDirect3DBenchmark::StartBenchmark(CBenchmarkEnvironment *e){


	 if( NULL == m_pd3dDevice )
        return false;


	 result=0;

	 e->UpdateStatus("Rendering...");

	 for(int i=0; i<500; i++){

		// Clear the backbuffer to a blue color
		m_pd3dDevice->Clear( 0, NULL, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER, D3DCOLOR_XRGB(255,255,255), 1.0f, 0 );
    
		// Begin the scene
		if( SUCCEEDED( m_pd3dDevice->BeginScene() ) )
		{


		m_pd3dDevice->SetRenderState( D3DRS_FOGENABLE, TRUE );
		m_pd3dDevice->SetRenderState( D3DRS_FOGCOLOR,  0x00FFFFFF );

		m_pd3dDevice->SetRenderState( D3DRS_FOGSTART,   FtoDW(650.0f) );
		m_pd3dDevice->SetRenderState( D3DRS_FOGEND,     FtoDW(1100.0f) );
//		m_pd3dDevice->SetRenderState( D3DRS_FOGDENSITY, FtoDW(m_fFogDensity) );

		m_pd3dDevice->SetRenderState( D3DRS_FOGTABLEMODE,   D3DFOG_NONE );
		m_pd3dDevice->SetRenderState( D3DRS_FOGVERTEXMODE,  D3DFOG_LINEAR );
		m_pd3dDevice->SetRenderState( D3DRS_RANGEFOGENABLE, TRUE );
 

			e->Step((float)i/5.0f);
			int start=timeGetTime();
			// Rendering of scene objects can happen here
			SetMatrices();


       		D3DLIGHT9 light1,light2;

			D3DUtil_InitLight( light2, D3DLIGHT_DIRECTIONAL, 0.0f,-50.0f, 330.0f );
			D3DUtil_InitLight( light1, D3DLIGHT_DIRECTIONAL, 0.0f,-40.0f, 60.0f );

			m_pd3dDevice->SetLight(0, &light1);
			m_pd3dDevice->LightEnable(0, TRUE );

			m_pd3dDevice->SetLight(1, &light2);
			m_pd3dDevice->LightEnable(1, FALSE );

			pMesh->Render();

			int stop=timeGetTime();

			float time=stop-start;

            m_font->DrawText(   2, 545, 0xffffffff, "Microsoft Direct3D 9.0 API" );


            m_font->DrawText(   2, 555, 0xffffffff, "HAL (software vertex processing)" );

			CString str;

			//str.Format("NumVertices: %d",pMesh->GetNumVertices());
          
			m_font->DrawText(   2, 565, 0xffffffff, "vertices=271544,faces=240388" );

			float fps=1000.0f/time;

			str.Format("Frame rate: %1.2f fps",fps);
          
			m_font->DrawText(   2, 575, 0xffffffff, str );

			
			str.Format("Rendering frame: %d of 500",i);
          
			m_font->DrawText(   2, 585, 0xffffffff, str );
	


			//calcolating medium fps

			result+=fps;
			// End the scene
			m_pd3dDevice->EndScene();
		}


		
		// Present the backbuffer contents to the display
		m_pd3dDevice->Present( NULL, NULL, NULL, NULL );

	 }

	result=result/500.0f;

	return true;

}