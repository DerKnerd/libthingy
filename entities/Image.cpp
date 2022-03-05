//
// Created by imanuel on 05.03.22.
//

#include "Image.h"

thingy::entities::ImageSize thingy::entities::ImageSize::fromJson(const nlohmann::json &json) {
    auto imageSize = ImageSize();
    imageSize.size = json["size"];
    imageSize.type = json["type"];
    imageSize.url = json["url"];

    return imageSize;
}

thingy::entities::Image thingy::entities::Image::fromJson(const nlohmann::json &json) {
    auto image = Image();
    image.url = json["url"];
    image.name = json["name"];
    image.id = json["id"];
    for (const auto& size: json["sizes"].get<std::vector<nlohmann::json>>()) {
        image.sizes.emplace_back(ImageSize::fromJson(size));
    }

    return image;
}
