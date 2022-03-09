//
// Created by imanuel on 08.03.22.
//

#include "../libthingy.h"

std::vector<thingy::entities::Collection>
thingy::ThingiverseClient::getCollectionsInternal(unsigned int page, unsigned int collectionsPerPage,
                                                  const std::string &keyword, const thingy::SortBy &sortBy,
                                                  bool hasUser, const std::string &username) {
    if (page == 0) {
        page = 1;
    }
    if (collectionsPerPage == 0) {
        collectionsPerPage = 1;
    }

    std::map<std::string, std::string> parameters = {
            {"page",     std::to_string(page)},
            {"per_page", std::to_string(collectionsPerPage)},
            {"type",     "collections"}
    };

    std::string path = "search/" + keyword;
    if (hasUser) {
        path = "users/" + username + "/search/" + keyword;
    }
    switch (sortBy) {
        case Popular:
            parameters["sort"] = "popular";
            break;
        case Newest:
            parameters["sort"] = "newest";
            break;
    }

    auto json = sendRequest(path, parameters);

    auto result = std::vector<thingy::entities::Collection>();
    for (const auto &item: json["hits"].get<std::vector<nlohmann::json>>()) {
        result.emplace_back(collectionFromSearchJson(item));
    }

    return result;
}


std::vector<thingy::entities::Collection>
thingy::ThingiverseClient::getCollectionsByUser(const std::string &username, unsigned int page,
                                                unsigned int collectionsPerPage, const std::string &keyword,
                                                const SortBy &sortBy) {
    return getCollectionsInternal(page, collectionsPerPage, keyword, sortBy, true, username);
}

thingy::entities::Collection thingy::ThingiverseClient::getCollection(unsigned long long id) {
    auto result = sendRequest("collections/" + std::to_string(id));

    return collectionFromJson(result);
}