//
// Created by imanuel on 06.03.22.
//

#include "../../libthingy.h"

thingy::entities::User thingy::ThingiverseClient::getUser(unsigned long long userId) {
    auto json = sendRequest("users/" + std::to_string(userId));
    return userFromJson(json);
}

thingy::entities::User thingy::ThingiverseClient::getUser(const std::string &username) {
    auto json = sendRequest("users/" + username);
    return userFromJson(json);
}

std::vector<thingy::entities::User>
thingy::ThingiverseClient::getUsers(unsigned int page, unsigned int usersPerPage, const std::string &keyword,
                                    const SortBy &sortBy) {
    if (page == 0) {
        page = 1;
    }
    if (usersPerPage == 0) {
        usersPerPage = 1;
    }

    std::map<std::string, std::string> parameters = {
            {"page",     std::to_string(page)},
            {"per_page", std::to_string(usersPerPage)},
            {"type",     "users"}
    };
    switch (sortBy) {
        case Relevant:
            parameters["sort"] = "relevant";
            break;
        case Designs:
            parameters["sort"] = "designs";
            break;
        case Followers:
            parameters["sort"] = "followers";
            break;
        case Makes:
            parameters["sort"] = "makes";
            break;
    }

    auto json = sendRequest("search/" + keyword, parameters);

    auto result = std::vector<thingy::entities::User>();
    for (const auto &item: json["hits"].get<std::vector<nlohmann::json>>()) {
        result.emplace_back(userFromCreatorJson(item));
    }

    return result;
}

std::vector<thingy::entities::Thing>
thingy::ThingiverseClient::getLikesByUser(const std::string &username, unsigned int page, unsigned int likesPerPage) {
    if (page == 0) {
        page = 1;
    }
    if (likesPerPage == 0) {
        likesPerPage = 1;
    }

    std::map<std::string, std::string> parameters = {
            {"page",     std::to_string(page)},
            {"per_page", std::to_string(likesPerPage)},
    };

    std::string path = "users/" + username + "/likes";

    auto json = sendRequest(path, parameters);

    auto result = std::vector<thingy::entities::Thing>();
    for (const auto &item: json.get<std::vector<nlohmann::json>>()) {
        result.emplace_back(thingFromSearchJson(item));
    }

    return result;
}
