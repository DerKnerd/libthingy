//
// Created by imanuel on 05.03.22.
//

#include "../libthingy.h"
#include "apiKey.h"

int main(int argc, char *argv[]) {
    auto client = thingy::ThingiverseClient(API_KEY);
    auto images = client.getImagesByThing(2064029);

    if (images.empty()) { return 1; }

    auto image = images[0];
    if (image.id == 0) { return 1; }
    if (image.name.empty()) { return 1; }
    if (image.url.empty()) { return 1; }
    if (image.sizes.empty()) { return 1; }

    auto size = image.sizes[0];
    if (size.url.empty()) { return 1; }
    if (size.size.empty()) { return 1; }
    if (size.type.empty()) { return 1; }

    return 0;
}