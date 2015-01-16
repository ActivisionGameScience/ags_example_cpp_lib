#ifndef ACTIVISION_GAME_SCIENCE_BLOSC_WRAPPER
#define ACTIVISION_GAME_SCIENCE_BLOSC_WRAPPER


#include <vector>


namespace activision_game_science {


    class BloscWrapper {
    public:

        BloscWrapper();
        ~BloscWrapper();

        std::size_t
        reserve_needed_to_compress(std::size_t srcsize);

        std::size_t
        reserve_needed_to_decompress(void* src);

        std::size_t
        compress(void* src, 
                 std::size_t srcsize, 
                 void* dst, 
                 std::size_t dstsize, 
                 int clevel=5, 
                 bool doshuffle=false, 
                 std::size_t typesize=4);

        std::size_t
        decompress(void* src, void* dst, std::size_t dstsize);

    private:

    };

}

#endif
