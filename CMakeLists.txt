cmake_minimum_required(VERSION 3.12)
project(lamportc)


set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/bin")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")
set(CMAKE_CXX_STANDARD 17)


#
# Platform build options
# (supported platforms are: LINUX | MAC_OS)
#
set(PLATFORM "LINUX")

IF (${PLATFORM} MATCHES "MAC_OS")
    add_definitions(-DMAC_OS)
ENDIF (${PLATFORM} MATCHES "MAC_OS")

IF (${PLATFORM} MATCHES "LINUX")
    add_definitions(-DLINUX)
ENDIF (${PLATFORM} MATCHES "LINUX")


#
# Debug options
# (available options are: DEBUG | RELEASE | TESTS)
#
set(BUILD_CONFIGURATION "RELEASE")

# todo: move debug configuration into separated cmake file
IF (${BUILD_CONFIGURATION} MATCHES "DEBUG")
    set(CMAKE_BUILD_TYPE "Debug")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -fsanitize=address")

    add_definitions(
      -DDEBUG
    )
ENDIF (${BUILD_CONFIGURATION} MATCHES "DEBUG")

# todo: move release configuration into separated cmake file
IF (${BUILD_CONFIGURATION} MATCHES "RELEASE")
    set(CMAKE_BUILD_TYPE "Release")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O2 -Os -s -fdata-sections -fmerge-all-constants")
ENDIF (${BUILD_CONFIGURATION} MATCHES "RELEASE")

#
# Libs
#
add_subdirectory(lib-crypto-lamport/)


set(SOURCE_FILES
  main.cpp
  core/generator.hpp
  core/signer.hpp
  core/validator.hpp
  core/modes.hpp
  core/errors.hpp
  core/validations.hpp
  core/utils.hpp
  )


add_executable(lamportc ${SOURCE_FILES})
target_link_libraries(lamportc
  ${Boost_SYSTEM_LIBRARY}
  lamport

  -lsodium
  )
