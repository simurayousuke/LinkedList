// STL_vector.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include <iostream>
#include "bitset.h"
#include <bitset>

void TestBitset(unsigned long long val) {
	my_stl::Bitset bitset(val);
	std::cout << " value_ : " << std::bitset<64>(val) << std::endl;

	std::cout << "Count(): " << bitset.Count() << "\t";
	std::cout << "Test(0): " << bitset.Test(0) << "\t";
	std::cout << "Test(62): " << bitset.Test(62) << "\t";
	std::cout << "[0]: " << bitset[0] << "\t";
	std::cout << "[62]: " << bitset[62] << std::endl;

	std::cout << "All(): " << bitset.All() << "\t";
	std::cout << "Any(): " << bitset.Any() << "\t";
	std::cout << "None(): " << bitset.None() << "\t";
	std::cout << std::endl;

	std::cout << "  << 1  : " << std::bitset<64>((bitset << 1).GetValue()) << std::endl;
	std::cout << "  << 62 : " << std::bitset<64>((bitset << 62).GetValue()) << std::endl;
	std::cout << "  >> 1  : " << std::bitset<64>((bitset >> 1).GetValue()) << std::endl;
	std::cout << "  >> 62 : " << std::bitset<64>((bitset >> 62).GetValue()) << std::endl;

	std::cout << "Flip( 0): " << std::bitset<64>(bitset.Flip(0).GetValue()) << std::endl;
	std::cout << "Flip(62): " << std::bitset<64>(bitset.Flip(62).GetValue()) << std::endl;
	std::cout << "Flip(  ): " << std::bitset<64>(bitset.Flip().GetValue()) << std::endl;
	std::cout << "~(新obj): " << std::bitset<64>((~bitset).GetValue()) << std::endl;

	std::cout << "Set(0,1): " << std::bitset<64>(bitset.Set(0, 1).GetValue()) << std::endl;
	std::cout << "Set(0,0): " << std::bitset<64>(bitset.Set(0, 0).GetValue()) << std::endl;
	std::cout << "Reset(1): " << std::bitset<64>(bitset.Reset(1).GetValue()) << std::endl;
	std::cout << " Set () : " << std::bitset<64>(bitset.Set().GetValue()) << std::endl;
	std::cout << "Reset() : " << std::bitset<64>(bitset.Reset().GetValue()) << std::endl;

	std::cout << std::endl << std::endl << std::endl;
}

void TestBitset2(unsigned long long val1, unsigned long long val2) {

	my_stl::Bitset set1(val1), set2(val2);

	std::cout << " value1 : " << std::bitset<64>(val1) << std::endl;
	std::cout << " value2 : " << std::bitset<64>(val2) << std::endl;

	std::cout << "    &   : " << std::bitset<64>((set1&set2).GetValue()) << std::endl;
	std::cout << "    |   : " << std::bitset<64>((set1 | set2).GetValue()) << std::endl;
}

int main() {

	unsigned long long values[] = {
		0b10101001'10101001'10101001'10101001'10101001'10101001'10101001'10101001,
		0b11111111'11111111'11111111'11111111'11111111'11111111'11111111'11111111,
		0b11111111'11111111'11111111'11111111'11111111'11111111'11111111'11111110,
		0
	};

	for (const auto& value : values)
		TestBitset(value);

	TestBitset2(0b10101001, 0b01010101);

	return 0;
}
