//
// Created by imanuel on 06.03.22.
//

#include "Category.h"

thingy::entities::Category thingy::entities::Category::fromThingJson(const nlohmann::json &json) {
    auto category = thingy::entities::Category();
    category.name = json["name"];
    category.count = json["count"];
    category.slug = json["slug"];

    return category;
}
