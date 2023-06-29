

#ifndef GOLDEN_LEAF_COIN_GLCGUIAPPLICATION_H
#define GOLDEN_LEAF_COIN_GLCGUIAPPLICATION_H

#include "../GLCApplicable.h"

namespace glc {
    namespace application {
        namespace gui {
            class GLCGUIApplication : public GLCApplicable {
            public:

                void start() const override;

                bool isStarted() const override;

                explicit GLCGUIApplication(int &main_argc, char **main_argv);

                GLCGUIApplication() = default;

            private:
                static bool initialize_once;
            };
        }
    }
}


#endif //GOLDEN_LEAF_COIN_GLCGUIAPPLICATION_H
