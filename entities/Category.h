//
// Created by imanuel on 06.03.22.
//

#ifndef LIBTHINGY_CATEGORY_H
#define LIBTHINGY_CATEGORY_H

#include <string>
#include <nlohmann/json.hpp>

namespace thingy::entities {
    class Category {
    public:
        std::string name;
        std::string slug;
        unsigned long long count;
        unsigned long long id;

        static Category fromThingJson(const nlohmann::json &json);
    };
}

#endif //LIBTHINGY_CATEGORY_H
