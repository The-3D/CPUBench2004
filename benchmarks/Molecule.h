// Molecule.h: interface for the CMolecule class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MOLECULE_H__DCDB6991_96FA_4163_B2E4_DC908137CEA6__INCLUDED_)
#define AFX_MOLECULE_H__DCDB6991_96FA_4163_B2E4_DC908137CEA6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include <afxtempl.h>
#include "atom.h"
#include "element.h"




class CGroup {


public:

	void AddAtom(CAtom* a){

		m_atoms.Add(a);
	}

	int NumAtoms(){ return m_atoms.GetSize(); }

	CAtom* GetAtom(int index) { return m_atoms[index]; }



private:

	CArray<CAtom*,CAtom*> m_atoms;

};


class CLink {

public:


	bool operator==(CLink& b){

		return m_source ==b.m_source && m_dest == b.m_dest ||
			   m_source ==b.m_dest && m_dest == b.m_source;

	}


	CLink(CAtom *a, CAtom *b){

		m_source=a;
		m_dest=b;
	}

	CAtom* GetSource(){ return m_source; }
	CAtom* GetDest(){ return m_dest; }


private:
	CAtom *m_source, *m_dest;

};


class CMolecule  
{



public:

	CMolecule();
	CMolecule(CString file);

	inline float GetX() const { return m_objCenterX; } 
	inline float GetY() const { return m_objCenterY; }
	inline float GetZ() const { return m_objCenterZ; }
	inline float GetRadius() const { return m_objectRadius;}

	void SetX(float x) { m_objCenterX=x; }
	void SetY(float y) { m_objCenterY=y; }
	void SetZ(float z) { m_objCenterZ=z; }
	void SetRadius(float r) { m_objectRadius=r; }




	inline CString GetName() const { return m_name; }
	void SetName(CString name){ m_name=name; }

	void AddGroup(CGroup *p) { m_groups.Add(p); }

	void AddAtomToGroup(CAtom* a,int group){ m_groups[group-1]->AddAtom(a); }
	
	void AddAtomToBackbone(CAtom* a){

		m_backbone.Add(a);
	}

	void BuildLinks();

	CString GetInformations() const {


		int atoms=0;

		for(int i=0; i<m_groups.GetSize(); i++){
			atoms+=m_groups[i]->NumAtoms();
		}


		CString str;

		str.Format("%d atoms, %d groups, %d bonds",atoms,m_groups.GetSize(), m_links.GetSize());

		return str;
	}



	
	virtual ~CMolecule();


	const CArray<CGroup*,CGroup*> * GetGroups() const { return (const CArray<CGroup*,CGroup*> *)&m_groups; }
	const CArray<CLink*,CLink*> * GetLinks() const { return (const CArray<CLink*,CLink*> *)&m_links; }
	const CArray<CAtom*,CAtom*> * GetBackbone() const { return (const CArray<CAtom*,CAtom*> *)&m_backbone; }



private:

	bool TestLink(CAtom* a,CAtom* b);

	
	CArray<CGroup*,CGroup*> m_groups;
	CArray<CLink*,CLink*> m_links;
	CArray<CAtom*,CAtom*> m_backbone;
	CString m_name;
	float m_objCenterX,m_objCenterY,m_objCenterZ,m_objectRadius;


};

#endif // !defined(AFX_MOLECULE_H__DCDB6991_96FA_4163_B2E4_DC908137CEA6__INCLUDED_)
