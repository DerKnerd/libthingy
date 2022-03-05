//
// Created by imanuel on 05.03.22.
//

#include "../thingiverseClient.h"
#include "apiKey.h"

int main(int argc, char *argv[]) {
    auto client = thingy::ThingiverseClient(API_KEY);
    auto thing = client.getThing(2064029);

    if (thing.id != 2064029) { return 1; }
    if (thing.name.empty()) { return 1; }
    if (thing.added.empty()) { return 1; }
    if (thing.thumbnail.empty()) { return 1; }
    if (thing.publicUrl.empty()) { return 1; }
    if (thing.added.empty()) { return 1; }
    if (thing.modified.empty()) { return 1; }
    if (thing.likeCount == 0) { return 1; }
    if (thing.collectCount == 0) { return 1; }
    if (thing.commentCount == 0) { return 1; }
    if (thing.description.empty()) { return 1; }
    if (thing.license.empty()) { return 1; }
    if (thing.fileCount == 0) { return 1; }
    if (thing.downloadCount == 0) { return 1; }
    if (thing.viewCount == 0) { return 1; }
    if (thing.makeCount == 0) { return 1; }

    return 0;
}