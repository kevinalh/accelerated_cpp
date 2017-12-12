#pragma once

#include <cstdlib>
#include <memory>
#include <stdexcept>

namespace CustomContainers {
template <typename T>
class Vec {
public:
	// Types defined for this class
	typedef T* iterator;
	typedef const T* const_iterator;
	typedef std::size_t size_type;
	typedef T value_type;

	// Constructors / Destructors
	Vec() {
		create();
	}
	explicit Vec(size_type n, const T& val = T()) {
		create(n, val);
	}
	Vec(const Vec& v) {
		create(v.begin(), v.end());
	}
	~Vec() {
		uncreate();
	}
	Vec& operator=(const Vec&);

	size_type size() const {
		return avail - data;
	}

	// Index operators (overloaded)
	T& operator[](size_type i) {
		return data[i];
	}
	const T& operator[](size_type i) const {
		return data[i];
	}
	// Iterator functions
	iterator begin() {
		return data;
	}
	const_iterator begin() const {
		return data;
	}
	iterator end() {
		return avail;
	}
	const_iterator end() const {
		return avail;
	}

	void push_back(const T& val) {
		if(avail == limit) {
			grow();
		}
		unchecked_append(val);
	}

	iterator erase(iterator element) {
		iterator rt = element;
		if(element < data || element >= avail) {
			throw std::out_of_range("Out of bounds Vec iterator");
		}
		iterator next = element + 1;
		alloc.destroy(element);
		while(next != limit) {
			alloc.construct(element, *next);
			element = next++;
		}
		alloc.destroy(element);
		avail--;
		return rt;
	}

	void clear() {
		iterator it = avail;
		while(it != data) {
			alloc.destroy(--it);
		}
		avail = 0;
	}

private:
	iterator data;
	iterator avail;
	iterator limit;

	void create();
	void create(size_type n, const T& val);
	void create(const_iterator, const_iterator);
	void uncreate();

	void grow();
	void unchecked_append(const T& val);

	// For handling memory allocation
	std::allocator<T> alloc;
};

template <typename T>
Vec<T>& Vec<T>::operator=(const Vec& rhs) {
	if(&rhs != this) {
		uncreate();
		create(rhs.begin(), rhs.end());
	}
	return *this;
}

template <typename T>
void Vec<T>::create() {
	data = avail = limit = 0;
}

template <typename T>
void Vec<T>::create(size_type n, const T& val) {
	data = alloc.allocate(n);
	limit = avail = data + n;
	std::uninitialized_fill(data, limit, val);
}

template <typename T>
void Vec<T>::create(const_iterator i, const_iterator j) {
	data = alloc.allocate(j-i);
	limit = avail = std::uninitialized_copy(i, j, data);
}

template <typename T>
void Vec<T>::uncreate() {
	if(data) {
		iterator it = avail;
		while(it != data) {
			alloc.destroy(--it);
		}
		alloc.deallocate(data, limit-data);
	}
	data=limit=avail=0;
}

template <typename T>
void Vec<T>::grow() {
	size_type new_size = std::max(2*(limit-data), std::ptrdiff_t(1));
	iterator new_data = alloc.allocate(new_size);
	iterator new_avail = std::uninitialized_copy(data, avail, new_data);
	uncreate();
	data = new_data;
	avail = new_avail;
	limit = data + new_size;
}

template <typename T>
void Vec<T>::unchecked_append(const T& val) {
	alloc.construct(avail++, val);
}
}
