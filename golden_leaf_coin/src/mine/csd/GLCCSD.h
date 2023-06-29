//
// Created by andriy on 4/19/23.
//

#ifndef GOLDEN_LEAF_COIN_GLCCSD_H
#define GOLDEN_LEAF_COIN_GLCCSD_H


#include <cstdint>

namespace glc {
    namespace mine {
        namespace csd {

            class GLCCSD {
            public:
                explicit GLCCSD(const uint8_t &current_state);

                [[nodiscard]] uint8_t getcurrentState() const;

                void setcurrentState(const uint8_t &current_state);

            private:
                 uint8_t current_state;
            };

        } // glc
    } // mine
} // csd

#endif //GOLDEN_LEAF_COIN_GLCCSD_H
