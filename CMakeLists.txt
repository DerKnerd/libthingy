cmake_minimum_required(VERSION 3.16)
project(libthingy CXX)

set(CMAKE_CXX_STANDARD 20)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_BINARY_DIR})
list(APPEND CMAKE_PREFIX_PATH ${CMAKE_BINARY_DIR})

include(./conan.cmake)
include(CTest)

if (WIN32 OR MINGW)
    set(options Poco:enable_netssl_win=True Poco:enable_netssl=False)
else ()
    set(options Poco:enable_netssl_win=False Poco:enable_netssl=True)
endif ()

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

file(GLOB SOURCES src/impl/*.cpp src/entities/*.cpp)

add_library(libthingy ${SOURCES})
add_library(libthingy::libthingy ALIAS libthingy)
include(tests.cmake)

target_link_libraries(libthingy PUBLIC OpenSSL::SSL OpenSSL::Crypto httplib::httplib nlohmann_json::nlohmann_json)

