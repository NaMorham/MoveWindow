// MoveWindow.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "Windows.h"
#include <iostream>
#include <string>
#include <sstream>

#define StlString std::string
#define IStringStream std::istringstream

int main(int argc, const char* argv[])
{
    const StlString numbers = "0123456789";
    if(argc < 3)
    {
        std::cout << "Syntax: " << argv[0] << " WindowName X Y" << std::endl;
        return 0;
    }
    HWND handle = FindWindowA(NULL, argv[1]);
    if (INVALID_HANDLE_VALUE == handle || NULL == handle)
    {
        std::cerr << "Failed to locate window with title \"" << argv[1] << "\"" << std::endl;
        return 1;
    }
#ifdef DEBUG
    else
    {
        std::cerr << "DBG: handle = [" << (unsigned int)handle << "]" << std::endl;
    }
#endif
    int x = 0,
        y = 0;
    StlString xPosStr(argv[2]);
    if (xPosStr.find_first_not_of(numbers) != StlString::npos)
    {
        std::cerr << "Invalid x position string [" << xPosStr << "]" << std::endl;
        return 2;
    }
    StlString yPosStr(argv[3]);
    if (yPosStr.find_first_not_of(numbers) != StlString::npos)
    {
        std::cerr << "Invalid y position string [" << yPosStr << "]" << std::endl;
        return 2;
    }
    IStringStream(xPosStr) >> x;
    IStringStream(yPosStr) >> y;
    std::cerr << "Attempt to move window [" << argv[1] << "] to [" << x << ", " << y << "]" << std::endl;
    RECT rect;
    GetWindowRect(handle, &rect);
    MoveWindow(handle, x, y, rect.right - rect.left, rect.bottom - rect.top, true);

    return 0;
}
