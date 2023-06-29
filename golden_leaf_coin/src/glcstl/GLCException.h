#ifndef GOLDEN_LEAF_COIN_GLCEXCEPTION_H
#define GOLDEN_LEAF_COIN_GLCEXCEPTION_H

#include "string_interpolation.h"
#include <boost/assert/source_location.hpp>
#include <sstream>
#include <string>

namespace glc {
    namespace stl {
        namespace exception {

            class GLCException : public std::exception {

            public:
                explicit GLCException(const boost::source_location &location);

                explicit GLCException(istr::StringInterpolation exception_message);

                virtual std::string what();

                GLCException(const boost::source_location &location,
                             istr::StringInterpolation exception_message);

                GLCException();

                [[nodiscard]] const boost::source_location & getLocation() const noexcept;

                [[nodiscard]] const istr::StringInterpolation &getExceptionMessage() const noexcept;

                void setLocation(const boost::source_location &location) noexcept;

                void setExceptionMessage(const istr::StringInterpolation &exception_message) noexcept;

            protected:

                virtual void initializeBasicInformMessage();


                boost::source_location location;
                istr::StringInterpolation exception_message;
                istr::StringInterpolation inform_message;
            };
        }
    }
} // namespace glc::stl::exception

#endif // GOLDEN_LEAF_COIN_GLCEXCEPTION_H
