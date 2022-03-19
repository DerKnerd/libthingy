//
// Created by imanuel on 06.03.22.
//

#include "../../libthingy.h"

thingy::entities::File thingy::ThingiverseClient::fileFromJson(const nlohmann::json &json) {
    auto file = thingy::entities::File();
    file.id = json["id"];
    file.name = json["name"];
    file.sizeInBytes = json["size"];
    file.url = json["url"];
    file.publicUrl = json["public_url"];
    file.thumbnail = json["thumbnail"];
    file.defaultImage = imageFromJson(json["default_image"]);
    file.date = json["date"];
    file.downloadCount = json["download_count"];
    file.directUrl = json["direct_url"];

    return file;
}
