
#include "GLCDateTime.h"

namespace glc
{
    namespace stl
    {
        namespace datetime
        {

            std::string
            GLCDateTime::now(const GLCDateTimeFormat &date_time_format) noexcept(false) {
                std::mutex mutex;
                std::lock_guard<std::mutex> lock(mutex);
                GLCDateTimeFormat correctDateTimeFormat{date_time_format};

#if defined(GLC_USE_EXCEPTIONS_CASES_DATE_TIME)
                try
                {
                    correctDateTimeFormat.tryFormat();
                }
                catch (GLCFormatException &glcFormatException)
                {
                    istr::StringInterpolation exception_message(
                        R"(wrong date time format "{{wrong_format}}", it will be replaced by default "{{default_format}}")");
                    exception_message.putPatternArguments({{"default_format", utc.getFormat()},
                                                          {"wrong_format", glcFormatException.getWrongFormat()}});
                    glcFormatException.setLocation(BOOST_CURRENT_LOCATION);
                    glcFormatException.setExceptionMessage(exception_message);

                    spdlog::warn(glcFormatException.what());

                    correctDateTimeFormat = utc;
                }
#else
                if (!date_time_format.isCorrect())
                {
                    correctDateTimeFormat = utc;
                }
#endif

                std::stringstream stringStream;
                auto t = std::time(nullptr);
                auto tm = *std::localtime(&t);

                stringStream << std::put_time(&tm, correctDateTimeFormat.getFormat().c_str());
                return stringStream.str();

            }

            std::string GLCDateTime::now()
            {
                return now(utc);
            }

        }
    }
} // namespace glc::stl::datetime
