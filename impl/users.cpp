//
// Created by imanuel on 06.03.22.
//

#include "../libthingy.h"

thingy::entities::User thingy::ThingiverseClient::getUser(unsigned long long userId) {
    auto json = sendRequest("users/" + std::to_string(userId));
    return userFromJson(json);
}

thingy::entities::User thingy::ThingiverseClient::getUser(const std::string& username) {
    auto json = sendRequest("users/" + username);
    return userFromJson(json);
}

