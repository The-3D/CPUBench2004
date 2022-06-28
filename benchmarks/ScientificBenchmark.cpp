// ScientificBenchmark.cpp: implementation of the CScientificBenchmark class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "benchmarks.h"
#include "ScientificBenchmark.h"
#include "moleculebuilder.h"
#include "moleculerenderer.h"
#include <afxmt.h>



#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

HDC hDC;
HGLRC hRC;

HDC hDC2;
HGLRC hRC2;

HDC hDC3;
HGLRC hRC3;


CSemaphore sem(1,1);

float result1=0,result2=0,result3=0;


INT Thread1(LPVOID arg){

		// TODO: Add extra initialization here

	CBenchmarkEnvironment *e;

	e=(CBenchmarkEnvironment*)arg;

	CSingleLock sl(&sem);

	sl.Lock();
    PIXELFORMATDESCRIPTOR pfd,pfd2;
    int iFormat;

    // get the device context (DC)
    hDC = ::GetDC( e->GetOutTarget(0)->m_hWnd );

    // set the pixel format for the DC
    ZeroMemory( &pfd, sizeof( pfd ) );
    pfd.nSize = sizeof( pfd );
    pfd.nVersion = 1;

	int pFormat=1;
	
	int count =1+ DescribePixelFormat(hDC,pFormat,sizeof(PIXELFORMATDESCRIPTOR),&pfd);

	while(--count){

		DescribePixelFormat(hDC,count,sizeof(PIXELFORMATDESCRIPTOR),&pfd);

		if((pfd.dwFlags & PFD_SUPPORT_OPENGL) &&

	      (pfd.dwFlags & PFD_DRAW_TO_WINDOW) &&
	
		  //(pfd.dwFlags & PFD_GENERIC_ACCELERATED) &&

	      (pfd.dwFlags & PFD_DOUBLEBUFFER) &&

		  ( pfd.cDepthBits == 32 ) &&

		  ( pfd.cColorBits == 32 ) &&

          (pfd.iPixelType == PFD_TYPE_RGBA)){

			iFormat = count;
			break;
	  
	   }
	}



    //iFormat = ChoosePixelFormat( hDC, &pfd );
    SetPixelFormat( hDC, iFormat, &pfd );

    // create and enable the render context (RC)
    hRC = wglCreateContext( hDC );
    wglMakeCurrent( hDC, hRC );


	CMoleculeBuilder b;

	b.BuildFromFile(".\\scientificdata\\prova.mol");

	sl.Unlock();


	CFont f;


	f.CreateFont(-13,0,0,0,FW_BOLD,FALSE,FALSE,0,ANSI_CHARSET,OUT_TT_PRECIS,
					CLIP_TT_ALWAYS,ANTIALIASED_QUALITY,DEFAULT_PITCH | FF_SWISS, "ARIAL");

//	CMolecule mol("prova.mol");


	const CMolecule *mol=b.GetMolecule();



	CRect r;

	CDC* dc=e->GetOutTarget(0)->GetDC();

	dc->SelectObject(&f);

	dc->SetTextColor(0x00FFFFFF);

	wglUseFontBitmaps (dc->m_hDC, 0, 255, 1000); 
 
	// display a string: 
	// indicate start of glyph display lists 
	glListBase (1000); 




	e->GetOutTarget(0)->GetClientRect(&r);


	glViewport(0,0,r.Width(),r.Height());						// Make our viewport the whole window

    GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat mat_color[] = { 1.0, 1.0, 1.0, 1.0 };
   
    GLfloat mat_shininess[] = { 1.0 };
    GLfloat light_position[] = { 1.0, 1.0, 1.0, 0.0 };

    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_color);
    glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);

    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glDepthFunc(GL_LEQUAL);
    glEnable(GL_DEPTH_TEST);

	CMoleculeRenderer renderer;

	float rot=90;

	int start,stop;

	float tot=0;

	start=timeGetTime();

	while(timeGetTime() - start <= 20000){


		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// Clear The Screen And The Depth Buffer


															// Our window if we wanted too.
														// The glViewport takes (x, y, width, height)
														// This basically means, what our our drawing boundries

		glMatrixMode(GL_PROJECTION);						// Select The Projection Matrix
		glLoadIdentity();									// Reset The Projection Matrix

														// Calculate The Aspect Ratio Of The Window
														// The parameters are:
														// (view angle, aspect ration of the width to the height, 
														//  The closest distance to the camera before it clips, 
				  // FOV		// Ratio				//  The farthest distance before it stops drawing)
		gluPerspective(45.0f,(GLfloat)(r.Width())/(GLfloat)r.Height(), .5f ,550.0f);

		glMatrixMode(GL_MODELVIEW);							// Select The Modelview Matrix
		glLoadIdentity();

		// We make our position a bit high and back to view the whole scene

		// 	  Position      View	   Up Vector
		gluLookAt(0,0 , -1.5 * (mol->GetRadius()),    0,0,0,     0, 1, 0);		// This determines where the camera's position and view is

		
		glMatrixMode(GL_MODELVIEW);

		glInitNames();										// This clears the name stack so we always start with 0 names.

		
		renderer.RenderMolecule(mol,(RENDER_MODE)1);


 
		SwapBuffers(hDC);									// Swap the backbuffers to the foreground


		e->Step(100*(float)(timeGetTime() - start)/15000.0f);
	

	}

    wglMakeCurrent( NULL, NULL );
    wglDeleteContext( hRC );
    ReleaseDC( e->GetOutTarget(0)->m_hWnd, hDC );
	

	return 0;
}



INT Thread2(LPVOID arg){

		// TODO: Add extra initialization here


	CBenchmarkEnvironment *e;

	e=(CBenchmarkEnvironment*)arg;


	CSingleLock sl(&sem);

	sl.Lock();
    PIXELFORMATDESCRIPTOR pfd,pfd2;
    int iFormat;

    // get the device context (DC)
    hDC2 = ::GetDC( e->GetOutTarget(1)->m_hWnd );

    // set the pixel format for the DC
    ZeroMemory( &pfd, sizeof( pfd ) );
    pfd.nSize = sizeof( pfd );
    pfd.nVersion = 1;

	int pFormat=1;
	
	int count =1+ DescribePixelFormat(hDC2,pFormat,sizeof(PIXELFORMATDESCRIPTOR),&pfd);

	while(--count){

		DescribePixelFormat(hDC2,count,sizeof(PIXELFORMATDESCRIPTOR),&pfd);

		if((pfd.dwFlags & PFD_SUPPORT_OPENGL) &&

	      (pfd.dwFlags & PFD_DRAW_TO_WINDOW) &&
	
		  //(pfd.dwFlags & PFD_GENERIC_ACCELERATED) &&

	      (pfd.dwFlags & PFD_DOUBLEBUFFER) &&

		  ( pfd.cDepthBits == 32 ) &&

		  ( pfd.cColorBits == 32 ) &&

          (pfd.iPixelType == PFD_TYPE_RGBA)){

			iFormat = count;
			break;
	  
	   }
	}



    //iFormat = ChoosePixelFormat( hDC2, &pfd );
    SetPixelFormat( hDC2, iFormat, &pfd );

    // create and enable the render context (RC)
    hRC2 = wglCreateContext( hDC2 );
    wglMakeCurrent( hDC2, hRC2 );


	CMoleculeBuilder b;

	b.BuildFromFile(".\\scientificdata\\prova.mol");

	sl.Unlock();


	CFont f;


	f.CreateFont(-13,0,0,0,FW_BOLD,FALSE,FALSE,0,ANSI_CHARSET,OUT_TT_PRECIS,
					CLIP_TT_ALWAYS,ANTIALIASED_QUALITY,DEFAULT_PITCH | FF_SWISS, "ARIAL");

//	CMolecule mol("prova.mol");


	const CMolecule *mol=b.GetMolecule();



	CRect r;

	CDC* dc=e->GetOutTarget(1)->GetDC();

	dc->SelectObject(&f);

	dc->SetTextColor(0x00FFFFFF);

	wglUseFontBitmaps (dc->m_hDC, 0, 255, 1000); 
 
	// display a string: 
	// indicate start of glyph display lists 
	glListBase (1000); 




	e->GetOutTarget(1)->GetClientRect(&r);

	glViewport(0,0,r.Width(),r.Height());						// Make our viewport the whole window

    GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat mat_color[] = { 1.0, 1.0, 1.0, 1.0 };
   
    GLfloat mat_shininess[] = { 1.0 };
    GLfloat light_position[] = { 1.0, 1.0, 1.0, 0.0 };

    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_color);
    glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);

    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glDepthFunc(GL_LEQUAL);
    glEnable(GL_DEPTH_TEST);

	CMoleculeRenderer renderer;

	float rot=90;

	int start,stop;

	float tot=0;

	start=timeGetTime();



	while(timeGetTime() - start <= 20000){

		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// Clear The Screen And The Depth Buffer


															// Our window if we wanted too.
														// The glViewport takes (x, y, width, height)
														// This basically means, what our our drawing boundries

		glMatrixMode(GL_PROJECTION);						// Select The Projection Matrix
		glLoadIdentity();									// Reset The Projection Matrix

														// Calculate The Aspect Ratio Of The Window
														// The parameters are:
														// (view angle, aspect ration of the width to the height, 
														//  The closest distance to the camera before it clips, 
				  // FOV		// Ratio				//  The farthest distance before it stops drawing)
		gluPerspective(45.0f,(GLfloat)(r.Width())/(GLfloat)r.Height(), .5f ,550.0f);

		glMatrixMode(GL_MODELVIEW);							// Select The Modelview Matrix
		glLoadIdentity();

		// We make our position a bit high and back to view the whole scene

		// 	  Position      View	   Up Vector
		gluLookAt(0,0 , -1.5 * (mol->GetRadius()),    0,0,0,     0, 1, 0);		// This determines where the camera's position and view is

		
		glMatrixMode(GL_MODELVIEW);

		glInitNames();										// This clears the name stack so we always start with 0 names.

		
		renderer.RenderMolecule(mol,(RENDER_MODE)0);


 
		SwapBuffers(hDC2);									// Swap the backbuffers to the foreground

	
	}

    wglMakeCurrent( NULL, NULL );
    wglDeleteContext( hRC2 );
    ReleaseDC( e->GetOutTarget(1)->m_hWnd, hDC2 );
	

	return 0;
}




INT Thread3(LPVOID arg){

		// TODO: Add extra initialization here
	CBenchmarkEnvironment *e;

	e=(CBenchmarkEnvironment*)arg;

	CSingleLock sl(&sem);

	sl.Lock();
    PIXELFORMATDESCRIPTOR pfd,pfd2;
    int iFormat;

    // get the device context (DC)
    hDC3 = ::GetDC( e->GetOutTarget(2)->m_hWnd );

    // set the pixel format for the DC
    ZeroMemory( &pfd, sizeof( pfd ) );
    pfd.nSize = sizeof( pfd );
    pfd.nVersion = 1;

	int pFormat=1;
	
	int count =1+ DescribePixelFormat(hDC3,pFormat,sizeof(PIXELFORMATDESCRIPTOR),&pfd);

	while(--count){

		DescribePixelFormat(hDC3,count,sizeof(PIXELFORMATDESCRIPTOR),&pfd);

		if((pfd.dwFlags & PFD_SUPPORT_OPENGL) &&

	      (pfd.dwFlags & PFD_DRAW_TO_WINDOW) &&
	
		  //(pfd.dwFlags & PFD_GENERIC_ACCELERATED) &&

	      (pfd.dwFlags & PFD_DOUBLEBUFFER) &&

		  ( pfd.cDepthBits == 32 ) &&

		  ( pfd.cColorBits == 32 ) &&

          (pfd.iPixelType == PFD_TYPE_RGBA)){

			iFormat = count;
			break;
	  
	   }
	}



    //iFormat = ChoosePixelFormat( hDC3, &pfd );
    SetPixelFormat( hDC3, iFormat, &pfd );

    // create and enable the render context (RC)
    hRC3 = wglCreateContext( hDC3 );
    wglMakeCurrent( hDC3, hRC3 );


	CMoleculeBuilder b;

	b.BuildFromFile(".\\scientificdata\\prova.mol");

	sl.Unlock();


	CFont f;


	f.CreateFont(-12,0,0,0,FW_BOLD,FALSE,FALSE,0,ANSI_CHARSET,OUT_TT_PRECIS,
					CLIP_TT_ALWAYS,ANTIALIASED_QUALITY,DEFAULT_PITCH | FF_SWISS, "ARIAL");

//	CMolecule mol("prova.mol");


	const CMolecule *mol=b.GetMolecule();



	CRect r;

	CDC* dc=e->GetOutTarget(2)->GetDC();

	dc->SelectObject(&f);

	dc->SetTextColor(0x00FFFFFF);

	wglUseFontBitmaps (dc->m_hDC, 0, 255, 1000); 
 
	// display a string: 
	// indicate start of glyph display lists 
	glListBase (1000); 

	e->GetOutTarget(2)->GetClientRect(&r);

	glViewport(0,0,r.Width(),r.Height());						// Make our viewport the whole window

    GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat mat_color[] = { 1.0, 1.0, 1.0, 1.0 };
   
    GLfloat mat_shininess[] = { 1.0 };
    GLfloat light_position[] = { 1.0, 1.0, 1.0, 0.0 };

    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_color);
    glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);

    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glDepthFunc(GL_LEQUAL);
    glEnable(GL_DEPTH_TEST);

	CMoleculeRenderer renderer;

	float rot=90;

	int start,stop;

	float tot=0;

	start=timeGetTime();


	while(timeGetTime() - start <= 20000){

		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// Clear The Screen And The Depth Buffer


															// Our window if we wanted too.
														// The glViewport takes (x, y, width, height)
														// This basically means, what our our drawing boundries

		glMatrixMode(GL_PROJECTION);						// Select The Projection Matrix
		glLoadIdentity();									// Reset The Projection Matrix

														// Calculate The Aspect Ratio Of The Window
														// The parameters are:
														// (view angle, aspect ration of the width to the height, 
														//  The closest distance to the camera before it clips, 
				  // FOV		// Ratio				//  The farthest distance before it stops drawing)
		gluPerspective(45.0f,(GLfloat)(r.Width())/(GLfloat)r.Height(), .5f ,550.0f);

		glMatrixMode(GL_MODELVIEW);							// Select The Modelview Matrix
		glLoadIdentity();

		// We make our position a bit high and back to view the whole scene

		// 	  Position      View	   Up Vector
		gluLookAt(0,0 , -1.5 * (mol->GetRadius()),    0,0,0,     0, 1, 0);		// This determines where the camera's position and view is

		
		glMatrixMode(GL_MODELVIEW);

		glInitNames();										// This clears the name stack so we always start with 0 names.

		
		renderer.RenderMolecule(mol,(RENDER_MODE)2);


 
	SwapBuffers(hDC3);									// Swap the backbuffers to the foreground

	stop=timeGetTime();

 
	}

    wglMakeCurrent( NULL, NULL );
    wglDeleteContext( hRC3 );
    ReleaseDC(e->GetOutTarget(2)->m_hWnd, hDC3 );


	return 0;
}



int CreateOGLFont(CDC* dc,CFont *f){

	int fontListID = 0;								
	
	fontListID = glGenLists(1000);

	dc->SelectObject(f);

	wglUseFontBitmaps(dc->m_hDC, 0, 255, fontListID);	

	return fontListID;	
	
}


CScientificBenchmark::~CScientificBenchmark()
{

}


bool CScientificBenchmark::InitBenchmarkData(CBenchmarkEnvironment *e){

	return true;
}


bool CScientificBenchmark::StartBenchmark(CBenchmarkEnvironment *e){


	e->UpdateStatus("Rendering molecule...");

	CWinThread *t1=AfxBeginThread((AFX_THREADPROC)Thread1,e,THREAD_PRIORITY_NORMAL);
	CWinThread *t2=AfxBeginThread((AFX_THREADPROC)Thread2,e,THREAD_PRIORITY_NORMAL);
	CWinThread *t3=AfxBeginThread((AFX_THREADPROC)Thread3,e,THREAD_PRIORITY_NORMAL);

	HANDLE threads[3];

	threads[0]=t1->m_hThread;
	threads[1]=t2->m_hThread;
	threads[2]=t3->m_hThread;


	::WaitForMultipleObjects(3,threads,TRUE,INFINITE);


	return true;
}
  


