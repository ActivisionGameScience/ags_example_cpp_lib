#include <activision_game_science/blosc_wrapper.h>
#include <blosc.h>


using namespace std;


namespace activision_game_science {


    // ctor
    BloscWrapper::BloscWrapper() {

        blosc_init();
    }


    // dtor
    BloscWrapper::~BloscWrapper() {

        blosc_destroy();
    }


    // compress a buffer
    vector<unsigned char>*
    BloscWrapper::compress(unsigned char* src, 
                           size_t nbytes,
                           int clevel, 
                           bool doshuffle, 
                           size_t typesize) {

        size_t destsize = nbytes + BLOSC_MAX_OVERHEAD;

        // convert doshuffle to int
        int doshuffle_int = 0;
        if (doshuffle) {

            doshuffle_int = 1;
        }

        // allocate enough space for destination
        vector<unsigned char>* dst = new vector<unsigned char>(destsize);

        // perform compression and resize as appropriate
        destsize = blosc_compress(clevel, doshuffle_int, typesize, nbytes, &src[0], &(*dst)[0], destsize); 
        if (destsize <= 0) {

            dst->clear();

        } else {

            dst->resize(destsize);
        }

        return dst;
    }
    


    // decompress a buffer
    vector<unsigned char>*
    BloscWrapper::decompress(unsigned char* src) {

        size_t nbytes;
        size_t cbytes;
        size_t blocksize;

        // figure out how much space we need
        blosc_cbuffer_sizes(&src[0], &nbytes, &cbytes, &blocksize);

        // allocate enough space for destination
        vector<unsigned char>* dst = new vector<unsigned char>(nbytes);
        
        nbytes = blosc_decompress(&src[0], &(*dst)[0], nbytes);

        if (nbytes <= 0) {

            dst->clear();

        } else {

            dst->resize(nbytes);
        }

        return dst;
    }

}
