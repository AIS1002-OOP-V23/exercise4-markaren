
#ifndef LAB_WEEK_8_TEMPLATE_EXERCISE1_HPP
#define LAB_WEEK_8_TEMPLATE_EXERCISE1_HPP

#include <memory>
#include <string>
#include <utility>
#include <stdexcept>

namespace ais1002 {

    class SharedString {

    public:
        explicit SharedString(std::shared_ptr<std::string> sharedStr)
            : sharedStr_(std::move(sharedStr)) {}

        [[nodiscard]] std::string str() const {
            return *sharedStr_;
        }

        void update(const std::string &str) {
           *sharedStr_ = str;
        }

    private:
        std::shared_ptr<std::string> sharedStr_;
    };

    // The use of std::pair as return type is arbitrary. Any compound object would do.
    std::pair<SharedString, SharedString> shareMe(std::unique_ptr<std::string>& ptr) {
        std::shared_ptr<std::string> str = std::move(ptr);

        return {SharedString(str), SharedString(str)};
    }

}// namespace ais1002

#endif//LAB_WEEK_8_TEMPLATE_EXERCISE1_HPP
