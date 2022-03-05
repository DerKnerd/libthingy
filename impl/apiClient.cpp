//
// Created by imanuel on 05.03.22.
//

#include "../thingiverseClient.h"

thingy::ThingiverseClient::ThingiverseClient(std::string apiKey) : apiKey(std::move(apiKey)) {}

nlohmann::json thingy::ThingiverseClient::sendRequest(const std::string &path) {
    auto client = httplib::Client("https://api.thingiverse.com");
    auto url = "/" + path + "?access_token=" + apiKey;
    auto response = client.Get(url.c_str());
    if (response.error() != httplib::Error::Success) {
        throw thingy::ThingiverseException(httplib::to_string(response.error()));
    }
    if (response->status != 200) {
        auto body = response->body;
        throw thingy::ThingiverseException(body);
    }

    return nlohmann::json::parse(response->body);
}

nlohmann::json
thingy::ThingiverseClient::sendRequest(const std::string &path, const std::map<std::string, std::string> &queryParams) {
    return nlohmann::json();
}