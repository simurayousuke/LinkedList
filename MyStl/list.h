#ifndef MYSTL_LIST_H_
#define MYSTL_LIST_H_

#include <Iterator>
#include <stdexcept>

namespace my_stl {

	template<class T>
	struct ListNode {
		T value_;
		ListNode<T>* before_ = nullptr;
		ListNode<T>* next_ = nullptr;
		ListNode(T value, ListNode<T>* before = nullptr, ListNode<T>* next = nullptr) :value_(value), before_(before), next_(next) {}
	};

	template<class T>
	class ListIterator :public std::iterator< std::forward_iterator_tag, T> {
	private:
		ListNode<T>* current_node_;
	public:
		ListIterator(ListNode<T>* node) :current_node_(node) {}
		T& operator*() const { return current_node_->value_; }

		// prefix
		ListIterator& operator++() {
			if (current_node_->next_ == nullptr)
				throw std::out_of_range("Out of range.");
			current_node_ = current_node_->next_;
			return *this;
		}

		// postfix
		ListIterator operator++(int) {
			auto temp = *this;
			++*this;
			return  temp;
		}

		/*ListIterator& operator--() {
			if (current_node_->before_ == nullptr)
				throw std::out_of_range("Out of range.");
			current_node_ = current_node_->before_;
			return *this;
		}

		ListIterator operator--(int) {
			auto temp = *this;
			--*this;
			return  temp;
		}*/

		bool operator==(const ListIterator& other)const { return current_node_->value_ == other.current_node_->value_; }
		bool operator!=(const ListIterator& other)const { return current_node_->value_ != other.current_node_->value_; }
	};

	template<class T>
	class List {
	private:
		ListNode<T>* begin_ = nullptr;
		ListNode<T>* end_ = nullptr;
		int size_ = 0;
	public:
		List() = default;
		List(T&& value);
		void PushFront(T&& value);
		void PushBack(T&& value);
		void PopFront();
		void PopBack();
		//void Erase(Iterator it);
		//void Clear();
		bool Empty() { return size_ == 0; }
		int Size() { return size_; }
		void Sort();
	public:
		typedef ListIterator<T> Iterator;
		auto Head() { return begin_; }
		auto Tail() { return end_; }
		Iterator Begin() { return Iterator(begin_); }
		Iterator End() { return Iterator(end_); }
	};

	template<class T>
	List<T>::List(T&& value) {
		auto node = new ListNode(value);
		begin_ = node;
		end_ = node;
		size_++;
	}

	template<class T>
	void List<T>::PushFront(T&& value) {
		ListNode<T>* node = new ListNode<T>(value, nullptr, begin_);
		if (begin_ != nullptr)
			begin_->before_ = node;

		begin_ = node;
		if (end_ == nullptr)
			end_ = node;

		size_++;
	}

	template<class T>
	void List<T>::PushBack(T&& value) {
		ListNode<T>* node = new ListNode<T>(value, end_, nullptr);
		if (end_ != nullptr)
			end_->next_ = node;

		end_ = node;
		if (begin_ == nullptr)
			begin_ = node;

		size_++;
	}

	template<class T>
	void List<T>::PopFront() {
		if (begin_ == nullptr)
			return;

		auto second = begin_->next_;
		second->before_ = nullptr;
		delete begin_;
		begin_ = second;

		size_--;
	}

	template<class T>
	void List<T>::PopBack() {
		if (end_ == nullptr)
			return;

		auto second = end_->before_;
		second->next_ = nullptr;
		delete end_;
		end_ = second;

		size_--;
	}

	template<class T>
	void List<T>::Sort() {

	}

}
#endif //MYSTL_LIST_H_