# For more information about using CMake with Android Studio, read the
# documentation: https://d.android.com/studio/projects/add-native-code.html

# Sets the minimum version of CMake required to build the native library.

cmake_minimum_required(VERSION 3.4.1)

#------------------------------------- path --------------------------------------------#
set(root_path ${CMAKE_SOURCE_DIR}/src/main/cpp)
#------------------------------------- path --------------------------------------------#

include_directories(
        "${root_path}"
)

add_library( # Sets the name of the library.
             mylog #.so库名 可自定义

             # Sets the library as a shared library.
             SHARED

             # Provides a relative path to your source file(s).
             ${root_path}/log.cpp)

# Searches for a specified prebuilt library and stores the path as a
# variable. Because CMake includes system libraries in the search path by
# default, you only need to specify the name of the public NDK library
# you want to add. CMake verifies that the library exists before
# completing its build.

find_library( # Sets the name of the path variable.
              log-lib

              # Specifies the name of the NDK library that
              # you want CMake to locate.
              log )
add_library( glog
             STATIC
             IMPORTED )
add_library( gflags
             STATIC
             IMPORTED )
set_target_properties(glog
                       PROPERTIES IMPORTED_LOCATION
                      ${root_path}/libglog.a)
set_target_properties(gflags
                       PROPERTIES IMPORTED_LOCATION
                      ${root_path}/libgflags.a)

# Specifies libraries CMake should link to your target library. You
# can link multiple libraries, such as libraries you define in this
# build script, prebuilt third-party libraries, or system libraries.

target_link_libraries( # Specifies the target library.
                       mylog #.so库名 可自定义
						
						glog
						gflags
                       # Links the target library to the log library
                       # included in the NDK.
                       ${log-lib} )