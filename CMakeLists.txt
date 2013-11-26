project(BoostLogExample)
cmake_minimum_required(VERSION 2.8)
message(STATUS "Build type: ${CMAKE_BUILD_TYPE}")

###############################
# set flags
###############################
# for Boost.Log
add_definitions("-DBOOST_LOG_DYN_LINK")

###############################
# set output path
###############################
set(LIBRARY_OUTPUT_PATH "${PROJECT_BINARY_DIR}/lib" CACHE PATH
    "Output directory for library" )
set(EXECUTABLE_OUTPUT_PATH "${PROJECT_BINARY_DIR}/bin" CACHE PATH
     "Output directory for executables" )


include_directories(".")

######################
# boost
######################
if(${CMAKE_SYSTEM_NAME} MATCHES "Linux")
  set(Boost_INCLUDE_DIR "/usr/local/boost/include")
  set(Boost_LIBRARY_DIR "/usr/local/boost/lib")
endif()

find_package(Boost COMPONENTS filesystem thread program_options system date_time log REQUIRED)
if (Boost_FOUND)
  message(STATUS "Found 'boost library'")
  include_directories(${Boost_INCLUDE_DIR})
  message(STATUS "  boost lib dir: ${Boost_LIBRARY_DIRS}")
  message(STATUS "  boost include dir: ${Boost_INCLUDE_DIR}")
  message(STATUS "  boost link:")
  foreach(var ${Boost_LIBRARIES})
    message(STATUS "    ${var}")
  endforeach(var)
else()
  message(FATAL_ERROR "Couldn't find Boost library.")
endif()

######################
# bins
######################
add_executable(main main.cpp logger.hpp)
target_link_libraries(main ${Boost_LIBRARIES})
