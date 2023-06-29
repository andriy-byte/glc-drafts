


#include "GLCVariables.h"

namespace glc {
    namespace environment {
        namespace variables {

            const std::map<std::string, std::string> glc_names{
                    {"upper",   "GOLDEN LEAF COIN"},
                    {"lower",   "golden leaf coin"},
                    {"capital", "Golden Leaf Coin"}
            };

            const std::filesystem::path glc_root{std::filesystem::current_path().parent_path()};



        }
    }
}