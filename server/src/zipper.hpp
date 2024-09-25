#ifndef ZIPPER_HPP
#define ZIPPER_HPP

#include "zipper_iterator.hpp"

template <typename... Containers>
class zipper {
public:
    using iterator = zipper_iterator<Containers...>;
    using iterator_tuple = typename iterator::iterator_tuple;

    // Constructor
    zipper(Containers&... cs)
        : _begin(_compute_begin(cs...)), _end(_compute_end(cs...)), _size(_compute_size(cs...)) {}

    // Begin and end methods
    iterator begin() {
        return iterator(_begin, _size);
    }

    iterator end() {
        return iterator(_end, _size);
    }

private:
    // Helper function to compute the maximum size of the containers
    static size_t _compute_size(Containers&... containers) {
        return std::min({containers.size()...});
    }

    // Helper function to compute the begin iterator tuple
    static iterator_tuple _compute_begin(Containers&... containers) {
        return std::make_tuple(containers.begin()...);
    }

    // Helper function to compute the end iterator tuple
    static iterator_tuple _compute_end(Containers&... containers) {
        return std::make_tuple(containers.end()...);
    }

private:
    iterator_tuple _begin;
    iterator_tuple _end;
    size_t _size;
};

#endif // ZIPPER_HPP