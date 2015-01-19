#ifndef ACTIVISION_GAME_SCIENCE_BLOSC_WRAPPER
#define ACTIVISION_GAME_SCIENCE_BLOSC_WRAPPER


#include <cstddef>


namespace activision_game_science {


    class BloscWrapper {
    public:

        BloscWrapper();
        ~BloscWrapper();

        size_t reserveNeededToCompress(size_t srcsize);

        size_t
        reserveNeededToDecompress(void* src);

        size_t
        compress(void* src, 
                 size_t srcsize, 
                 void* dst, 
                 size_t dstsize, 
                 int clevel=5, 
                 bool doshuffle=true, 
                 size_t typesize=4);

        size_t
        decompress(void* src, void* dst, size_t dstsize);

    private:

    };

}

#endif
