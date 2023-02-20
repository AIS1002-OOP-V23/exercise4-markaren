
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
            // TODO: return the value held by `sharedStr_`
            // Hint: dereference operator
            return {}; //placeholder
        }

        void update(const std::string &str) {
           // TODO: update the value held by `sharedStr_`
           // Hint: https://stackoverflow.com/questions/51093546/dereferencing-a-shared-pointer-and-assigning-to-it
        }

    private:
        std::shared_ptr<std::string> sharedStr_;
    };

    // The use of std::pair as return type is arbitrary. Any compound object would do.
    std::pair<SharedString, SharedString> shareMe(std::unique_ptr<std::string>& ptr) {
        // TODO: `ptr` represents unique ownership of an std::string. Your goal is to share that ownership between two instances of `SharedString` defined above.
        // Hint: std::move can be used to transfer ownership from a unique_ptr. Copying is not possible.
        // Hint: Calling std::move on a variable that has already been moved makes no sense.
        // Hint: Copying shared_ptr is allowed.

        throw std::runtime_error("Function 'shareMe' has not been implemented yet!"); // placeholder
    }

}// namespace ais1002

#endif//LAB_WEEK_8_TEMPLATE_EXERCISE1_HPP
