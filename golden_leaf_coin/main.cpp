#include "src/front/application/GLCApplication.h"
#include "src/front/application/cli/GLCCLIApplication.h"

int main(int argc, char **argv, char **env) {
    using namespace glc::application;

    GLCApplication<cli::GLCCLIApplication> glc_application{argc, argv};
    glc_application.configure();
    glc_application.start();



    return 0;
}
