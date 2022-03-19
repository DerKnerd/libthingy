//
// Created by imanuel on 05.03.22.
//

#include "../../libthingy.h"

thingy::entities::ImageSize thingy::ThingiverseClient::imageSizeFromJson(const nlohmann::json &json) {
    auto imageSize = thingy::entities::ImageSize();
    imageSize.size = json["size"];
    imageSize.type = json["type"];
    imageSize.url = json["url"];

    return imageSize;
}

thingy::entities::Image thingy::ThingiverseClient::imageFromJson(const nlohmann::json &json) {
    auto image = thingy::entities::Image();
    image.url = json["url"];
    image.name = json["name"];
    image.id = json["id"];
    for (const auto& size: json["sizes"].get<std::vector<nlohmann::json>>()) {
        image.sizes.emplace_back(imageSizeFromJson(size));
    }

    return image;
}
