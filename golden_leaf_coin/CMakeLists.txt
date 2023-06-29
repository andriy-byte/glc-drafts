cmake_minimum_required(VERSION 3.25)
project(golden_leaf_coin CXX)

set(CMAKE_CXX_STANDARD 23)
set(CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if (WIN32)
    option(STATIC_BUILD "Build Application with static libraries" OFF)
endif (WIN32)


set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(EXTERNAL_LIBS_ROOT "${PROJECT_SOURCE_DIR}/externallibs")

add_subdirectory("${EXTERNAL_LIBS_ROOT}/string_interpolation")
include_directories("${EXTERNAL_LIBS_ROOT}/string_interpolation/include")
if (WIN32)
    set(VCPKG_TARGET_ARCHITECTURE "x64")
    set(VCPKG_TARGET_TRIPLET "x64-windows")

endif (WIN32)

#if (UNIX)
#     add_compile_definitions(_GLIBCXX_USE_CXX11_ABI=0)
#     add_definitions(-D_GLIBCXX_USE_CXX11_ABI=1)
#endif (UNIX)


add_executable(${PROJECT_NAME}
        main.cpp
        externallibs/defer-cpp/include/defer.hpp
        src/GLCVariables.cpp
        src/GLCVariables.h
        src/front/application/GLCApplicable.h
        src/front/application/GLCApplication.h
        src/front/application/GLCApplicationConfiguration.cpp
        src/front/application/GLCApplicationConfiguration.h
        src/front/application/authentication/cli/GLCCLIAuthentification.cpp
        src/front/application/authentication/cli/GLCCLIAuthentification.h
        src/front/application/cli/GLCCLIApplication.cpp
        src/front/application/cli/GLCCLIApplication.h
        src/front/application/cli/GLCCLICommands.cpp
        src/front/application/cli/GLCCLICommands.h
        src/front/application/cli/GLCCLIDecoration.cpp
        src/front/application/cli/GLCCLIDecoration.h
        src/front/application/cli/GLCCLIInpput.cpp
        src/front/application/cli/GLCCLIInput.h
        src/front/application/cli/GLCCLIVariables.cpp
        src/front/application/cli/GLCCLIVariables.h
        src/front/application/gui/GLCGUIApplication.cpp
        src/front/application/gui/GLCGUIApplication.h
        src/front/application/mainarguments/GLCApplicationMainArgumentsParser.cpp
        src/front/application/mainarguments/GLCApplicationMainArgumentsParser.h
        src/front/application/mainarguments/GLCApplicationProgramArguments.cpp
        src/front/application/mainarguments/GLCApplicationProgramArguments.h
        src/glcstl/GLCBadInitializationException.cpp
        src/glcstl/GLCBadInitializationException.h
        src/glcstl/GLCDateTime.cpp
        src/glcstl/GLCDateTime.h
        src/glcstl/GLCDateTimeFormat.cpp
        src/glcstl/GLCDateTimeFormat.h
        src/glcstl/GLCDateTimeFormatTypes.cpp
        src/glcstl/GLCDateTimeFormatTypes.h
        src/glcstl/GLCException.cpp
        src/glcstl/GLCException.h
        src/glcstl/GLCFormatException.cpp
        src/glcstl/GLCFormatException.h
        src/glcstl/GLCInternalException.cpp
        src/glcstl/GLCInternalException.h
        src/mine/configurator/GLCUserAction.cpp
        src/mine/configurator/GLCUserAction.h
        src/mine/csd/GLCCSD.cpp
        src/mine/csd/GLCCSD.h
        src/network/peer_to_peer/GLCNetworkPeerToPeerConfigurator.cpp
        src/network/peer_to_peer/GLCNetworkPeerToPeerConfigurator.h
        src/network/peer_to_peer/GLCNetworkPeerToPeerConstants.cpp
        src/network/peer_to_peer/GLCNetworkPeerToPeerConstants.h
        src/front/application/authentication/GLCAuthentificationSecurity.cpp
        src/front/application/authentication/GLCAuthentificationSecurity.h
        src/project/helper/GLCGenerativeMacros.h
        src/program/repair/GCLRepairable.h)


if (WIN32)
    set_target_properties(${PROJECT_NAME}
            PROPERTIES
            ARCHIVE_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/lib/windows"
            LIBRARY_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/lib/windows"
            RUNTIME_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/bin/windows"
            )
    # install(TARGETS ${PROJECT_NAME} CONFIGURATIONS Debug RUNTIME DESTINATION bin/windows)

endif (WIN32)


if (UNIX)
    set_target_properties(${PROJECT_NAME}
            PROPERTIES
            ARCHIVE_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/lib/linux"
            LIBRARY_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/lib/linux"
            RUNTIME_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/bin/linux"
            )
endif (UNIX)


if (WIN32)
    #include("${PROJECT_SOURCE_DIR}/conan/windows/conan_paths.cmake")

    # external libs start
    include_directories("${EXTERNAL_LIBS_ROOT}/string_interpolation/lib/Debug")
    # external libs end

    set(CMAKE_TOOLCHAIN_FILE c:/vcpkg/scripts/buildsystems/vcpkg.cmake)
    include(C:/vcpkg/scripts/buildsystems/vcpkg.cmake)

    file(GLOB_RECURSE LIBRARIES ${CMAKE_TOOLCHAIN_FILE})

    if (STATIC_BUILD)
        include_directories(C:/vcpkg/installed/x64-windows-static/include/)
        link_directories(C:/vcpkg/installed/x64-windows-static/lib/)
    else ()
        include_directories(C:/vcpkg/installed/x64-windows/include/)
        link_directories(C:/vcpkg/installed/x64-windows/lib/)
    endif (STATIC_BUILD)
endif (WIN32)


if (UNIX)
    # external libs start
    include_directories("${EXTERNAL_LIBS_ROOT}/string_interpolation/lib")
    # external libs end
    #include("${PROJECT_SOURCE_DIR}/conan/linux/files/conan_paths.cmake")
    set(CMAKE_TOOLCHAIN_FILE "/opt/vcpkg/scripts/buildsystems/vcpkg.cmake")
    include(/opt/vcpkg/scripts/buildsystems/vcpkg.cmake)
    include_directories(/opt/vcpkg/installed/x64-linux/include/)
    link_directories(/opt/vcpkg/installed/x64-linux/lib/)

    # set(CMAKE_CXX_FLAGS "-lboost_program_options")

endif (UNIX)



find_package(fmt REQUIRED)
target_link_libraries(${PROJECT_NAME} PUBLIC fmt::fmt)


# set(Boost_USE_STATIC_LIBS ON)
# set(Boost_USE_MULTITHREADED ON)
# set(Boost_USE_STATIC_RUNTIME ON)

set(Boost_NO_WARN_NEW_VERSIONS 1)


find_package(Boost COMPONENTS program_options REQUIRED)
include_directories(${Boost_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} PUBLIC ${Boost_LIBRARIES})


find_package(cryptopp REQUIRED)
target_link_libraries(${PROJECT_NAME} PUBLIC cryptopp::cryptopp)

find_package(spdlog REQUIRED)
target_link_libraries(${PROJECT_NAME} PUBLIC spdlog::spdlog)

find_package(range-v3 REQUIRED)
target_link_libraries(${PROJECT_NAME} PUBLIC range-v3::range-v3)



set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)



# set (PROJECT_FILES)
# list (APPEND PROJECT_FILES src/glcstl/*.h src/glcstl/*.cpp)
# list (APPEND PROJECT_FILES src/*.h src/*.cpp)
# list (APPEND PROJECT_FILES src/mine/*.h src/mine/*.cpp)
# list (APPEND PROJECT_FILES src/mine/configurator/*.h src/mine/configurator/*.cpp)
# list (APPEND PROJECT_FILES src/network/peer_to_peer/*.h src/network/peer_to_peer/*.cpp)
# list (APPEND PROJECT_FILES application/*.h application/*.cpp)
# list (APPEND PROJECT_FILES application/cli/*.h application/cli/*.cpp)
# list (APPEND PROJECT_FILES application/gui/*.h application/gui/*.cpp)
# list (APPEND PROJECT_FILES application/mainarguments/*.h application/mainarguments/*.cpp)
