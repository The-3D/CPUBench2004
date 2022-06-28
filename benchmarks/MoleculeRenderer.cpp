// MoleculeRenderer.cpp: implementation of the CMoleculeRenderer class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "benchmarks.h"
#include "MoleculeRenderer.h"
#include <math.h>

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CMoleculeRenderer::CMoleculeRenderer()
{

	rot=90;
}

CMoleculeRenderer::~CMoleculeRenderer()
{

}

float CMoleculeRenderer::distance(CAtom* a1,CAtom* a2){


	float x1=a1->GetX();
	float x2=a2->GetX();

	float y1=a1->GetY();
	float y2=a2->GetY();

	float z1=a1->GetZ();
	float z2=a2->GetZ();


	return sqrt(pow(x2-x1,2)+pow(y2-y1,2)+pow(z2-z1,2));
}


void CMoleculeRenderer::RenderMolecule(const CMolecule *mol, RENDER_MODE mode){


	GLUquadricObj *pObj = gluNewQuadric();				// Get a new Quadric off the stack



	const CArray<CGroup*,CGroup*>  *groups=mol->GetGroups();
	const CArray<CLink*,CLink*>  *links=mol->GetLinks();

	float objCenterX=mol->GetX();
	float objCenterY=mol->GetY();
	float objCenterZ=mol->GetZ();

	GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat mat_shininess[] = { 25.0 };



	if(mode == BACKBONE){

		const CArray<CAtom*,CAtom*> *bb=mol->GetBackbone();

		for(int i=0; i<bb->GetSize(); i++){
	
			float atomSize=0.98f;

		GLfloat mat_color[] = { bb->GetAt(i)->GetR()/255.0, bb->GetAt(i)->GetG()/255.0, bb->GetAt(i)->GetB()/255.0, 1.0 };
   
	
	    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_color);
	    glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);


		
		glPushMatrix();										// Push on a new matrix scope
			glRotatef(rot, 0.0, 1.0, 0.0);				// Rotate the sphere around the Y axis to make it spin
			glTranslatef(bb->GetAt(i)->GetX()-objCenterX, bb->GetAt(i)->GetY()-objCenterY, bb->GetAt(i)->GetZ()-objCenterZ);							// Translate this sphere to the left
//			glRotatef(rot, 1.0, 1.0, 1.0);				// Rotate the sphere around the Y axis to make it spin
			gluSphere(pObj, atomSize, 20,20);					// Draw the sunwith a radius of 0.5
		glPopMatrix();// End the current scope of this matrix

		}
	

		for(i=0; i<bb->GetSize()-1; i++){

			float v1x=bb->GetAt(i+1)->GetX() - bb->GetAt(i)->GetX();
			float v1y=bb->GetAt(i+1)->GetY() - bb->GetAt(i)->GetY();
			float v1z=bb->GetAt(i+1)->GetZ() - bb->GetAt(i)->GetZ();


			float vlenght=sqrt(v1x*v1x+v1y*v1y+v1z*v1z);


			float angle=180*acos(v1z/vlenght)/3.14159;

			if(v1z <=0.0) angle=-angle;




			
			GLfloat mat_color[] = { bb->GetAt(0)->GetR()/255.0, bb->GetAt(0)->GetG()/255.0, bb->GetAt(0)->GetB()/255.0, 1.0 };
   
   
			mat_shininess[0] =10.0;
		
			glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
			glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_color);
			glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);

			glPushMatrix();										// Push on a new matrix scope
				glRotatef(rot, 0.0, 1.0, 0.0);				// Rotate the sphere around the Y axis to make it spin
				glTranslatef(bb->GetAt(i)->GetX()-objCenterX,bb->GetAt(i)->GetY()-objCenterY,bb->GetAt(i)->GetZ()-objCenterZ);							// Translate this sphere to the left
				glRotated(angle,-v1y*v1z,v1x*v1z,0.0);
				gluCylinder(pObj, 1.0,1.0,distance(bb->GetAt(i),bb->GetAt(i+1)),15,15);					// Draw the sunwith a radius of 0.5
			
			glPopMatrix();// End the current scope of this matrix

		}

	}

	else {

	for(int i=0; i<groups->GetSize(); i++)
		for(int j=0; j<groups->GetAt(i)->NumAtoms(); j++){

			float atomSize=(mode == FILLSPACE) ? groups->GetAt(i)->GetAtom(j)->GetVanDerWaalsRadius()/250.0f : 0.30f;

		GLfloat mat_color[] = { groups->GetAt(i)->GetAtom(j)->GetR()/255.0, groups->GetAt(i)->GetAtom(j)->GetG()/255.0, groups->GetAt(i)->GetAtom(j)->GetB()/255.0, 1.0 };
   
	
	    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_color);
	    glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);


		
		glPushMatrix();										// Push on a new matrix scope
			glRotatef(rot, 0.0, 1.0, 0.0);				// Rotate the sphere around the Y axis to make it spin
			glTranslatef(groups->GetAt(i)->GetAtom(j)->GetX()-objCenterX, groups->GetAt(i)->GetAtom(j)->GetY()-objCenterY, groups->GetAt(i)->GetAtom(j)->GetZ()-objCenterZ);							// Translate this sphere to the left
//			glRotatef(rot, 1.0, 1.0, 1.0);				// Rotate the sphere around the Y axis to make it spin
			gluSphere(pObj, atomSize, 6,6);					// Draw the sunwith a radius of 0.5
		glPopMatrix();// End the current scope of this matrix

	}


	if(mode == STICK_N_BALLS){
	
		for(i=0; i<links->GetSize(); i++){


			float v1x=links->GetAt(i)->GetDest()->GetX() - links->GetAt(i)->GetSource()->GetX();
			float v1y=links->GetAt(i)->GetDest()->GetY() - links->GetAt(i)->GetSource()->GetY();
			float v1z=links->GetAt(i)->GetDest()->GetZ() - links->GetAt(i)->GetSource()->GetZ();


			float vlenght=sqrt(v1x*v1x+v1y*v1y+v1z*v1z);


			float angle=180*acos(v1z/vlenght)/3.14159;

			if(v1z <=0.0) angle=-angle;




			
			GLfloat mat_color[] = { 1.0,1.0,1.0, 1.0 };
   
			mat_shininess[0] =10.0;
		
			glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
			glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_color);
			glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);

			glPushMatrix();										// Push on a new matrix scope
				glRotatef(rot, 0.0, 1.0, 0.0);				// Rotate the sphere around the Y axis to make it spin
				glTranslatef(links->GetAt(i)->GetSource()->GetX()-objCenterX,links->GetAt(i)->GetSource()->GetY()-objCenterY,links->GetAt(i)->GetSource()->GetZ()-objCenterZ);							// Translate this sphere to the left
				glRotated(angle,-v1y*v1z,v1x*v1z,0.0);
				gluCylinder(pObj, 0.09f,0.09f,distance(links->GetAt(i)->GetSource(),links->GetAt(i)->GetDest()),3,3);					// Draw the sunwith a radius of 0.5
			
			glPopMatrix();// End the current scope of this matrix

		}

	}

		if(mode == STICK_N_BALLS){
	
		for(i=0; i<links->GetSize(); i++){


			float v1x=links->GetAt(i)->GetDest()->GetX() - links->GetAt(i)->GetSource()->GetX();
			float v1y=links->GetAt(i)->GetDest()->GetY() - links->GetAt(i)->GetSource()->GetY();
			float v1z=links->GetAt(i)->GetDest()->GetZ() - links->GetAt(i)->GetSource()->GetZ();


			float vlenght=sqrt(v1x*v1x+v1y*v1y+v1z*v1z);


			float angle=180*acos(v1z/vlenght)/3.14159;

			if(v1z <=0.0) angle=-angle;




			
			GLfloat mat_color[] = { 1.0,1.0,1.0, 1.0 };
   
			mat_shininess[0] =10.0;
		
			glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
			glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_color);
			glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);

			glPushMatrix();										// Push on a new matrix scope
				glRotatef(rot, 0.0, 1.0, 0.0);				// Rotate the sphere around the Y axis to make it spin
				glTranslatef(links->GetAt(i)->GetSource()->GetX()-objCenterX,links->GetAt(i)->GetSource()->GetY()-objCenterY,links->GetAt(i)->GetSource()->GetZ()-objCenterZ);							// Translate this sphere to the left
				glRotated(angle,-v1y*v1z,v1x*v1z,0.0);
				gluCylinder(pObj, 0.09f,0.09f,distance(links->GetAt(i)->GetSource(),links->GetAt(i)->GetDest()),3,3);					// Draw the sunwith a radius of 0.5
			
			glPopMatrix();// End the current scope of this matrix

		}

	}

	}

		
	gluDeleteQuadric(pObj);

	rot+=0.8;


	/* informazioni sulla molecola */

	glDisable(GL_LIGHTING);
	glDisable(GL_LIGHT0);

			
	mat_specular[0]=0;
	mat_specular[1]=0;
	mat_specular[2]=0;

			//	GLfloat mat_color[] = { links->GetAt(i)->GetSource()->GetR()/255.0, links->GetAt(i)->GetSource()->GetG()/255.0, links->GetAt(i)->GetSource()->GetB()/255.0, 1.0 };
  	GLfloat mat_color[] = { 1.0,1.0,1.0, 1.0 };
   
	mat_shininess[0] =0.0;
		
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_color);
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
	

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glMatrixMode( GL_MODELVIEW );						// Set our matrix to our model view matrix
	glPushMatrix();										// Push on a new matrix to work with
	glLoadIdentity();									// Reset that matrix

	glRasterPos4f( -0.96, 0.94, 0, 1 );						// Set the drawing position

	CString s;

	switch(mode){
		
		
	case STICK_N_BALLS:

		glCallLists (mol->GetName().GetLength(), GL_UNSIGNED_BYTE, mol->GetName()); 

		glRasterPos4f( -0.96, 0.89, 0, 1 );						// Set the drawing position
	
		glCallLists (mol->GetInformations().GetLength(), GL_UNSIGNED_BYTE, mol->GetInformations()); 


		glRasterPos4f( -0.96, 0.84, 0, 1 );						// Set the drawing position

		s = "Balls & sticks method";

		glCallLists (s.GetLength(), GL_UNSIGNED_BYTE, s); 

		break;

	case FILLSPACE:
		

	//glRasterPos4f( -0.96, 0.84, 0, 1 );						// Set the drawing position
		s="Fillspace method";
		glCallLists (s.GetLength(), GL_UNSIGNED_BYTE, s); 
		break;

	case BACKBONE:

		s = "P backbone";
		glCallLists (s.GetLength(), GL_UNSIGNED_BYTE, s); 

		break;
	}



	glPopMatrix();	// Pop the current modelview matrix off the stack
	glPopMatrix();

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);




}
