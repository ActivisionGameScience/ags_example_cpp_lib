#ifndef ACTIVISION_GAME_SCIENCE_BLOSC_WRAPPER_CAPI
#define ACTIVISION_GAME_SCIENCE_BLOSC_WRAPPER_CAPI

#include <stddef.h>

#ifdef _MSC_VER
    #define  EXPORT_THIS_SYMBOL  __declspec(dllexport)
#else
    #define  EXPORT_THIS_SYMBOL
#endif


//***********************
// C API
//***********************

#ifdef __cplusplus
extern "C" {
#endif


// opaque pointers to underlying types
typedef  void*  ags_BloscWrapper;



// BloscWrapper methods

EXPORT_THIS_SYMBOL
ags_BloscWrapper 
ags_BloscWrapper_new();



EXPORT_THIS_SYMBOL
void 
ags_BloscWrapper_delete(ags_BloscWrapper instance);



EXPORT_THIS_SYMBOL
size_t
ags_BloscWrapper_reserve_needed_to_compress(ags_BloscWrapper instance, size_t srcsize);



EXPORT_THIS_SYMBOL
size_t
ags_BloscWrapper_reserve_needed_to_decompress(ags_BloscWrapper instance, void* src);



EXPORT_THIS_SYMBOL
size_t
ags_BloscWrapper_compress(ags_BloscWrapper instance, void* src, size_t srcsize, void* dst, size_t dstsize);



EXPORT_THIS_SYMBOL
size_t
ags_BloscWrapper_decompress(ags_BloscWrapper instance, unsigned char* src);



#ifdef __cplusplus
}  // end extern "C"
#endif


#endif // end header guard
