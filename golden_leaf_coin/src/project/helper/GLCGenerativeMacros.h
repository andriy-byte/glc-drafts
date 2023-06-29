//
// Created by andriy on 5/19/23.
//

#ifndef GOLDEN_LEAF_COIN_GLCGENERATIVEMACROS_H
#define GOLDEN_LEAF_COIN_GLCGENERATIVEMACROS_H



#define GLC_OOP_GET_SET_CONST_REFERENCE_DECLARATION(type, name_lowercase, name_uppercase) \
[[nodiscard]] const type &get##name_uppercase() const;                                    \
void set##name_uppercase(const type &name_lowercase);



#define GLC_OOP_GET_SET_CONST_REFERENCE_REALIZATION(method_path, type, name_lowercase, name_uppercase) \
const type &method_path::get##name_uppercase() const {                                                  \
    return this->name_lowercase;                                                                       \
}                                                                                                      \
                                                                                                       \
void method_path::set##name_uppercase(const type &name_lowercase){                                     \
    this->name_lowercase = name_lowercase;                                                             \
}



#endif //GOLDEN_LEAF_COIN_GLCGENERATIVEMACROS_H
