

#include "GLCDateTimeFormat.h"

namespace glc {
    namespace stl {
        namespace datetime {
            namespace formats {

                const char datetime_format_piece_start = '%';

                GLCDateTimeFormat::GLCDateTimeFormat(const std::string &format)
                        : format(format) {}

                const std::string &GLCDateTimeFormat::getFormat() const { return this->format; }

                void GLCDateTimeFormat::setFormat(const std::string &format) {
                    this->format = format;
                }

                bool GLCDateTimeFormat::isCorrect() const {
                    return getFormat().empty() ||
                           std::all_of(getFormat().cbegin(), getFormat().cend(), isspace) ||
                           getFormat().contains(datetime_format_piece_start);
                }

                void GLCDateTimeFormat::tryFormat() const noexcept(false) {
                    if (!isCorrect()) {
                        throw GLCFormatException(getFormat());
                    }
                }
                const std::string GLCDateTimeFormat::getFormatAsFormatrable() const {
                    return "{" + getFormat()+ "}";
                }

            }
        }
    }
} // namespace glc::stl::datetime::formats
