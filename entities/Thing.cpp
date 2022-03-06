//
// Created by imanuel on 05.03.22.
//

#include "../libthingy.h"
#include "../helper.h"

using namespace thingy;
using namespace entities;

Thing ThingiverseClient::thingFromJson(const nlohmann::json &json) {
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
    thing.defaultImage = ThingiverseClient::imageFromJson(json["default_image"]);
    thing.creator = ThingiverseClient::userFromCreatorJson(json["creator"]);

    for (const auto &item: json["details_parts"].get<std::vector<nlohmann::json>>()) {
        if (item["type"] == "settings" && !item["data"].empty()) {
            auto data = item["data"].get<std::vector<nlohmann::json>>();
            if (!data.empty()) {
                thing.printerSettings = ThingiverseClient::printerSettingsFromJson(data[0]);
            }
        } else {
            thing.details.emplace_back(ThingiverseClient::detailsTextPartFromJson(item));
        }
    }

    return thing;
}

Thing ThingiverseClient::thingFromSearchJson(const nlohmann::json &json) {
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

DetailsTextPart ThingiverseClient::detailsTextPartFromJson(const nlohmann::json &json) {
    auto part = DetailsTextPart();
    part.type = json["type"];
    part.name = json["name"];
    if (json.contains("data")) {
        for (const auto &item: json["data"].get<std::vector<nlohmann::json>>()) {
            part.contentParts.emplace_back(item["content"]);
        }
    }

    return part;
}

PrinterSettings ThingiverseClient::printerSettingsFromJson(const nlohmann::json &json) {
    auto settings = PrinterSettings();
    settings.infill = json["infill"];
    settings.printer = json["printer"];
    settings.resolution = json["resolution"];
    if (json.contains("rafts") && toLower(json["rafts"]) == "yes") {
        settings.rafts = true;
    }
    if (json.contains("supports") && toLower(json["supports"]) == "yes") {
        settings.supports = true;
    }

    return settings;
}
