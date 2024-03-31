// The following ifdef block is the standard way of creating macros which make exporting
// from a DLL simpler. All files within this DLL are compiled with the MATIKAKERNEL_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see
// MATIKAKERNEL_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef MATIKAKERNEL_EXPORTS
#define MATIKAKERNEL_API __declspec(dllexport)
#else
#define MATIKAKERNEL_API __declspec(dllimport)
#endif

// This class is exported from the dll
class MATIKAKERNEL_API CMatikaKernel {
public:
	CMatikaKernel(void);
	// TODO: add your methods here.
};

extern MATIKAKERNEL_API int nMatikaKernel;

MATIKAKERNEL_API int fnMatikaKernel(void);
