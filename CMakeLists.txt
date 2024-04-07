cmake_minimum_required(VERSION 3.22)
project(Unpacker2)

# Include directories
include_directories(include)

# Find Boost package
set(Boost_USE_STATIC_LIBS OFF)
set(Boost_USE_MULTITHREADED ON)
set(Boost_USE_STATIC_RUNTIME OFF)
find_package(Boost 1.58 REQUIRED)

# Find ROOT package
find_package(ROOT CONFIG REQUIRED PATHS "/home/jakub/Opt/ROOT/root_v6.30.04.Linux-ubuntu22.04-x86_64-gcc11.4/root/cmake")
if(ROOT_FOUND)
    message(STATUS "ROOT (version ${ROOT_VERSION}) was found using ROOTConfig")
endif()

# Check ROOT version
if(ROOT_VERSION VERSION_LESS "6.10")
    message(FATAL_ERROR "Only ROOT >= 6.10 is currently supported")
endif(ROOT_VERSION VERSION_LESS "6.10")

# Include RootNewMacros.cmake if necessary
if(ROOT_VERSION VERSION_LESS "6.20")
    find_file(ROOT_NEWMACROS_PATH NAMES "RootNewMacros.cmake"
            PATHS "${ROOT_DIR}/modules" "${ROOT_DIR}/cmake/modules" "${ROOT_DIR}/../cmake/modules")
    if(ROOT_NEWMACROS_PATH)
        include("${ROOT_NEWMACROS_PATH}")
        message(STATUS "Found RootNewMacros.cmake in: ${ROOT_NEWMACROS_PATH}")
    else()
        message(FATAL_ERROR "ERROR! Could not find RootNewMacros.cmake file! Aborting..")
    endif()
endif()

# Generate ROOT dictionary
set(DICTIONARY_NAME G__Unpacker2)
set(HEADERS_WITH_DICTIONARY_REQUIRED
        ${CMAKE_CURRENT_SOURCE_DIR}/include/EventIII.h
        ${CMAKE_CURRENT_SOURCE_DIR}/include/TDCChannel.h
)
set(LINKDEF_NAME Unpacker2_LinkDef.h)

include_directories(ROOT_BUG) # Fix bug in NewMacros Root file
ROOT_GENERATE_DICTIONARY(${DICTIONARY_NAME} ${HEADERS_WITH_DICTIONARY_REQUIRED}
        OPTIONS -Iinclude
        LINKDEF ${LINKDEF_NAME})
## End of configuration of ROOT

# Set all sources
set(SOURCES src/Unpacker2.cc src/Unpacker2D.cc src/EventIII.cc src/TDCChannel.cc ${DICTIONARY_NAME}.cxx src/main.cpp)

# Create Unpacker2 library
add_library(Unpacker2 SHARED ${SOURCES})
# Set include directories
target_include_directories(Unpacker2
        PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>)
# Link Unpacker2 to Boost and ROOT libraries
target_link_libraries(Unpacker2 PUBLIC Boost::boost ROOT::Core ROOT::Hist ROOT::Tree)

# Set target properties
set_target_properties(Unpacker2 PROPERTIES LINKER_LANGUAGE CXX)
set_target_properties(Unpacker2 PROPERTIES POSITION_INDEPENDENT_CODE ON) #-fPIC for shared library
set_target_properties(Unpacker2 PROPERTIES VERSION ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}.${PROJECT_VERSION_PATCH})

# Packaging support
set(CPACK_GENERATOR "DEB")
set(CPACK_PACKAGE_VENDOR "JPetTomography")
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "Package contains Unpacker2 module")
set(CPACK_DEBIAN_PACKAGE_MAINTAINER "grey")
set(CPACK_PACKAGE_VERSION_MAJOR ${PROJECT_VERSION_MAJOR})
set(CPACK_PACKAGE_VERSION_MINOR ${PROJECT_VERSION_MINOR})
set(CPACK_PACKAGE_VERSION_PATCH ${PROJECT_VERSION_PATCH})
set(CPACK_RESOURCE_FILE_README "${CMAKE_CURRENT_SOURCE_DIR}/README.md")

set(CPACK_SOURCE_GENERATOR "TGZ;ZIP")
set(CPACK_SOURCE_IGNORE_FILES
        /.git
        /*.dist*
        /.*build.*
        /\\\\.DS_Store
)

include(CPack)

message(STATUS "")
message(STATUS "    == Final overview for ${PROJECT_NAME} ==")
message(STATUS "Version:              ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}.${PROJECT_VERSION_PATCH}")
message(STATUS "Install prefix:       ${CMAKE_INSTALL_PREFIX}")
message(STATUS "Compiler:             ${CMAKE_CXX_COMPILER}")
message(STATUS "CMAKE_BUILD_TYPE:     ${CMAKE_BUILD_TYPE}")
message(STATUS "  possible options: Debug Release RelWithDebInfo MinSizeRel")
message(STATUS "  set with ` cmake -DCMAKE_BUILD_TYPE=Debug .. `")
message(STATUS "")
