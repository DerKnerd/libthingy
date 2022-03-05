//
// Created by imanuel on 05.03.22.
//

#ifndef LIBTHINGY_IMAGE_H
#define LIBTHINGY_IMAGE_H

#include <string>
#include <vector>
#include <nlohmann/json.hpp>

namespace thingy::entities {
    class ImageSize {
    public:
        std::string type;
        std::string size;
        std::string url;

        static ImageSize fromJson(const nlohmann::json &json);
    };

    class Image {
    public:
        unsigned long long id;
        std::string name;
        std::string url;
        std::vector<ImageSize> sizes;

        static Image fromJson(const nlohmann::json &json);
    };
}

#endif //LIBTHINGY_IMAGE_H
