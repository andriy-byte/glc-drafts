
#ifndef GLC_CONSTANTS_H
#define GLC_CONSTANTS_H


#include <filesystem>

namespace glc {
    namespace constants {
        static const std::filesystem::path CURRENT_PATH{std::filesystem::current_path()};
        static constexpr uint MEDIUM_ARGUMENTS_SIZE = 4, ARGUMENTS_QUANTITY = 2, ERROR_EXIT = 1;
        static constexpr const char *PROGRAM_DESCRIPTION_NAME = "GLC command line application";
        static constexpr float VERSION = 0.1;
    }
}


#endif //GLC_CONSTANTS_H
