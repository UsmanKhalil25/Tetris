#ifndef vector_hpp
#define vector_hpp

#include <memory>
#include <stdexcept>
#include <iterator>
#include <limits>
#include <algorithm>

template<class T, class Allocator = std::allocator<T>>
class MyVector {
public:
    typedef T value_type;
    typedef Allocator allocator_type;
    typedef size_t size_type;
    typedef std::ptrdiff_t difference_type;
    typedef T& reference;
    typedef const T& const_reference;
    typedef T* pointer;
    typedef const T* const_pointer;
    typedef T* iterator;
    typedef const T* const_iterator;
    typedef std::reverse_iterator<iterator> reverse_iterator;
    typedef std::reverse_iterator<const_iterator> const_reverse_iterator;

    MyVector() : _size(0), _capacity(0) {
        _data = _allocator.allocate(_capacity);
    }

    MyVector(size_type count, const T& value = T()) : _size(count), _capacity(calculateGrowth(count)) {
        _data = _allocator.allocate(_capacity);
        std::fill_n(_data, count, value);
    }

    MyVector(iterator first, iterator last) {
        _size = last - first;
        _capacity = last - first;
        _data = _allocator.allocate(_capacity);

        std::copy(first, last, _data);
    }

    MyVector(const MyVector& other) {
        _size = other.size();
        _capacity = other.capacity();
        _data = _allocator.allocate(_capacity);

        std::copy(other.begin(), other.end(), _data);
    }

    MyVector(MyVector&& other) {
        _size = other.size();
        _capacity = other.capacity();

        _data = _allocator.allocate(_capacity);
        std::move(other.begin(), other.end(), _data);

        other.clear();
    }

    MyVector(std::initializer_list<T> init) {
        _size = init.size();
        _capacity = calculateGrowth(_size);
        _data = _allocator.allocate(_capacity);

        std::copy(init.begin(), init.end(), _data);
    }

    ~MyVector() {}

    MyVector& operator=(const MyVector& other) {
        _size = other.size();
        _capacity = other.capacity();
        _data = _allocator.allocate(_capacity);

        std::copy(other.begin(), other.end(), _data);
        return *this;
    }

    void assign(size_t count, const T& value) {
        clear();

        if (count > capacity()) {
            reallocate(count);
        }

        for (int i = 0; i < count; i++) {
            _data[i] = value;
        }

        _size = count;
    }

    allocator_type get_allocator() const {
        return _allocator;
    }

    void assign(iterator first, iterator last) {
        clear();

        const difference_type count = last - first;

        if (count > capacity()) {
            reallocate(count);
        }

        std::copy(first, last, _data);

        _size = count;
    }

    reference at(size_type pos) {
        if (pos < size() && pos >= 0) {
            return _data[pos];
        }

        throw std::out_of_range("position is out of range");
    }

    const_reference at(size_type pos) const {
        if (pos < size() && pos >= 0) {
            return _data[pos];
        }

        throw std::out_of_range("position is out of range");
    }

    reference operator[](size_type pos) {
        return _data[pos];
    }

    const_reference operator[](size_type pos) const {
        return _data[pos];
    }

    reference front() {
        return _data[0];
    }

    const_reference front() const {
        return _data[0];
    }

    reference back() {
        return _data[size() - 1];
    }

    const_reference back() const {
        return _data[size() - 1];
    }

    T* data() noexcept {
        return _data;
    }

    const T* data() const noexcept {
        return _data;
    }

    iterator begin() noexcept {
        return _data;
    }

    const_iterator begin() const noexcept {
        return _data;
    }

    const_iterator cbegin() const noexcept {
        return begin();
    }

    iterator end() noexcept {
        return begin() + _size;
    }

    const_iterator end() const noexcept {
        return begin() + _size;
    }

    const_iterator cend() const noexcept {
        return end();
    }

    reverse_iterator rbegin() noexcept {
        return reverse_iterator(_data + _size);
    }

    const_reverse_iterator rbegin() const noexcept {
        return rbegin();
    }

    reverse_iterator rend() noexcept {
        return reverse_iterator(_data);
    }

    const_reverse_iterator rend() const noexcept {
        return rend();
    }

    bool empty() const {
        return size() == 0;
    }

    size_type size() const {
        return _size;
    }

    size_type max_size() const {
        return std::numeric_limits<size_type>::max();
    }

    void reserve(size_type new_cap) {
        if (new_cap > max_size()) {
            throw new std::length_error("capacity cannot be larger than max size");
        }

        if (new_cap > capacity()) {
            reallocate(capacity() + new_cap);
        }

        _capacity = new_cap;
    }

    size_type capacity() const {
        return _capacity;
    }

    void shrink_to_fit() {
        for (auto i = size(); i < capacity(); i++) {
            _allocator.destroy(data() + i);
        }
        _capacity = size();
    }

    void clear() {
        for (size_type i = 0; i < size(); i++) {
            _allocator.destroy(data() + i);
        }

        _size = 0;
    }

    iterator insert(const_iterator pos, const T& value) {
        return insert(pos, 1, value);
    }

    iterator insert(const_iterator pos, T&& value) {
        difference_type index = pos - begin();

        if (index < 0 || index > size()) {
            throw new std::out_of_range("Insert index is out of range");
        }

        if (size() == capacity()) {
            reallocate(capacity() + 1);
        }

        iterator it = &_data[index];

        std::move(it, end(), it + 1);
        *it = std::move(value);

        _size++;

        return it;
    }

    iterator insert(const_iterator pos, size_type count, const T& value) {
        const difference_type index = pos - begin();

        if (index < 0 || index > size()) {
            throw new std::out_of_range("Insert index is out of range");
        }

        if (size() + count > capacity()) {
            reallocate(capacity() + count);
        }

        iterator it = &_data[index];

        std::move(it, end(), it + count);
        std::fill_n(it, count, value);

        _size += count;

        return it;
    }

    iterator insert(const_iterator pos, iterator first, iterator last) {
        const difference_type count = last - first;
        const difference_type index = pos - begin();

        if (size() + count > capacity()) {
            reallocate(capacity() + count);
        }

        iterator it = &_data[index];
        std::move(it, end(), it + count);
        std::copy(first, last, it);

        _size += count;

        return it;
    }

    iterator insert(const_iterator pos, std::initializer_list<T> ilist) {
        const difference_type count = ilist.size();
        const difference_type index = pos - begin();

        if (size() + count > capacity()) {
            reallocate(capacity() + count);
        }

        iterator it = &_data[index];
        std::move(it, end(), it + count);
        std::copy(ilist.begin(), ilist.end(), it);

        _size += count;

        return it;
    }

    template< class... Args >
    iterator emplace(const_iterator pos, Args&&... args) {
        const difference_type index = pos - begin();

        if (index < 0 || index > size()) {
            throw new std::out_of_range("Insert index is out of range");
        }

        if (size() == capacity()) {
            reallocate(capacity() + 1);
        }

        iterator it = &_data[index];

        std::move(it, end(), it + 1);
        _allocator.construct(it, args...);

        _size++;

        return it;
    }

    iterator erase(const_iterator pos) {
        const difference_type index = pos - begin();
        _allocator.destroy(&_data[index]);

        for (auto i = index; i < size() - 1; i++) {
            _allocator.destroy(&_data[i + 1]);
            _allocator.construct(&_data[i], _data[i + 1]);
        }

        _size--;
        iterator it = &_data[index];

        return it;
    }

    iterator erase(const_iterator first, const_iterator last) {
        const difference_type startIndex = first - begin();
        const difference_type endIndex = last - begin();

        for (difference_type i = 0; i < endIndex - startIndex; i++) {
            _allocator.destroy(&_data[startIndex + i]);
            _allocator.construct(&_data[startIndex + i], _data[endIndex + i]);
        }

        _size -= endIndex - startIndex;
        iterator it = &_data[startIndex];

        return it;
    }

    void push_back(const T& item) {
        if (size() == capacity()) {
            reallocate(capacity() + 1);
        }
        _allocator.construct(end(), item);
        ++_size;
    }

    void push_back(T&& value) {
        if (size() == capacity()) {
            reallocate(capacity() + 1);
        }

        _allocator.construct(end(), std::move(value));
        ++_size;
    }

    template< class... Args >
    void emplace_back(Args&&... args) {
        emplace(end(), std::forward<Args>(args)...);
    }

    void pop_back() {
        _allocator.destroy(end() - 1);
        --_size;
    }

    void resize(size_type count) {
        resize(count, T());
    }

    void resize(size_type count, const value_type& value) {
        if (count > capacity()) {
            reallocate(count);
            for (size_type i = size(); i < count; i++) {
                _allocator.construct(data() + i, value);
            }
        }
        else if (count < size()) {
            for (size_type i = count; i < size(); i++) {
                _allocator.destroy(data() + i);
            }
        }

        _size = count;
    }

    void swap(MyVector& other) {
        std::swap(_size, other._size);
        std::swap(_capacity, other._capacity);
        std::swap(_allocator, other._allocator);
        std::swap(_data, other._data);
    }
private:
    size_type _size = 0;
    size_type _capacity = 0;
    T* _data;
    Allocator _allocator;

    size_type calculateGrowth(size_type newSize) const {
        if (capacity() > max_size() - capacity() / 2) {
            return newSize;
        }

        const size_type geometric = capacity() * 1.5;

        if (geometric < newSize) {
            return newSize;
        }

        return geometric;
    }

    void reallocate(size_type minSize) {
        const size_type newCapacity = calculateGrowth(minSize);

        T* newData = _allocator.allocate(newCapacity);
        for (size_type i = 0; i < _size; i++) {
            _allocator.construct(&newData[i], std::move(_data[i]));
            _allocator.destroy(&_data[i]);
        }
        _allocator.deallocate(_data, capacity());

        _data = newData;
        _capacity = newCapacity;
    }
};

template< class T, class Alloc>
bool operator==(const MyVector<T, Alloc>& lhs, const MyVector<T, Alloc>& rhs) {
    if (lhs.size() != rhs.size()) {
        return false;
    }

    for (int i = 0; i < lhs.size(); i++) {
        if (lhs.at(i) != rhs.at(i)) {
            return false;
        }
    }

    return true;
}

template< class T, class Alloc>
bool operator!=(const MyVector<T, Alloc>& lhs, const MyVector<T, Alloc>& rhs) {
    return !(lhs == rhs);
}

template< class T, class Alloc>
bool operator<(const MyVector<T, Alloc>& lhs, const MyVector<T, Alloc>& rhs) {
    return std::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
}

template< class T, class Alloc>
bool operator>(const MyVector<T, Alloc>& lhs, const MyVector<T, Alloc>& rhs) {
    return rhs < lhs;
}

template< class T, class Alloc>
bool operator<=(const MyVector<T, Alloc>& lhs, const MyVector<T, Alloc>& rhs) {
    return !(rhs < lhs);\
}

template< class T, class Alloc>
bool operator>=(const MyVector<T, Alloc>& lhs, const MyVector<T, Alloc>& rhs) {
    return !(lhs < rhs);
}

#endif /* vector_hpp */