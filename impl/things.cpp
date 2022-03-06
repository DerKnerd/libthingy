//
// Created by imanuel on 05.03.22.
//

#include "../thingiverseClient.h"

using namespace thingy;
using namespace entities;

Thing ThingiverseClient::getThing(unsigned long long thingId) {
    auto json = sendRequest("things/" + std::to_string(thingId));
    return Thing::fromJson(json);
}

std::vector<Thing> ThingiverseClient::getThingAncestors(unsigned long long int thingId) {
    auto json = sendRequest("things/" + std::to_string(thingId) + "/ancestors");

    auto result = std::vector<Thing>();
    for (const auto &item: json.get<std::vector<nlohmann::json>>()) {
        result.emplace_back(Thing::fromSearchJson(item));
    }

    return result;
}

std::vector<Thing> ThingiverseClient::getThingDerivatives(unsigned long long int thingId) {
    auto json = sendRequest("things/" + std::to_string(thingId) + "/derivatives");

    auto result = std::vector<Thing>();
    for (const auto &item: json.get<std::vector<nlohmann::json>>()) {
        result.emplace_back(Thing::fromSearchJson(item));
    }

    return result;
}

std::vector<Image> ThingiverseClient::getImagesByThing(unsigned long long thingId) {
    auto json = sendRequest("things/" + std::to_string(thingId) + "/images");

    auto result = std::vector<Image>();
    for (const auto &item: json.get<std::vector<nlohmann::json>>()) {
        result.emplace_back(Image::fromJson(item));
    }

    return result;
}

std::vector<File> ThingiverseClient::getFilesByThing(unsigned long long thingId) {
    auto json = sendRequest("things/" + std::to_string(thingId) + "/files");

    auto result = std::vector<File>();
    for (const auto &item: json.get<std::vector<nlohmann::json>>()) {
        result.emplace_back(File::fromJson(item));
    }

    return result;
}

std::vector<Category> ThingiverseClient::getCategoriesByThing(unsigned long long thingId) {
    auto json = sendRequest("things/" + std::to_string(thingId) + "/categories");

    auto result = std::vector<Category>();
    for (const auto &item: json.get<std::vector<nlohmann::json>>()) {
        result.emplace_back(Category::fromThingJson(item));
    }

    return result;
}

std::vector<Thing>
ThingiverseClient::getThingsInternal(unsigned int page, unsigned int thingsPerPage, const std::string &keyword,
                                     const SortThingsBy &sortBy, bool hasCategory, unsigned long long categoryId) {
    if (page == 0) {
        page = 1;
    }
    if (thingsPerPage == 0) {
        thingsPerPage = 1;
    }

    std::map<std::string, std::string> parameters = {
            {"page",     std::to_string(page)},
            {"per_page", std::to_string(thingsPerPage)},
            {"type",     "things"}
    };
    if (hasCategory) {
        parameters["category_id"] = categoryId;
    }
    switch (sortBy) {
        case Relevant:
            parameters["sort"] = "relevant";
            break;
        case Text:
            parameters["sort"] = "text";
            break;
        case Popular:
            parameters["sort"] = "popular";
            break;
        case Makes:
            parameters["sort"] = "makes";
            break;
        case Newest:
            parameters["sort"] = "newest";
            break;
    }

    auto json = sendRequest("search/" + keyword, parameters);

    auto result = std::vector<Thing>();
    for (const auto &item: json["hits"].get<std::vector<nlohmann::json>>()) {
        result.emplace_back(Thing::fromSearchJson(item));
    }

    return result;
}

std::vector<Thing>
ThingiverseClient::getThings(unsigned int page, unsigned int thingsPerPage, const std::string &keyword,
                             const SortThingsBy &sortBy) {
    return getThingsInternal(page, thingsPerPage, keyword, sortBy, false, 0);

}

std::vector<entities::Thing>
ThingiverseClient::getThingByCategory(unsigned long long categoryId, unsigned int page, unsigned int thingsPerPage,
                                      const std::string &keyword, const SortThingsBy &sortBy) {
    return getThingsInternal(page, thingsPerPage, keyword, sortBy, true, categoryId);
}
