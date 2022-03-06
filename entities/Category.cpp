//
// Created by imanuel on 06.03.22.
//

#include "../libthingy.h"

thingy::entities::Category thingy::ThingiverseClient::categoryFromThingJson(const nlohmann::json &json) {
    auto category = thingy::entities::Category();
    category.name = json["name"];
    category.count = json["count"];
    category.slug = json["slug"];
    category.id = json["id"];

    return category;
}
