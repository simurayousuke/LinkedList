// STL_vector.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include <iostream>
#include "list.h"

template<class T>
void ListPrintFromHead(my_stl::List<T>* list) {
	std::cout << "Forward Print (size: " << list->Size() <<" ):"<< std::endl;
	for (auto it = list->Begin(); it != list->End();++it) {
		std::cout << *it<< "\t";
	}
	std::cout << std::endl << std::endl;
}

template<class T>
void ListPrintFromTail(my_stl::List<T>* list) {

	std::cout << "Reverse Print (size: " << list->Size() << " ):" << std::endl;
	for (auto it = list->RBegin(); it != list->REnd(); --it) {
		std::cout << *it << "\t";
	}
	std::cout << std::endl << std::endl;
}

void TestList() {
	my_stl::List<int> list;
	list.PushBack(3);
	list.PushFront(2);
	list.PushFront(1);
	list.PushBack(4);
	list.PushFront(7);
	list.PushFront(0);
	list.PushFront(9);
	list.PushBack(-1);
	list.PushBack(2);
	list.PushFront(0);
	list.PushBack(9);
	list.PushBack(-1);
	list.PushBack(-1);
	list.PushFront(-1);
	ListPrintFromHead<int>(&list);

	std::cout << "Removing first -1, last -1, all 9..." << std::endl << std::endl;
	list.RemoveFirst(-1);
	list.RemoveLast(-1);
	list.RemoveAll(9);
	ListPrintFromHead<int>(&list);


	std::cout << "Popping back and front..." << std::endl << std::endl;
	list.PopBack();
	list.PopFront();
	ListPrintFromHead<int>(&list);

	std::cout << "Calling Sort()" << std::endl << std::endl;
	list.Sort();
	ListPrintFromHead<int>(&list);

	std::cout << "Calling Sort([](const T& lhs, const T& rhs) {return lhs > rhs; });" << std::endl << std::endl;
	list.Sort([](const int& lhs, const int& rhs) {return lhs > rhs; });
	ListPrintFromHead<int>(&list);
}



int main() {
	TestList();

	return 0;
}
