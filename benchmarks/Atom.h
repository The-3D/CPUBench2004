// Atom.h: interface for the CAtom class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_ATOM_H__0EC8DCCB_AF1E_4D8E_99E0_5C14D9BF6D8D__INCLUDED_)
#define AFX_ATOM_H__0EC8DCCB_AF1E_4D8E_99E0_5C14D9BF6D8D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CAtom  
{



public:

	bool operator==(CAtom &b){

		return x == b.x && y == b.y && z == b.z;

	}


	CAtom(CString name,int r,int g, int b,float x,float y,float z,int vdwRadius,int covRadius){

		this->name=name;
		this->x=x;
		this->y=y;
		this->z=z;
		this->r=r;
		this->g=g;
		this->b=b;
		this->vdwRadius=(float)vdwRadius; //250 indica la conversione in angstroms
		this->covRadius=(float)covRadius;

	}

	inline int GetR(){ return r; }
	inline int GetG(){ return g; }
	inline int GetB(){ return b; }
	inline float GetX(){ return x; }
	inline float GetY(){ return y; }
	inline float GetZ(){ return z; }
	inline CString GetName(){ return name; }
	inline float GetVanDerWaalsRadius() { return vdwRadius; }
	inline float GetCovalentBondRadius() { return covRadius; }
	


	virtual ~CAtom();


private:
	int r,g,b;
	float x,y,z;
	CString name;
	float vdwRadius,covRadius;
};

#endif // !defined(AFX_ATOM_H__0EC8DCCB_AF1E_4D8E_99E0_5C14D9BF6D8D__INCLUDED_)
