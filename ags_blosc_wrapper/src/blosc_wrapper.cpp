#include <activision_game_science/blosc_wrapper.h>
#include <blosc.h>


namespace activision_game_science {


    // ctor
    BloscWrapper::BloscWrapper() {

        blosc_init();

        if (blosc_set_compressor("zlib") == -1) {

            std::cerr << "Blosc reports cannot use zlib.  Falling back to default" << std::endl;
        }
    }


    // dtor
    BloscWrapper::~BloscWrapper() {

        blosc_destroy();
    }



    size_t BloscWrapper::reserveNeededToCompress(size_t srcsize) {

        return srcsize + BLOSC_MAX_OVERHEAD;
    }



    size_t
    BloscWrapper::reserveNeededToDecompress(void* src) {

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
