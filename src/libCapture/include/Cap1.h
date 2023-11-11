#pragma once
#include "libUtil/include/util.h"
namespace app{
    class Cap1{
        public:
            Cap1();
            ~Cap1();

            int getVal() const {
                return xyz_;
            }

        private:
         int xyz_;
    };
}