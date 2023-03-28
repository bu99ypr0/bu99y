#ifndef BU99Y_MEMLEAK_CHECK_H
#define BU99Y_MEMLEAK_CHECK_H


//  bu99y_memleak_check.h -- simple memory checker
//  
//  usage:
//  
//  #define BU99Y_MEMLEAK_CHECK_IMPLEMENTATION
//  //#define BU99Y_MEMLEAK_CHECK_ENABLED 0
//  //#define BU99Y_MEMLEAK_CHECK_STATIC
//  #include "bu99y_memleak_check.h"
//  
//  int main(int argc, char *argv[])
//  {
//      bu99y_memleak_check(0);
//  }


#ifdef __cplusplus
extern "C" {
#endif

#ifndef BU99Y_DEF
	#ifdef BU99Y_MEMLEAK_CHECK_STATIC
		#define BU99Y_DEF static
	#else
		#define BU99Y_DEF extern
	#endif

#endif

#ifndef BU99Y_MEMLEAK_CHECK_ENABLED
#define BU99Y_MEMLEAK_CHECK_ENABLED 1
#endif

#if defined(_WIN32) && BU99Y_MEMLEAK_CHECK_ENABLED
#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#endif

	BU99Y_DEF void bu99y_memleak_check(long breakAt);

#ifdef BU99Y_MEMLEAK_CHECK_IMPLEMENTATION

	BU99Y_DEF void bu99y_memleak_check(long breakAt)
	{
#if defined(_WIN32) && BU99Y_MEMLEAK_CHECK_ENABLED
		_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
		_CrtSetBreakAlloc(breakAt);
#endif
	}

#endif

#ifdef __cplusplus
}
#endif

#endif
