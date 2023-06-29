

#ifndef GOLDEN_LEAF_COIN_GLCCLIAPPLICATION_H
#define GOLDEN_LEAF_COIN_GLCCLIAPPLICATION_H

#include "../../../GLCVariables.h"
#include "../../../glcstl/GLCDateTime.h"
#include "../../../glcstl/GLCDateTimeFormat.h"
#include "../../../glcstl/GLCDateTimeFormatTypes.h"
#include "GLCCLIDecoration.h"
#include "../GLCApplicable.h"
#include "GLCCLIVariables.h"
#include <algorithm>
#include <fmt/color.h>
#include <fmt/printf.h>
#include <iostream>
#include <utility>
#include <filesystem>
#include <spdlog/spdlog.h>
#include "../../../externallibs/defer-cpp/include/defer.hpp"

namespace glc {
    namespace application {
        namespace cli {
            class GLCCLIApplication : public GLCApplicable {
            public:

                void start() const override;

                bool isStarted() const override;

                void configurate() const override;

                explicit GLCCLIApplication(int &main_argc, char **main_argv);

                GLCCLIApplication() = default;

            private:
                static bool is_initializated;
                args::GLCApplicationMainArgumentsParser main_arguments_parser;
            };
        }
    }
} // namespace cli

#endif // GOLDEN_LEAF_COIN_GLCCLIAPPLICATION_H
