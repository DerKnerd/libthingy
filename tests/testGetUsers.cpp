//
// Created by imanuel on 05.03.22.
//

#include "../libthingy.h"
#include "apiKey.h"

int main(int argc, char *argv[]) {
    auto client = thingy::ThingiverseClient(API_KEY);
    auto users = client.getUsers(1);

    if (users.empty()) { return 1; }

    users = client.getUsers(1, 20, "Polymaker_3D");

    if (users.empty()) { return 1; }
    auto user = users[0];
    if (user.username != "Polymaker_3D") { return 1; }

    return 0;
}