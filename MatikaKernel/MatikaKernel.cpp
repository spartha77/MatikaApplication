// MatikaKernel.cpp : Defines the exported functions for the DLL.
//

#include "pch.h"
#include "framework.h"
#include "MatikaKernel.h"


// This is an example of an exported variable
MATIKAKERNEL_API int nMatikaKernel=0;

// This is an example of an exported function.
MATIKAKERNEL_API int fnMatikaKernel(void)
{
    return 0;
}

// This is the constructor of a class that has been exported.
CMatikaKernel::CMatikaKernel()
{
    return;
}
