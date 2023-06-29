
#include "GLCFormatException.h"

#include <utility>

namespace glc {
    namespace stl {
        namespace exception {

            GLCFormatException::GLCFormatException() : GLCException() {
                setExceptionMessage(istr::StringInterpolation("throwing a format exception, look at the information "
                                                              "above, format is incorrect "));
            }


            GLCFormatException::GLCFormatException(const istr::StringInterpolation &exception_message,
                                                   const std::string& wrong_format) : GLCException(exception_message),
                                                                                      wrong_format(std::move(wrong_format)) {}

            const std::string &GLCFormatException::getWrongFormat() const {
                return wrong_format;
            }

            void GLCFormatException::setWrongFormat(const std::string &wrong_format) {
                this->wrong_format = wrong_format;
            }

            GLCFormatException::GLCFormatException(const boost::source_location &location,
                                                   istr::StringInterpolation exception_message,
                                                   const std::string &wrong_format) : GLCException(location,
                                                                                                   exception_message),
                                                                                      wrong_format(wrong_format) {

            }

            void GLCFormatException::initializeBasicInformMessage() {
                GLCException::initializeBasicInformMessage();
                this->inform_message += istr::StringInterpolation("wrong format : {{wrong_format}}\n",
                                                                  {{"wrong_format", this->wrong_format}});
            }

            GLCFormatException::GLCFormatException(const boost::source_location &location,
                                                   const std::string &wrong_format)
                    : GLCException(location), wrong_format(wrong_format) {}

            GLCFormatException::GLCFormatException(const std::string &wrong_format)
                    : GLCException(), wrong_format(wrong_format) {}

        }
    }
} // namespace glc::stl::exception