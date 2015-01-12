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
typedef  void*  ags_BloscBuffer; 



// BloscWrapper methods

EXPORT_THIS_SYMBOL
ags_BloscWrapper 
ags_BloscWrapper_new();



EXPORT_THIS_SYMBOL
void 
ags_BloscWrapper_delete(ags_BloscWrapper instance);



EXPORT_THIS_SYMBOL
ags_BloscBuffer 
ags_BloscWrapper_compress(ags_BloscWrapper instance, unsigned char* src, size_t nbytes);



EXPORT_THIS_SYMBOL
ags_BloscBuffer 
ags_BloscWrapper_decompress(ags_BloscWrapper instance, unsigned char* src);



// buffer methods

EXPORT_THIS_SYMBOL
ags_BloscBuffer 
ags_BloscBuffer_new(size_t size);



EXPORT_THIS_SYMBOL
void 
ags_BloscBuffer_delete(ags_BloscBuffer instance);



EXPORT_THIS_SYMBOL
size_t 
ags_BloscBuffer_size(ags_BloscBuffer instance);



EXPORT_THIS_SYMBOL
unsigned char* 
ags_BloscBuffer_getRaw(ags_BloscBuffer instance);



#ifdef __cplusplus
}  // end extern "C"
#endif


#endif // end header guard
