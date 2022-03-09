//
// Created by imanuel on 05.03.22.
//

#include "../libthingy.h"
#include "apiKey.h"

int main(int argc, char *argv[]) {
    auto client = thingy::ThingiverseClient(API_KEY);
    auto collection = client.getCollection(6668049);

    if (collection.id != 6668049) { return 1; }
    if (collection.name.empty()) { return 1; }
    if (collection.added.empty()) { return 1; }
    if (collection.thumbnail.empty()) { return 1; }
    if (collection.modified.empty()) { return 1; }
    if (collection.modified.empty()) { return 1; }
    if (collection.description.empty()) { return 1; }

    return 0;
}