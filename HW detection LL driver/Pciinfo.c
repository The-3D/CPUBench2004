
//-----------------------------------------------------------------------------
// pciinfo.c
//-----------------------------------------------------------------------------

#include <ntddk.h>



#define DEVICE_NAME_STRING  L"pciinfo"

#define PCI_DEVICES_DETECTION 10
#define CPU_CLOCK_MULTIPLIER_AMD_K7 11
#define CPU_CLOCK_MULTIPLIER_AMD_K8 12
#define CPU_CLOCK_MULTIPLIER_INTEL_WILLAMETTE 13
#define CPU_CLOCK_MULTIPLIER_INTEL_NORTHWOOD 14
#define CPU_CLOCK_MULTIPLIER_INTEL_PRESCOTT 15
#define CPU_CLOCK_MULTIPLIER_INTEL_BANIAS 16



//-----------------------------------------------------------------------------
VOID UnloadDriver ( IN PDRIVER_OBJECT DriverObject )
{
    WCHAR LinkString[] = L"\\DosDevices\\" DEVICE_NAME_STRING;
    UNICODE_STRING linkString;

    IoDeleteDevice(DriverObject->DeviceObject);
    RtlInitUnicodeString(&linkString,LinkString);
    IoDeleteSymbolicLink(&linkString);
}
//-----------------------------------------------------------------------------
static NTSTATUS MainDispatch ( IN PDEVICE_OBJECT DeviceObject, IN PIRP Irp )
{
    NTSTATUS status;
    PIO_STACK_LOCATION irpSp;
    PULONG dataptr;
    PCI_COMMON_CONFIG pcidata;
	ULONG msr=0;

	int val;

    UNREFERENCED_PARAMETER(DeviceObject);
    irpSp=IoGetCurrentIrpStackLocation(Irp);
    switch(irpSp->MajorFunction)
    {
        case IRP_MJ_CREATE:
            Irp->IoStatus.Status = STATUS_SUCCESS;
            Irp->IoStatus.Information = 0L;
            break;
        case IRP_MJ_CLOSE:
            Irp->IoStatus.Status = STATUS_SUCCESS;
            Irp->IoStatus.Information = 0L;
            break;
        case IRP_MJ_DEVICE_CONTROL:
            Irp->IoStatus.Status = STATUS_SUCCESS;
            Irp->IoStatus.Information = 0L;
            //if(irpSp->Parameters.DeviceIoControl.InputBufferLength!=12 || irpSp->Parameters.DeviceIoControl.InputBufferLength!=4) break;
            //this is the size of the PCI_COMMON_CONFIG structure
            //if(irpSp->Parameters.DeviceIoControl.OutputBufferLength!=256 || irpSp->Parameters.DeviceIoControl.OutputBufferLength!=4) break;
            dataptr = (PULONG) Irp->AssociatedIrp.SystemBuffer;


			__try{
				switch(dataptr[0]) {

				case PCI_DEVICES_DETECTION:
					Irp->IoStatus.Information=HalGetBusData(PCIConfiguration,dataptr[1],dataptr[2],&pcidata,sizeof(pcidata));
					memcpy(dataptr,&pcidata,sizeof(pcidata));
					break;

				case CPU_CLOCK_MULTIPLIER_AMD_K7:

				//devo verificare se è abilitato il controllo del FID
				__asm {


						mov eax,0x80000007;
						cpuid;
						mov val, edx;
					}


					if(((val >> 1) & 1)){

						//se FID control è abilitato leggo il registro FIDVID_STATUS
						__asm{

							mov ecx,0xC0010042; //FIDVID_STATUS register
							rdmsr;
							mov msr,eax;
						}

					}else {

						__asm {
							//se pstates non è abilitato leggo lo start_FID
							mov ecx,0xC0010015;
							rdmsr;
							mov msr,eax;
						}

					}

					memcpy(dataptr,&msr,sizeof(msr));
					Irp->IoStatus.Information=4;
					break;

				case CPU_CLOCK_MULTIPLIER_AMD_K8:

				//devo verificare se è abilitato il controllo del FID
				__asm {


						mov eax,0x80000007;
						cpuid;
						mov val, edx;
					}


					if(((val >> 1) & 1)){

						//se FID control è abilitato leggo il registro FIDVID_STATUS
						__asm{

							mov ecx,0xC0010042; //FIDVID_STATUS register
							rdmsr;
							mov msr,eax;
						}

					}else {

						__asm {
							//se pstates non è abilitato leggo lo start_FID
							mov ecx,0xC0010015;
							rdmsr;
							mov msr,eax;
						}

					}

					memcpy(dataptr,&msr,sizeof(msr));
					Irp->IoStatus.Information=4;
					break;


				case CPU_CLOCK_MULTIPLIER_INTEL_WILLAMETTE:

				__asm {

						mov ecx,0x2A;
						rdmsr;
						mov msr,eax;

					}

					memcpy(dataptr,&msr,sizeof(msr));
					Irp->IoStatus.Information=4;
					break;

				case CPU_CLOCK_MULTIPLIER_INTEL_NORTHWOOD:
				case CPU_CLOCK_MULTIPLIER_INTEL_PRESCOTT:

				__asm {

						mov ecx,0x2C;
						rdmsr;
						mov msr,eax;

					}

					memcpy(dataptr,&msr,sizeof(msr));
					Irp->IoStatus.Information=4;
					break;


				case CPU_CLOCK_MULTIPLIER_INTEL_BANIAS:

				__asm {

						mov ecx,0x2A;
						rdmsr;
						mov msr,eax;

					}

					memcpy(dataptr,&msr,sizeof(msr));
					Irp->IoStatus.Information=4;
					break;

				}
				break;
			}
			__except(EXCEPTION_EXECUTE_HANDLER){

				msr=0;
				memcpy(dataptr,&msr,sizeof(msr));
				Irp->IoStatus.Information=4;

		}

	}


    status=Irp->IoStatus.Status;
    IoCompleteRequest(Irp,0);
    return(status);
}
//-----------------------------------------------------------------------------
NTSTATUS DriverEntry ( IN PDRIVER_OBJECT DriverObject, IN PUNICODE_STRING RegistryPath )
{
    WCHAR NameString[] = L"\\Device\\" DEVICE_NAME_STRING;
    WCHAR LinkString[] = L"\\DosDevices\\" DEVICE_NAME_STRING;
    UNICODE_STRING nameString, linkString;
    PDEVICE_OBJECT deviceObject;
    NTSTATUS status;

    RtlInitUnicodeString(&nameString,NameString);
    status=IoCreateDevice(DriverObject,0,&nameString,FILE_DEVICE_UNKNOWN,0,TRUE,&deviceObject);
    if(!NT_SUCCESS(status)) return(status);

    RtlInitUnicodeString(&linkString,LinkString);
    status=IoCreateSymbolicLink(&linkString,&nameString);
    if(!NT_SUCCESS(status))
    {
        IoDeleteDevice (DriverObject->DeviceObject);
        return(status);
    }

    DriverObject->DriverUnload = UnloadDriver;
    DriverObject->MajorFunction[IRP_MJ_CREATE] =
    DriverObject->MajorFunction[IRP_MJ_CLOSE]  =
    DriverObject->MajorFunction[IRP_MJ_DEVICE_CONTROL] = MainDispatch;
    return(STATUS_SUCCESS);
}
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------

