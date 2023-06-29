#ifndef GOLDEN_LEAF_COIN_GLCFORMATEXCEPTION_H
#define GOLDEN_LEAF_COIN_GLCFORMATEXCEPTION_H

#include "GLCException.h"

namespace glc {
    namespace stl {
        namespace exception {

            class GLCFormatException : public GLCException {
            public:
                using GLCException::GLCException;

                GLCFormatException();

                GLCFormatException(const boost::source_location &location,
                                   istr::StringInterpolation exception_message, const std::string &wrong_format);

                GLCFormatException(const istr::StringInterpolation &exception_message, const std::string &wrong_format);

                [[nodiscard]] const std::string &getWrongFormat() const;

                void setWrongFormat(const std::string &wrong_format);

                GLCFormatException(const boost::source_location &location, const std::string &wrong_format);

                explicit GLCFormatException(const std::string &wrong_format);

            protected:
                void initializeBasicInformMessage() override;

            private:
                std::string wrong_format;

            };

        }
    }
} // namespace glc::stl::exception

#endif // GOLDEN_LEAF_COIN_GLCFORMATEXCEPTION_H
