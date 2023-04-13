// STL_vector.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include <iostream>
#include "list.h"

template<class T>
void ListPrintFromHead(my_stl::List<T>* list) {
	/*for (auto node = list->Head(); node != nullptr; node = node->next_) {
		std::cout << node->value_ << "\t";
	}
	std::cout << "size: " << list->Size() << std::endl;*/

	for (auto it = list->Begin(); it != list->End();it++) {
		std::cout << *it<< "\t";
	}
	std::cout << "size: " << list->Size() << std::endl;
}

template<class T>
void ListPrintFromTail(my_stl::List<T>* list) {
	for (auto node = list->Tail(); node != nullptr; node = node->before_) {
		std::cout << node->value_ << "\t";
	}
	std::cout << "size: " << list->Size() << std::endl;
}

void TestList() {
	my_stl::List<int> list;
	list.PushBack(3);
	list.PushFront(2);
	list.PushFront(1);
	list.PushBack(4);
	ListPrintFromHead<int>(&list);
	ListPrintFromTail<int>(&list);

	list.PopBack();
	list.PopFront();
	ListPrintFromHead<int>(&list);
	ListPrintFromTail<int>(&list);

}



int main() {
	TestList();

	return 0;
}
