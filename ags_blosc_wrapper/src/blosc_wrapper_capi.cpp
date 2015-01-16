#include <activision_game_science/blosc_wrapper_capi.h>
#include <activision_game_science/blosc_wrapper.h>

#include <vector>


using namespace activision_game_science;
using namespace std;



ags_BloscWrapper 
ags_BloscWrapper_new() {

    return static_cast<ags_BloscWrapper>(new BloscWrapper());
}



void 
ags_BloscWrapper_delete(ags_BloscWrapper instance) {

    if (instance != NULL)
        delete static_cast<BloscWrapper*>(instance);
}



size_t
ags_BloscWrapper_reserve_needed_to_compress(ags_BloscWrapper instance, size_t srcsize) {

    BloscWrapper* inst = static_cast<BloscWrapper*>(instance);

    return inst->reserve_needed_to_compress(srcsize);
}



size_t
ags_BloscWrapper_reserve_needed_to_decompress(ags_BloscWrapper instance, void* src) {

    BloscWrapper* inst = static_cast<BloscWrapper*>(instance);

    return inst->reserve_needed_to_decompress(src);
}   



size_t
ags_BloscWrapper_compress(ags_BloscWrapper instance, void* src, size_t srcsize, void* dst, size_t dstsize) {

    BloscWrapper* inst = static_cast<BloscWrapper*>(instance);

    return inst->compress(src, srcsize, dst, dstsize);
}



size_t
ags_BloscWrapper_decompress(ags_BloscWrapper instance, void* src, void* dst, size_t dstsize) {

    BloscWrapper* inst = static_cast<BloscWrapper*>(instance);

    return inst->decompress(src, dst, dstsize);
}
