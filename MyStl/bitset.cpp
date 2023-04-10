#include "bitset.h"

namespace my_stl {

	Bitset::Bitset(unsigned long long val) {
		value_ = val;
	}

	size_t Bitset::Count() const noexcept {

		auto temp = value_;
		size_t count = 0;

		while (temp != 0) {

			// ��ԉE��1������Ă���
			temp &= (temp - 1);

			//�@1���S�������܂ŃJ�E���g����
			count++;
		}
		return count;
	}

	size_t Bitset::Size() const noexcept {

		return kSize;
	}

	bool Bitset::Test(size_t pos) const {

		if (pos >= kSize)
			throw std::out_of_range("Index should not be greater than the size of Bitset.");

		// �e�X�g�������Ƃ������Ԍ��Ɉړ����A�e�X�g����
		return (value_ >> (pos) & 1) != 0;
	}

	bool Bitset::All() const noexcept {

		// �����S����1�Ȃ�+1�����0�ɂȂ�;
		return (value_ + 1) == 0ull;
	}

	bool Bitset::Any() const noexcept {

		return (value_ | 0ull) != 0ull;
	}

	bool Bitset::None() const noexcept {
		return value_ == 0ull;
	}

	Bitset& Bitset::Flip() noexcept {

		value_ = ~value_;
		return *this;
	}

	Bitset& Bitset::Flip(size_t pos) {

		if (pos >= kSize)
			throw std::out_of_range("Index should not be greater than the size of Bitset.");

		if (Test(pos))
			value_ &= ~(1ull << pos);
		else
			value_ |= 1ull << pos;

		return *this;
	}

	Bitset Bitset::operator~() const noexcept {

		return Bitset(~value_);
	}

	Bitset Bitset::operator<<(size_t pos) const noexcept {

		return Bitset(value_ << pos);
	}

	Bitset Bitset::operator>>(size_t pos) const noexcept {

		return Bitset(value_ >> pos);
	}

	bool Bitset::operator[](size_t pos) const {

		if (pos >= kSize)
			throw std::out_of_range("Index should not be greater than the size of Bitset.");

		return Test(pos);
	}


	Bitset& Bitset::Set() noexcept {

		value_ = 0b11111111'11111111'11111111'11111111'11111111'11111111'11111111'11111111;
		return *this;
	}

	Bitset& Bitset::Set(size_t pos, bool val) {

		if (pos >= kSize)
			throw std::out_of_range("Index should not be greater than the size of Bitset.");

		if (Test(pos) == val)
			return *this;
		else if (val)
			value_ |= 1ull << pos;
		else
			value_ &= ~(1ull << pos);

		return *this;
	}

	Bitset& Bitset::Reset() noexcept {

		value_ = 0ull;

		return *this;
	}

	Bitset& Bitset::Reset(size_t pos) {

		if (pos >= kSize)
			throw std::out_of_range("Index should not be greater than the size of Bitset.");

		value_ &= ~(1ull << pos);

		return *this;
	}

	
	Bitset operator|(const Bitset& lhs, const Bitset& rhs) noexcept {
		return Bitset(lhs.GetValue() | rhs.GetValue());
	}

	Bitset operator&(const Bitset& lhs, const Bitset& rhs) noexcept {
		return Bitset(lhs.GetValue() & rhs.GetValue());
	}
	

	unsigned long long Bitset::GetValue() const noexcept {
		return value_;
	}

}