cmake_minimum_required(VERSION  2.8.11)


############################
#
#  make sure RPATH is relative (as it should be, damnit)
#
#############################

set (CMAKE_BUILD_WITH_INSTALL_RPATH  TRUE)
set (CMAKE_INSTALL_RPATH "$ORIGIN/../lib:$ORIGIN/")


###########################
#
#  set preprocessor defines
#
###########################

if (UNIX)
  add_definitions(-DUNIX)
endif ()

if (WIN32)
  add_definitions(-DBOOST_ALL_NO_LIB)  # disable Boost autolinking
  add_definitions(-DBOOST_ALL_DYN_LINK)  # enable link to Boost DLLs
endif ()


#############################
# import Third-party dependencies (using cmake "Find" modules)
# NOTE: several of the "official" Find modules are either (1) missing, or (2) don't work very well
#       hence most of these are home-brewed
#############################
set(CMAKE_MODULE_PATH  "${CMAKE_SOURCE_DIR}/cmake/Modules/"  ${CMAKE_MODULE_PATH})


# find c-blosc (set hint CBLOSC_ROOT)
find_package(CBLOSC  REQUIRED)
include_directories(${CBLOSC_INCLUDE_DIR})
message (STATUS  "CBLOSC DLLS: ${CBLOSC_DLLS}")
message (STATUS  "CBLOSC SHARED LIB: ${CBLOSC_LIBRARIES}")
set (DLLS_to_install  ${DLLS_to_install}  ${CBLOSC_DLLS})


#####################
#
#  ags_blosc_wrapper_static target
#  A STATIC LIBRARY target
#
#####################

# add includes for current target
set (WORKING_SOURCE_DIR ${CMAKE_SOURCE_DIR}/ags_blosc_wrapper)
include_directories(${WORKING_SOURCE_DIR}/inc)

# add .cpp, .c files, .hpp, .h files
file (GLOB_RECURSE  WORKING_HPP_SOURCES  ${WORKING_SOURCE_DIR}/inc/*.hpp)
file (GLOB_RECURSE  WORKING_H_SOURCES  ${WORKING_SOURCE_DIR}/inc/*.h)
file (GLOB_RECURSE  WORKING_CPP_SOURCES  ${WORKING_SOURCE_DIR}/src/*.cpp)
file (GLOB_RECURSE  WORKING_C_SOURCES  ${WORKING_SOURCE_DIR}/src/*.c)
set (WORKING_SOURCES  ${WORKING_HPP_SOURCES}  ${WORKING_H_SOURCES}  ${WORKING_CPP_SOURCES}  ${WORKING_C_SOURCES})
set_source_files_properties(${WORKING_C_SOURCES} PROPERTIES LANGUAGE CXX)

# create the target (note: *_LIBRARIES and *_LIBRARY variables come from import process above)
add_library (ags_blosc_wrapper_static  ${WORKING_SOURCES})  # it is also possible to specify the option SHARED here
target_link_libraries (ags_blosc_wrapper_static  ${CBLOSC_STATIC_LIBRARIES})
set_target_properties (ags_blosc_wrapper_static  PROPERTIES  LINKER_LANGUAGE  CXX)

# install the library
install (TARGETS ags_blosc_wrapper_static
         DESTINATION lib)

# install the headers
# note the trailing slash on /inc/ ... this is necessary!
install (DIRECTORY  ${WORKING_SOURCE_DIR}/inc/  
         DESTINATION  include
         FILES_MATCHING 
         PATTERN  "*.hpp"
         PATTERN  "*.h"
         PATTERN  ".svn"  EXCLUDE
         PATTERN  ".git"  EXCLUDE)


#####################
#
#  ags_blosc_wrapper target
#  A SHARED LIBRARY target
#
#####################

# add includes for current target
set (WORKING_SOURCE_DIR ${CMAKE_SOURCE_DIR}/ags_blosc_wrapper)
include_directories(${WORKING_SOURCE_DIR}/inc)

# add .cpp, .c files, .hpp, .h files
file (GLOB_RECURSE  WORKING_HPP_SOURCES  ${WORKING_SOURCE_DIR}/inc/*.hpp)
file (GLOB_RECURSE  WORKING_H_SOURCES  ${WORKING_SOURCE_DIR}/inc/*.h)
file (GLOB_RECURSE  WORKING_CPP_SOURCES  ${WORKING_SOURCE_DIR}/src/*.cpp)
file (GLOB_RECURSE  WORKING_C_SOURCES  ${WORKING_SOURCE_DIR}/src/*.c)
set (WORKING_SOURCES  ${WORKING_HPP_SOURCES}  ${WORKING_H_SOURCES}  ${WORKING_CPP_SOURCES}  ${WORKING_C_SOURCES})
set_source_files_properties(${WORKING_C_SOURCES} PROPERTIES LANGUAGE CXX)

# create the target (note: *_LIBRARIES and *_LIBRARY variables come from import process above)
add_library (ags_blosc_wrapper  SHARED  ${WORKING_SOURCES})  # it is also possible to specify the option SHARED here
target_link_libraries (ags_blosc_wrapper  ${CBLOSC_LIBRARIES})
set_target_properties (ags_blosc_wrapper  PROPERTIES  LINKER_LANGUAGE  CXX)

# install the library
install (TARGETS ags_blosc_wrapper
         DESTINATION lib
         PERMISSIONS  OWNER_EXECUTE  OWNER_READ  OWNER_WRITE)

# headers already installed
