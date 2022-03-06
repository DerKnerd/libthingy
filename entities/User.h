//
// Created by imanuel on 06.03.22.
//

#ifndef LIBTHINGY_USER_H
#define LIBTHINGY_USER_H

#include <string>
#include <nlohmann/json.hpp>

namespace thingy::entities {
    class User {
    public:
        unsigned long long id;
        std::string username;
        std::string firstName;
        std::string lastName;
        std::string publicUrl;
        std::string thumbnail;
        unsigned long long countOfFollowers;
        unsigned long long countOfFollowing;
        unsigned long long countOfDesigns;
        bool acceptsTips;
        std::string location;
        std::string cover;

        static User fromCreatorJson(const nlohmann::json &json);
    };
}

#endif //LIBTHINGY_USER_H
