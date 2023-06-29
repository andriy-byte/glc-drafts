
#include "GLCCLICommandsTools.h"

namespace glc {
    namespace application {
        namespace cli {
            namespace commands {
                std::string basicReCommandGeneration(const std::string &name) {
                    std::string temp = boost::to_lower_copy(name);

                    istr::StringInterpolation result("({{upper}}|[{{fistr_letter}}]{{after_first_letter}})");
                    result.setMode(istr::Modes::WITHOUT_REPLACEMENT_VALIDATION);
                    result.putPatternArguments(
                            {
                                    {"upper",              boost::to_upper_copy(name)},
                                    {"first_letter",       boost::lexical_cast<std::string>(name.at(0))},
                                    {"after_first_letter", name.substr(1, name.size())}
                            }
                    );


                    return result.getSubstituted();

                };
            } // glc
        } // application
    } // cli
} // commands