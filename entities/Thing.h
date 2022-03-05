//
// Created by imanuel on 05.03.22.
//

#ifndef LIBTHINGY_THING_H
#define LIBTHINGY_THING_H

#include <nlohmann/json.hpp>
#include <string>

namespace thingy::entities {
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

        static Thing fromJson(const nlohmann::json &json);

        static Thing fromSearchJson(const nlohmann::json &json);
    };
}

#endif //LIBTHINGY_THING_H
