//
// Created by imanuel on 05.03.22.
//

#include "../thingiverseClient.h"
#include "apiKey.h"

int main(int argc, char *argv[]) {
    auto client = thingy::ThingiverseClient(API_KEY);
    auto thing = client.getThing(763622);

    if (thing.id != 763622) { return 1; }
    if (thing.name.length() == 0) { return 1; }
    if (thing.added.length() == 0) { return 1; }
    if (thing.thumbnail.length() == 0) { return 1; }
    if (thing.publicUrl.length() == 0) { return 1; }
    if (thing.added.length() == 0) { return 1; }
    if (thing.modified.length() == 0) { return 1; }
    if (thing.likeCount == 0) { return 1; }
    if (thing.collectCount == 0) { return 1; }
    if (thing.commentCount == 0) { return 1; }
    if (thing.description.length() == 0) { return 1; }
    if (thing.license.length() == 0) { return 1; }
    if (thing.fileCount == 0) { return 1; }
    if (thing.downloadCount == 0) { return 1; }
    if (thing.viewCount == 0) { return 1; }
    if (thing.makeCount == 0) { return 1; }

    return 0;
}