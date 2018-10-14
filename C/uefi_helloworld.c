// EDK2
#include <Uefi.h>
#include <Library/UefiLib.h>

EFI_STATUS EFIAPI UefiMain(IN EFI_HANDLE IH, IN EFI_SYSTEM_TABLE *ST) {
    auto console = ST->ConOut;
    
    //We want blank screen!
    console->ClearScreen(console);
    CHAR16 *msg = L"Hello world!";
    console->OutString(msg); 

    // Pause
    while(1);
    //Never get to here, just make compiler happy :)
    return EFI_SUCCESS;
}