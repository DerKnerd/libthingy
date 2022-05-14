//
// Created by imanuel on 05.03.22.
//

#include "../libthingy.h"
#include "apiKey.h"

int main(int argc, char *argv[]) {
    auto client = thingy::ThingiverseClient(API_KEY);
    auto files = client.getFilesByThing(763622);

    if (files.empty()) { return 1; }

    return 0;
}