
#include "GLCCLICommands.h"

namespace glc {
    namespace application {
        namespace cli {
            namespace commands {
                const boost::regex authentication("AUTHENTICATION|[Aa]uthentication");
                const boost::regex exit("EXIT|[Ee]xit");
                const boost::regex mining("MINING|[Mm]ining");
                const boost::regex wallet("WALLET|[Ww]allet");

                namespace mine {
                    const boost::regex start("START|[Ss]tart");
                    const boost::regex stop("STOP|[Ss]top");
                    const boost::regex pause("PAUSE|[Pp]ause");
                }

                namespace wallets {
                    const boost::regex create("CREATE|[Cc]reate");
                    const boost::regex show("SHOW|[Ss]how");
                }
                namespace transactions {
                    const boost::regex send("SEND|[Ss]end");
                }

                namespace authentications {
                    const boost::regex sign_in("SIGN_IN|[Ss]ign_in");
                    const boost::regex sign_up("SIGN_UP|[Ss]ign_up");
                }

            } // commands
        } // glc
    } // application
} // cli