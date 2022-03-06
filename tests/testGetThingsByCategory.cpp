//
// Created by imanuel on 05.03.22.
//

#include "../libthingy.h"
#include "apiKey.h"
#include "../helper.h"

int main(int argc, char *argv[]) {
    auto client = thingy::ThingiverseClient(API_KEY);
    auto things = client.getThings();
    if (things.empty() || things.size() != 20) {
        return 1;
    }

    auto things2 = client.getThings(2);
    if (things2.empty() || things2.size() != 20) {
        return 1;
    }
    if (things[0].name == things2[0].name) {
        return 1;
    }

    things = client.getThings(1, 20, "filament");
    if (things.empty() || things.size() != 20) {
        return 1;
    }

    auto firstName = thingy::toLower(things[0].name);
    if (!firstName.contains("filament")) {
        return 1;
    }

    things = client.getThings(1, 2);
    if (things.empty() || things.size() != 2) {
        return 1;
    }

    return 0;
}