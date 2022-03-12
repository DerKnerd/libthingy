//
// Created by imanuel on 06.03.22.
//

#include "../libthingy.h"

thingy::entities::Category thingy::ThingiverseClient::categoryFromThingJson(const nlohmann::json &json) {
    auto category = thingy::entities::Category();
    category.name = json["name"];
    category.count = json["count"];
    category.slug = json["slug"];
    category.id = json["id"].is_string() ? std::stol(json["id"].get<std::string>()) : json["id"].get<long>();

    return category;
}

thingy::entities::Category thingy::ThingiverseClient::categoryFromJson(const nlohmann::json &json) {
    auto category = thingy::entities::Category();
    category.name = json["name"];
    category.count = json["count"];
    category.thumbnail = json["thumbnail"];
    category.previewImage = json["preview_image"];
    for (const auto &item: json["children"].get<std::vector<nlohmann::json>>()) {
        category.children.emplace_back(categoryFromThingJson(item));
    }

    return category;
}