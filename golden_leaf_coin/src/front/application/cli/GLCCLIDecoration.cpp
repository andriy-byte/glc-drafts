


#include "GLCCLIDecoration.h"

namespace glc {
    namespace applicationattributes {
        namespace cli {
            namespace decoration {

                const istr::StringInterpolation glc_cli_name_figlet_banner(
                        R"(
   _____         _      _                _                    __    _____        _
  / ____|       | |    | |              | |                  / _|  / ____|      (_)
 | |  __   ___  | |  __| |  ___  _ __   | |      ___   __ _ | |_  | |      ___   _  _ __
 | | |_ | / _ \ | | / _` | / _ \| '_ \  | |     / _ \ / _` ||  _| | |     / _ \ | || '_ \
 | |__| || (_) || || (_| ||  __/| | | | | |____|  __/| (_| || |   | |____| (_) || || | | |
  \_____| \___/ |_| \__,_| \___||_| |_| |______|\___| \__,_||_|    \_____|\___/ |_||_| |_|
                                        {{version}}
)", istr::SubstitutionPreparationModes::WITHOUT_REPLACEMENT_VALIDATION);

                const istr::StringInterpolation glc_cli_representable_version("v {{version}}",
                                                                              istr::SubstitutionPreparationModes::WITHOUT_REPLACEMENT_VALIDATION);
            }
        }
    }
}