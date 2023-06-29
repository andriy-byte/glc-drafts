//
// Created by andriy on 6/28/23.
//

#include "command.h"

namespace glc {
    namespace cli {


        command_list &command_list::get_instance() {
            static command_list instance;
            return instance;
        }

        std::map<std::string, command> &
        command_list::get_commands() const {
            return commands;
        }


        boost::regex command::generate_command(std::string &&name) {
            return boost::regex{std::string("--?" + name), boost::regex_constants::icase};
        }


        command::command(std::string &&name, std::string &&description)
                : name(std::move(name)), description(std::move(description)),
                  command_regex(generate_command(std::move(name))) {}

        const std::string &command::get_name() const {
            return name;
        }

        const std::string &command::get_description() const {
            return description;
        }

        const boost::regex &command::get_command_regex() const {
            return command_regex;
        }

        void command::set_name(const std::string &name) {
            this->name = name;
        }

        void command::set_description(const std::string &description) {
            this->description = description;
        }

        void command::set_command_regex(const boost::regex &command_regex) {
            this->command_regex = command_regex;
        }


    } // glc
} // cli