#include <stddef.h>

#ifndef ENTITY_HPP_
    #define ENTITY_HPP_

namespace Entity
{
    class Entity {
        public:
            explicit Entity(size_t value) : value_(value) {}

            operator size_t() const {
                return value_;
            }

        private:
            size_t value_;
    };
}


#endif /* !ENTITY_HPP_ */