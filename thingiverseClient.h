//
// Created by imanuel on 05.03.22.
//

#ifndef LIBTHINGY_THINGIVERSECLIENT_H
#define LIBTHINGY_THINGIVERSECLIENT_H

#define CPPHTTPLIB_OPENSSL_SUPPORT

#include <utility>
#include <httplib/httplib.h>
#include <nlohmann/json.hpp>
#include "entities/Thing.h"

namespace thingy {
    class ThingiverseException : public std::exception {
    public:
        explicit ThingiverseException(std::string cause);

        [[nodiscard]] const char *what() const noexcept override;

    private:
        std::string cause;
    };

    class ThingiverseClient {
    public:
        explicit ThingiverseClient(std::string apiKey);

        entities::Thing getThing(long long thingId);

        std::vector<entities::Thing> getThings(unsigned int page = 1, unsigned int thingsPerPage = 20, const std::string& keyword = "");

    private:
        std::string apiKey;

        nlohmann::json sendRequest(const std::string &path);

        nlohmann::json sendRequest(const std::string &path, const std::map<std::string, std::string> &queryParams);
    };
}
#endif //LIBTHINGY_THINGIVERSECLIENT_H
