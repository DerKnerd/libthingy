cmake_minimum_required(VERSION 3.21)
project(libthingy CXX)

set(CMAKE_CXX_STANDARD 23)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_BINARY_DIR})
list(APPEND CMAKE_PREFIX_PATH ${CMAKE_BINARY_DIR})

include(./conan.cmake)
include(CTest)

conan_cmake_configure(
        REQUIRES
        nlohmann_json/3.10.5
        cpp-httplib/0.10.3
        openssl/3.0.1
        GENERATORS cmake_find_package
)

conan_cmake_autodetect(settings)

conan_cmake_install(PATH_OR_REFERENCE .
        BUILD missing
        REMOTE conancenter
        SETTINGS ${settings}
        SETTINGS ${CONAN_SETTINGS}
        OPTIONS ${options})

find_package(nlohmann_json)
find_package(httplib)
find_package(OpenSSL)

file(GLOB SOURCES thingiverseClient.h thingiverseClient.cpp impl/*.cpp entities/*.cpp)

add_library(libthingy ${SOURCES})
add_library(libthingy::libthingy ALIAS libthingy)

add_executable(libthingy_test_get_thing ${SOURCES} tests/testGetThing.cpp)

add_test(NAME libthingy_test_get_thing COMMAND libthingy_test_get_thing)

target_link_libraries(libthingy PUBLIC OpenSSL::SSL httplib::httplib nlohmann_json::nlohmann_json)
target_link_libraries(libthingy_test_get_thing PUBLIC OpenSSL::SSL httplib::httplib nlohmann_json::nlohmann_json)
