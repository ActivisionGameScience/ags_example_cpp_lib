#include <activision_game_science/blosc_wrapper.h>
#include <blosc.h>


using namespace std;
using namespace activision_game_science;


namespace activision_game_science {


    // ctor
    BloscWrapper::BloscWrapper() {

        blosc_init();
    }


    // dtor
    BloscWrapper::~BloscWrapper() {

        blosc_destroy();
    }



    size_t
    BloscWrapper::reserve_needed_to_compress(size_t srcsize) {

        return srcsize + BLOSC_MAX_OVERHEAD;
    }



    size_t
    BloscWrapper::reserve_needed_to_decompress(void* src) {

        size_t nbytes;
        size_t cbytes;
        size_t blocksize;

        // figure out how much space we need
        blosc_cbuffer_sizes(src, &nbytes, &cbytes, &blocksize);

        return nbytes;
    }


    // compress a buffer
    size_t
    BloscWrapper::compress(void* src, 
                           size_t srcsize, 
                           void* dst, 
                           size_t dstsize, 
                           int clevel, 
                           bool doshuffle, 
                           size_t typesize) {

        // convert doshuffle to int
        int doshuffle_int = 0;
        if (doshuffle) {

            doshuffle_int = 1;
        }

        // perform compression
        return blosc_compress(clevel, doshuffle_int, typesize, srcsize, src, dst, dstsize); 
    }
    


    // decompress a buffer
    size_t
    BloscWrapper::decompress(void* src, void* dst, size_t dstsize) {

        return blosc_decompress(src, dst, dstsize);
    }

}
