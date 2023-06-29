//
// Created by andriy on 4/19/23.
//

#include "GLCCSD.h"

namespace glc {
    namespace mine {
        namespace csd {
            GLCCSD::GLCCSD(const uint8_t &current_state) : current_state(current_state) {}

            uint8_t GLCCSD::getcurrentState() const {
                return current_state;
            }

            void GLCCSD::setcurrentState(const uint8_t &current_state) {
                this->current_state = current_state;
            }
        } // glc
    } // mine
} // csd