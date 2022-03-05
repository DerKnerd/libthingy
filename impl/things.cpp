//
// Created by imanuel on 05.03.22.
//

#include "../thingiverseClient.h"

thingy::entities::Thing thingy::ThingiverseClient::getThing(unsigned long long thingId) {
    auto json = sendRequest("things/" + std::to_string(thingId));
    return thingy::entities::Thing::fromJson(json);
}


std::vector<thingy::entities::Thing>
thingy::ThingiverseClient::getThings(unsigned int page, unsigned int thingsPerPage, const std::string &keyword) {
    if (page == 0) {
        page = 1;
    }
    if (thingsPerPage == 0) {
        thingsPerPage = 1;
    }

    auto json = sendRequest("search/" + keyword, {
            {"page",     std::to_string(page)},
            {"per_page", std::to_string(thingsPerPage)},
            {"type",     "things"}
    });

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