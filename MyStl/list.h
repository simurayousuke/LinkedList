#ifndef MYSTL_LIST_H_
#define MYSTL_LIST_H_

#include <Iterator>
#include <stdexcept>
#include <functional>

namespace my_stl {

	template<class T>
	class List {
	private:
		struct Node {
			T value_;
			Node* prev_;
			Node* next_;
			Node(const T& value = T(), Node* prev = nullptr, Node* next = nullptr)
				: value_(value), prev_(prev), next_(next) {}
		};
		Node* head_;
		Node* tail_;
		int size_;
	public:
		class Iterator {
		private:
			Node* node_;
			friend typename List<T>::Iterator List<T>::Erase(Iterator position);
		public:
			Iterator(Node* node = nullptr) : node_(node) {}
			Iterator& operator++() { node_ = node_->next_; return *this; }
			Iterator operator++(int) { auto temp = *this; ++*this; return temp; }
			Iterator& operator--() { node_ = node_->prev_; return *this; }
			Iterator operator--(int) { auto temp = *this; --*this; return temp; }
			bool operator==(const Iterator& rhs) const { return node_ == rhs.node_; }
			bool operator!=(const Iterator& rhs) const { return node_ != rhs.node_; }
			T& operator*() { return node_->value_; }
		};

		List() : head_(nullptr), tail_(nullptr), size_(0) {}
		~List() { Clear(); }
		List(const List& rhs) : head_(nullptr), tail_(nullptr), size_(0) { *this = rhs; }
		List& operator=(const List& rhs);
		void PushBack(const T& val);
		void PushFront(const T& val);
		void PopBack();
		void PopFront();
		Iterator Erase(Iterator position);
		void Clear();
		bool Empty() const { return size_ == 0; }
		int Size() const { return size_; }
		void Sort(bool asc = true);
		void Sort(std::function<bool(const T&, const T&)> comp);
		void RemoveAll(T value);
		void RemoveFirst(T value);
		void RemoveLast(T value);

		Iterator Begin() { return Iterator(head_); }
		Iterator End() { return Iterator(nullptr); }
		Iterator RBegin() { return Iterator(tail_); }
		Iterator REnd() { return Iterator(nullptr); }
	};

	template <typename T>
	List<T>& List<T>::operator=(const List<T>& rhs) {
		Clear();
		for (auto it = rhs.Begin(); it != rhs.End(); ++it) {
			PushBack(*it);
		}
		return *this;
	}

	template <typename T>
	void List<T>::PushBack(const T& val) {
		Node* node = new Node(val, tail_, nullptr);
		if (tail_) {
			tail_->next_ = node;
		}
		else {
			head_ = node;
		}
		tail_ = node;
		++size_;
	}

	template <typename T>
	void List<T>::PushFront(const T& val) {
		Node* node = new Node(val, nullptr, head_);
		if (head_) {
			head_->prev_ = node;
		}
		else {
			tail_ = node;
		}
		head_ = node;
		++size_;
	}

	template <typename T>
	void List<T>::PopBack() {
		if (!tail_)
			return;

		Node* temp = tail_;
		tail_ = tail_->prev_;
		if (tail_) {
			tail_->next_ = nullptr;
		}
		else {
			head_ = nullptr;
		}
		delete temp;
		--size_;
	}

	template <typename T>
	void List<T>::PopFront() {
		if (!head_)
			return;

		Node* temp = head_;
		head_ = head_->next_;
		if (head_) {
			head_->prev_ = nullptr;
		}
		else {
			tail_ = nullptr;
		}
		delete temp;
		--size_;
	}

	template <typename T>
	typename List<T>::Iterator List<T>::Erase(Iterator position) {
		Node* node = position.node_;
		List<T>::Iterator ret(node->next_);

		if (node == head_) {
			PopFront();
		}
		else if (node == tail_) {
			PopBack();
		}
		else {
			node->prev_->next_ = node->next_;
			node->next_->prev_ = node->prev_;
			delete node;
			--size_;
		}

		return ret;
	}

	template <typename T>
	void List<T>::Clear() {
		while (head_) {
			Node* temp = head_;
			head_ = head_->next_;
			delete temp;
		}
		tail_ = nullptr;
		size_ = 0;
	}

	template <typename T>
	void List<T>::Sort(bool asc) {
		if (asc)
			Sort([](const T& lhs, const T& rhs) {return lhs < rhs; });
		else
			Sort([](const T& lhs, const T& rhs) {return lhs > rhs; });
	}

	template <typename T>
	void List<T>::Sort(std::function<bool(const T&, const T&)> comp) {
		if (size_ < 2) {
			return;
		}

		// ‘}“üƒ\[ƒg
		Node* i = head_->next_;
		while (i) {
			Node* j = i;
			while (j->prev_ && comp(j->value_, j->prev_->value_)) {
				std::swap(j->value_, j->prev_->value_);
				j = j->prev_;
			}
			i = i->next_;
		}
	}

	template <typename T>
	void List<T>::RemoveAll(T value) {
		for (auto it = Begin(); it != End(); ) {
			if (*it == value)
				it = Erase(it);
			else
				++it;
		}
	}

	template <typename T>
	void List<T>::RemoveFirst(T value) {
		for (auto it = Begin(); it != End(); ++it) {
			if (*it != value)
				continue;
			Erase(it);
			return;
		}
	}

	template <typename T>
	void List<T>::RemoveLast(T value) {
		for (auto it = RBegin(); it != REnd(); --it) {
			if (*it != value)
				continue;
			Erase(it);
			return;
		}
	}

}
#endif //MYSTL_LIST_H_