//
// Created by imanuel on 05.03.22.
//

#ifndef LIBTHINGY_THING_H
#define LIBTHINGY_THING_H

#include <nlohmann/json.hpp>
#include <string>
#include "Image.h"
#include "User.h"

namespace thingy::entities {
    class DetailsTextPart {
    public:
        std::string type;
        std::string name;
        std::vector<std::string> contentParts;

        static DetailsTextPart fromJson(const nlohmann::json &json);
    };

    class PrinterSettings {
    public:
        std::string printer;
        bool rafts;
        bool supports;
        std::string resolution;
        std::string infill;

        static PrinterSettings fromJson(const nlohmann::json &json);
    };

    class Thing {
    public:
        unsigned long long id;
        std::string name;
        std::string thumbnail;
        std::string publicUrl;
        std::string added;
        std::string modified;
        bool isWip;
        unsigned long long likeCount;
        unsigned long long collectCount;
        unsigned long long commentCount;
        std::string description;
        std::string license;
        unsigned long fileCount;
        unsigned long long downloadCount;
        unsigned long long viewCount;
        unsigned long long makeCount;
        bool allowDerivatives;
        std::vector<DetailsTextPart> details;
        PrinterSettings printerSettings;
        Image defaultImage;
        User creator;

        static Thing fromJson(const nlohmann::json &json);

        static Thing fromSearchJson(const nlohmann::json &json);
    };
}

#endif //LIBTHINGY_THING_H
