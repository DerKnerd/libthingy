//
// Created by imanuel on 05.03.22.
//

#include "../libthingy.h"

thingy::entities::ImageSize thingy::ThingiverseClient::imageSizeFromJson(const nlohmann::json &json) {
    auto imageSize = thingy::entities::ImageSize();
    imageSize.size = json["size"];
    imageSize.type = json["type"];
    imageSize.url = json["url"];

    return imageSize;
}

thingy::entities::Image thingy::ThingiverseClient::imageFromJson(const nlohmann::json &json) {
    auto image = thingy::entities::Image();
    if (json.contains("url") && json["url"].is_string()) {
        image.url = json["url"];
    }
    if (json.contains("name") && json["name"].is_string()) {
        image.name = json["name"];
    }
    if (json.contains("id") && json["id"].is_string()) {
        image.id = json["id"].get<unsigned long long>();
    }
    if (json.contains("sizes")) {
        for (const auto &size: json["sizes"].get<std::vector<nlohmann::json>>()) {
            image.sizes.emplace_back(imageSizeFromJson(size));
        }
    }

    return image;
}
