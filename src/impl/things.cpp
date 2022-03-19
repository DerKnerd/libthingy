//
// Created by imanuel on 05.03.22.
//

#include "../../libthingy.h"

using namespace thingy;
using namespace entities;

Thing ThingiverseClient::getThing(unsigned long long thingId) {
    auto json = sendRequest("things/" + std::to_string(thingId));
    return thingFromJson(json);
}

std::vector<Thing> ThingiverseClient::getThingAncestors(unsigned long long int thingId) {
    auto json = sendRequest("things/" + std::to_string(thingId) + "/ancestors");

    auto result = std::vector<Thing>();
    for (const auto &item: json.get<std::vector<nlohmann::json>>()) {
        result.emplace_back(thingFromSearchJson(item));
    }

    return result;
}

std::vector<Thing> ThingiverseClient::getThingDerivatives(unsigned long long int thingId) {
    auto json = sendRequest("things/" + std::to_string(thingId) + "/derivatives");

    auto result = std::vector<Thing>();
    for (const auto &item: json.get<std::vector<nlohmann::json>>()) {
        result.emplace_back(thingFromSearchJson(item));
    }

    return result;
}

std::vector<Image> ThingiverseClient::getImagesByThing(unsigned long long thingId) {
    auto json = sendRequest("things/" + std::to_string(thingId) + "/images");

    auto result = std::vector<Image>();
    for (const auto &item: json.get<std::vector<nlohmann::json>>()) {
        result.emplace_back(imageFromJson(item));
    }

    return result;
}

std::vector<File> ThingiverseClient::getFilesByThing(unsigned long long thingId) {
    auto json = sendRequest("things/" + std::to_string(thingId) + "/files");

    auto result = std::vector<File>();
    for (const auto &item: json.get<std::vector<nlohmann::json>>()) {
        result.emplace_back(fileFromJson(item));
    }

    return result;
}

std::vector<Category> ThingiverseClient::getCategoriesByThing(unsigned long long thingId) {
    auto json = sendRequest("things/" + std::to_string(thingId) + "/categories");

    auto result = std::vector<Category>();
    for (const auto &item: json.get<std::vector<nlohmann::json>>()) {
        result.emplace_back(categoryFromThingJson(item));
    }

    return result;
}

std::vector<Thing>
ThingiverseClient::getThingsInternal(unsigned int page, unsigned int thingsPerPage, const std::string &keyword,
                                     const SortBy &sortBy, bool hasCategory, unsigned long long categoryId,
                                     bool hasUser, const std::string &username, bool isFeatured) {
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
        parameters["category_id"] = std::to_string(categoryId);
    }
    if (isFeatured) {
        parameters["is_featured"] = "1";
    }

    std::string path = "search/" + keyword;
    if (hasUser) {
        path = "users/" + username + "/search/" + keyword;
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

    auto json = sendRequest(path, parameters);

    auto result = std::vector<Thing>();
    for (const auto &item: json["hits"].get<std::vector<nlohmann::json>>()) {
        result.emplace_back(thingFromSearchJson(item));
    }

    return result;
}

std::vector<Thing>
ThingiverseClient::getThings(unsigned int page, unsigned int thingsPerPage, const std::string &keyword,
                             const SortBy &sortBy) {
    return getThingsInternal(page, thingsPerPage, keyword, sortBy, false, 0, false, "", false);

}

std::vector<entities::Thing>
ThingiverseClient::getThingsByCategory(unsigned long long categoryId, unsigned int page, unsigned int thingsPerPage,
                                       const std::string &keyword, const SortBy &sortBy) {
    return getThingsInternal(page, thingsPerPage, keyword, sortBy, true, categoryId, false, "", false);
}

std::vector<entities::Thing>
ThingiverseClient::getThingsByUser(const std::string &username, unsigned int page, unsigned int thingsPerPage,
                                   const std::string &keyword, const SortBy &sortBy) {
    return getThingsInternal(page, thingsPerPage, keyword, sortBy, false, 0, false, username, false);
}

std::vector<entities::Thing>
ThingiverseClient::getThingsByCollection(unsigned long long collectionId, const SortBy &sortBy,
                                         const SortDirection &sortDirection) {
    std::map<std::string, std::string> parameters = {};

    std::string path = "collections/" + std::to_string(collectionId) + "/things";
    switch (sortBy) {
        case Added:
            parameters["sort"] = "date";
            break;
        case ThingName:
            parameters["sort"] = "name";
            break;
    }

    switch (sortDirection) {
        case Asc:
            parameters["order"] = "asc";
            break;
        case Desc:
            parameters["order"] = "desc";
            break;
    }

    auto json = sendRequest(path, parameters);

    auto result = std::vector<Thing>();
    for (const auto &item: json.get<std::vector<nlohmann::json>>()) {
        result.emplace_back(thingFromSearchJson(item));
    }

    return result;
}

std::vector<entities::Thing>
ThingiverseClient::getFeaturedThings(unsigned int page, unsigned int thingsPerPage, const std::string &keyword,
                                     const SortBy &sortBy) {
    return getThingsInternal(page, thingsPerPage, keyword, sortBy, false, 0, false, "", true);
}
