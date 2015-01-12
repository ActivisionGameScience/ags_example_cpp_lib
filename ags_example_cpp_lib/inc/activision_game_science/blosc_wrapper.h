#ifndef ACTIVISION_GAME_SCIENCE_BLOSC_WRAPPER
#define ACTIVISION_GAME_SCIENCE_BLOSC_WRAPPER


#include <vector>


namespace activision_game_science {


    class BloscWrapper {
    public:

        BloscWrapper();
        ~BloscWrapper();


        std::vector<unsigned char>*
        compress(unsigned char* src, std::size_t nbytes, int clevel=5, bool doshuffle=false, std::size_t typesize=4);

        std::vector<unsigned char>*
        decompress(unsigned char* src);

    private:

    };

}

#endif
