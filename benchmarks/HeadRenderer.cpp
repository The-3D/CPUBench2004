// HeadRenderer.cpp: implementation of the CHeadRenderer class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
//#include "prova CAD benchmark.h"
#include "HeadRenderer.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CHeadRenderer::CHeadRenderer()
{

	LoadModel(".\\caddata\\d2.dll");
}

CHeadRenderer::~CHeadRenderer()
{

}



void CHeadRenderer::RenderWireframeWithAmbient(HDC renderDC){

		//trovo il raggio più grande tra le mesh all'interno del file

	float maxRadius=0;

	for(int i=0; i<m_loader.GetMeshCount(); i++)
		maxRadius=(m_loader.GetMesh(i).GetRadius() > maxRadius) ? m_loader.GetMesh(i).GetRadius() : maxRadius;


	float rot=90;



	GLfloat tempMatrix[4][4];


	ZeroMemory(tempMatrix,4*4*4);

	glGetFloatv(GL_PROJECTION_MATRIX,(GLfloat*)tempMatrix);

	

	while(rot < 260.0f){


		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	


		glMatrixMode(GL_PROJECTION);
		glLoadMatrixf((GLfloat*)tempMatrix);


		//imposto il punto di vista
		gluLookAt(0,0 , -1.7f*maxRadius,    0,0,0,     0, 1, 0);		// This determines where the camera's position and view is


		glMatrixMode(GL_MODELVIEW);							
		glLoadIdentity();

		GLfloat light_pos[] ={ 0,0,-200,0};

		//posizione della luce
		glLightfv(GL_LIGHT0,GL_POSITION,light_pos);

		glPushMatrix();
		//ruoto la testa di 90° lungo l'asse x
		glRotatef(-90,1.0,0,0);

		glRotatef(rot, 0.0,0 , 1.0);
	
		for(int u=0; u< m_loader.GetMeshCount(); u++){

			LMesh &mesh=m_loader.GetMesh(u);

//			glPushMatrix();


			//traslo il modello al centro del sistema di coordinate	
			glTranslatef(-mesh.GetCenter().x,-mesh.GetCenter().y,-mesh.GetCenter().z);							// Translate this sphere to the left



			LMaterial m=m_loader.GetMaterial(mesh.GetMaterial(0));
			GLfloat mat_color[] = { m.GetDiffuseColor().r, m.GetDiffuseColor().g, m.GetDiffuseColor().b, 1.0 };
			GLfloat ambient_color[] = { 1.0f, 1.0f, 1.0f, 1.0 };
	//		GLfloat mat_specular[] = { m.GetSpecularColor().r, m.GetSpecularColor().g, m.GetSpecularColor().b, 1.0 };
 
		//	GLfloat shininess[]={m.GetShininess()};

			glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_color);
			glMaterialfv(GL_FRONT, GL_AMBIENT, mat_color);

//  			glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
		  

    
			glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambient_color);  
//			glLightModelfv(GL_LIGHT_MODEL_LOCAL_VIEWER, local_view); 
	

			glVertexPointer(4, GL_FLOAT, 0, &mesh.GetVertex(0));
	        glNormalPointer(GL_FLOAT, 0, &mesh.GetNormal(0));
		    glColorPointer(3, GL_FLOAT, 0, &mesh.GetBinormal(0));


			glDrawElements(GL_LINES, mesh.GetTriangleCount()*3, 
                        GL_UNSIGNED_SHORT, &mesh.GetTriangle(0));


	


		}

		glPopMatrix();



		GLfloat mat_color[] = { 1.0,1.0,1.0, 1.0 };

		glMaterialfv(GL_FRONT, GL_AMBIENT, mat_color);

		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		glMatrixMode( GL_MODELVIEW );						// Set our matrix to our model view matrix
		glPushMatrix();										// Push on a new matrix to work with
		glLoadIdentity();									// Reset that matrix
		glRasterPos4f( -0.98, 0.96, 0, 1 );						// Set the drawing position
		CString s="Model: PatchHead.max (from 3ds max 4.2)";
		glCallLists (s.GetLength(), GL_UNSIGNED_BYTE, s); 
		glRasterPos4f( -0.98, 0.91, 0, 1 );						// Set the drawing position
		s="Rendering mode: wireframe, without lighting (using ambient light)";
		glCallLists (s.GetLength(), GL_UNSIGNED_BYTE, s); 
		glPopMatrix();



		SwapBuffers(renderDC);

		rot+=0.5;

	}


		
	//ripristino la projection matrix
	glMatrixMode(GL_PROJECTION);
	glLoadMatrixf((GLfloat*)tempMatrix);


}


void CHeadRenderer::RenderShadedWithLight(HDC renderDC){


		//trovo il raggio più grande tra le mesh all'interno del file

	float maxRadius=0;

	for(int i=0; i<m_loader.GetMeshCount(); i++)
		maxRadius=(m_loader.GetMesh(i).GetRadius() > maxRadius) ? m_loader.GetMesh(i).GetRadius() : maxRadius;


	float rot=90;

	GLfloat tempMatrix[4][4];


	ZeroMemory(tempMatrix,4*4*4);

	glGetFloatv(GL_PROJECTION_MATRIX,(GLfloat*)tempMatrix);


	while(rot < 260.0f){


		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	

		glMatrixMode(GL_PROJECTION);
		glLoadMatrixf((GLfloat*)tempMatrix);


		//imposto il punto di vista
		gluLookAt(0,0 , -1.7f*maxRadius,    0,0,0,     0, 1, 0);		// This determines where the camera's position and view is


		glMatrixMode(GL_MODELVIEW);							
		glLoadIdentity();

		GLfloat light_pos[] ={ 0,0,-200,0};

		//posizione della luce
		glLightfv(GL_LIGHT0,GL_POSITION,light_pos);
		glEnable(GL_LIGHT0);


		glPushMatrix();
		//ruoto la testa di 90° lungo l'asse x
		glRotatef(-90,1.0,0,0);

		glRotatef(rot, 0.0,0 , 1.0);
	
		for(int u=0; u< m_loader.GetMeshCount(); u++){

			LMesh &mesh=m_loader.GetMesh(u);

//			glPushMatrix();


			//traslo il modello al centro del sistema di coordinate	
			glTranslatef(-mesh.GetCenter().x,-mesh.GetCenter().y,-mesh.GetCenter().z);							// Translate this sphere to the left



			LMaterial m=m_loader.GetMaterial(mesh.GetMaterial(0));
			GLfloat mat_color[] = { m.GetDiffuseColor().r, m.GetDiffuseColor().g, m.GetDiffuseColor().b, 1.0 };
	
			glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_color);
			glMaterialfv(GL_FRONT, GL_AMBIENT, mat_color);
		  
			GLfloat mat_specular[] = { 0.0f,0.0f,0.0f, 1.0 };
 		
			glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
			
	

			glVertexPointer(4, GL_FLOAT, 0, &mesh.GetVertex(0));
	        glNormalPointer(GL_FLOAT, 0, &mesh.GetNormal(0));
		    glColorPointer(3, GL_FLOAT, 0, &mesh.GetBinormal(0));
			glDrawElements(GL_TRIANGLES, mesh.GetTriangleCount()*3, 
                        GL_UNSIGNED_SHORT, &mesh.GetTriangle(0));


			glPopMatrix();



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
		CString s="Model: PatchHead.max (from 3ds max 4.2)";
		glCallLists (s.GetLength(), GL_UNSIGNED_BYTE, s); 
		glRasterPos4f( -0.98, 0.91, 0, 1 );						// Set the drawing position
		s="Rendering mode: shaded, one light";
		glCallLists (s.GetLength(), GL_UNSIGNED_BYTE, s); 
		glPopMatrix();




		SwapBuffers(renderDC);

		rot+=0.5;

	}


	//ripristino la projection matrix
	glMatrixMode(GL_PROJECTION);
	glLoadMatrixf((GLfloat*)tempMatrix);



}




void CHeadRenderer::RenderShadedWithSpecular(HDC renderDC){


		//trovo il raggio più grande tra le mesh all'interno del file

	float maxRadius=0;

	for(int i=0; i<m_loader.GetMeshCount(); i++)
		maxRadius=(m_loader.GetMesh(i).GetRadius() > maxRadius) ? m_loader.GetMesh(i).GetRadius() : maxRadius;


	float rot=90;

	GLfloat tempMatrix[4][4];

	ZeroMemory(tempMatrix,4*4*4);

	glGetFloatv(GL_PROJECTION_MATRIX,(GLfloat*)tempMatrix);


    GLfloat mat_shininess[] = { 87.0 };
    GLfloat light_position[] = { 1.0, 1.0, 1.0, 0.0 };

    glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);


	while(rot < 260.0f){


		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	

		glMatrixMode(GL_PROJECTION);
		glLoadMatrixf((GLfloat*)tempMatrix);

		//imposto il punto di vista
		gluLookAt(0,0 , -1.7f*maxRadius,    0,0,0,     0, 1, 0);		// This determines where the camera's position and view is


		glMatrixMode(GL_MODELVIEW);							
		glLoadIdentity();

		GLfloat light_pos[] ={ 0,0,-200,0};

		//posizione della luce
		glLightfv(GL_LIGHT0,GL_POSITION,light_pos);
		glEnable(GL_LIGHT0);


		glPushMatrix();
		//ruoto la testa di 90° lungo l'asse x
		glRotatef(-90,1.0,0,0);

		glRotatef(rot, 0.0,0 , 1.0);
	
		for(int u=0; u< m_loader.GetMeshCount(); u++){

			LMesh &mesh=m_loader.GetMesh(u);

//			glPushMatrix();


			//traslo il modello al centro del sistema di coordinate	
			glTranslatef(-mesh.GetCenter().x,-mesh.GetCenter().y,-mesh.GetCenter().z);							// Translate this sphere to the left



			LMaterial m=m_loader.GetMaterial(mesh.GetMaterial(0));
			GLfloat mat_color[] = { m.GetDiffuseColor().r, m.GetDiffuseColor().g, m.GetDiffuseColor().b, 1.0 };
			GLfloat mat_specular[] = { m.GetSpecularColor().r, m.GetSpecularColor().g, m.GetSpecularColor().b, 1.0 };
	 		GLfloat mat_shininess[] ={85.0};

	
			glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_color);
			glMaterialfv(GL_FRONT, GL_AMBIENT, mat_color);
		    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
		    glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
		  

	

			glVertexPointer(4, GL_FLOAT, 0, &mesh.GetVertex(0));
	        glNormalPointer(GL_FLOAT, 0, &mesh.GetNormal(0));
		    glColorPointer(3, GL_FLOAT, 0, &mesh.GetBinormal(0));
			glDrawElements(GL_TRIANGLES, mesh.GetTriangleCount()*3, 
                        GL_UNSIGNED_SHORT, &mesh.GetTriangle(0));


			glPopMatrix();

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
		CString s="Model: PatchHead.max (from 3ds max 4.2)";
		glCallLists (s.GetLength(), GL_UNSIGNED_BYTE, s); 
		glRasterPos4f( -0.98, 0.91, 0, 1 );						// Set the drawing position
		s="Rendering mode: shaded, one light, specular highlights";
		glCallLists (s.GetLength(), GL_UNSIGNED_BYTE, s); 
		glPopMatrix();




		SwapBuffers(renderDC);

		rot+=0.5;

	}


	//ripristino la projection matrix
	glMatrixMode(GL_PROJECTION);
	glLoadMatrixf((GLfloat*)tempMatrix);




}

void CHeadRenderer::Render(HDC renderDC){


    GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat mat_color[] = { 1.0, 1.0, 1.0, 1.0 };
   
   GLfloat mat_shininess[] = { 40.0 };
    GLfloat light_position[] = { 1.0, 1.0, 1.0, 0.0 };

    glMaterialfv(GL_FRONT, GL_AMBIENT, mat_color);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);

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
    
	glLightfv(GL_LIGHT0, GL_AMBIENT, glfLightAmbient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, glfLightDiffuse);


	RenderWireframeWithAmbient(renderDC);


	glLightModelfv(GL_LIGHT_MODEL_AMBIENT,glfLightAmbient);

	RenderShadedWithLight(renderDC);


	RenderShadedWithSpecular(renderDC);



}


