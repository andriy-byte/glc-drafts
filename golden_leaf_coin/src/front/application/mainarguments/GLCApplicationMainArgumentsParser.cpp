#include "GLCApplicationMainArgumentsParser.h"

namespace glc {
    namespace application {
        namespace args {

            GLCApplicationMainArgumentsParser::GLCApplicationMainArgumentsParser(int &main_argc, char **main_argv) {
                this->main_argc = main_argc;
                this->main_argv = main_argv;
                this->main_arguments_parser = std::make_unique<boost::program_options::command_line_parser>(
                        boost::program_options::command_line_parser(main_argc, main_argv)
                );
            }


        }
    }
} // namespace glc::cli::application