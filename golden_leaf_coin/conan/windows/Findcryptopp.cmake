########## MACROS ###########################################################################
#############################################################################################

function(conan_message MESSAGE_OUTPUT)
    if (NOT CONAN_CMAKE_SILENT_OUTPUT)
        message(${ARGV${0}})
    endif ()
endfunction()


macro(conan_find_apple_frameworks FRAMEWORKS_FOUND FRAMEWORKS FRAMEWORKS_DIRS)
    if (APPLE)
        foreach (_FRAMEWORK ${FRAMEWORKS})
            # https://cmake.org/pipermail/cmake-developers/2017-August/030199.html
            find_library(CONAN_FRAMEWORK_${_FRAMEWORK}_FOUND NAMES ${_FRAMEWORK} PATHS ${FRAMEWORKS_DIRS} CMAKE_FIND_ROOT_PATH_BOTH)
            if (CONAN_FRAMEWORK_${_FRAMEWORK}_FOUND)
                list(APPEND ${FRAMEWORKS_FOUND} ${CONAN_FRAMEWORK_${_FRAMEWORK}_FOUND})
            else ()
                message(FATAL_ERROR "Framework library ${_FRAMEWORK} not found in paths: ${FRAMEWORKS_DIRS}")
            endif ()
        endforeach ()
    endif ()
endmacro()


function(conan_package_library_targets libraries package_libdir deps out_libraries out_libraries_target build_type package_name)
    unset(_CONAN_ACTUAL_TARGETS CACHE)
    unset(_CONAN_FOUND_SYSTEM_LIBS CACHE)
    foreach (_LIBRARY_NAME ${libraries})
        find_library(CONAN_FOUND_LIBRARY NAMES ${_LIBRARY_NAME} PATHS ${package_libdir}
                NO_DEFAULT_PATH NO_CMAKE_FIND_ROOT_PATH)
        if (CONAN_FOUND_LIBRARY)
            conan_message(STATUS "Library ${_LIBRARY_NAME} found ${CONAN_FOUND_LIBRARY}")
            list(APPEND _out_libraries ${CONAN_FOUND_LIBRARY})
            if (NOT ${CMAKE_VERSION} VERSION_LESS "3.0")
                # Create a micro-target for each lib/a found
                string(REGEX REPLACE "[^A-Za-z0-9.+_-]" "_" _LIBRARY_NAME ${_LIBRARY_NAME})
                set(_LIB_NAME CONAN_LIB::${package_name}_${_LIBRARY_NAME} ${build_type})
                if (NOT TARGET ${_LIB_NAME})
                    # Create a micro-target for each lib/a found
                    add_library(${_LIB_NAME} UNKNOWN IMPORTED)
                    set_target_properties(${_LIB_NAME} PROPERTIES IMPORTED_LOCATION ${CONAN_FOUND_LIBRARY})
                    set(_CONAN_ACTUAL_TARGETS ${_CONAN_ACTUAL_TARGETS} ${_LIB_NAME})
                else ()
                    conan_message(STATUS "Skipping already existing target: ${_LIB_NAME}")
                endif ()
                list(APPEND _out_libraries_target ${_LIB_NAME})
            endif ()
            conan_message(STATUS "Found: ${CONAN_FOUND_LIBRARY}")
        else ()
            conan_message(STATUS "Library ${_LIBRARY_NAME} not found in package, might be system one")
            list(APPEND _out_libraries_target ${_LIBRARY_NAME})
            list(APPEND _out_libraries ${_LIBRARY_NAME})
            set(_CONAN_FOUND_SYSTEM_LIBS "${_CONAN_FOUND_SYSTEM_LIBS};${_LIBRARY_NAME}")
        endif ()
        unset(CONAN_FOUND_LIBRARY CACHE)
    endforeach ()

    if (NOT ${CMAKE_VERSION} VERSION_LESS "3.0")
        # Add all dependencies to all targets
        string(REPLACE " " ";" deps_list "${deps}")
        foreach (_CONAN_ACTUAL_TARGET ${_CONAN_ACTUAL_TARGETS})
            set_property(TARGET ${_CONAN_ACTUAL_TARGET} PROPERTY INTERFACE_LINK_LIBRARIES "${_CONAN_FOUND_SYSTEM_LIBS};${deps_list}")
        endforeach ()
    endif ()

    set(${out_libraries} ${_out_libraries} PARENT_SCOPE)
    set(${out_libraries_target} ${_out_libraries_target} PARENT_SCOPE)
endfunction()


########### FOUND PACKAGE ###################################################################
#############################################################################################

include(FindPackageHandleStandardArgs)

conan_message(STATUS "Conan: Using autogenerated Findcryptopp.cmake")
set(cryptopp_FOUND 1)
set(cryptopp_VERSION "8.7.0")

find_package_handle_standard_args(cryptopp REQUIRED_VARS
        cryptopp_VERSION VERSION_VAR cryptopp_VERSION)
mark_as_advanced(cryptopp_FOUND cryptopp_VERSION)

set(cryptopp_COMPONENTS cryptopp::cryptopp-static)

if (cryptopp_FIND_COMPONENTS)
    foreach (_FIND_COMPONENT ${cryptopp_FIND_COMPONENTS})
        list(FIND cryptopp_COMPONENTS "cryptopp::${_FIND_COMPONENT}" _index)
        if (${_index} EQUAL -1)
            conan_message(FATAL_ERROR "Conan: Component '${_FIND_COMPONENT}' NOT found in package 'cryptopp'")
        else ()
            conan_message(STATUS "Conan: Component '${_FIND_COMPONENT}' found in package 'cryptopp'")
        endif ()
    endforeach ()
endif ()

########### VARIABLES #######################################################################
#############################################################################################


set(cryptopp_INCLUDE_DIRS "C:/Users/Andriy/.conan/data/cryptopp/8.7.0/_/_/package/5a61a86bb3e07ce4262c80e1510f9c05e9b6d48b/include")
set(cryptopp_INCLUDE_DIR "C:/Users/Andriy/.conan/data/cryptopp/8.7.0/_/_/package/5a61a86bb3e07ce4262c80e1510f9c05e9b6d48b/include")
set(cryptopp_INCLUDES "C:/Users/Andriy/.conan/data/cryptopp/8.7.0/_/_/package/5a61a86bb3e07ce4262c80e1510f9c05e9b6d48b/include")
set(cryptopp_RES_DIRS)
set(cryptopp_DEFINITIONS)
set(cryptopp_LINKER_FLAGS_LIST
        "$<$<STREQUAL:$<TARGET_PROPERTY:TYPE>,SHARED_LIBRARY>:>"
        "$<$<STREQUAL:$<TARGET_PROPERTY:TYPE>,MODULE_LIBRARY>:>"
        "$<$<STREQUAL:$<TARGET_PROPERTY:TYPE>,EXECUTABLE>:>"
        )
set(cryptopp_COMPILE_DEFINITIONS)
set(cryptopp_COMPILE_OPTIONS_LIST "" "")
set(cryptopp_COMPILE_OPTIONS_C "")
set(cryptopp_COMPILE_OPTIONS_CXX "")
set(cryptopp_LIBRARIES_TARGETS "") # Will be filled later, if CMake 3
set(cryptopp_LIBRARIES "") # Will be filled later
set(cryptopp_LIBS "") # Same as cryptopp_LIBRARIES
set(cryptopp_SYSTEM_LIBS ws2_32)
set(cryptopp_FRAMEWORK_DIRS)
set(cryptopp_FRAMEWORKS)
set(cryptopp_FRAMEWORKS_FOUND "") # Will be filled later
set(cryptopp_BUILD_MODULES_PATHS "C:/Users/Andriy/.conan/data/cryptopp/8.7.0/_/_/package/5a61a86bb3e07ce4262c80e1510f9c05e9b6d48b/lib/cmake/conan-official-cryptopp-targets.cmake")

conan_find_apple_frameworks(cryptopp_FRAMEWORKS_FOUND "${cryptopp_FRAMEWORKS}" "${cryptopp_FRAMEWORK_DIRS}")

mark_as_advanced(cryptopp_INCLUDE_DIRS
        cryptopp_INCLUDE_DIR
        cryptopp_INCLUDES
        cryptopp_DEFINITIONS
        cryptopp_LINKER_FLAGS_LIST
        cryptopp_COMPILE_DEFINITIONS
        cryptopp_COMPILE_OPTIONS_LIST
        cryptopp_LIBRARIES
        cryptopp_LIBS
        cryptopp_LIBRARIES_TARGETS)

# Find the real .lib/.a and add them to cryptopp_LIBS and cryptopp_LIBRARY_LIST
set(cryptopp_LIBRARY_LIST cryptopp)
set(cryptopp_LIB_DIRS "C:/Users/Andriy/.conan/data/cryptopp/8.7.0/_/_/package/5a61a86bb3e07ce4262c80e1510f9c05e9b6d48b/lib")

# Gather all the libraries that should be linked to the targets (do not touch existing variables):
set(_cryptopp_DEPENDENCIES "${cryptopp_FRAMEWORKS_FOUND} ${cryptopp_SYSTEM_LIBS} ")

conan_package_library_targets("${cryptopp_LIBRARY_LIST}"  # libraries
        "${cryptopp_LIB_DIRS}"      # package_libdir
        "${_cryptopp_DEPENDENCIES}"  # deps
        cryptopp_LIBRARIES            # out_libraries
        cryptopp_LIBRARIES_TARGETS    # out_libraries_targets
        ""                          # build_type
        "cryptopp")                                      # package_name

set(cryptopp_LIBS ${cryptopp_LIBRARIES})

foreach (_FRAMEWORK ${cryptopp_FRAMEWORKS_FOUND})
    list(APPEND cryptopp_LIBRARIES_TARGETS ${_FRAMEWORK})
    list(APPEND cryptopp_LIBRARIES ${_FRAMEWORK})
endforeach ()

foreach (_SYSTEM_LIB ${cryptopp_SYSTEM_LIBS})
    list(APPEND cryptopp_LIBRARIES_TARGETS ${_SYSTEM_LIB})
    list(APPEND cryptopp_LIBRARIES ${_SYSTEM_LIB})
endforeach ()

# We need to add our requirements too
set(cryptopp_LIBRARIES_TARGETS "${cryptopp_LIBRARIES_TARGETS};")
set(cryptopp_LIBRARIES "${cryptopp_LIBRARIES};")

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH})
set(CMAKE_PREFIX_PATH ${CMAKE_PREFIX_PATH})


########### COMPONENT cryptopp-static VARIABLES #############################################

set(cryptopp_cryptopp-static_INCLUDE_DIRS "C:/Users/Andriy/.conan/data/cryptopp/8.7.0/_/_/package/5a61a86bb3e07ce4262c80e1510f9c05e9b6d48b/include")
set(cryptopp_cryptopp-static_INCLUDE_DIR "C:/Users/Andriy/.conan/data/cryptopp/8.7.0/_/_/package/5a61a86bb3e07ce4262c80e1510f9c05e9b6d48b/include")
set(cryptopp_cryptopp-static_INCLUDES "C:/Users/Andriy/.conan/data/cryptopp/8.7.0/_/_/package/5a61a86bb3e07ce4262c80e1510f9c05e9b6d48b/include")
set(cryptopp_cryptopp-static_LIB_DIRS "C:/Users/Andriy/.conan/data/cryptopp/8.7.0/_/_/package/5a61a86bb3e07ce4262c80e1510f9c05e9b6d48b/lib")
set(cryptopp_cryptopp-static_RES_DIRS)
set(cryptopp_cryptopp-static_DEFINITIONS)
set(cryptopp_cryptopp-static_COMPILE_DEFINITIONS)
set(cryptopp_cryptopp-static_COMPILE_OPTIONS_C "")
set(cryptopp_cryptopp-static_COMPILE_OPTIONS_CXX "")
set(cryptopp_cryptopp-static_LIBS cryptopp)
set(cryptopp_cryptopp-static_SYSTEM_LIBS ws2_32)
set(cryptopp_cryptopp-static_FRAMEWORK_DIRS)
set(cryptopp_cryptopp-static_FRAMEWORKS)
set(cryptopp_cryptopp-static_BUILD_MODULES_PATHS "C:/Users/Andriy/.conan/data/cryptopp/8.7.0/_/_/package/5a61a86bb3e07ce4262c80e1510f9c05e9b6d48b/lib/cmake/conan-official-cryptopp-targets.cmake")
set(cryptopp_cryptopp-static_DEPENDENCIES)
set(cryptopp_cryptopp-static_LINKER_FLAGS_LIST
        "$<$<STREQUAL:$<TARGET_PROPERTY:TYPE>,SHARED_LIBRARY>:>"
        "$<$<STREQUAL:$<TARGET_PROPERTY:TYPE>,MODULE_LIBRARY>:>"
        "$<$<STREQUAL:$<TARGET_PROPERTY:TYPE>,EXECUTABLE>:>"
        )


########## FIND PACKAGE DEPENDENCY ##########################################################
#############################################################################################

include(CMakeFindDependencyMacro)


########## FIND LIBRARIES & FRAMEWORKS / DYNAMIC VARS #######################################
#############################################################################################

########## COMPONENT cryptopp-static FIND LIBRARIES & FRAMEWORKS / DYNAMIC VARS #############

set(cryptopp_cryptopp-static_FRAMEWORKS_FOUND "")
conan_find_apple_frameworks(cryptopp_cryptopp-static_FRAMEWORKS_FOUND "${cryptopp_cryptopp-static_FRAMEWORKS}" "${cryptopp_cryptopp-static_FRAMEWORK_DIRS}")

set(cryptopp_cryptopp-static_LIB_TARGETS "")
set(cryptopp_cryptopp-static_NOT_USED "")
set(cryptopp_cryptopp-static_LIBS_FRAMEWORKS_DEPS ${cryptopp_cryptopp-static_FRAMEWORKS_FOUND} ${cryptopp_cryptopp-static_SYSTEM_LIBS} ${cryptopp_cryptopp-static_DEPENDENCIES})
conan_package_library_targets("${cryptopp_cryptopp-static_LIBS}"
        "${cryptopp_cryptopp-static_LIB_DIRS}"
        "${cryptopp_cryptopp-static_LIBS_FRAMEWORKS_DEPS}"
        cryptopp_cryptopp-static_NOT_USED
        cryptopp_cryptopp-static_LIB_TARGETS
        ""
        "cryptopp_cryptopp-static")

set(cryptopp_cryptopp-static_LINK_LIBS ${cryptopp_cryptopp-static_LIB_TARGETS} ${cryptopp_cryptopp-static_LIBS_FRAMEWORKS_DEPS})

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH})
set(CMAKE_PREFIX_PATH ${CMAKE_PREFIX_PATH})


########## TARGETS ##########################################################################
#############################################################################################

########## COMPONENT cryptopp-static TARGET #################################################

if (NOT ${CMAKE_VERSION} VERSION_LESS "3.0")
    # Target approach
    if (NOT TARGET cryptopp::cryptopp-static)
        add_library(cryptopp::cryptopp-static INTERFACE IMPORTED)
        set_target_properties(cryptopp::cryptopp-static PROPERTIES INTERFACE_INCLUDE_DIRECTORIES
                "${cryptopp_cryptopp-static_INCLUDE_DIRS}")
        set_target_properties(cryptopp::cryptopp-static PROPERTIES INTERFACE_LINK_DIRECTORIES
                "${cryptopp_cryptopp-static_LIB_DIRS}")
        set_target_properties(cryptopp::cryptopp-static PROPERTIES INTERFACE_LINK_LIBRARIES
                "${cryptopp_cryptopp-static_LINK_LIBS};${cryptopp_cryptopp-static_LINKER_FLAGS_LIST}")
        set_target_properties(cryptopp::cryptopp-static PROPERTIES INTERFACE_COMPILE_DEFINITIONS
                "${cryptopp_cryptopp-static_COMPILE_DEFINITIONS}")
        set_target_properties(cryptopp::cryptopp-static PROPERTIES INTERFACE_COMPILE_OPTIONS
                "${cryptopp_cryptopp-static_COMPILE_OPTIONS_C};${cryptopp_cryptopp-static_COMPILE_OPTIONS_CXX}")
    endif ()
endif ()

########## GLOBAL TARGET ####################################################################

if (NOT ${CMAKE_VERSION} VERSION_LESS "3.0")
    if (NOT TARGET cryptopp::cryptopp)
        add_library(cryptopp::cryptopp INTERFACE IMPORTED)
    endif ()
    set_property(TARGET cryptopp::cryptopp APPEND PROPERTY
            INTERFACE_LINK_LIBRARIES "${cryptopp_COMPONENTS}")
endif ()

########## BUILD MODULES ####################################################################
#############################################################################################
########## COMPONENT cryptopp-static BUILD MODULES ##########################################

foreach (_BUILD_MODULE_PATH ${cryptopp_cryptopp-static_BUILD_MODULES_PATHS})
    include(${_BUILD_MODULE_PATH})
endforeach ()
