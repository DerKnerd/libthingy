//
// Created by imanuel on 05.03.22.
//

#include "../libthingy.h"
#include "apiKey.h"

int main(int argc, char *argv[]) {
    auto client = thingy::ThingiverseClient(API_KEY);
    auto category = client.getCategory("3d-printing");

    if (category.name.empty()) { return 1; }
    if (category.slug.empty()) { return 1; }
    if (category.count == 0) { return 1; }

    return 0;
}