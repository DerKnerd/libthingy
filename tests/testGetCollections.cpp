//
// Created by imanuel on 05.03.22.
//

#include "../libthingy.h"
#include "apiKey.h"
#include "../helper.h"

int main(int argc, char *argv[]) {
    auto client = thingy::ThingiverseClient(API_KEY);
    auto things = client.getCollections();
    if (things.empty() || things.size() != 20) {
        return 1;
    }

    return 0;
}