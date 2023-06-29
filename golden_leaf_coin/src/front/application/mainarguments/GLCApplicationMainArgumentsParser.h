#ifndef GOLDEN_LEAF_COIN_GLCCLIMAINARGUMENTSPARSER_H
#define GOLDEN_LEAF_COIN_GLCCLIMAINARGUMENTSPARSER_H


#include <boost/program_options.hpp>
#include <utility>

namespace glc {
    namespace application {
        namespace args {

            class GLCApplicationMainArgumentsParser {

            public:
                GLCApplicationMainArgumentsParser() = default;

                explicit GLCApplicationMainArgumentsParser(int &main_argc, char **main_argv);

                bool isMainArgumentsValid() const;

                void tryMainArgumentsValidation() noexcept(false);


            private:
                std::unique_ptr<boost::program_options::command_line_parser> main_arguments_parser;
                int main_argc;
                char **main_argv;

            };

        }
    }
} // namespace glc::cli::application

#endif // GOLDEN_LEAF_COIN_GLCCLIMAINARGUMENTSPARSER_H
