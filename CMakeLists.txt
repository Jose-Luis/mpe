project(Particles)

cmake_minimum_required (VERSION 2.8)

# Project headers
# ===============
include_directories(${PROJECT_SOURCE_DIR}/include)

# External Libraries management
# =============================
set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake/Modules)
set(EXT_LIBS ${PROJECT_SOURCE_DIR}/ext_libs)

if (${UNIX})
   set(EXT_LIBS_DIR ${EXT_LIBS}/libraries/linux32)
else()
   if(${WIN32})
      set(EXT_LIBS_DIR ${EXT_LIBS}/libraries/win32)
   endif()
endif()
   
   #GT
   #==
   find_package(GT REQUIRED)
   include_directories(${GT_INCLUDE_DIR})
   #SFML
   #====
   find_package(SFML REQUIRED audio graphics window system)
   include_directories(${SFML_INCLUDE_DIR})

# Compilation options
# ===================
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

if(MSVC)
   set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W4")
elseif(CMAKE_COMPILER_IS_GNUCC OR CMAKE_COMPILER_IS_GNUCXX)
   set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall  -pedantic")
endif()

set(CMAKE_DEBUG_POSTFIX "_debug") 
set(CMAKE_CXX_FLAGS_OPTIMIZED "-O3")

# Code to compile
# ===============
add_subdirectory(src)

# Summary
# =======

message( "" )
message( "Summary:" )
message( "  CMAKE_SYSTEM_NAME = ${CMAKE_SYSTEM_NAME}" )
message( "  WIN32 = ${WIN32}" )
message( "  UNIX = ${UNIX}" )
message( "  APPLE = ${APPLE}" )
message( "  CMAKE_BUILD_TYPE = ${CMAKE_BUILD_TYPE}" )
message( "  CMAKE_INSTALL_PREFIX = ${CMAKE_INSTALL_PREFIX}" )
message( "  CMAKE_MODULE_PATH = ${CMAKE_MODULE_PATH}" )
message( "  CMAKE_GENERATOR = ${CMAKE_GENERATOR}" )
message( "  SFML_LIBRARIES = ${SFML_LIBRARIES}" )
message( "  GT_LIBRARY = ${GT_LIBRARY}" )
message( "" )
