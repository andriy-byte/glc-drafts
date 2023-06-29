//
// Created by andriy on 4/23/23.
//

#ifndef GOLDEN_LEAF_COIN_GLCCLIINPUT_H
#define GOLDEN_LEAF_COIN_GLCCLIINPUT_H




#include <fmt/color.h>
#include "../../../project/helper/GLCGenerativeMacros.h"

namespace glc {
    namespace application {
        namespace cli {
            class GLCCLIInput {
            public:
                void scan();
                GLCCLIInput() = default;

                GLCCLIInput(const fmt::text_style &input_style, const fmt::text_style &info_style, const fmt::text_style &error_style);
                GLC_OOP_GET_SET_CONST_REFERENCE_DECLARATION(fmt::text_style,input_style, InputStyle)
                GLC_OOP_GET_SET_CONST_REFERENCE_DECLARATION(fmt::text_style,info_style, InfoStyle)
                GLC_OOP_GET_SET_CONST_REFERENCE_DECLARATION(fmt::text_style,error, ErrorStyle)

            private:
                static const char line_input;
                fmt::text_style input_style, info_style, error_style;
            };
        }
    }
}


#endif //GOLDEN_LEAF_COIN_GLCCLIINPUT_H
