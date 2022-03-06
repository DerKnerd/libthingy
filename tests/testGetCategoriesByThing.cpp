//
// Created by imanuel on 05.03.22.
//

#include "../libthingy.h"
#include "apiKey.h"

int main(int argc, char *argv[]) {
    auto client = thingy::ThingiverseClient(API_KEY);
    auto categories = client.getCategoriesByThing(2064029);

    if (categories.empty()) { return 1; }

    auto file = categories[0];
    if (file.name.empty()) { return 1; }
    if (file.slug.empty()) { return 1; }
    if (file.count == 0) { return 1; }

    return 0;
}