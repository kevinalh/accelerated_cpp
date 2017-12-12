#pragma once

#include <cstdio>
#include <memory>

namespace CustomContainers {

template <typename T>
class ListNode {
	T value;
public:
	ListNode<T>* next;
	ListNode() {
		value = T();
		next = nullptr;
	}
	ListNode(const T& val): value(val) {
		next = nullptr;
	}
	ListNode(const ListNode& from) {
		value = T(from.value);
		next = nullptr;
	}
	~ListNode() {
		delete &value;
	}
	ListNode& operator=(const ListNode& node) {
		value = node.value;
		return *this;
	}
	void set_next(ListNode& following) {
		this->next = &following;
	}
	T& operator *() {
		return value;
	}
	bool operator==(const ListNode& another) const {
		return &another == this;
	}
};

template <typename T>
class ListIterator {
public:
	ListIterator(): pointer(nullptr) {};
	ListIterator(ListNode<T>* node) {
		pointer = node;
	};
	bool operator==(const ListIterator& another) const {
		return another.pointer == pointer;
	}
	bool operator!=(const ListIterator& another) const {
		return !(*this == another);
	}
	ListIterator& operator++() {
		pointer = pointer->next;
		return *this;
	}
	ListIterator operator++(int) {
		ListIterator current = *this;
		++(*this);
		return current;
	}
	ListNode<T>& pointingNode() {
		return *pointer;
	}
	T& operator*() {
		return *(*pointer);
	}
private:
	ListNode<T>* pointer;
};

template <typename T>
class List {
public:
	List(): first(nullptr), last(nullptr), nelements(0) {};

	typedef T value_type;
	typedef ListIterator<T> iterator;
	typedef std::size_t size_type;

	iterator begin() {
		return ListIterator<T>(first);
	}
	iterator end() {
		return ListIterator<T>();
	}

	void push_back(const T& val) {
		ListNode<T>* node = new ListNode<T>(val);
		if(first == nullptr) {
			first = node;
			last = node;
		} else {
			last->next = node;
			last = node;
		}
		nelements++;
	}

	iterator insert(iterator pos, const T& val) {
		ListNode<T>* node = new ListNode<T>(val);
		(*node).set_next(*(pos.pointingNode().next));
		pos.pointingNode().set_next(*node);
		if(pos == last) last = node;
		return pos;
	}

	size_type size() {
		return nelements;
	}

private:
	ListNode<T>* first;
	ListNode<T>* last;
	size_type nelements;
};

}
