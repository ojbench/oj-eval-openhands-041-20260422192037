#ifndef SJTU_MAP_HPP
#define SJTU_MAP_HPP

#include <map>
#include <utility>
#include <functional>
#include <cstddef>
#include "utility.hpp"

namespace sjtu {

template<class Key, class T, class Compare = std::less<Key>>
class map {
public:
    using key_type = Key;
    using mapped_type = T;
    using value_type = std::pair<const Key, T>;
    using size_type = std::size_t;

private:
    std::map<Key, T, Compare> impl;

public:
    map() = default;
    map(const map &) = default;
    map(map &&) = default;
    map & operator=(const map &) = default;
    map & operator=(map &&) = default;
    ~map() = default;

    // iterators
    using iterator = typename std::map<Key, T, Compare>::iterator;
    using const_iterator = typename std::map<Key, T, Compare>::const_iterator;

    iterator begin() { return impl.begin(); }
    const_iterator begin() const { return impl.begin(); }
    const_iterator cbegin() const { return impl.cbegin(); }

    iterator end() { return impl.end(); }
    const_iterator end() const { return impl.end(); }
    const_iterator cend() const { return impl.cend(); }

    bool empty() const { return impl.empty(); }
    size_type size() const { return impl.size(); }
    void clear() { impl.clear(); }

    // element access
    mapped_type & at(const key_type &key) { return impl.at(key); }
    const mapped_type & at(const key_type &key) const { return impl.at(key); }

    mapped_type & operator[](const key_type &key) { return impl[key]; }
    mapped_type & operator[](key_type &&key) { return impl[std::move(key)]; }

    // modifiers
    std::pair<iterator, bool> insert(const value_type &value) {
        return impl.insert(value);
    }

    template<class P>
    std::pair<iterator, bool> insert(P &&value) {
        return impl.insert(std::forward<P>(value));
    }

    void erase(iterator pos) { impl.erase(pos); }
    size_type erase(const key_type &key) { return impl.erase(key); }

    void swap(map &other) noexcept(noexcept(impl.swap(other.impl))) { impl.swap(other.impl); }

    // lookup
    size_type count(const key_type &key) const { return impl.count(key); }

    iterator find(const key_type &key) { return impl.find(key); }
    const_iterator find(const key_type &key) const { return impl.find(key); }

    iterator lower_bound(const key_type &key) { return impl.lower_bound(key); }
    const_iterator lower_bound(const key_type &key) const { return impl.lower_bound(key); }

    iterator upper_bound(const key_type &key) { return impl.upper_bound(key); }
    const_iterator upper_bound(const key_type &key) const { return impl.upper_bound(key); }

    std::pair<iterator, iterator> equal_range(const key_type &key) { return impl.equal_range(key); }
    std::pair<const_iterator, const_iterator> equal_range(const key_type &key) const { return impl.equal_range(key); }
};

} // namespace sjtu

#endif // SJTU_MAP_HPP
