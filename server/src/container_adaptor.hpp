/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** Container Adaptor
*/

#ifndef CONTAINER_ADAPTOR_HPP_
#define CONTAINER_ADAPTOR_HPP_

#include <tuple>
#include <vector>
#include <iterator>
#include <type_traits>
#include "sparse_array.hpp"

template <typename... Components>
class ContainerAdaptor {
public:
    using iterator = CustomIterator<Components...>;

    ContainerAdaptor(sparse_array<Components>&... arrays)
        : _arrays(std::make_tuple(std::ref(arrays)...)) {}

    iterator begin() {
        return iterator(_arrays, 0);
    }

    iterator end() {
        return iterator(_arrays, std::get<0>(_arrays).get().size());
    }

private:
    std::tuple<std::reference_wrapper<sparse_array<Components>>...> _arrays;
};

template <typename... Components>
class CustomIterator {
public:
    using iterator_category = std::input_iterator_tag;
    using value_type = std::tuple<Components&...>;
    using difference_type = std::ptrdiff_t;
    using pointer = value_type*;
    using reference = value_type&;

    CustomIterator(std::tuple<std::reference_wrapper<sparse_array<Components>>...>& arrays, size_t index)
        : _arrays(arrays), _index(index) {}

    reference operator*() {
        return _dereference();
    }

    pointer operator->() {
        return &_dereference();
    }

    CustomIterator& operator++() {
        do {
            ++_index;
        } while (_index < std::get<0>(_arrays).get().size() && !_valid());
        return *this;
    }

    CustomIterator operator++(int) {
        CustomIterator tmp = *this;
        ++(*this);
        return tmp;
    }

    bool operator!=(CustomIterator const& other) const {
        return _index != other._index;
    }

private:
    std::tuple<std::reference_wrapper<sparse_array<Components>>...>& _arrays;
    size_t _index;

    bool _valid() const {
        return (std::get<0>(_arrays).get()[_index] && ...);
    }

    reference _dereference() {
        return std::tuple<Components&...>(*std::get<0>(_arrays).get()[_index], ...);
    }
};

#endif /* !CONTAINER_ADAPTOR_HPP_ */
