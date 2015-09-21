// restrict_windows.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <Windows.h>
#include <iostream>

BOOL CALLBACK enumWindowProc(HWND hWnd, LPARAM lParam)
{
    SetWindowPos(
        hWnd,
        NULL,
        0,
        0,
        0,
        0,
        SWP_NOSIZE
        );

    return TRUE;
}

int _tmain(int argc, _TCHAR* argv[])
{
    if (EnumWindows(enumWindowProc, NULL) != TRUE)
    {
        std::cout << "EnumWindows() failed, error : " << GetLastError() << "\n";
        return 1;
    }
    return 0;
}

