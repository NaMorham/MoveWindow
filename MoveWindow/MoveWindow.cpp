// MoveWindow.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "Windows.h" 
#include <iostream> 
#include <string> 
#include <sstream> 

#ifdef _UNICODE
#define StlString std::wstring
#define IStringStream std::wistringstream
#else
#define StlString std::string
#define IStringStream std::istringstream
#endif

int _tmain(int argc, _TCHAR* argv[])
{ 
   if(argc < 3) 
   { 
      std::cout << _T("Syntax: ") << argv[0] << _T(" WindowName X Y") << std::endl; 
      return 0; 
   } 
   HWND handle = FindWindow(NULL, argv[1]); 
   int x = 0, 
       y = 0; 
   StlString xPosStr(argv[2]);
   StlString yPosStr(argv[3]);
   IStringStream(xPosStr) >> x; 
   IStringStream(yPosStr) >> y; 
   //std::istringstream(StlString(argv[2])) >> x; 
   //std::istringstream(StlString(argv[3])) >> y; 
   RECT rect; 
   GetWindowRect(handle, &rect); 
   MoveWindow(handle, x, y, rect.right - rect.left, rect.bottom - rect.top, true); 
    
   return 0; 
}