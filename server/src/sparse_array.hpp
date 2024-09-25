/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** Bs
*/

#ifndef CONTAINER_HPP_
#define CONTAINER_HPP_

#include <vector>
#include <memory>
#include <cassert>
#include <optional>
#include <algorithm>

template <typename Component, typename Allocator = std::allocator<Component>>
class sparse_array {
public:
    using value_type = std::optional<Component>;
    using reference_type = value_type&;
    using const_reference_type = const value_type&;
    using container_t = std::vector<value_type, typename std::allocator_traits<Allocator>::template rebind_alloc<value_type>>;
    using size_type = typename container_t::size_type;
    using iterator = typename container_t::iterator;
    using const_iterator = typename container_t::const_iterator;

public:
    sparse_array() = default;
    sparse_array(const sparse_array&) = default;
    sparse_array(sparse_array&&) noexcept = default;
    ~sparse_array() = default;
    sparse_array& operator=(const sparse_array&) = default;
    sparse_array& operator=(sparse_array&&) noexcept = default;

    reference_type operator[](size_t idx) {
        assert(idx < _data.size());
        return _data[idx];
    }

    const_reference_type operator[](size_t idx) const {
        assert(idx < _data.size());
        return _data[idx];
    }

    iterator begin() { return _data.begin(); }
    const_iterator begin() const { return _data.begin(); }
    const_iterator cbegin() const { return _data.cbegin(); }
    iterator end() { return _data.end(); }
    const_iterator end() const { return _data.end(); }
    const_iterator cend() const { return _data.cend(); }
    size_type size() const { return _data.size(); }

    reference_type insert_at(size_type pos, const Component& component) {
        if (pos >= _data.size()) {
            _data.resize(pos + 1);
        }
        _data[pos] = component;
        return _data[pos];
    }

    reference_type insert_at(size_type pos, Component&& component) {
        if (pos >= _data.size()) {
            _data.resize(pos + 1);
        }
        _data[pos] = std::move(component);
        return _data[pos];
    }

    template <class... Params>
    reference_type emplace_at(size_type pos, Params&&... params) {
        if (pos >= _data.size()) {
            _data.resize(pos + 1);
        }
        _data[pos].emplace(std::forward<Params>(params)...);
        return _data[pos];
    }

    void erase(size_type pos) {
        if (pos < _data.size()) {
            _data[pos].reset();
        }
    }

    size_type get_index(const value_type& value) const {
        auto it = std::find(_data.begin(), _data.end(), value);
        if (it != _data.end()) {
            return std::distance(_data.begin(), it);
        }
        return _data.size();
    }

private:
    container_t _data;
};


#endif /* !CONTAINER_HPP_ */
