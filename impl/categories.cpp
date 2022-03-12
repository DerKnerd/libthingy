//
// Created by imanuel on 10.03.22.
//

#include "../libthingy.h"

std::vector<thingy::entities::Category>
thingy::ThingiverseClient::getCategories(unsigned int page, unsigned int categoriesPerPage) {
    auto result = sendRequest("categories", {
            {"page",     std::to_string(page)},
            {"per_page", std::to_string(categoriesPerPage)}
    });

    auto categories = std::vector<thingy::entities::Category>();
    for (const auto &item: result.get<std::vector<nlohmann::json>>()) {
        categories.emplace_back(categoryFromThingJson(item));
    }

    return categories;
}

thingy::entities::Category thingy::ThingiverseClient::getCategory(const std::string &slug) {
    auto result = sendRequest("categories/" + slug);
    auto category = categoryFromJson(result);
    category.slug = slug;

    return category;
}