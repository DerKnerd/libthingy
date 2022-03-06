//
// Created by imanuel on 06.03.22.
//

#include "User.h"

thingy::entities::User thingy::entities::User::fromCreatorJson(const nlohmann::json &json) {
    auto user = thingy::entities::User();
    user.id = json["id"];
    user.username = json["name"];
    user.firstName = json["first_name"];
    user.lastName = json["last_name"];
    user.publicUrl = json["public_url"];
    user.thumbnail = json["thumbnail"];
    user.countOfFollowers = json["count_of_followers"];
    user.countOfFollowing = json["count_of_following"];
    user.countOfDesigns = json["count_of_designs"];
    user.acceptsTips = json["accepts_tips"];
    user.location = json["location"];
    user.cover = json["cover"];

    return user;
}
