file(GLOB SOURCES thingiverseClient.h thingiverseClient.cpp impl/*.cpp entities/*.cpp)

add_executable(libthingy_test_get_thing ${SOURCES} tests/testGetThing.cpp)
add_executable(libthingy_test_get_things ${SOURCES} tests/testGetThings.cpp)
add_executable(libthingy_test_get_thing_ancestors ${SOURCES} tests/testGetThingAncestors.cpp)
add_executable(libthingy_test_get_thing_derivatives ${SOURCES} tests/testGetThingDerivatives.cpp)
add_executable(libthingy_test_get_images_by_thing ${SOURCES} tests/testGetImagesByThing.cpp)

add_test(NAME libthingy_test_get_thing COMMAND libthingy_test_get_thing)
add_test(NAME libthingy_test_get_things COMMAND libthingy_test_get_things)
add_test(NAME libthingy_test_get_thing_ancestors COMMAND libthingy_test_get_thing_ancestors)
add_test(NAME libthingy_test_get_thing_derivatives COMMAND libthingy_test_get_thing_derivatives)
add_test(NAME libthingy_test_get_images_by_thing COMMAND libthingy_test_get_images_by_thing)

target_link_libraries(libthingy_test_get_thing PUBLIC OpenSSL::SSL httplib::httplib nlohmann_json::nlohmann_json)
target_link_libraries(libthingy_test_get_things PUBLIC OpenSSL::SSL httplib::httplib nlohmann_json::nlohmann_json)
target_link_libraries(libthingy_test_get_thing_ancestors PUBLIC OpenSSL::SSL httplib::httplib nlohmann_json::nlohmann_json)
target_link_libraries(libthingy_test_get_thing_derivatives PUBLIC OpenSSL::SSL httplib::httplib nlohmann_json::nlohmann_json)
target_link_libraries(libthingy_test_get_images_by_thing PUBLIC OpenSSL::SSL httplib::httplib nlohmann_json::nlohmann_json)