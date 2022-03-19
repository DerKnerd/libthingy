//
// Created by imanuel on 05.03.22.
//

#include "../libthingy.h"
#include "apiKey.h"

int main(int argc, char *argv[]) {
    auto client = thingy::ThingiverseClient(API_KEY);
    auto things = client.getThingDerivatives(2884082);

    auto thing = things[0];
    if (thing.id != 5242411) { return 1; }
    if (thing.name.empty()) { return 1; }
    if (thing.added.empty()) { return 1; }
    if (thing.thumbnail.empty()) { return 1; }
    if (thing.publicUrl.empty()) { return 1; }
    if (thing.likeCount == 0) { return 1; }
    if (thing.commentCount == 0) { return 1; }
    if (thing.makeCount == 0) { return 1; }

    things = client.getThingDerivatives(5242411);
    if (!things.empty()) {
        return 1;
    }

    return 0;
}