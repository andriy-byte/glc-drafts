

#ifndef GOLDEN_LEAF_COIN_GLCVARIABLES_H
#define GOLDEN_LEAF_COIN_GLCVARIABLES_H


#include <map>
#include <string>
#include <filesystem>

namespace glc {
    namespace environment {
        namespace variables {

            extern const std::map<std::string, std::string> glc_names;
            extern const std::filesystem::path glc_root;

        }
    }
}

#endif //GOLDEN_LEAF_COIN_GLCVARIABLES_H
