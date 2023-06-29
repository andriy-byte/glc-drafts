//
// Created by andriy on 6/28/23.
//

#ifndef GLC_COMMANDS_LIST_H
#define GLC_COMMANDS_LIST_H


#include <boost/program_options.hpp>
#include <functional>
#include <map>
#include "mode.h"

namespace glc {
    namespace cli {
        namespace po = boost::program_options;

        void load_commands(po::options_description &description);

        std::map<std::string, std::function<void(project::mode &)>> create_operations();


    } // glc
} // cli

#endif //GLC_COMMANDS_LIST_H
