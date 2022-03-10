add_executable(libthingy_test_get_thing tests/testGetThing.cpp)
add_executable(libthingy_test_get_things tests/testGetThings.cpp)
add_executable(libthingy_test_get_thing_ancestors tests/testGetThingAncestors.cpp)
add_executable(libthingy_test_get_thing_derivatives tests/testGetThingDerivatives.cpp)
add_executable(libthingy_test_get_images_by_thing tests/testGetImagesByThing.cpp)
add_executable(libthingy_test_get_files_by_thing tests/testGetFilesByThing.cpp)
add_executable(libthingy_test_get_categories_by_thing tests/testGetCategoriesByThing.cpp)
add_executable(libthingy_test_get_things_by_category tests/testGetThingsByCategory.cpp)
add_executable(libthingy_test_get_things_by_user tests/testGetThingsByUser.cpp)
add_executable(libthingy_test_get_things_by_collection tests/testGetThingsByCollection.cpp)
add_executable(libthingy_test_get_featured_things tests/testGetFeaturedThings.cpp)

add_executable(libthingy_test_get_user tests/testGetUser.cpp)
add_executable(libthingy_test_get_users tests/testGetUsers.cpp)
add_executable(libthingy_test_get_likes_by_user tests/testGetLikesByUser.cpp)

add_executable(libthingy_test_get_collections_by_user tests/testGetCollectionsByUser.cpp)
add_executable(libthingy_test_get_collections tests/testGetCollections.cpp)
add_executable(libthingy_test_get_collection tests/testGetCollection.cpp)


add_test(NAME libthingy_test_get_thing COMMAND libthingy_test_get_thing)
add_test(NAME libthingy_test_get_things COMMAND libthingy_test_get_things)
add_test(NAME libthingy_test_get_thing_ancestors COMMAND libthingy_test_get_thing_ancestors)
add_test(NAME libthingy_test_get_thing_derivatives COMMAND libthingy_test_get_thing_derivatives)
add_test(NAME libthingy_test_get_images_by_thing COMMAND libthingy_test_get_images_by_thing)
add_test(NAME libthingy_test_get_files_by_thing COMMAND libthingy_test_get_files_by_thing)
add_test(NAME libthingy_test_get_categories_by_thing COMMAND libthingy_test_get_categories_by_thing)
add_test(NAME libthingy_test_get_things_by_category COMMAND libthingy_test_get_things_by_category)
add_test(NAME libthingy_test_get_things_by_user COMMAND libthingy_test_get_things_by_user)
add_test(NAME libthingy_test_get_things_by_collection COMMAND libthingy_test_get_things_by_collection)
add_test(NAME libthingy_test_get_featured_things COMMAND libthingy_test_get_featured_things)

add_test(NAME libthingy_test_get_user COMMAND libthingy_test_get_user)
add_test(NAME libthingy_test_get_users COMMAND libthingy_test_get_users)
add_test(NAME libthingy_test_get_likes_by_user COMMAND libthingy_test_get_likes_by_user)

add_test(NAME libthingy_test_get_collections_by_user COMMAND libthingy_test_get_collections_by_user)
add_test(NAME libthingy_test_get_collections COMMAND libthingy_test_get_collections)
add_test(NAME libthingy_test_get_collection COMMAND libthingy_test_get_collection)


target_link_libraries(libthingy_test_get_thing PUBLIC libthingy::libthingy OpenSSL::SSL httplib::httplib nlohmann_json::nlohmann_json)
target_link_libraries(libthingy_test_get_things PUBLIC libthingy::libthingy OpenSSL::SSL httplib::httplib nlohmann_json::nlohmann_json)
target_link_libraries(libthingy_test_get_thing_ancestors PUBLIC libthingy::libthingy OpenSSL::SSL httplib::httplib nlohmann_json::nlohmann_json)
target_link_libraries(libthingy_test_get_thing_derivatives PUBLIC libthingy::libthingy OpenSSL::SSL httplib::httplib nlohmann_json::nlohmann_json)
target_link_libraries(libthingy_test_get_images_by_thing PUBLIC libthingy::libthingy OpenSSL::SSL httplib::httplib nlohmann_json::nlohmann_json)
target_link_libraries(libthingy_test_get_files_by_thing PUBLIC libthingy::libthingy OpenSSL::SSL httplib::httplib nlohmann_json::nlohmann_json)
target_link_libraries(libthingy_test_get_categories_by_thing PUBLIC libthingy::libthingy OpenSSL::SSL httplib::httplib nlohmann_json::nlohmann_json)
target_link_libraries(libthingy_test_get_things_by_category PUBLIC libthingy::libthingy OpenSSL::SSL httplib::httplib nlohmann_json::nlohmann_json)
target_link_libraries(libthingy_test_get_things_by_user PUBLIC libthingy::libthingy OpenSSL::SSL httplib::httplib nlohmann_json::nlohmann_json)
target_link_libraries(libthingy_test_get_things_by_collection PUBLIC libthingy::libthingy OpenSSL::SSL httplib::httplib nlohmann_json::nlohmann_json)
target_link_libraries(libthingy_test_get_featured_things PUBLIC libthingy::libthingy OpenSSL::SSL httplib::httplib nlohmann_json::nlohmann_json)

target_link_libraries(libthingy_test_get_user PUBLIC libthingy::libthingy OpenSSL::SSL httplib::httplib nlohmann_json::nlohmann_json)
target_link_libraries(libthingy_test_get_users PUBLIC libthingy::libthingy OpenSSL::SSL httplib::httplib nlohmann_json::nlohmann_json)
target_link_libraries(libthingy_test_get_likes_by_user PUBLIC libthingy::libthingy OpenSSL::SSL httplib::httplib nlohmann_json::nlohmann_json)

target_link_libraries(libthingy_test_get_collections_by_user PUBLIC libthingy::libthingy OpenSSL::SSL httplib::httplib nlohmann_json::nlohmann_json)
target_link_libraries(libthingy_test_get_collections PUBLIC libthingy::libthingy OpenSSL::SSL httplib::httplib nlohmann_json::nlohmann_json)
target_link_libraries(libthingy_test_get_collection PUBLIC libthingy::libthingy OpenSSL::SSL httplib::httplib nlohmann_json::nlohmann_json)
