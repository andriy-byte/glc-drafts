
#ifndef GLC_APPLICATION_H
#define GLC_APPLICATION_H


#include "constants.h"
#include <boost/container/small_vector.hpp>
#include <boost/program_options.hpp>
#include "commands_list.h"

namespace glc {
    namespace cli {
        namespace po = boost::program_options;

        class application {
        public:
            explicit application(po::variables_map &arguments_map,po::options_description &description);

            void run();


        private:
            po::variables_map arguments_map;
            po::options_description description;


        };


        class application_preparation final {
        public:

            application_preparation() = default;

            bool is_correct_arguments_quantity(const int &argc);

            bool is_correct_arguments(const int &argc, const char **argv);

            void wrong_preparation();

            [[nodiscard]] po::variables_map &get_arguments_map() const;

            [[nodiscard]] po::options_description &get_description() const;

        private:
            std::string error_preparation_message;
            mutable po::options_description description{constants::PROGRAM_DESCRIPTION_NAME};
            mutable po::variables_map arguments_map;

        };
    }
}


#endif //GLC_APPLICATION_H
