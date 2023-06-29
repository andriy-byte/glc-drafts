

#include "GLCException.h"
#include <utility>

namespace glc
{
    namespace stl
    {
        namespace exception
        {
            GLCException::GLCException(const boost::source_location &location)
                : location(location) {}

            std::string GLCException::what()
            {
                this->initializeBasicInformMessage();
                return this->inform_message.getSubstituted();
            }

            const boost::source_location &GLCException::getLocation() const noexcept
            {
                return this->location;
            }

            const istr::StringInterpolation &GLCException::getExceptionMessage() const noexcept
            {
                return this->exception_message;
            }

            void GLCException::setLocation(
                const boost::source_location &location) noexcept
            {
                this->location = location;
            }

            void GLCException::setExceptionMessage(
                const istr::StringInterpolation &exception_message) noexcept
            {
                this->exception_message = exception_message;
            }

            GLCException::GLCException(istr::StringInterpolation exception_message)
                : exception_message(std::move(exception_message)) {}

            GLCException::GLCException(const boost::source_location &location,
                                       istr::StringInterpolation exception_message)
                : location(location), exception_message(std::move(exception_message)) {}

            GLCException::GLCException()
            {
                setExceptionMessage(
                    istr::StringInterpolation("throwing a base exception, look at the information above"));
            }

            void GLCException::initializeBasicInformMessage()
            {
                this->inform_message = istr::StringInterpolation("\n"
                                                                "exception in file : {{file_name}}\n"
                                                                "inside function : {{function_name}}\n"
                                                                "at line : {{line}}\n"
                                                                "exception message : {{exception_message}}\n");
                this->inform_message.putPatternArguments({{"file_name",         getLocation().file_name()},
                                                          {"function_name",     getLocation().function_name()},
                                                          {"line",              std::to_string(getLocation().line())},
                                                          {"exception_message", exception_message.getSubstituted()}});
            }

        }
    }
} // namespace glc::stl::exception
