

#include "GLCInternalException.h"

namespace glc {
    namespace stl {
        namespace exception {


            GLCInternalException::GLCInternalException(std::string exception_message) : exception_message(
                    std::move(exception_message)) {

            }

            std::string GLCInternalException::what() {

                std::stringstream stringStream;
                stringStream << "\n";
                stringStream << "exception in file : " << location.file_name() << "\n"
                             << "inside function : " << location.function_name() << "\n"
                             << "at line : " << location.line() << "\n"
                             << "exception message : " << exception_message << "\n";

                return stringStream.str();
            }

            GLCInternalException::GLCInternalException(std::string exceptionMessage,
                                                       const boost::source_location &location)
                    : exception_message(std::move(exceptionMessage)), location(location) {}

            const std::string &GLCInternalException::getExceptionMessage() const {
                return this->exception_message;
            }

            void GLCInternalException::setExceptionMessage(const std::string &exception_message) {
                this->exception_message = exception_message;
            }

            const boost::source_location &GLCInternalException::getLocation() const {
                return this->location;
            }

            void GLCInternalException::setLocation(const boost::source_location &location) {
                this->location = location;
            }

        }
    }
} // glc::stl::exception