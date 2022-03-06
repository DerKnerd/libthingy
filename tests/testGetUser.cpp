//
// Created by imanuel on 05.03.22.
//

#include "../libthingy.h"
#include "apiKey.h"

int main(int argc, char *argv[]) {
    auto client = thingy::ThingiverseClient(API_KEY);
    auto user = client.getUser(483002);

    if (user.id != 483002) { return 1; }
    if (user.username != "Polymaker_3D") { return 1; }

    user = client.getUser("Polymaker_3D");

    if (user.id != 483002) { return 1; }

    return 0;
}