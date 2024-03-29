//
// Created by imanuel on 06.03.22.
//

#include "../libthingy.h"

thingy::entities::User thingy::ThingiverseClient::userFromCreatorJson(const nlohmann::json &json) {
    auto user = thingy::entities::User();
    user.id = json.contains("id") ? json["id"].get<unsigned long long>() : -1;
    user.username = json.contains("name") ? json["name"] : "";
    user.firstName = json.contains("first_name") ? json["first_name"].is_null() ? "" : json["first_name"] : "";
    user.lastName = json.contains("last_name") ? json["last_name"].is_null() ? "" : json["last_name"] : "";
    user.publicUrl = json.contains("public_url") ? json["public_url"] : "";
    user.thumbnail = json.contains("thumbnail") ? json["thumbnail"] : "";
    user.countOfFollowers = json.contains("count_of_followers") ? json["count_of_followers"].get<unsigned long long>() : 0;
    user.countOfFollowing = json.contains("count_of_following") ? json["count_of_following"].get<unsigned long long>() : 0;
    user.countOfDesigns = json.contains("count_of_designs") ? json["count_of_designs"].get<unsigned long long>() : 0;
    user.acceptsTips = json.contains("accepts_tips") && json["accepts_tips"].get<bool>();
    user.location = json.contains("location") ? json["location"] : "";
    user.cover = json.contains("cover") ? json["cover"] : json["cover_image"];

    return user;
}

thingy::entities::TwitterAccount thingy::ThingiverseClient::twitterAccountFromJson(const nlohmann::json &json) {
    auto account = thingy::entities::TwitterAccount();
    account.name = json["account_name"];
    account.url = json["account_url"];

    return account;
}

thingy::entities::User thingy::ThingiverseClient::userFromJson(const nlohmann::json &json) {
    auto user = userFromCreatorJson(json);
    user.twitterAccount = twitterAccountFromJson(json["twitter"]);
    user.website = json["website"];
    user.skillLevel = json["skill_level"];
    user.fullName = json["full_name"];
    user.bio = json["bio"];
    user.industry = json["industry"];
    user.registered = json["registered"];
    user.lastActive = json["last_active"];
    user.country = json["country"].is_null() ? "" : json["country"];

    for (const auto &item: json["printers"].get<std::vector<nlohmann::json>>()) {
        user.printers.emplace_back(item["name"]);
    }
    for (const auto &item: json["programs"].get<std::vector<nlohmann::json>>()) {
        user.programs.emplace_back(item["name"]);
    }
    for (const auto &item: json["types"].get<std::vector<nlohmann::json>>()) {
        user.types.emplace_back(item["name"]);
    }

    return user;
}