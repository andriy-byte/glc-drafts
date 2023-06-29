#include "GLCBadInitializationException.h"
#include "string_interpolation.h"

namespace glc {
    namespace stl {
        namespace exception {

            std::string GLCBadInitializationException::what() {
                return GLCException::what();
            }

            GLCBadInitializationException::GLCBadInitializationException()
                    : GLCException() {
                setExceptionMessage(istr::StringInterpolation(
                        "throwing a bad initialization exception"
                        ", the istance can't be created that way.",
                        istr::SubstitutionPreparationModes::WITHOUT_REPLACEMENT_VALIDATION));
            }

        }
    }
} // namespace glc::stl::exception