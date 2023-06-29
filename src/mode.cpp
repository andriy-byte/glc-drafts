//
// Created by andriy on 6/28/23.
//

#include "mode.h"

namespace glc {
    namespace project {
        void mode::version() const {
            fmt::print("\nVersion : {}\n", constants::VERSION);
        }

        void mode::help() const {
            description.print(std::cout);

        }

        void mode::repair() const {
            fmt::print("\n{}\n", __FUNCTION__);

        }

        void mode::install() const {
            fmt::print("\n{}\n", __FUNCTION__);

        }

        void mode::recovery() const {
            fmt::print("\n{}\n", __FUNCTION__);

        }

        void mode::upgrade() const {
            fmt::print("\n{}\n", __FUNCTION__);

        }

        void mode::migrate() const {
            fmt::print("\n{}\n", __FUNCTION__);

        }

        void mode::start() const {
            fmt::print("\n{}\n", __FUNCTION__);

        }

        void mode::info() const {
            fmt::print("\nGLC cryptocurency\ncurrent version : {}",constants::VERSION);
            fmt::print("\nMore information will follow.\n");

        }

        mode::mode(const po::options_description &description) : description(description) {}



    } // glc
} // project