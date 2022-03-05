//
// Created by imanuel on 05.03.22.
//

#include "../thingiverseClient.h"

thingy::entities::Thing thingy::ThingiverseClient::getThing(long long thingId) {
    auto json = sendRequest("things/" + std::to_string(thingId));
    return thingy::entities::Thing::fromJson(json);
}


std::vector<thingy::entities::Thing> thingy::ThingiverseClient::getThings(int page) {
    return std::vector<entities::Thing>();
}