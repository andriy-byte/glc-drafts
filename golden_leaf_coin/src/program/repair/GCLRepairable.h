//
// Created by andriy on 5/19/23.
//

#ifndef GOLDEN_LEAF_COIN_GCLREPAIRABLE_H
#define GOLDEN_LEAF_COIN_GCLREPAIRABLE_H



namespace glc {
    namespace program {
        namespace repair {
            enum RepairStatus {
                IS_BROKEN,
                IS_WHOLE
            };

            class GLCProgramRepaireble {
                virtual void repair() const = 0;
                [[nodiscard]] virtual const RepairStatus& getRepairStatus() const = 0;
            };
        }
    }
}


#endif //GOLDEN_LEAF_COIN_GCLREPAIRABLE_H
