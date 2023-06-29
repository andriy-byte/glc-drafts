

#ifndef GOLDEN_LEAF_COIN_GLCAPPLICABLE_H
#define GOLDEN_LEAF_COIN_GLCAPPLICABLE_H

#include "mainarguments/GLCApplicationMainArgumentsParser.h"
#include "GLCApplicationConfiguration.h"
namespace glc {
    namespace application {

        class GLCApplicable {

        public:
            virtual void start() const = 0;
            [[nodiscard]] virtual bool isStarted() const = 0;
            virtual void configurate() const  = 0;

        };

    }
} // application

#endif //GOLDEN_LEAF_COIN_GLCAPPLICABLE_H
