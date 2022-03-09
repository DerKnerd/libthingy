//
// Created by imanuel on 08.03.22.
//

#include "../libthingy.h"

thingy::entities::Collection thingy::ThingiverseClient::collectionFromSearchJson(const nlohmann::json &json) {
    auto collection = thingy::entities::Collection();
    collection.id = json["id"];
    collection.name = json["name"];
    collection.description = json["description"];
    collection.added = json["added"];
    collection.modified = json["modified"];
    collection.creator = userFromCreatorJson(json["creator"]);
    collection.count = json["count"];
    collection.previewImage = json["preview_image"];
    collection.absoluteUrl = json["absolute_url"];
    collection.thumbnail = json["thumbnail"];

    return collection;
}

thingy::entities::Collection thingy::ThingiverseClient::collectionFromJson(const nlohmann::json &json) {
    auto collection = collectionFromSearchJson(json);
    collection.thumbnail1 = json["thumbnail_1"];
    collection.thumbnail2 = json["thumbnail_2"];
    collection.thumbnail3 = json["thumbnail_3"];

    return collection;
}