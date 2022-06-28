// Molecule.cpp: implementation of the CMolecule class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "benchmarks.h"
#include "Molecule.h"
#include <math.h>
//#include "stringtokenizer.h"


#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////



#define r2d (180/3.14159);

CMolecule::CMolecule()
{

}

CMolecule::CMolecule(CString file){

}


void CMolecule::BuildLinks(){


	for(int u=0; u<m_groups.GetSize(); u++){
		for(int i=0; i<m_groups[u]->NumAtoms(); i++)
			for(int j=0; j<m_groups[u]->NumAtoms(); j++){
			
				if(i==j) continue;

				if(TestLink(m_groups[u]->GetAtom(i),m_groups[u]->GetAtom(j))){

					CLink *l=new CLink(m_groups[u]->GetAtom(i),m_groups[u]->GetAtom(j));

					for(int k=0; k<m_links.GetSize(); k++)
						if(*m_links[k]==*l) break;


					if(k==m_links.GetSize())
						m_links.Add(l);
			}
		}

	}

}








bool CMolecule::TestLink(CAtom* a,CAtom *b){

//	int aIndex=GetElemNumber(a->GetName());
//	int bIndex=GetElemNumber(b->GetName());

//	CString str;

//	str.Format("%d %d",aIndex,bIndex);

	//MessageBox(NULL,str,NULL,NULL);


	float max=0;

    float dist = b->GetCovalentBondRadius() + a->GetCovalentBondRadius() + 140;
    max = dist*dist;
    

	//dist=distance(a,b);

	float dx=a->GetX()*250.0f-b->GetX()*250.0f;
	float dy=a->GetY()*250.0f-b->GetY()*250.0f;
	float dz=a->GetZ()*250.0f-b->GetZ()*250.0f;

	dist = dx*dx+dy*dy+dz*dz;

//	str.Format("%1.2f,%1.2f",dist,max);

//	MessageBox(NULL,str,NULL,NULL);


    if(dist >max ) return false;


//	if(dist < MinBondDist)	return false;

	return true;

}




	
CMolecule::~CMolecule()
{
	m_groups.RemoveAll();
	m_links.RemoveAll();

}
