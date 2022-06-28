// StaircaseRenderer.cpp: implementation of the CStaircaseRenderer class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "benchmarks.h"
#include "StaircaseRenderer.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CStaircaseRenderer::CStaircaseRenderer()
{

	if(!m_loader.LoadFile(".\\caddata\\d1.dll"))
		throw new CException();

}

CStaircaseRenderer::~CStaircaseRenderer()
{

}


void CStaircaseRenderer::RenderPerspectiveView(HDC renderDC){


	GLfloat mat_color[] = { 1.0, 1.0, 1.0, 1.0 };
   

    glMaterialfv(GL_FRONT, GL_AMBIENT, mat_color);

	glClearColor(0.5, 0.5, 0.5, 0.0);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);  
	glEnable(GL_NORMALIZE);
	glEnable(GL_LIGHTING);
	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_NORMAL_ARRAY);
	glEnableClientState(GL_COLOR_ARRAY);



	float maxRadius=0;

	for(int i=0; i<m_loader.GetMeshCount(); i++)
		maxRadius=(m_loader.GetMesh(i).GetRadius() > maxRadius) ? m_loader.GetMesh(i).GetRadius() : maxRadius;


	float rot=90;

	GLfloat tempMatrix[4][4];


	ZeroMemory(tempMatrix,4*4*4);

	glGetFloatv(GL_PROJECTION_MATRIX,(GLfloat*)tempMatrix);

	GLfloat ambient_color[]={ 1,1,1,1};



	int start=timeGetTime();


	int currTime=0;
	while((currTime=timeGetTime()) - start  <=5000){

		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	

		glMatrixMode(GL_PROJECTION);
		glLoadMatrixf((GLfloat*)tempMatrix);


		float eyePosX=0.0f;
		float eyePosY=100.0f;
		float eyePosZ=-2.4f*maxRadius;
		float lookAtY=100.0f;
		float rotationAngleX=-140.0f;
		float rotationAngleY=0.0f;
		float rotationAngleZ=-15.0f;

		if(currTime - start >= 1000 && currTime - start <=4000){

			eyePosX=100.0f;
			eyePosY=180.0f;
			lookAtY=0;
			eyePosZ=-1.4f*maxRadius;
//			rotationAngleX=-120.0f;
//			rotationAngleY=0.0f;
		}
	
		//imposto il punto di vista
		gluLookAt(eyePosX,eyePosY , eyePosZ,    0,lookAtY,0,     0, 1, 0);		// This determines where the camera's position and view is


		glMatrixMode(GL_MODELVIEW);							
		glLoadIdentity();

		GLfloat light_pos[] ={ 0,0,-200,0};

		glRotatef(rotationAngleX,1.0,0,0);
		glRotatef(rotationAngleZ,0,0,1);
		glRotatef(rotationAngleY,0,1,0);



		for(int u=0; u< m_loader.GetMeshCount(); u++){

			LMesh &mesh=m_loader.GetMesh(u);


			glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambient_color);  


			LMaterial m=m_loader.GetMaterial(mesh.GetMaterial(0));
			GLfloat mat_color[] = { m.GetDiffuseColor().r, m.GetDiffuseColor().g, m.GetDiffuseColor().b, 1.0 };
	
			glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_color);
			glMaterialfv(GL_FRONT, GL_AMBIENT, mat_color);
			

			glVertexPointer(4, GL_FLOAT, 0, &mesh.GetVertex(0));
	        glNormalPointer(GL_FLOAT, 0, &mesh.GetNormal(0));
		    glColorPointer(3, GL_FLOAT, 0, &mesh.GetBinormal(0));
			glDrawElements(GL_LINES, mesh.GetTriangleCount()*3, 
                        GL_UNSIGNED_SHORT, &mesh.GetTriangle(0));

		}


		
		GLfloat mat_color[] = { 1.0,1.0,1.0, 1.0 };
		GLfloat mat_specular[] = { 1.0f,1.0f,1.0f, 1.0 };
 		GLfloat mat_shininess[] ={0.0};
		
		glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_color);
		glMaterialfv(GL_FRONT, GL_AMBIENT, mat_color);
		glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);

		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		glMatrixMode( GL_MODELVIEW );						// Set our matrix to our model view matrix
		glPushMatrix();										// Push on a new matrix to work with
		glLoadIdentity();									// Reset that matrix
		glRasterPos4f( -0.96, 0.96, 0, 1 );						// Set the drawing position
		CString s="Model: Staircase.dxf (Generated with Autocad)";
		glCallLists (s.GetLength(), GL_UNSIGNED_BYTE, s); 
		glRasterPos4f( -0.96, 0.91, 0, 1 );						// Set the drawing position
		s="Perspective view";
		glCallLists (s.GetLength(), GL_UNSIGNED_BYTE, s); 
		glPopMatrix();




		SwapBuffers(renderDC);

	}



	//ripristino la projection matrix
	glMatrixMode(GL_PROJECTION);
	glLoadMatrixf((GLfloat*)tempMatrix);



}


void CStaircaseRenderer::RenderLeftView(HDC renderDC){


	GLfloat mat_color[] = { 1.0, 1.0, 1.0, 1.0 };
   

    glMaterialfv(GL_FRONT, GL_AMBIENT, mat_color);

	glClearColor(0.5, 0.5, 0.5, 0.0);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);  
	glEnable(GL_NORMALIZE);
	glEnable(GL_LIGHTING);
	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_NORMAL_ARRAY);
	glEnableClientState(GL_COLOR_ARRAY);



	float maxRadius=0;

	for(int i=0; i<m_loader.GetMeshCount(); i++)
		maxRadius=(m_loader.GetMesh(i).GetRadius() > maxRadius) ? m_loader.GetMesh(i).GetRadius() : maxRadius;


	float rot=90;

	GLfloat tempMatrix[4][4];


	ZeroMemory(tempMatrix,4*4*4);

	glGetFloatv(GL_PROJECTION_MATRIX,(GLfloat*)tempMatrix);

	GLfloat ambient_color[]={ 1,1,1,1};



	int start=timeGetTime();

	while(timeGetTime() - start <=10000){


		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	

		glMatrixMode(GL_PROJECTION);
		glLoadMatrixf((GLfloat*)tempMatrix);


		//imposto il punto di vista


		gluLookAt(320,0 ,-2.5f*maxRadius,    320,0,0,     0, 1, 0);		// This determines where the camera's position and view is


		glMatrixMode(GL_MODELVIEW);							
		glLoadIdentity();

		GLfloat light_pos[] ={ 0,0,-200,0};

		glRotatef(-90,1.0,0,0);
		glRotatef(90,0,0,1);


		for(int u=0; u< m_loader.GetMeshCount(); u++){

			LMesh &mesh=m_loader.GetMesh(u);


			glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambient_color);  


			LMaterial m=m_loader.GetMaterial(mesh.GetMaterial(0));
			GLfloat mat_color[] = { m.GetDiffuseColor().r, m.GetDiffuseColor().g, m.GetDiffuseColor().b, 1.0 };
	
			glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_color);
			glMaterialfv(GL_FRONT, GL_AMBIENT, mat_color);
			

			glVertexPointer(4, GL_FLOAT, 0, &mesh.GetVertex(0));
	        glNormalPointer(GL_FLOAT, 0, &mesh.GetNormal(0));
		    glColorPointer(3, GL_FLOAT, 0, &mesh.GetBinormal(0));
			glDrawElements(GL_LINES, mesh.GetTriangleCount()*3, 
                        GL_UNSIGNED_SHORT, &mesh.GetTriangle(0));

		}


		
		GLfloat mat_color[] = { 1.0,1.0,1.0, 1.0 };
		GLfloat mat_specular[] = { 1.0f,1.0f,1.0f, 1.0 };
 		GLfloat mat_shininess[] ={0.0};
		
		glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_color);
		glMaterialfv(GL_FRONT, GL_AMBIENT, mat_color);
		glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);

		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		glMatrixMode( GL_MODELVIEW );						// Set our matrix to our model view matrix
		glPushMatrix();										// Push on a new matrix to work with
		glLoadIdentity();									// Reset that matrix
		glRasterPos4f( -0.98, 0.96, 0, 1 );						// Set the drawing position
		CString s="Model: Staircase.dxf (Generated with Autocad)";
		glCallLists (s.GetLength(), GL_UNSIGNED_BYTE, s); 
		glRasterPos4f( -0.98, 0.91, 0, 1 );						// Set the drawing position
		s="Left view";
		glCallLists (s.GetLength(), GL_UNSIGNED_BYTE, s); 
		glPopMatrix();



		SwapBuffers(renderDC);

	}



	//ripristino la projection matrix
	glMatrixMode(GL_PROJECTION);
	glLoadMatrixf((GLfloat*)tempMatrix);



}



void CStaircaseRenderer::RenderUpView(HDC renderDC){

	GLfloat mat_color[] = { 1.0, 1.0, 1.0, 1.0 };
   

    glMaterialfv(GL_FRONT, GL_AMBIENT, mat_color);

	glClearColor(0.5, 0.5, 0.5, 0.0);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);  
	glEnable(GL_NORMALIZE);
	glEnable(GL_LIGHTING);
	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_NORMAL_ARRAY);
	glEnableClientState(GL_COLOR_ARRAY);



	float maxRadius=0;

	for(int i=0; i<m_loader.GetMeshCount(); i++)
		maxRadius=(m_loader.GetMesh(i).GetRadius() > maxRadius) ? m_loader.GetMesh(i).GetRadius() : maxRadius;


	float rot=90;

	GLfloat tempMatrix[4][4];


	ZeroMemory(tempMatrix,4*4*4);

	glGetFloatv(GL_PROJECTION_MATRIX,(GLfloat*)tempMatrix);

	GLfloat ambient_color[]={ 1,1,1,1};



	int start=timeGetTime();
	int currTime=0;

	while((currTime=timeGetTime()) - start <=10000){


		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	

		glMatrixMode(GL_PROJECTION);
		glLoadMatrixf((GLfloat*)tempMatrix);


		//imposto il punto di vista
		float pow= ((currTime - start > 1000)  && (currTime - start<8000 ) ) ? -1.1f*maxRadius :  -2.5f*maxRadius; 

		float dir = ((currTime - start > 3500) && (currTime - start<6000)) ? 120 : 0;


		gluLookAt(dir,420 ,pow,    dir,420,0,     0, 1, 0);		// This determines where the camera's position and view is


		glMatrixMode(GL_MODELVIEW);							

		glLoadIdentity();

		GLfloat light_pos[] ={ 0,0,-200,0};

		glRotatef(-180,1.0,0,0);


		for(int u=0; u< m_loader.GetMeshCount(); u++){

			LMesh &mesh=m_loader.GetMesh(u);


			glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambient_color);  


			LMaterial m=m_loader.GetMaterial(mesh.GetMaterial(0));
			GLfloat mat_color[] = { m.GetDiffuseColor().r, m.GetDiffuseColor().g, m.GetDiffuseColor().b, 1.0 };
	
			glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_color);
			glMaterialfv(GL_FRONT, GL_AMBIENT, mat_color);
			

			glVertexPointer(4, GL_FLOAT, 0, &mesh.GetVertex(0));
	        glNormalPointer(GL_FLOAT, 0, &mesh.GetNormal(0));
		    glColorPointer(3, GL_FLOAT, 0, &mesh.GetBinormal(0));
			glDrawElements(GL_LINES, mesh.GetTriangleCount()*3, 
                        GL_UNSIGNED_SHORT, &mesh.GetTriangle(0));

		}


		
		GLfloat mat_color[] = { 1.0,1.0,1.0, 1.0 };
		GLfloat mat_specular[] = { 1.0f,1.0f,1.0f, 1.0 };
 		GLfloat mat_shininess[] ={0.0};
		
		glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_color);
		glMaterialfv(GL_FRONT, GL_AMBIENT, mat_color);
		glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);

		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		glMatrixMode( GL_MODELVIEW );						// Set our matrix to our model view matrix
		glPushMatrix();										// Push on a new matrix to work with
		glLoadIdentity();									// Reset that matrix
		glRasterPos4f( -0.98, 0.96, 0, 1 );						// Set the drawing position
		CString s="Model: Staircase.dxf (Generated with Autocad)";
		glCallLists (s.GetLength(), GL_UNSIGNED_BYTE, s); 
		glRasterPos4f( -0.98, 0.91, 0, 1 );						// Set the drawing position
		s="Up view";
		glCallLists (s.GetLength(), GL_UNSIGNED_BYTE, s); 
		glPopMatrix();

		SwapBuffers(renderDC);

	}



	//ripristino la projection matrix
	glMatrixMode(GL_PROJECTION);
	glLoadMatrixf((GLfloat*)tempMatrix);



}



void CStaircaseRenderer::Render(HDC renderDC){

	glDisable(GL_LIGHT0);

	RenderLeftView(renderDC);
//	RenderUpView(renderDC);
	RenderPerspectiveView(renderDC);
	RenderPerspectiveShadedView(renderDC);




}
void CStaircaseRenderer::RenderPerspectiveShadedView(HDC renderDC){

    GLfloat light_position[] = { 1.0, 1.0, 1.0, 0.0 };

   // glLightfv(GL_LIGHT0, GL_POSITION, light_position);

	glClearColor(0.5, 0.5, 0.5, 0.0);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);  
	glEnable(GL_NORMALIZE);
	glEnable(GL_LIGHTING);
	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_NORMAL_ARRAY);
	glEnableClientState(GL_COLOR_ARRAY);

	GLfloat glfLightAmbient[] = {0.0, 0.0, 0.0, 1.0};
	GLfloat glfLightDiffuse[] = {1.0, 1.0, 1.0, 1.0};
	GLfloat glfLightSpecular[] = {1.0f, 1.0f, 1.0f, 1.0f};
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, glfLightAmbient);  

   	glLightfv(GL_LIGHT0, GL_AMBIENT, glfLightAmbient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, glfLightDiffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, glfLightSpecular);

	float maxRadius=0;

	for(int i=0; i<m_loader.GetMeshCount(); i++)
		maxRadius=(m_loader.GetMesh(i).GetRadius() > maxRadius) ? m_loader.GetMesh(i).GetRadius() : maxRadius;


	float rot=90;

	GLfloat tempMatrix[4][4];


	ZeroMemory(tempMatrix,4*4*4);

	glGetFloatv(GL_PROJECTION_MATRIX,(GLfloat*)tempMatrix);



	int start=timeGetTime();

	while(timeGetTime() - start <=5000){


		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	

		glMatrixMode(GL_PROJECTION);
		glLoadMatrixf((GLfloat*)tempMatrix);


		//imposto il punto di vista
		gluLookAt(0,100 , -1.8f*maxRadius,    0,100,0,     0, 1, 0);		// This determines where the camera's position and view is


		glMatrixMode(GL_MODELVIEW);							
		glLoadIdentity();

		GLfloat light_pos[] ={ 0,0,-1200,0};

		//posizione della luce
		glLightfv(GL_LIGHT0,GL_POSITION,light_pos);
		glEnable(GL_LIGHT0);

		glRotatef(-90,1.0,0,0);
		glRotatef(-15,0,0,1);
		glRotatef(-20,1,0,0);



		for(int u=0; u< m_loader.GetMeshCount(); u++){

			LMesh &mesh=m_loader.GetMesh(u);


			LMaterial m=m_loader.GetMaterial(mesh.GetMaterial(0));
			GLfloat mat_color[] = { m.GetDiffuseColor().r, m.GetDiffuseColor().g, m.GetDiffuseColor().b, 1.0 };
			GLfloat mat_specular[] = { m.GetSpecularColor().r, m.GetSpecularColor().g, m.GetSpecularColor().b, 1.0 };
	 		GLfloat mat_shininess[] ={40.0};

	
			glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_color);
		    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
		    glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
		  
			
			glVertexPointer(4, GL_FLOAT, 0, &mesh.GetVertex(0));
	        glNormalPointer(GL_FLOAT, 0, &mesh.GetNormal(0));
		    glColorPointer(3, GL_FLOAT, 0, &mesh.GetBinormal(0));
			glDrawElements(GL_TRIANGLES, mesh.GetTriangleCount()*3, 
                        GL_UNSIGNED_SHORT, &mesh.GetTriangle(0));


		}


		glDisable(GL_LIGHT0);

		
		GLfloat mat_color2[] = { 1.0,1.0,1.0, 1.0 };
		GLfloat mat_specular2[] = { 1.0f,1.0f,1.0f, 1.0 };
 		GLfloat mat_shininess2[] ={0.0};
		
		glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular2);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_color2);
		glMaterialfv(GL_FRONT, GL_AMBIENT, mat_color2);
		glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess2);

		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		glMatrixMode( GL_MODELVIEW );						// Set our matrix to our model view matrix
		glPushMatrix();										// Push on a new matrix to work with
		glLoadIdentity();									// Reset that matrix
		glRasterPos4f( -0.98, 0.96, 0, 1 );						// Set the drawing position
		CString s="Model: Staircase.dxf (Generated with Autocad)";
		glCallLists (s.GetLength(), GL_UNSIGNED_BYTE, s); 
		glRasterPos4f( -0.98, 0.91, 0, 1 );						// Set the drawing position
		s="Perspective view (shaded)";
		glCallLists (s.GetLength(), GL_UNSIGNED_BYTE, s); 
		glPopMatrix();




		SwapBuffers(renderDC);

	}



	//ripristino la projection matrix
	glMatrixMode(GL_PROJECTION);
	glLoadMatrixf((GLfloat*)tempMatrix);



}
