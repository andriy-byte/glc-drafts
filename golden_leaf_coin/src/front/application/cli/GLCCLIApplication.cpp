


#include "GLCCLIApplication.h"

namespace glc {
    namespace application {
        namespace cli {

            bool GLCCLIApplication::is_initializated = false;

            void GLCCLIApplication::start() const {

                namespace glcdt = glc::stl::datetime;
                namespace glcdtf = glcdt::formats;
                namespace glcev = glc::environment::variables;
                namespace glcadcli = glc::applicationattributes::cli::decoration;
                namespace glccliv = glc::application::cli::variables;
                namespace fs = std::filesystem;

                int af = 0;
                defer::defer<int> a(af,34);

                std::string msg;
                fmt::text_style user_color;

                msg = "Welcome. You is administrator. Project in development. ";
                user_color = fmt::fg(fmt::color::fire_brick);

                glcadcli::glc_cli_representable_version.putPatternArgument("version", glccliv::glc_cli_version);
                glcadcli::glc_cli_name_figlet_banner.putPatternArgument("version",
                                                                        glcadcli::glc_cli_representable_version.getSubstituted());
                fmt::print("{banner}", fmt::arg("banner", fmt::format(fmt::fg(fmt::color::gold),
                                                                      glcadcli::glc_cli_name_figlet_banner.getSubstituted())));


                fmt::print(
                        "[{date}] {sep} {msg} \n",
                        fmt::arg("date",
                                 fmt::format(fmt::fg(fmt::color::white) | fmt::emphasis::bold,
                                             glcdt::GLCDateTime::now())),
                        fmt::arg("sep", fmt::format(user_color | fmt::emphasis::bold, " - ")),
                        fmt::arg("msg", fmt::format(user_color, msg)));

                fmt::print("Press any key to continue ... ");
                std::cin.get();
            }

            GLCCLIApplication::GLCCLIApplication(int &main_argc, char **main_argv) {
                if (!this->isStarted()) {
                    this->main_arguments_parser = args::GLCApplicationMainArgumentsParser(main_argc, main_argv);

                    is_initializated = true;
                }
            }

            bool GLCCLIApplication::isStarted() const {
                return is_initializated;
            }

            void GLCCLIApplication::configurate() const {
                spdlog::set_level(spdlog::level::warn);


            }

        }
    }
} // namespace glc::application::cli