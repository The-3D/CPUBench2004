// MoleculeBuilder.cpp: implementation of the CMoleculeBuilder class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "benchmarks.h"
#include "MoleculeBuilder.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
#define MAXELEMNO  104
typedef struct {
           char symbol[2];
           int covalrad;
           int vdwrad;
           int cpkcol;
           char *name;
        } ElemStruct;


ElemStruct Element[MAXELEMNO] =  {
    { { ' ', ' ' }, 170, 360, 12, ""             },  /*   0 */
    { { 'H', ' ' },  80, 275,  4, "HYDROGEN"     },  /*   1 */
    { { 'H', 'e' }, 400, 550,  5, "HELIUM"       },  /*   2 */
    { { 'L', 'i' }, 170, 305, 14, "LITHIUM"      },  /*   3 */
    { { 'B', 'e' },  88, 157, 12, "BERYLLIUM"    },  /*   4 */
    { { 'B', ' ' }, 208, 387, 13, "BORON"        },  /*   5 */
    { { 'C', ' ' }, 180, 387,  0, "CARBON"       },  /*   6 */
    { { 'N', ' ' }, 170, 350,  1, "NITROGEN"     },  /*   7 */
    { { 'O', ' ' }, 170, 337,  2, "OXYGEN"       },  /*   8 */
    { { 'F', ' ' }, 160, 325,  6, "FLUORINE"     },  /*   9 */
    { { 'N', 'e' }, 280, 505, 12, "NEON"         },  /*  10 */
    { { 'N', 'a' }, 243, 550,  7, "SODIUM"       },  /*  11 */
    { { 'M', 'g' }, 275, 375, 15, "MAGNESIUM"    },  /*  12 */
    { { 'A', 'l' }, 338, 375,  9, "ALUMINIUM"    },  /*  13 */
    { { 'S', 'i' }, 300, 550,  6, "SILICON"      },  /*  14 */
    { { 'P', ' ' }, 259, 470,  8, "PHOSPHORUS"   },  /*  15 */  /* 262? */
    { { 'S', ' ' }, 255, 452,  3, "SULPHUR"      },  /*  16 */
    { { 'C', 'l' }, 250, 437, 13, "CHLORINE"     },  /*  17 */
    { { 'A', 'r' }, 392, 692, 12, "ARGON"        },  /*  18 */
    { { 'K', ' ' }, 332, 597, 12, "POTASSIUM"    },  /*  19 */
    { { 'C', 'a' }, 248, 487,  9, "CALCIUM"      },  /*  20 */
    { { 'S', 'c' }, 360, 330, 12, "SCANDIUM"     },  /*  21 */
    { { 'T', 'i' }, 368, 487,  9, "TITANIUM"     },  /*  22 */
    { { 'V', ' ' }, 332, 265, 12, "VANADIUM"     },  /*  23 */
    { { 'C', 'r' }, 338, 282,  9, "CHROMIUM"     },  /*  24 */
    { { 'M', 'n' }, 338, 297,  9, "MANGANESE"    },  /*  25 */
    { { 'F', 'e' }, 335, 487,  8, "IRON"         },  /*  26 */
    { { 'C', 'o' }, 332, 282, 12, "COBALT"       },  /*  27 */
    { { 'N', 'i' }, 405, 310, 10, "NICKEL"       },  /*  28 */  /* >375! */
    { { 'C', 'u' }, 380, 287, 10, "COPPER"       },  /*  29 */
    { { 'Z', 'n' }, 362, 287, 10, "ZINC"         },  /*  30 */
    { { 'G', 'a' }, 305, 387, 12, "GALLIUM"      },  /*  31 */
    { { 'G', 'e' }, 292, 999, 12, "GERMANIUM"    },  /*  32 */  /* 1225? */
    { { 'A', 's' }, 302, 207, 12, "ARSENIC"      },  /*  33 */
    { { 'S', 'e' }, 305, 225, 12, "SELENIUM"     },  /*  34 */
    { { 'B', 'r' }, 302, 437, 10, "BROMINE"      },  /*  35 */
    { { 'K', 'r' }, 400, 475, 12, "KRYPTON"      },  /*  36 */
    { { 'R', 'b' }, 368, 662, 12, "RUBIDIUM"     },  /*  37 */
    { { 'S', 'r' }, 280, 505, 12, "STRONTIUM"    },  /*  38 */
    { { 'Y', ' ' }, 445, 402, 12, "YTTRIUM"      },  /*  39 */
    { { 'Z', 'r' }, 390, 355, 12, "ZIRCONIUM"    },  /*  40 */
    { { 'N', 'b' }, 370, 332, 12, "NIOBIUM"      },  /*  41 */
    { { 'M', 'o' }, 368, 437, 12, "MOLYBDENUM"   },  /*  42 */
    { { 'T', 'c' }, 338, 450, 12, "TECHNETIUM"   },  /*  43 */
    { { 'R', 'u' }, 350, 300, 12, "RUTHENIUM"    },  /*  44 */
    { { 'R', 'h' }, 362, 305, 12, "RHODIUM"      },  /*  45 */
    { { 'P', 'd' }, 375, 360, 12, "PALLADIUM"    },  /*  46 */
    { { 'A', 'g' }, 398, 387,  9, "SILVER"       },  /*  47 */
    { { 'C', 'd' }, 422, 437, 12, "CADMIUM"      },  /*  48 */
    { { 'I', 'n' }, 408, 362, 12, "INDIUM"       },  /*  49 */
    { { 'S', 'n' }, 365, 417, 12, "TIN",         },  /*  50 */
    { { 'S', 'b' }, 365, 280, 12, "ANTIMONY"     },  /*  51 */
    { { 'T', 'e' }, 368, 315, 12, "TELLURIUM"    },  /*  52 */
    { { 'I', ' ' }, 350, 437, 11, "IODINE"       },  /*  53 */
    { { 'X', 'e' }, 425, 525, 12, "XENON"        },  /*  54 */
    { { 'C', 's' }, 418, 752, 12, "CAESIUM"      },  /*  55 */
    { { 'B', 'a' }, 335, 602,  8, "BARIUM"       },  /*  56 */
    { { 'L', 'a' }, 468, 457, 12, "LANTHANUM"    },  /*  57 */
    { { 'C', 'e' }, 458, 465, 12, "CERIUM"       },  /*  58 */
    { { 'P', 'r' }, 455, 405, 12, "PRASEODYMIUM" },  /*  59 */
    { { 'N', 'd' }, 452, 447, 12, "NEODYMIUM"    },  /*  60 */
    { { 'P', 'm' }, 450, 440, 12, "PROMETHIUM"   },  /*  61 */
    { { 'S', 'm' }, 450, 435, 12, "SAMARIUM"     },  /*  62 */
    { { 'E', 'u' }, 498, 490, 12, "EUROPIUM"     },  /*  63 */
    { { 'G', 'd' }, 448, 422, 12, "GADOLINIUM"   },  /*  64 */
    { { 'T', 'b' }, 440, 415, 12, "TERBIUM"      },  /*  65 */
    { { 'D', 'y' }, 438, 407, 12, "DYSPROSIUM"   },  /*  66 */
    { { 'H', 'o' }, 435, 402, 12, "HOLMIUM"      },  /*  67 */
    { { 'E', 'r' }, 432, 397, 12, "ERBIUM"       },  /*  68 */
    { { 'T', 'm' }, 430, 392, 12, "THULIUM"      },  /*  69 */
    { { 'Y', 'b' }, 485, 385, 12, "YTTERBIUM"    },  /*  70 */
    { { 'L', 'u' }, 430, 382, 12, "LUTETIUM"     },  /*  71 */
    { { 'H', 'f' }, 392, 350, 12, "HAFNIUM"      },  /*  72 */
    { { 'T', 'a' }, 358, 305, 12, "TANTALUM"     },  /*  73 */
    { { 'W', ' ' }, 342, 315, 12, "TUNGSTEN"     },  /*  74 */
    { { 'R', 'e' }, 338, 325, 12, "RHENIUM"      },  /*  75 */
    { { 'O', 's' }, 342, 395, 12, "OSMIUM"       },  /*  76 */
    { { 'I', 'r' }, 330, 305, 12, "IRIDIUM"      },  /*  77 */
    { { 'P', 't' }, 375, 387, 12, "PLATINUM"     },  /*  78 */
    { { 'A', 'u' }, 375, 362,  6, "GOLD"         },  /*  79 */
    { { 'H', 'g' }, 425, 495, 12, "MERCURY"      },  /*  80 */
    { { 'T', 'l' }, 388, 427, 12, "THALLIUM"     },  /*  81 */
    { { 'P', 'b' }, 385, 540, 12, "LEAD"         },  /*  82 */
    { { 'B', 'i' }, 385, 432, 12, "BISMUTH"      },  /*  83 */
    { { 'P', 'o' }, 420, 302, 12, "POLONIUM"     },  /*  84 */
    { { 'A', 't' }, 302, 280, 12, "ASTATINE"     },  /*  85 */
    { { 'R', 'n' }, 475, 575, 12, "RADON"        },  /*  86 */
    { { 'F', 'r' }, 450, 810, 12, "FRANCIUM"     },  /*  87 */
    { { 'R', 'a' }, 358, 642, 12, "RADIUM"       },  /*  88 */
    { { 'A', 'c' }, 295, 530, 12, "ACTINIUM"     },  /*  89 */
    { { 'T', 'h' }, 255, 460, 12, "THORIUM"      },  /*  90 */
    { { 'P', 'a' }, 222, 400, 12, "PROTACTINIUM" },  /*  91 */
    { { 'U', ' ' }, 242, 437, 12, "URANIUM"      },  /*  92 */
    { { 'N', 'p' }, 238, 427, 12, "NEPTUNIUM"    },  /*  93 */
    { { 'P', 'u' }, 232, 417, 12, "PLUTONIUM"    },  /*  94 */
    { { 'A', 'm' }, 230, 415, 12, "AMERICIUM"    },  /*  95 */
    { { 'C', 'm' }, 228, 412, 12, "CURIUM"       },  /*  96 */
    { { 'B', 'k' }, 225, 410, 12, "BERKELIUM"    },  /*  97 */
    { { 'C', 'f' }, 222, 407, 12, "CALIFORNIUM"  },  /*  98 */
    { { 'E', 's' }, 220, 405, 12, "EINSTEINIUM"  },  /*  99 */
    { { 'F', 'm' }, 218, 402, 12, "FERMIUM"      },  /* 100 */
    { { 'M', 'd' }, 215, 400, 12, "MENDELEVIUM"  },  /* 101 */
    { { 'N', 'o' }, 212, 397, 12, "NOBELIUM"     },  /* 102 */
    { { 'L', 'r' }, 210, 395, 12, "LAWRENCIUM"   }   /* 103 */ /* Lw? */
 };



 int GetElemNumber( CString name ){

	char ch1=name[0],ch2=name[1];


    switch( ch1 )
    {   case(' '):  switch( ch2 )
                    {   case('B'):  return(  5 );
                        case('C'):  return(  6 );
                        case('D'):  return(  1 );
                        case('F'):  return(  9 );
                        case('H'):  return(  1 );
                        case('I'):  return( 53 );
                        case('K'):  return( 19 );
                        case('L'):  return(  1 );
                        case('N'):  return(  7 );
                        case('O'):  return(  8 );
                        case('P'):  return( 15 );
                        case('S'):  return( 16 );
                        case('U'):  return( 92 );
                        case('V'):  return( 23 );
                        case('W'):  return( 74 );
                        case('Y'):  return( 39 );
                    }
                    break;

        case('A'):  switch( ch2 )
                    {   case('C'):  return( 89 );
                        case('G'):  return( 47 );
                        case('L'):  return( 13 );
                        case('M'):  return( 95 );
                        case('R'):  return( 18 );
                        case('S'):  return( 33 );
                        case('T'):  return( 85 );
                        case('U'):  return( 79 );
                    }
                    break;

        case('B'):  switch( ch2 )
                    {   case('A'):  return( 56 );
                        case('E'):  return(  4 );
                        case('I'):  return( 83 );
                        case('K'):  return( 97 );
                        case('R'):  return( 35 );
                    }
                    break;

        case('C'):  switch( ch2 )
                    {   case('A'):  return( 20 );
                        case('D'):  return( 48 );
                        case('E'):  return( 58 );
                        case('F'):  return( 98 );
                        case('L'):  return( 17 );
                        case('M'):  return( 96 );
                        case('O'):  return( 27 );
                        case('R'):  return( 24 );
                        case('S'):  return( 55 );
                        case('U'):  return( 29 );
                    }
                    break;

        case('D'):  if( ch2=='Y' )
                        return( 66 );
                    break;

        case('E'):  if( ch2=='R' )
                    {   return( 68 );
                    } else if( ch2=='S' )
                    {   return( 99 );
                    } else if( ch2=='U' )
                        return( 63 );
                    break;

        case('F'):  if( ch2=='E' )
                    {   return(  26 );
                    } else if( ch2=='M' )
                    {   return( 100 );
                    } else if( ch2=='R' )
                        return(  87 );
                    break;

        case('G'):  if( ch2=='A' )
                    {   return( 31 );
                    } else if( ch2=='D' )
                    {   return( 64 );
                    } else if( ch2=='E' )
                        return( 32 );
                    break;

        case('H'):  if( ch2=='E' )
                    {   return(  2 );
                    } else if( ch2=='F' )
                    {   return( 72 );
                    } else if( ch2=='G' )
                    {   return( 80 );
                    } else if( ch2=='O' )
                        return( 67 );
                    break;

        case('I'):  if( ch2=='N' )
                    {   return( 49 );
                    } else if( ch2=='R' )
                        return( 77 );
                    break;

        case('K'):  if( ch2=='R' )
                        return( 36 );
                    break;

        case('L'):  if( ch2=='A' )
                    {   return(  57 );
                    } else if( ch2=='I' )
                    {   return(   3 );
                    } else if( (ch2=='R') || (ch2=='W') )
                    {   return( 103 );
                    } else if( ch2=='U' )
                        return(  71 );
                    break;

        case('M'):  if( ch2=='D' )
                    {   return( 101 );
                    } else if( ch2=='G' )
                    {   return(  12 );
                    } else if( ch2=='N' )
                    {   return(  25 );
                    } else if( ch2=='O' )
                        return(  42 );
                    break;

        case('N'):  switch( ch2 )
                    {   case('A'):  return(  11 );
                        case('B'):  return(  41 );
                        case('D'):  return(  60 );
                        case('E'):  return(  10 );
                        case('I'):  return(  28 );
                        case('O'):  return( 102 );
                        case('P'):  return(  93 );
                    }
                    break;

        case('O'):  if( ch2=='S' )
                        return( 76 );
                    break;

        case('P'):  switch( ch2 )
                    {   case('A'):  return( 91 );
                        case('B'):  return( 82 );
                        case('D'):  return( 46 );
                        case('M'):  return( 61 );
                        case('O'):  return( 84 );
                        case('R'):  return( 59 );
                        case('T'):  return( 78 );
                        case('U'):  return( 94 );
                    }
                    break;

        case('R'):  switch( ch2 )
                    {   case('A'):  return( 88 );
                        case('B'):  return( 37 );
                        case('E'):  return( 75 );
                        case('H'):  return( 45 );
                        case('N'):  return( 86 );
                        case('U'):  return( 44 );
                    }
                    break;

        case('S'):  switch( ch2 )
                    {   case('B'):  return( 51 );
                        case('C'):  return( 21 );
                        case('E'):  return( 34 );
                        case('I'):  return( 14 );
                        case('M'):  return( 62 );
                        case('N'):  return( 50 );
                        case('R'):  return( 38 );
                    }
                    break;

        case('T'):  switch( ch2 )
                    {   case('A'):  return( 73 );
                        case('B'):  return( 65 );
                        case('C'):  return( 43 );
                        case('E'):  return( 52 );
                        case('H'):  return( 90 );
                        case('I'):  return( 22 );
                        case('L'):  return( 81 );
                        case('M'):  return( 69 );
                    }
                    break;

        case('X'):  if( ch2=='E' )
                        return( 54 );
                    break;

        case('Y'):  if( ch2=='B' )
                        return( 70 );
                    break;

        case('Z'):  if( ch2=='N' )
                    {   return( 30 );
                    } else if( ch2=='R' )
                        return( 40 );
                    break;
    }

    if( (ch1>='0') && (ch1<='9') )
        if( (ch2=='H') || (ch2=='D') )
            return( 1 ); /* Hydrogen */

    return( 0 );
}


CMoleculeBuilder::CMoleculeBuilder()
{

}

CMoleculeBuilder::~CMoleculeBuilder()
{

}


void CMoleculeBuilder::BuildFromFile(CString file){

	CStdioFile f(file,CFile::modeRead);

	CString s;


	float minX=9999,maxX=-9999,minY=9999,maxY=-9999,minZ=9999,maxZ=-9999;	
	
	float molCenterX,molCenterY,molCenterZ;


	//leggo il nome della molecola
	f.ReadString(s);

	m_molecule.SetName(s);

	float molRadius;


	
	int groupNum=1;
	
	//gruppo iniziale
	m_molecule.AddGroup(new CGroup);

	int currGroupNum=1;


	while(f.ReadString(s) && s != ""){


		CString sym=s.Mid(12,4);
		
		int atomGroup= atoi(s.Mid(22,4));


		CString str;

		str.Format("%d",atomGroup);

	//	MessageBox(NULL,str,NULL,NULL);

		if(atomGroup != groupNum) {
			//aggiungo il gruppo corrente alla molecola
			//m_molecule.AddGroup(currGroup);

			currGroupNum++;

			//creo un nuovo gruppo 
			m_molecule.AddGroup(new CGroup);
			
			groupNum=atomGroup;

			//MessageBox(NULL,"Addedd group",NULL,NULL);

		}



		int r=0,g=0,b=0;

		if(sym.GetAt(1) == 'C'){
			g=128;
			r=128;
			b=128;
		}
		else if(sym.GetAt(1) == 'O'){
		//	g=200;
			r=128;
		//	b=200;

		}

		else if(sym.GetAt(1) == 'N')
			b=255;
		else if(sym.GetAt(1) == 'NA'){
			r=255;
			b=255;
		}
		else if(sym.GetAt(1) == 'NH'){
			g=255;
			b=255;
		}
		else if(sym.GetAt(1) == 'H'){
			r=255;
			g=255;
			b=255;
		}
		else if(sym.GetAt(1) == 'P'){
			r=255;
			g=223;
			b=7;


		}

		float x=atof(s.Mid(30,8));
		float z=atof(s.Mid(38,8));
		float y=atof(s.Mid(46,8));

		if(x > maxX) maxX=x;
		else if(x <minX) minX=x;
		
		if(y > maxY) maxY=y;
		else if(y <minY) minY=y;

		if(z > maxZ) maxZ=z;
		else if(z <minZ) minZ=z;
		

		int aIndex=GetElemNumber(sym);

		CAtom* atom=new CAtom(sym,r,g,b,x,y,z,Element[aIndex].vdwrad,Element[aIndex].covalrad);


		m_molecule.AddAtomToGroup(atom,currGroupNum);

		if(sym.GetAt(1) == 'P')
			m_molecule.AddAtomToBackbone(atom);

	}

	molCenterX=(maxX+minX)/2;
	molCenterY=(maxY+minY)/2;
	molCenterZ=(maxZ+minZ)/2;


	m_molecule.SetX(molCenterX);
	m_molecule.SetY(molCenterY);
	m_molecule.SetZ(molCenterZ);


	molRadius=maxX-minX;
	
	if(maxY-minY > molRadius ) molRadius=maxY-minY;

	if(maxZ-minZ > molRadius ) molRadius=maxZ-minZ;

	m_molecule.SetRadius(molRadius);


	m_molecule.BuildLinks();


	//MessageBox(NULL,m_molecule.GetInformations(),NULL,NULL);


	f.Close();

}
