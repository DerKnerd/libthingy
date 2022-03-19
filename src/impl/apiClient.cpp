//
// Created by imanuel on 05.03.22.
//

#include "../../libthingy.h"

thingy::ThingiverseClient::ThingiverseClient(std::string apiKey) : apiKey(std::move(apiKey)) {}

nlohmann::json thingy::ThingiverseClient::sendRequest(const std::string &path) {
    return this->sendRequest(path, std::map<std::string, std::string>{});
}

nlohmann::json
thingy::ThingiverseClient::sendRequest(const std::string &path, const std::map<std::string, std::string> &queryParams) {
    auto client = httplib::Client("https://api.thingiverse.com");
    client.set_read_timeout(5 * 60);
    client.set_connection_timeout(5 * 60);
    auto queryParamsIncludingAccessToken = std::map<std::string, std::string>(queryParams);
    queryParamsIncludingAccessToken["access_token"] = apiKey;
    auto mappedQueryParams = std::string("");
    for (const auto &item: queryParamsIncludingAccessToken) {
        mappedQueryParams += item.first + "=" + item.second + "&";
    }

    mappedQueryParams.pop_back();
    auto url = "/" + path + "?" + mappedQueryParams;
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