// MoleculeBuilder.h: interface for the CMoleculeBuilder class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MOLECULEBUILDER_H__47EA8F27_1053_41EF_8868_5CAA2A25C3E8__INCLUDED_)
#define AFX_MOLECULEBUILDER_H__47EA8F27_1053_41EF_8868_5CAA2A25C3E8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "molecule.h"

class CMoleculeBuilder  
{
public:
	CMoleculeBuilder();

	void BuildFromFile(CString file);


	const CMolecule* GetMolecule() { return (const CMolecule*)&m_molecule; }

	virtual ~CMoleculeBuilder();

private:

	CMolecule m_molecule;

};

#endif // !defined(AFX_MOLECULEBUILDER_H__47EA8F27_1053_41EF_8868_5CAA2A25C3E8__INCLUDED_)
