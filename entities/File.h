//
// Created by imanuel on 06.03.22.
//

#ifndef LIBTHINGY_FILE_H
#define LIBTHINGY_FILE_H

#include <string>
#include "Image.h"

namespace thingy::entities {
    class File {
    public:
        unsigned long long id;
        std::string name;
        unsigned long long sizeInBytes;
        std::string url;
        std::string publicUrl;
        std::string thumbnail;
        Image defaultImage;
        std::string date;
        unsigned long long downloadCount;
        std::string directUrl;

        static File fromJson(const nlohmann::json &json);
    };
}

#endif //LIBTHINGY_FILE_H
