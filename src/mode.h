//
// Created by andriy on 6/28/23.
//

#ifndef GLC_MODE_H
#define GLC_MODE_H


#include <boost/program_options.hpp>
#include <fmt/printf.h>
#include <iostream>
#include "constants.h"

namespace glc {
    namespace project {
        namespace po = boost::program_options;

        class informatable {
        public:
            virtual void version() const = 0;

            virtual void help() const = 0;

            virtual void info() const = 0;

        };

        class maintenanceable {
        public:
            virtual void repair() const = 0;

            virtual void install() const = 0;

            virtual void recovery() const = 0;

            virtual void upgrade() const = 0;
        };

        class controller {
        public:
            virtual void migrate() const = 0;

            virtual void start() const = 0;
        };

        class mode : public informatable, public maintenanceable, public controller {
        public:
            mode() = default;

            explicit mode(const po::options_description &description);

            void version() const override;

            void help() const override;

            void repair() const override;

            void install() const override;

            void recovery() const override;

            void info() const override;

            void upgrade() const override;

            void migrate() const override;

            void start() const override;

        private:
            po::options_description description;

        };

    } // glc
} // project

#endif //GLC_MODE_H
