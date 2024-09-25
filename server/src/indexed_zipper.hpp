#ifndef INDEXED_ZIPPER_HPP
#define INDEXED_ZIPPER_HPP

#include "indexed_zipper_iterator.hpp"

template <typename... Containers>
class indexed_zipper {
public:
    using iterator = indexed_zipper_iterator<Containers...>;
    using iterator_tuple = typename iterator::iterator_tuple;

    // Constructor
    indexed_zipper(Containers&... cs)
        : _begin(_compute_begin(cs...)), _end(_compute_end(cs...)), _size(_compute_size(cs...)) {}

    // Begin and end methods
    iterator begin() {
        return iterator(_begin, _size, 0);
    }

    iterator end() {
        return iterator(_end, _size, _size);
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

#endif // INDEXED_ZIPPER_HPP