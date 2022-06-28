// CPUInformations.h: interface for the CCPUInformations class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CPUINFORMATIONS_H__B65283B7_B4A4_4580_89F7_BC2A858E3D26__INCLUDED_)
#define AFX_CPUINFORMATIONS_H__B65283B7_B4A4_4580_89F7_BC2A858E3D26__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000



//wrap class for cpuinfo.dll

struct CacheInfo{


	int L1DCache,L1ICache,L2Cache;

	int L1D_ass,L1D_linesPerTag,L1D_lineSize;
	int L1I_ass,L1I_linesPerTag,L1I_lineSize;
	int L2_ass,L2_linesPerTag,L2_lineSize;
		
	int L1D_TLB4M_ass,L1D_TLB4M_entries;
	int L1D_TLB4K_ass,L1D_TLB4K_entries;
	int L1I_TLB4M_ass,L1I_TLB4M_entries;
	int L1I_TLB4K_ass,L1I_TLB4K_entries;

	int L2D_TLB4M_ass,L2D_TLB4M_entries;
	int L2D_TLB4K_ass,L2D_TLB4K_entries;
	int L2I_TLB4M_ass,L2I_TLB4M_entries;
	int L2I_TLB4K_ass,L2I_TLB4K_entries;

	int traceSize;

};




class CCPUInformations  
{
public:
	CCPUInformations();
	virtual ~CCPUInformations();

	CString GetVendorString(){ return m_Vendor;}
	CString GetCPUFeatures(){ return m_Features;}
	CString GetCPUFrequency() { return m_CPUFreq; }
	CString GetL1DCache() { return m_L1D; }
	CString GetL1ICache() { return m_L1I; }
	CString GetL2Cache() { return m_L2; }
	CString GetTraceCache() { return m_TraceCache; }
	CString GetBrandString() { return m_BrandName; }
	CString GetSocketName() { return m_socketName; }
	CString GetBusType() { return m_busType; }
	CString GetCodeName() { return m_codeName; }
	CString GetCPUName() { return m_cpuName; }
	CString GetLogoName() { return m_logoName; }
	CString GetMultiplier() { return m_multiplier; }
	CString GetFSBSpeed() { return m_fsbFreq; }
	CString GetDefaultVCore() { return m_defVcore;}
	CString GetFrequencyRange(){ return m_freqRange;}
	CString GetHTSupport(){ return m_HTSupport;}
	CString GetMMXSupport() { return m_MMX; }
	CString GetSSESupport() { return m_SSE; }
	CString GetSSE2Support() { return m_SSE2; }
	CString GetSSE3Support() { return m_SSE3; }
	CString GetAMD64Support() { return m_AMD64; }
	CString GetPSE36Support() { return m_PSE36; }
	CString GetFPUSupport() { return m_HasFPU; }
	CString GetVirtualModeSupport() { return m_HasVirtualMode; }
	CString GetDebugExtSupport() { return m_HasDebugExt; }
	CString GetPageSizeExt() { return m_HasPageSizeExt; }
	CString GetTimestamp() { return m_HasTimestamp; }
	CString GetPAEExt() { return m_HasPAE; }
	CString GetCMPXCHG8B() { return m_HasCMPXCHG8B; }
	CString GetAPIC() { return m_HasAPIC; }
	CString GetMachineCheck() { return m_HasMachineCheck; }
	CString GetSysEnterExit() { return m_HasSysEnterExit; }
	CString GetMTRR() { return m_HasMTRR; }
	CString GetGlobalPaging() { return m_HasGlobalPagingExt; }
	CString GetCMOV() { return m_HasCMOV; }
	CString GetFXSAVERESTOR() { return m_HasFXSAVERESTOR; }
	CString GetCLFLUSH() { return m_HasCLFLUSH; }
	CString Get3DNow() { return m_Has3DNow; }
	CString GetXtendedMMX() { return m_HasXtendedMMX; }

	CString GetL1D_TLB4M_Associativity() { return m_L1D_TLB4M_ass; }
	CString GetL1I_TLB4M_Associativity() { return m_L1I_TLB4M_ass; }
	CString GetL1D_TLB4M_Entries() { return m_L1D_TLB4M_entries; }
	CString GetL1I_TLB4M_Entries() { return m_L1I_TLB4M_entries; }
	CString GetL1D_Associativity() { return m_L1D_ass; }
	CString GetL1D_LineSize() { return m_L1D_lineSize; }
	CString GetL1D_LinesPerTag() { return m_L1D_linesPerTag; }
	CString GetL1I_Associativity() { return m_L1I_ass; }
	CString GetL1I_LineSize() { return m_L1I_lineSize; }
	CString GetL1I_LinesPerTag() { return m_L1I_linesPerTag; }
	CString GetL1D_TLB4K_Associativity() { return m_L1D_TLB4K_ass; }
	CString GetL1I_TLB4K_Associativity() { return m_L1I_TLB4K_ass; }
	CString GetL1D_TLB4K_Entries() { return m_L1D_TLB4K_entries; }
	CString GetL1I_TLB4K_Entries() { return m_L1I_TLB4K_entries; }

	CString GetL2_Associativity() { return m_L2_ass; }
	CString GetL2_LineSize() { return m_L2_lineSize; }
	CString GetL2_LinesPerTag() { return m_L2_linesPerTag; }

	CString GetL2D_TLB4M_Associativity() { return m_L2D_TLB4M_ass; }
	CString GetL2I_TLB4M_Associativity() { return m_L2I_TLB4M_ass; }
	CString GetL2D_TLB4M_Entries() { return m_L2D_TLB4M_entries; }
	CString GetL2I_TLB4M_Entries() { return m_L2I_TLB4M_entries; }

	CString GetL2D_TLB4K_Associativity() { return m_L2D_TLB4K_ass; }
	CString GetL2I_TLB4K_Associativity() { return m_L2I_TLB4K_ass; }
	CString GetL2D_TLB4K_Entries() { return m_L2D_TLB4K_entries; }
	CString GetL2I_TLB4K_Entries() { return m_L2I_TLB4K_entries; }








private:
	CacheInfo ci;


	void FormatCacheValues();
	void InitCPUFeatures(HINSTANCE hLib);
	CString m_Vendor;
	CString m_CPUFreq;
	CString m_multiplier,m_fsbFreq;
	CString m_Features;
	CString m_L1I,m_L1D,m_L2,m_TraceCache;
	CString m_BrandName;
	CString m_socketName,m_busType,m_codeName;
	CString m_cpuName;
	CString m_logoName;
	CString m_defVcore,m_freqRange;
	CString m_HTSupport;
	CString m_MMX,m_SSE,m_SSE2,m_SSE3,m_AMD64,m_PSE36;
	CString m_HasFPU;
	CString m_HasVirtualMode;
	CString m_HasDebugExt;
	CString m_HasPageSizeExt;
	CString m_HasTimestamp;
	CString m_HasPAE;
	CString m_HasMachineCheck;
	CString m_HasCMPXCHG8B;
	CString m_HasAPIC;
	CString m_HasSysEnterExit;
	CString m_HasMTRR;
	CString m_HasGlobalPagingExt;
	CString m_HasCMOV;
	CString m_HasCLFLUSH;
	CString m_HasFXSAVERESTOR;
	CString m_Has3DNow;
	CString m_HasXtended3DNow;
	CString m_HasXtendedMMX;


	CString m_L1D_ass,m_L1D_linesPerTag,m_L1D_lineSize;
	CString m_L1I_ass,m_L1I_linesPerTag,m_L1I_lineSize;
	CString m_L2_ass,m_L2_linesPerTag,m_L2_lineSize;

	CString m_L1D_TLB4M_ass,m_L1D_TLB4M_entries;
	CString m_L1D_TLB4K_ass,m_L1D_TLB4K_entries;
	CString m_L1I_TLB4M_ass,m_L1I_TLB4M_entries;
	CString m_L1I_TLB4K_ass,m_L1I_TLB4K_entries;

	CString m_L2D_TLB4M_ass,m_L2D_TLB4M_entries;
	CString m_L2D_TLB4K_ass,m_L2D_TLB4K_entries;
	CString m_L2I_TLB4M_ass,m_L2I_TLB4M_entries;
	CString m_L2I_TLB4K_ass,m_L2I_TLB4K_entries;
	


};

#endif // !defined(AFX_CPUINFORMATIONS_H__B65283B7_B4A4_4580_89F7_BC2A858E3D26__INCLUDED_)
