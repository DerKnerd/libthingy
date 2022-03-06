//
// Created by imanuel on 06.03.22.
//

#include "File.h"

using namespace thingy::entities;

File File::fromJson(const nlohmann::json &json) {
    auto file = File();
    file.id = json["id"];
    file.name = json["name"];
    file.sizeInBytes = json["size"];
    file.url = json["url"];
    file.publicUrl = json["public_url"];
    file.thumbnail = json["thumbnail"];
    file.defaultImage = Image::fromJson(json["default_image"]);
    file.date = json["date"];
    file.downloadCount = json["download_count"];
    file.directUrl = json["direct_url"];

    return file;
}
