#===============================================================================
#                         MINI PARTICLE ENGINE 
#===============================================================================

project(MPE)
cmake_minimum_required (VERSION 2.8)
set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake/Modules)

if(CMAKE_SIZEOF_VOID_P EQUAL 8)
   set(BITS 64) 
else()
   set(BITS 32) 
endif()

#===============================================================================
#                     Compilation options             
#===============================================================================
set(EXT_LIBS ${PROJECT_SOURCE_DIR}/ext_libs)

if(MSVC)
   set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W3")
   set(EXT_LIBS_DIR ${EXT_LIBS}/libraries/win${BITS})
elseif(CMAKE_COMPILER_IS_GNUCC OR CMAKE_COMPILER_IS_GNUCXX)
   set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall  -pedantic")
   set(EXT_LIBS_DIR ${EXT_LIBS}/libraries/linux${BITS})
endif()

set(CMAKE_DEBUG_POSTFIX "_debug") 
set(CMAKE_CXX_FLAGS_OPTIMIZED "-O3")
set(CMAKE_CXX_FLAGS_PROFILING "-O3 -pg")

#===============================================================================
#                             Dependencies 
#===============================================================================

# TinyXML2

find_package(TinyXML2 REQUIRED)
include_directories(${TINYXML2_INCLUDE_DIR})

#===============================================================================
#                             Code 
#===============================================================================

include_directories(${PROJECT_SOURCE_DIR}/include)

#     Directories

set(HEADERS_DIR ${PROJECT_SOURCE_DIR}/include/MPE)
set(SOURCES_DIR ${PROJECT_SOURCE_DIR}/src/MPE)

#     Files

set(HEADERS_FILES 
   ${HEADERS_DIR}/MPE.hpp
   ${HEADERS_DIR}/Config.hpp
   ${HEADERS_DIR}/classes/Affector.hpp
   ${HEADERS_DIR}/classes/Emitter.hpp
   ${HEADERS_DIR}/classes/Focus.hpp
   ${HEADERS_DIR}/classes/Particle.hpp
   ${HEADERS_DIR}/classes/System.hpp
   ${HEADERS_DIR}/classes/Vec2.hpp
   ${HEADERS_DIR}/classes/Generator.hpp
   ${HEADERS_DIR}/classes/Mortal.hpp)

set(SOURCES_FILES 
   ${SOURCES_DIR}/classes/Affector.cpp
   ${SOURCES_DIR}/classes/Emitter.cpp
   ${SOURCES_DIR}/classes/Focus.cpp
   ${SOURCES_DIR}/classes/Particle.cpp
   ${SOURCES_DIR}/classes/System.cpp
   ${SOURCES_DIR}/classes/Generator.cpp
   ${SOURCES_DIR}/classes/Mortal.cpp)

#     Library

add_library(particles ${HEADERS_FILES} ${SOURCES_FILES})
target_link_libraries(particles ${TINYXML2_LIBRARIES})

#===============================================================================
#                            Tests
#===============================================================================
#set(BUILD_TESTS false)

if(${BUILD_TESTS})
   add_executable(tests ${PROJECT_SOURCE_DIR}/tests/tests.cpp )
   target_link_libraries(tests particles)
endif()

#===============================================================================
#                            Summary
#===============================================================================

message( "" )
message( "Summary:" )
message( "  CMAKE_SYSTEM_NAME = ${CMAKE_SYSTEM_NAME}" )
message( "  WIN32 = ${WIN32}" )
message( "  UNIX = ${UNIX}" )
message( "  APPLE = ${APPLE}" )
message( "  BITS = ${BITS}" )
message( "  EXT_LIBS = ${EXT_LIBS_DIR}" )
message( "  CMAKE_BUILD_TYPE = ${CMAKE_BUILD_TYPE}" )
message( "  CMAKE_INSTALL_PREFIX = ${CMAKE_INSTALL_PREFIX}" )
message( "  CMAKE_MODULE_PATH = ${CMAKE_MODULE_PATH}" )
message( "  CMAKE_GENERATOR = ${CMAKE_GENERATOR}" )
message( "  TINYXML2_LIBRARY = ${TINYXML2_LIBRARIES}" )
message( "  BUILD_TESTS = ${BUILD_TESTS}" )
message( "" )

#================================================================================
