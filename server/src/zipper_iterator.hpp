#ifndef ZIPPER_ITERATOR_HPP
#define ZIPPER_ITERATOR_HPP

#include <tuple>
#include <iterator>
#include <type_traits>
#include <utility>
#include <optional>

template <typename... Containers>
class zipper_iterator {
    template <typename Container>
    using iterator_t = decltype(std::declval<Container>().begin());

    template <typename Container>
    using it_reference_t = typename std::iterator_traits<iterator_t<Container>>::reference;

public:
    using value_type = std::tuple<it_reference_t<Containers>...>;
    using reference = value_type;
    using pointer = void;
    using difference_type = std::ptrdiff_t;
    using iterator_category = std::input_iterator_tag;
    using iterator_tuple = std::tuple<iterator_t<Containers>...>;

    // Constructor
    zipper_iterator(const iterator_tuple& it_tuple, size_t max)
        : _current(it_tuple), _max(max), _idx(0) {}

    // Copy constructor
    zipper_iterator(const zipper_iterator& z) = default;

    // Increment operators
    zipper_iterator& operator++() {
        incr_all(_seq);
        return *this;
    }

    zipper_iterator operator++(int) {
        zipper_iterator tmp = *this;
        ++(*this);
        return tmp;
    }

    // Dereference operators
    value_type operator*() {
        return to_value(_seq);
    }

    value_type operator->() {
        return **this;
    }

    // Equality operators
    friend bool operator==(const zipper_iterator& lhs, const zipper_iterator& rhs) {
        return lhs._idx == rhs._idx;
    }

    friend bool operator!=(const zipper_iterator& lhs, const zipper_iterator& rhs) {
        return !(lhs == rhs);
    }

private:
    // Increment all iterators
    template <size_t... Is>
    void incr_all(std::index_sequence<Is...>) {
        (++std::get<Is>(_current), ...);
        ++_idx;
    }

    // Check if all optionals are set
    template <size_t... Is>
    bool all_set(std::index_sequence<Is...>) {
        return (std::get<Is>(_current)->has_value() && ...);
    }

    // Return a tuple of references to components
    template <size_t... Is>
    value_type to_value(std::index_sequence<Is...>) {
        return std::tie(*std::get<Is>(_current)...);
    }

    iterator_tuple _current;
    size_t _max; // compare this value to _idx to prevent infinite loop
    size_t _idx;
    static constexpr auto _seq = std::index_sequence_for<Containers...>{};
};

#endif // ZIPPER_ITERATOR_HPP