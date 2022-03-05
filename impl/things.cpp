//
// Created by imanuel on 05.03.22.
//

#include "../thingiverseClient.h"

thingy::entities::Thing thingy::ThingiverseClient::getThing(unsigned long long thingId) {
    auto json = sendRequest("things/" + std::to_string(thingId));
    return thingy::entities::Thing::fromJson(json);
}


std::vector<thingy::entities::Thing>
thingy::ThingiverseClient::getThings(unsigned int page, unsigned int thingsPerPage, const std::string &keyword,
                                     const SortThingsBy &sortBy) {
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
    switch (sortBy) {
        case SortThingsBy::Relevant:
            parameters["sort"] = "relevant";
            break;
        case SortThingsBy::Text:
            parameters["sort"] = "text";
            break;
        case SortThingsBy::Popular:
            parameters["sort"] = "popular";
            break;
        case SortThingsBy::Makes:
            parameters["sort"] = "makes";
            break;
        case SortThingsBy::Newest:
            parameters["sort"] = "newest";
            break;
    }

    auto json = sendRequest("search/" + keyword, parameters);

    auto result = std::vector<thingy::entities::Thing>();
    for (const auto &item: json["hits"].get<std::vector<nlohmann::json>>()) {
        result.emplace_back(thingy::entities::Thing::fromSearchJson(item));
    }

    return result;
}

std::vector<thingy::entities::Thing> thingy::ThingiverseClient::getThingAncestors(unsigned long long int thingId) {
    auto json = sendRequest("things/" + std::to_string(thingId) + "/ancestors");

    auto result = std::vector<thingy::entities::Thing>();
    for (const auto &item: json.get<std::vector<nlohmann::json>>()) {
        result.emplace_back(thingy::entities::Thing::fromSearchJson(item));
    }

    return result;
}

std::vector<thingy::entities::Thing> thingy::ThingiverseClient::getThingDerivatives(unsigned long long int thingId) {
    auto json = sendRequest("things/" + std::to_string(thingId) + "/derivatives");

    auto result = std::vector<thingy::entities::Thing>();
    for (const auto &item: json.get<std::vector<nlohmann::json>>()) {
        result.emplace_back(thingy::entities::Thing::fromSearchJson(item));
    }

    return result;
}