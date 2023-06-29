

#include "GLCGUIApplication.h"


namespace glc {
    namespace application {
        namespace gui {

            bool GLCGUIApplication::initialize_once = true;

            void GLCGUIApplication::start() const {

            }

            bool GLCGUIApplication::isStarted() const {
                return initialize_once;
            }

            GLCGUIApplication::GLCGUIApplication(int &main_argc, char **main_argv) {
                if (initialize_once) {
                    /*
                     *
                     * main arguments
                     */

                    initialize_once = false;
                }

            }
        }
    }
}


