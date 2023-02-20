
#ifndef LAB_WEEK_8_EXERCISE2_HPP
#define LAB_WEEK_8_EXERCISE2_HPP

#include "impl/MyClass.hpp"

namespace ais1002 {

    class LeakyMyClassOwner {

    public:
        LeakyMyClassOwner() : cls_(new MyClass()) {} // stranger danger, a wild new spotted!

        [[nodiscard]] int add(int a, int b) const {
            return cls_->add(a, b);
        }

    private:
        MyClass *cls_;
    };

    int testWillCallThisFunction(int a, int b) {
        // TODO: Calling this function will result in a memory leak. Do you see it?
        //  Fix the leak by fixing the underlying issue, not by circumventing it by say return a + b...
        //  Hint: RAII
        LeakyMyClassOwner leaky;
        return leaky.add(a, b);
    }


}// namespace ais1002

#endif//LAB_WEEK_8_EXERCISE2_HPP
