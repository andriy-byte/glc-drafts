//
// Created by andriy on 6/28/23.
//

#ifndef GLC_COMMAND_H
#define GLC_COMMAND_H


#include <boost/regex.hpp>
#include <fmt/format.h>
#include <unordered_set>
#include <utility>

namespace glc {
    namespace cli {

        class command {
        public:
            command(std::string &&name, std::string &&description);

            [[nodiscard]] const std::string &get_name() const;

            [[nodiscard]] const std::string &get_description() const;

            [[nodiscard]] const boost::regex &get_command_regex() const;

            void set_name(const std::string &name);

            void set_description(const std::string &description);

            void set_command_regex(const boost::regex &command_regex);

        private:
            boost::regex generate_command(std::string &&name);

            std::string name;
            std::string description;
            boost::regex command_regex;
        };


        class command_list {
        private:
            command_list() = default;

        public:
            static command_list &get_instance();

            std::map<std::string, command> &get_commands() const;

        private:
            mutable std::map<std::string, command> commands;

        };


    } // glc
} // cli

#endif //GLC_COMMAND_H
