

#ifndef GOLDEN_LEAF_COIN_GLCAPPLICATION_H
#define GOLDEN_LEAF_COIN_GLCAPPLICATION_H

#include <concepts>
#include "GLCApplicable.h"

namespace glc {
    namespace application {

        template<typename ApplicationType>
        concept Application = std::is_base_of<GLCApplicable, ApplicationType>::value;

        template<Application T>
        class GLCApplication {
        public:
            GLCApplication() = delete;

            GLCApplication(int &mainArgc, char **mainArgv);

            void start() const;
            void configure() const noexcept;

        private:
            friend class GLCApplicable;

            T application;
        };

        template<Application T>
        GLCApplication<T>::GLCApplication(int &mainArgc, char **mainArgv) {
            if (!this->application.isStarted()) {
                application = T(mainArgc, mainArgv);
            }
        }

        template<Application T>
        void GLCApplication<T>::start() const {
            application.start();
        }
        template <Application T>
        void GLCApplication<T>::configure() const noexcept {
            application.configurate();
        }

    }
} // namespace glc::application

#endif // GOLDEN_LEAF_COIN_GLCAPPLICATION_H
