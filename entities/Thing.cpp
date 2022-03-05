//
// Created by imanuel on 05.03.22.
//

#include "Thing.h"

thingy::entities::Thing thingy::entities::Thing::fromJson(const nlohmann::json &json) {
    auto thing = Thing();
    thing.id = json["id"];
    thing.name = json["name"];
    thing.thumbnail = json["thumbnail"];
    thing.publicUrl = json["public_url"];
    thing.added = json["added"];
    thing.modified = json["modified"];
    thing.isWip = json["is_wip"].get<int>() == 1;
    thing.likeCount = json["like_count"];
    thing.collectCount = json["collect_count"];
    thing.commentCount = json["comment_count"];
    thing.description = json["description"];
    thing.license = json["license"];
    thing.fileCount = json["file_count"];
    thing.downloadCount = json["download_count"];
    thing.viewCount = json["view_count"];
    thing.makeCount = json["make_count"];
    thing.allowDerivatives = json["allows_derivatives"];

    return thing;
}

thingy::entities::Thing thingy::entities::Thing::fromSearchJson(const nlohmann::json &json) {
    auto thing = Thing();
    thing.id = json["id"];
    thing.name = json["name"];
    thing.thumbnail = json["thumbnail"];
    thing.publicUrl = json["public_url"];
    thing.added = json["created_at"];
    thing.likeCount = json["like_count"];
    thing.commentCount = json["comment_count"];
    thing.makeCount = json["make_count"];

    return thing;
}
