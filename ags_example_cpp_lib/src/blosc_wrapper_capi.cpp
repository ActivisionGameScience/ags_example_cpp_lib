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



ags_BloscBuffer 
ags_BloscWrapper_compress(ags_BloscWrapper instance, unsigned char* src, size_t nbytes) {

    BloscWrapper* inst = static_cast<BloscWrapper*>(instance);

    vector<unsigned char>* dst = inst->compress(src, nbytes);
    return static_cast<ags_BloscBuffer>(dst);
}



ags_BloscBuffer 
ags_BloscWrapper_decompress(ags_BloscWrapper instance, unsigned char* src) {

    BloscWrapper* inst = static_cast<BloscWrapper*>(instance);

    vector<unsigned char>* dst = inst->decompress(src);
    return static_cast<ags_BloscBuffer>(dst);
}



// buffer methods

ags_BloscBuffer 
ags_BloscBuffer_new(size_t size) {

    return static_cast<ags_BloscBuffer>(new vector<unsigned char>(size));
}



void 
ags_BloscBuffer_delete(ags_BloscBuffer instance) {

    if (instance != NULL)
        delete static_cast<vector<unsigned char>*>(instance);
}



size_t 
ags_BloscBuffer_size(ags_BloscBuffer instance) {

    vector<unsigned char>* inst = static_cast<vector<unsigned char>*>(instance);

    return inst->size();
}



unsigned char* 
ags_BloscBuffer_getRaw(ags_BloscBuffer instance) {

    vector<unsigned char>* inst = static_cast<vector<unsigned char>*>(instance);

    return &(*inst)[0];
}

