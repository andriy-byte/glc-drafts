#ifndef GOLDEN_LEAF_COIN_GLCBADINITIALIZATIONEXCEPTION_H
#define GOLDEN_LEAF_COIN_GLCBADINITIALIZATIONEXCEPTION_H

#include "GLCException.h"

namespace glc {
    namespace stl {
        namespace exception {

            class GLCBadInitializationException : public GLCException {
            public:
                using GLCException::GLCException;

                GLCBadInitializationException();

                std::string what() override;
            };

        }
    }
} // namespace glc::stl::exception

#endif // GOLDEN_LEAF_COIN_GLCBADINITIALIZATIONEXCEPTION_H
