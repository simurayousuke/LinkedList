#ifndef MYSTL_BITSET_H_
#define MYSTL_BITSET_H_

#include <stdexcept>

namespace my_stl {

	// https://cpprefjp.github.io/reference/bitset/bitset.html
	class Bitset {
	public:
		Bitset(unsigned long long val);
		size_t Count() const noexcept;
		size_t Size() const noexcept;
		bool Test(size_t pos) const;
		bool All() const noexcept;
		bool Any() const noexcept;
		bool None() const noexcept;
		Bitset& Flip() noexcept;
		Bitset& Flip(size_t pos);
		Bitset operator~() const noexcept;
		Bitset operator<<(size_t pos) const noexcept;
		Bitset operator>>(size_t pos) const noexcept;
		bool operator[](size_t pos) const;
		Bitset& Set() noexcept;
		Bitset& Set(size_t pos, bool val = true);
		Bitset& Reset() noexcept;
		Bitset& Reset(size_t pos);
		unsigned long long GetValue() const noexcept;
	private:
		unsigned long long value_;
		const size_t kSize = 64; // 課題ではテンプレートを使わず、64bit固定のため
	};

	Bitset operator|(const Bitset& lhs, const Bitset& rhs) noexcept;
	Bitset operator&(const Bitset& lhs, const Bitset& rhs) noexcept;
}
#endif //MYSTL_BITSET_H_