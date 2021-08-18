#include <windows.h>
#include <wchar.h>

#define BUFSIZE MAX_PATH

int wmain(int argc, wchar_t **argv) {

    wchar_t buf[BUFSIZE];
    
    if(argc != 2) {

        wprintf(L"Usage: %ls <dir>\n", argv[0]);
        return 1;
    }

    DWORD r = SetCurrentDirectoryW(argv[1]);

    if (r == 0) {

        wprintf(L"SetCurrentDirectoryW() failed (%ld)\n", GetLastError());
        return 1;
    }

    r = GetCurrentDirectoryW(BUFSIZE, buf);

    if (r == 0) {

        wprintf(L"GetCurrentDirectoryW() failed (%ld)\n", GetLastError());
        return 1;
    }

    if (r > BUFSIZE) {

        wprintf(L"Buffer too small; needs %d characters\n", r);
        return 1;
    }

    wprintf(L"Current directory is: %ls\n", buf);

    return 0;
}