
#ifndef LAB_WEEK_8_MYCLASS_HPP
#define LAB_WEEK_8_MYCLASS_HPP

// NOTE: Don't modify this file

namespace ais1002 {

    struct MyClass {

        MyClass() {
            useCount++;
        }

        int add(int a, int b) const {
            return a + b;
        }

        ~MyClass() {
            useCount--;
        }

        inline static int useCount = 0;
    };

}

#endif//LAB_WEEK_8_MYCLASS_HPP
