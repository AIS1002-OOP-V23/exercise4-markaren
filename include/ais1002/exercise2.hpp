
#ifndef LAB_WEEK_8_EXERCISE2_HPP
#define LAB_WEEK_8_EXERCISE2_HPP

#include "impl/MyClass.hpp"

#include <memory>

namespace ais1002 {

    class LeakyMyClassOwner {

    public:
        LeakyMyClassOwner() : cls_(std::make_unique<MyClass>()) {} // stranger danger, a wild new spotted!

        [[nodiscard]] int add(int a, int b) const {
            return cls_->add(a, b);
        }

    private:
        std::unique_ptr<MyClass> cls_;
    };

    int testWillCallThisFunction(int a, int b) {
        LeakyMyClassOwner leaky;
        return leaky.add(a, b);
    }


}// namespace ais1002

#endif//LAB_WEEK_8_EXERCISE2_HPP
