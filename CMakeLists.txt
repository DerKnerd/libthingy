cmake_minimum_required(VERSION 3.16)
project(libthingy CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_BINARY_DIR})
list(APPEND CMAKE_PREFIX_PATH ${CMAKE_BINARY_DIR})

if (NOT LIBTHINGY_SKIP_TESTS AND NOT CONAN_EXPORTED)
    include(CTest)
endif ()

if (WIN32 OR MINGW)
    set(options Poco:enable_netssl_win=True Poco:enable_netssl=False)
else ()
    set(options Poco:enable_netssl_win=False Poco:enable_netssl=True)
endif ()
include(conan.cmake)

conan_add_remote(NAME conan.imanuel.dev
        URL https://conan.imanuel.dev/artifactory/api/conan/conan-virtual)

if (CONAN_EXPORTED) # in conan local cache
    # standard conan installation, deps will be defined in conanfile.py
    # and not necessary to call conan again, conan is already running
    include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
    conan_basic_setup()
else ()
    # Make sure to use conanfile.py to define dependencies, to stay consistent
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
            REMOTE conan.imanuel.dev
            SETTINGS ${settings})
endif ()

find_package(nlohmann_json)
find_package(httplib)
find_package(OpenSSL)

file(GLOB SOURCES impl/*.cpp entities/*.cpp)

add_library(libthingy ${SOURCES})
add_library(libthingy::libthingy ALIAS libthingy)
if (NOT LIBTHINGY_SKIP_TESTS AND NOT CONAN_EXPORTED)
    include(tests.cmake)
endif ()

target_link_libraries(libthingy PRIVATE OpenSSL::SSL OpenSSL::Crypto httplib::httplib nlohmann_json::nlohmann_json)

