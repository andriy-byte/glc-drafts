
#ifndef GOLDEN_LEAF_COIN_GLCCLICOMMANDSTOOLS_H
#define GOLDEN_LEAF_COIN_GLCCLICOMMANDSTOOLS_H


#include <boost/algorithm/string.hpp>
#include <string_interpolation.h>
#include <boost/lexical_cast.hpp>

namespace glc {
    namespace application {
        namespace cli {
            namespace commands {

                std::string basicReCommandGeneration(const std::string &name);

#define BASICCREATERE2COMMAND(var) \
const re2::RE2 var(basicReCommandGeneration(#var));


            } // glc
        } // application
    } // cli
} // commands

#endif //GOLDEN_LEAF_COIN_GLCCLICOMMANDSTOOLS_H
BASICCREATERE2COMMAND(start)
BASICCREATERE2COMMAND(exit)
BASICCREATERE2COMMAND(mine)
BASICCREATERE2COMMAND(send)