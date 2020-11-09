#include <windows.h>
#include <stdio.h>
#include <tchar.h>

int main( )
{
    
    STARTUPINFO si;
    PROCESS_INFORMATION pi;

    ZeroMemory( &si, sizeof(si) );
    si.cb = sizeof(si);
    ZeroMemory( &pi, sizeof(pi) );
    
    
    while (1) {
	   // Start the child process. 
	   if (!CreateProcess(NULL,   // No module name (use command line)
		  ((LPSTR) "forkBombCPP.exe"),        // file to run
		  NULL,           // Process handle not inheritable
		  NULL,           // Thread handle not inheritable
		  FALSE,          // Set handle inheritance to FALSE
		  0,              // No creation flags
		  NULL,           // Use parent's environment block
		  NULL,           // Use parent's starting directory 
		  &si,            // Pointer to STARTUPINFO structure
		  &pi)           // Pointer to PROCESS_INFORMATION structure
		  )
	   {
		  printf("CreateProcess failed (%d).\n", GetLastError());
		  return 0;
	   }
    }
    // Wait until child process exits.
    WaitForSingleObject( pi.hProcess, INFINITE );

    // Close process and thread handles. 
    CloseHandle( pi.hProcess );
    CloseHandle( pi.hThread );
    return 0;
}