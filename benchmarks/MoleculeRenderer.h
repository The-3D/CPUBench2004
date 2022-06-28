// MoleculeRenderer.h: interface for the CMoleculeRenderer class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MOLECULERENDERER_H__D69AFEC9_CB9E_4223_9F8D_6A154A647E91__INCLUDED_)
#define AFX_MOLECULERENDERER_H__D69AFEC9_CB9E_4223_9F8D_6A154A647E91__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "molecule.h"

enum RENDER_MODE { FILLSPACE, STICK_N_BALLS,BACKBONE };

#include <GL\gl.h>
#include <GL\glu.h>

class CMoleculeRenderer  
{
public:

	CMoleculeRenderer();


	void RenderMolecule(const CMolecule* molecule, RENDER_MODE renderMode);


	virtual ~CMoleculeRenderer();


private:


	float distance(CAtom* a1,CAtom* a2);

	float rot;




};

#endif // !defined(AFX_MOLECULERENDERER_H__D69AFEC9_CB9E_4223_9F8D_6A154A647E91__INCLUDED_)
