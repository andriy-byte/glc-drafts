//
// Created by andriy on 4/23/23.
//

#include "GLCCLIInput.h"


glc::application::cli::GLCCLIInput::GLCCLIInput(const fmt::text_style &input_style, const fmt::text_style &info_style,
                                                const fmt::text_style &error_style) : input_style(input_style), info_style(info_style),
                                                                                  error_style(error_style) {}



const char glc::application::cli::GLCCLIInput::line_input = '>';

GLC_OOP_GET_SET_CONST_REFERENCE_REALIZATION(glc::application::cli::GLCCLIInput, fmt::text_style, input_style, InputStyle)
GLC_OOP_GET_SET_CONST_REFERENCE_REALIZATION(glc::application::cli::GLCCLIInput, fmt::text_style, info_style, InfoStyle)
GLC_OOP_GET_SET_CONST_REFERENCE_REALIZATION(glc::application::cli::GLCCLIInput, fmt::text_style, error_style, ErrorStyle)

void glc::application::cli::GLCCLIInput::scan() {

}

