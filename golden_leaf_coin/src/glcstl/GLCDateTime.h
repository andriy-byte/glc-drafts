

#ifndef GOLDEN_LEAF_COIN_GLCDATETIME_H
#define GOLDEN_LEAF_COIN_GLCDATETIME_H

#include "GLCFormatException.h"
#include "GLCDateTimeFormatTypes.h"
#include "string_interpolation.h"
#include "GLCDateTimeFormat.h"
#include <mutex>
#include <iomanip>

#if defined(GLC_USE_EXCEPTIONS_CASES_DATE_TIME)
#include <spdlog/spdlog.h>
#endif

namespace glc {
    namespace stl {
        namespace datetime {
            using namespace exception;
            using namespace formats;
            using namespace formats::types;

            class GLCDateTime {

            public:
                static std::string now(const GLCDateTimeFormat &date_time_format) noexcept(false);

                static std::string now();


            };

        }
    }
} // namespace glc::stl::datetime

#endif // GOLDEN_LEAF_COIN_GLCDATETIME_H
