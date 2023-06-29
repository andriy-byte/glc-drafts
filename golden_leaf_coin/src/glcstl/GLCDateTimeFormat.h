

#ifndef GOLDEN_LEAF_COIN_GLCDATETIMEFORMAT_H
#define GOLDEN_LEAF_COIN_GLCDATETIMEFORMAT_H

#include "GLCFormatException.h"
#include <string>
#include <algorithm>

namespace glc {
    namespace stl {
        namespace datetime {
            namespace formats {
                using namespace exception;

                extern const char datetime_format_piece_start;

                class GLCDateTimeFormat {

                public:
                    GLCDateTimeFormat() = default;

                    explicit GLCDateTimeFormat(const std::string &format);

                    [[nodiscard]] bool isCorrect() const;

                    void tryFormat() const noexcept(false);

                    [[nodiscard]] const std::string &getFormat() const;

                    void setFormat(const std::string &format);
                    [[nodiscard]] const std::string getFormatAsFormatrable() const;

                private:
                    std::string format;
                };

            }
        }
    }
} // namespace glc::stl::datetime::formats

#endif // GOLDEN_LEAF_COIN_GLCDATETIMEFORMAT_H
