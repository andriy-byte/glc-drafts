//
// Created by andriy on 6/28/23.
//

#ifndef GLC_COMANDS_LIST_H
#define GLC_COMANDS_LIST_H

#include <set>
#include "command.h"

namespace glc {
    namespace cli {

        void make_commands(std::map<std::string, command>& commands);

    } // glc
} // cli

#endif //GLC_COMANDS_LIST_H
