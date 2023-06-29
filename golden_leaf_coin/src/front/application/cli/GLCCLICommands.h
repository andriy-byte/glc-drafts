

#ifndef GOLDEN_LEAF_COIN_GLCCLICOMMANDS_H
#define GOLDEN_LEAF_COIN_GLCCLICOMMANDS_H


#include <boost/regex.hpp>



namespace glc {
    namespace application {
        namespace cli {
            namespace commands {
                extern const boost::regex authentication;
                extern const boost::regex exit;
                extern const boost::regex mining;
                extern const boost::regex wallet;
                namespace mine {
                    extern const boost::regex start;
                    extern const boost::regex stop;
                    extern const boost::regex pause;
                }
                namespace wallets {
                    extern const boost::regex create;
                    extern const boost::regex show;
                }
                namespace transactions {
                    extern const boost::regex send;
                }

                namespace authentications {
                    extern const boost::regex sign_in;
                    extern const boost::regex sign_up;
                }


            } // commands
        } // glc
    } // application
} // cli

#endif //GOLDEN_LEAF_COIN_GLCCLICOMMANDS_H
