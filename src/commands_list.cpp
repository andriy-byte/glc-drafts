//
// Created by andriy on 6/28/23.
//

#include "commands_list.h"

namespace glc {
    namespace cli {
        void load_commands(po::options_description &description) {
            po::options_description current_options;
            current_options.add_options()
                    ("help", "")
                    ("start", "")
                    ("upgrade", "")
                    ("recovery", "")
                    ("migrate", "")
                    ("install", "")
                    ("version", "")
                    ("repair", "")
                    ("info","");

            description.add(current_options);
        }

        std::map<std::string, std::function<void(project::mode &)>> create_operations() {
            std::map<std::string, std::function<void(project::mode &)>> operations_map;
            operations_map["help"] = &project::mode::help;
            operations_map["start"] = &project::mode::start;
            operations_map["upgrade"] = &project::mode::upgrade;
            operations_map["recovery"] = &project::mode::recovery;
            operations_map["migrate"] = &project::mode::migrate;
            operations_map["install"] = &project::mode::install;
            operations_map["version"] = &project::mode::version;
            operations_map["repair"] = &project::mode::repair;
            operations_map["info"] = &project::mode::info;


            return operations_map;
        }

    } // glc
} // cli