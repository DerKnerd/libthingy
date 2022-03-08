//
// Created by imanuel on 06.03.22.
//

#ifndef LIBTHINGY_LIBTHINGY_H
#define LIBTHINGY_LIBTHINGY_H

#define CPPHTTPLIB_OPENSSL_SUPPORT

#include <utility>
#include <httplib/httplib.h>
#include <nlohmann/json.hpp>

namespace thingy {
    namespace entities {
        class Category {
        public:
            std::string name;
            std::string slug;
            unsigned long long count;
            unsigned long long id;
        };

        class ImageSize {
        public:
            std::string type;
            std::string size;
            std::string url;
        };

        class Image {
        public:
            unsigned long long id;
            std::string name;
            std::string url;
            std::vector<ImageSize> sizes;
        };

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
        };

        class DetailsTextPart {
        public:
            std::string type;
            std::string name;
            std::vector<std::string> contentParts;
        };

        class PrinterSettings {
        public:
            std::string printer;
            bool rafts;
            bool supports;
            std::string resolution;
            std::string infill;
        };

        class TwitterAccount {
        public:
            std::string name;
            std::string url;
        };

        class User {
        public:
            unsigned long long id;
            std::string username;
            std::string firstName;
            std::string lastName;
            std::string fullName;
            std::string publicUrl;
            std::string thumbnail;
            unsigned long long countOfFollowers;
            unsigned long long countOfFollowing;
            unsigned long long countOfDesigns;
            bool acceptsTips;
            std::string location;
            std::string cover;
            std::string bio;
            std::string country;
            std::string industry;
            std::string registered;
            std::string lastActive;
            std::vector<std::string> printers;
            std::vector<std::string> programs;
            std::vector<std::string> types;
            std::string skillLevel;
            std::string website;
            unsigned long long collectionCount;
            TwitterAccount twitterAccount;
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
        };
    }

    enum SortBy {
        Relevant,
        Text,
        Popular,
        Makes,
        Newest,
        Designs,
        Followers,
    };

    class ThingiverseException : public std::exception {
    public:
        explicit ThingiverseException(std::string cause);

        [[nodiscard]] const char *what() const noexcept override;

    private:
        std::string cause;
    };

    class ThingiverseClient {
    private:
        entities::Thing thingFromJson(const nlohmann::json &json);

        entities::Thing thingFromSearchJson(const nlohmann::json &json);

        entities::User userFromJson(const nlohmann::json &json);

        entities::User userFromCreatorJson(const nlohmann::json &json);

        entities::TwitterAccount twitterAccountFromJson(const nlohmann::json &json);

        entities::PrinterSettings printerSettingsFromJson(const nlohmann::json &json);

        entities::DetailsTextPart detailsTextPartFromJson(const nlohmann::json &json);

        entities::File fileFromJson(const nlohmann::json &json);

        entities::Image imageFromJson(const nlohmann::json &json);

        entities::ImageSize imageSizeFromJson(const nlohmann::json &json);

        entities::Category categoryFromThingJson(const nlohmann::json &json);

    public:
        explicit ThingiverseClient(std::string apiKey);

        entities::Thing getThing(unsigned long long thingId);

        std::vector<entities::Thing>
        getThings(unsigned int page = 1, unsigned int thingsPerPage = 20, const std::string &keyword = "",
                  const SortBy &sortBy = SortBy::Relevant);

        std::vector<entities::Thing>
        getThingsByCategory(unsigned long long categoryId, unsigned int page = 1, unsigned int thingsPerPage = 20,
                            const std::string &keyword = "", const SortBy &sortBy = SortBy::Relevant);

        std::vector<entities::Thing>
        getThingsByUser(const std::string& username, unsigned int page = 1, unsigned int thingsPerPage = 20,
                        const std::string &keyword = "", const SortBy &sortBy = SortBy::Relevant);

        std::vector<entities::Thing> getThingAncestors(unsigned long long thingId);

        std::vector<entities::Thing> getThingDerivatives(unsigned long long thingId);

        std::vector<entities::Image> getImagesByThing(unsigned long long thingId);

        std::vector<entities::File> getFilesByThing(unsigned long long thingId);

        std::vector<entities::Category> getCategoriesByThing(unsigned long long thingId);


        entities::User getUser(unsigned long long userId);

        entities::User getUser(const std::string &username);

        std::vector<entities::User>
        getUsers(unsigned int page = 1, unsigned int usersPerPage = 20, const std::string &keyword = "",
                 const SortBy &sortBy = SortBy::Relevant);

    private:
        std::string apiKey;

        nlohmann::json sendRequest(const std::string &path);

        nlohmann::json sendRequest(const std::string &path, const std::map<std::string, std::string> &queryParams);

        std::vector<entities::Thing>
        getThingsInternal(unsigned int page, unsigned int thingsPerPage, const std::string &keyword,
                          const SortBy &sortBy, bool hasCategory, unsigned long long categoryId, bool hasUser,
                          const std::string& username);
    };
}

#endif //LIBTHINGY_LIBTHINGY_H
