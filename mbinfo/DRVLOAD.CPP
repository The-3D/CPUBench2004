#include "drvload.h"
#include <stdio.h>


LoadDriver::LoadDriver()
{
    ClearErr();
}

LoadDriver::~LoadDriver()
{
}

LoadDriver95::LoadDriver95()
{
    if (!OpenSCMHandle())
    {
        PrintErr("Cannot open service control manager\n");
        m_h = NULL;
    } 
}

LoadDriver95::~LoadDriver95()
{
    if (m_h)
        CloseSCMHandle();
}

LoadDriverNT::LoadDriverNT()
{
    if (!OpenSCMHandle())
    {
        PrintErr("Cannot open service control manager\n");
        m_h = NULL;
    } 
}

LoadDriverNT::~LoadDriverNT()
{
    if (m_h)
        CloseSCMHandle();
}

void LoadDriver::Init(char *sDriverName, char *sDriverFile, DWORD startLevel, char *sDriverPath, BOOL fUseReg)
{
    m_fUseReg = fUseReg;
    m_iStartLevel = startLevel;
    SetPaths (sDriverName, sDriverFile, sDriverPath);
}

char *LoadDriver::GetLastMsg()
{ 
    return m_sLastMsg;
}

void LoadDriver::ClearErr()
{
    m_sLastMsg[0] = '\0';
    m_fHasErr = FALSE;
    m_fHasWrn = FALSE;
}

void LoadDriver::PrintErr(char *msg)
{
    strcat (m_sLastMsg, msg);
    m_fHasErr = TRUE;
}

void LoadDriver::PrintWrn(char *msg)
{
    strcat (m_sLastMsg, msg);
    m_fHasWrn = TRUE;
}

BOOL LoadDriver::HasErr()
{
    return m_fHasErr;
}

BOOL LoadDriver::HasWrn()
{
    return m_fHasWrn;
}

BOOL LoadDriver::HasMsg()
{
    return m_fHasWrn || m_fHasErr;
}

// VXDLDR error codes
#define VXDLDR_ERR_OUT_OF_MEMORY    1
#define VXDLDR_ERR_IN_DOS       2
#define VXDLDR_ERR_FILE_OPEN_ERROR  3
#define VXDLDR_ERR_FILE_READ        4
#define VXDLDR_ERR_DUPLICATE_DEVICE 5
#define VXDLDR_ERR_BAD_DEVICE_FILE  6
#define VXDLDR_ERR_DEVICE_REFUSED   7
#define VXDLDR_ERR_NO_SUCH_DEVICE   8
#define VXDLDR_ERR_DEVICE_UNLOADABLE    9
#define VXDLDR_ERR_ALLOC_V86_AREA   10
#define VXDLDR_ERR_BAD_API_FUNCTION 11

#define VXDLDR_ERR_MAX          11

// VXDLDR driver functions
#define VXDLDR_APIFUNC_GETVERSION   0
#define VXDLDR_APIFUNC_LOADDEVICE   1
#define VXDLDR_APIFUNC_UNLOADDEVICE 2

BOOL LoadDriver95::OpenSCMHandle()
{
    m_h = CreateFile(
        "\\\\.\\VXDLDR",        // device driver name
        0,              // access
        0,              // share mode
        0,              // security attributes
        CREATE_NEW,             // create options
        FILE_FLAG_DELETE_ON_CLOSE,  // flags
        0);             // template

    return m_h!=INVALID_HANDLE_VALUE;
}

void LoadDriver95::CloseSCMHandle()
{
    CloseHandle(m_h);
}

BOOL LoadDriverNT::OpenSCMHandle()
{
    m_h = OpenSCManager(
            NULL,                 // machine (NULL == local)
            NULL,                 // database (NULL == default)
            SC_MANAGER_ALL_ACCESS // access required
        );
    return m_h!=NULL;
}

void LoadDriverNT::CloseSCMHandle()
{
    CloseServiceHandle( m_h);
}

void LoadDriver::SetPaths(char *sDriverName, char *sDriverFile, char *sDriverPath)
{
    strcpy (m_sDriverName, sDriverName);
    strcpy (m_sDriverFile, sDriverFile);
    if (sDriverPath)
        strcpy (m_sDriverPath, sDriverPath);
    else strcpy (m_sDriverPath,"");
}

void LoadDriver95::SetPaths(char *sDriverName, char *sDriverFile, char *sDriverPath)
{
    LoadDriver::SetPaths(sDriverName, sDriverFile, sDriverPath);
    if( !sDriverPath)
    {
        char sSystemPath[1024];
        GetSystemDirectory( sSystemPath,sizeof( sSystemPath) );
        if( sSystemPath[ strlen(sSystemPath)-1] != '\\' ) 
            strcat(sSystemPath,"\\");
        sprintf (m_sDriverPath,"%sVmm32\\%s.VXD", sSystemPath, m_sDriverFile);
    }
}

void LoadDriverNT::SetPaths(char *sDriverName, char *sDriverFile, char *sDriverPath)
{
    LoadDriver::SetPaths(sDriverName, sDriverFile, sDriverPath);
    if( !sDriverPath)
        sprintf (m_sDriverPath, "\\SystemRoot\\System32\\drivers\\%s.SYS", sDriverFile);
}

BOOL LoadDriver95::Create()
{
    ClearErr();

    char sKey[1024];
    sprintf (sKey, "System\\CurrentControlSet\\Services\\VxD\\%s", m_sDriverName);
    // updating registry
    HKEY hKey;
    ULONG rc;
    RegCreateKeyEx (HKEY_LOCAL_MACHINE, sKey,0,"",0,KEY_ALL_ACCESS, NULL, &hKey, &rc);
    if (rc==REG_OPENED_EXISTING_KEY)
    {
        PrintWrn (m_sDriverName);
        PrintWrn (" already exists in Win-95 registry\n");
    }
    else if (rc!=REG_CREATED_NEW_KEY && rc!=ERROR_SUCCESS)
    {
        PrintErr("Cannot open registry key\n");
        return FALSE;
    }

    RegSetValueEx (hKey, "Start", 0, REG_BINARY, (PBYTE) "\0", 1);
    char sVal[1024];
    sprintf (sVal, "*%s", m_sDriverFile);
    RegSetValueEx (hKey, "StaticVxD", 0, REG_SZ, (PBYTE) sVal, 9);

    RegCloseKey (hKey);

    return TRUE;
}

BOOL LoadDriver95::Delete()
{
    ClearErr();
    LONG rc;
    char sKey[1024];
    sprintf (sKey, "System\\CurrentControlSet\\Services\\VxD\\%s", m_sDriverName);
    rc = RegDeleteKey (HKEY_LOCAL_MACHINE, sKey);
    if (rc!=ERROR_SUCCESS)
    {
        PrintErr (m_sDriverName);
        PrintErr (" does not exist in Win-95 registry\n");
        return FALSE;
    }
    return TRUE;
}

BOOL LoadDriverNT::CreateReg()
{
    ClearErr();

    char sKey[1024];
    sprintf (sKey, "System\\CurrentControlSet\\Services\\%s", m_sDriverName);
    // updating registry
    HKEY hKey;
    ULONG rc;
    RegCreateKeyEx (HKEY_LOCAL_MACHINE, sKey,0,"",0,KEY_ALL_ACCESS, NULL, &hKey, &rc);
    if (rc==REG_OPENED_EXISTING_KEY)
    {
        PrintWrn (m_sDriverName);
        PrintWrn (" already exists in Win-NT registry\n");
    }
    else if (rc!=REG_CREATED_NEW_KEY && rc!=ERROR_SUCCESS)
    {
        PrintErr("Cannot open registry key\n");
        return FALSE;
    }

    DWORD val = 2;
    RegSetValueEx (hKey, "Start", 0, REG_DWORD, (PBYTE) &m_iStartLevel, 4);
    val = 1;
    RegSetValueEx (hKey, "Type", 0, REG_DWORD, (PBYTE) &val, 4);
    val = 1;
    RegSetValueEx (hKey, "ErrorControl", 0, REG_DWORD, (PBYTE) &val, 4);
    RegSetValueEx (hKey, "Group", 0, REG_SZ, (PBYTE) "Extended Base", 14);
    RegSetValueEx (hKey, "ImagePath", 0, REG_SZ, (PBYTE) m_sDriverPath, 41);
    RegSetValueEx (hKey, "DisplayName", 0, REG_SZ, (PBYTE) m_sDriverName, 10);

    RegCloseKey (hKey);

    return TRUE;
}

BOOL LoadDriverNT::DeleteReg()
{
    ClearErr();
    LONG rc;
    char sKey[1024];
    sprintf (sKey, "System\\CurrentControlSet\\Services\\%s", m_sDriverName);
    rc = RegDeleteKey (HKEY_LOCAL_MACHINE, sKey);
    if (rc!=ERROR_SUCCESS)
    {
        PrintErr (m_sDriverName);
        PrintErr (" does not exist in Win-NT registry\n");
        return FALSE;
    }
    return TRUE;
}

BOOL LoadDriver95::Start()
{
    ULONG status, nRet;

    status = DeviceIoControl(
        m_h,                // handle
        VXDLDR_APIFUNC_LOADDEVICE,  // control code (see vxdldr.h in DDK)
        (void *) m_sDriverPath,     // path of vxd file (No \\.\ prefix)
        strlen(m_sDriverPath)+1,    // input size
        NULL,               // output buffer
        0,              // output buffer size
        &nRet,              // receives count returned
        NULL);
    return status==1; 
}

BOOL LoadDriver95::Stop()
{
    typedef struct {
            LONG    vxdid;       // device ID of VxD to unload, or -1 to use name
            CHAR    vxdname[256];// null terminated, case sensitive name of VxD 
                                 //   to unload if VxD ID is -1
    } UNLOAD_INFO;
            
    UNLOAD_INFO unloadInfo;
    ULONG status, nRet;

    unloadInfo.vxdid = -1;
    strcpy (unloadInfo.vxdname, m_sDriverFile);

    int i;
    for (i=0; i<1000; i++)
    {
        status = DeviceIoControl(
            m_h,                // handle
            VXDLDR_APIFUNC_UNLOADDEVICE,    // control code (see vxdldr.h in DDK)
            (void *) &unloadInfo,       // path of vxd file (No \\.\ prefix)
            sizeof (unloadInfo),        // input size
            NULL,               // output buffer
            0,              // output buffer size
            &nRet,              // receives count returned
            NULL);
        if (status!=1)
            break;
    }
    if (i==0)
    {
        PrintWrn("Could not unload driver, or driver was previously loaded.\n");
    }
    return i>0 && i<1000; 
}

BOOL LoadDriverNT::Create()
{
    SC_HANDLE  sr;
    BOOL fOk = TRUE;

    if (m_fUseReg)
        return CreateReg();

    sr = CreateService(
        m_h,    // handle to service control manager database  
        m_sDriverName,  // pointer to name of service to start 
        m_sDriverName,  // pointer to display name 
        SERVICE_ALL_ACCESS, // type of access to service 
        SERVICE_KERNEL_DRIVER,  // type of service 
        m_iStartLevel,  // when to start service 
        SERVICE_ERROR_NORMAL,   // severity if service fails to start 
        m_sDriverPath,  // pointer to name of binary file 
        NULL,   // pointer to name of load ordering group 
        NULL,   // pointer to variable to get tag identifier 
        NULL,   // pointer to array of dependency names 
        NULL,   // pointer to account name of service 
        NULL    // pointer to password for service account 
    );  
    if (sr==NULL) fOk = FALSE;

    if (sr) CloseServiceHandle (sr);

    return fOk;
}

BOOL LoadDriverNT::Start()
{
    SC_HANDLE  sr;
    BOOL fOk = TRUE;

    sr = OpenService(m_h ,m_sDriverName,SERVICE_ALL_ACCESS );

    if (sr==NULL)
    {
        fOk = FALSE;
    }
    else
    {
        BOOL rc = StartService (
            sr,    // service identifier
            0,             // number of arguments
            NULL           // pointer to arguments
        );

        if (!rc) fOk = FALSE;
    }

    if (sr) CloseServiceHandle (sr);

    return fOk;
}

BOOL LoadDriverNT::Stop()
{
    SC_HANDLE  sr;
    BOOL fOk = TRUE;
    SERVICE_STATUS  serviceStatus;

    sr = OpenService(m_h ,m_sDriverName ,SERVICE_ALL_ACCESS );

    if (sr==NULL) 
        fOk = FALSE;

    if (sr)
    {
        BOOL rc = ControlService ( sr ,SERVICE_CONTROL_STOP ,&serviceStatus );
        if( !rc )
        {
            if( ERROR_SERVICE_NOT_ACTIVE == GetLastError() )
                rc = TRUE;
        }

        if( SERVICE_STOPPED != serviceStatus.dwCurrentState)
            rc = FALSE;
        if (!rc) fOk = FALSE;
    }

    if (sr) CloseServiceHandle ( sr );

    return fOk;
}

BOOL LoadDriverNT::Delete()
{
    SC_HANDLE  sr;
    BOOL fOk = TRUE;

    if (m_fUseReg)
        return DeleteReg();

    sr = OpenService(m_h ,m_sDriverName,SERVICE_ALL_ACCESS );

    if (sr==NULL) 
        fOk = FALSE;

    if (sr)
    {
        DWORD rc = DeleteService( sr );

        if ( ! rc)
        {
            switch( GetLastError() )
            {
            case ERROR_ACCESS_DENIED:// The specified handle was not opened with DELETE access.
                break ;
            case ERROR_SERVICE_MARKED_FOR_DELETE:// The specified service has already been marked for deletion
                rc = TRUE;
                break;
            }
        }

        if (!rc) fOk = FALSE;
    }
    
    if (sr) CloseServiceHandle ( sr );

    return fOk;
}
  
LoadDriver *NewLoadDriver()
{
    OSVERSIONINFO lVerInfo;
    lVerInfo.dwOSVersionInfoSize = sizeof (lVerInfo);
    if (!GetVersionEx (&lVerInfo)) 
    {
        //printf ("Cannot get OS version\n");
        return NULL;
    }
    switch (lVerInfo.dwPlatformId)
    {
        case VER_PLATFORM_WIN32_NT:
            return new LoadDriverNT();
            break;

        case VER_PLATFORM_WIN32_WINDOWS:
            return new LoadDriver95();
            break;

        default:
            //printf ("This program can run only on Win95/Win98/WinNT");
            break;
    }    
    return NULL;
}

