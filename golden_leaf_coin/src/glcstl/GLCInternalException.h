

#ifndef GOLDEN_LEAF_COIN_GLCINTERNALEXCEPTION_H
#define GOLDEN_LEAF_COIN_GLCINTERNALEXCEPTION_H

#include <exception>
#include <string>
#include <boost/assert/source_location.hpp>
#include <utility>
#include <sstream>


namespace glc {
    namespace stl {
        namespace exception {

            class GLCInternalException : std::exception {

            public:
                GLCInternalException() = default;

                [[nodiscard]] std::string what();

                explicit GLCInternalException(std::string exception_message);

                [[nodiscard]] const std::string &getExceptionMessage() const;

                void setExceptionMessage(const std::string &exception_message);

                [[nodiscard]] const boost::source_location &getLocation() const;

                void setLocation(const boost::source_location &location);

                GLCInternalException(std::string exceptionMessage, const boost::source_location &location);

            private:
                std::string exception_message;
                boost::source_location location;

            };

        }
    }
} // glc::stl::exception

#endif //GOLDEN_LEAF_COIN_GLCINTERNALEXCEPTION_H
