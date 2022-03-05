//
// Created by imanuel on 05.03.22.
//

#include "../thingiverseClient.h"
#include "apiKey.h"

int main(int argc, char *argv[]) {
    auto client = thingy::ThingiverseClient(API_KEY);
    auto things = client.getThingDerivatives(2884082);

    auto thing = things[0];
    if (thing.id != 5242411) { return 1; }
    if (thing.name.length() == 0) { return 1; }
    if (thing.added.length() == 0) { return 1; }
    if (thing.thumbnail.length() == 0) { return 1; }
    if (thing.publicUrl.length() == 0) { return 1; }
    if (thing.likeCount == 0) { return 1; }
    if (thing.commentCount == 0) { return 1; }
    if (thing.makeCount != 0) { return 1; }

    things = client.getThingDerivatives(5242411);
    if (!things.empty()) {
        return 1;
    }

    return 0;
}