//
// Created by imanuel on 05.03.22.
//

#include "../thingiverseClient.h"
#include "apiKey.h"

int main(int argc, char *argv[]) {
    auto client = thingy::ThingiverseClient(API_KEY);
    auto files = client.getFilesByThing(2064029);

    if (files.empty()) { return 1; }

    auto file = files[0];
    if (file.id == 0) { return 1; }
    if (file.name.empty()) { return 1; }
    if (file.url.empty()) { return 1; }
    if (file.publicUrl.empty()) { return 1; }
    if (file.thumbnail.empty()) { return 1; }
    if (file.date.empty()) { return 1; }
    if (file.directUrl.empty()) { return 1; }
    if (file.downloadCount == 0) { return 1; }
    if (file.sizeInBytes == 0) { return 1; }
    if (file.defaultImage.sizes.empty()) { return 1; }

    return 0;
}