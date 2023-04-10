#ifndef MYSTL_VECTOR_H_
#define MYSTL_VECTOR_H_

namespace my_stl {

	template<class T>
	class Vector {
	public:
		Vector(void);
		~Vector(void);
		void Add(T value);
		void Remove(T value);
		void RemoveAt(int index);
		T Get(int index);
		void Clear(void);
		void Print(void);
	private:
		const int kInitialMaxCount = 4;
		int max_count_;
		int current_count_;
		T *array_;
		void DoubleSize(void);
	};

	template<class T> Vector<T>::Vector(void)
	{
		array_ = new T[kInitialMaxCount]{ 0 };
		max_count_ = kInitialMaxCount;
		current_count_ = 0;
	}

	template<class T> Vector<T>::~Vector(void)
	{
		delete[] array_;
	}

	template<class T> void Vector<T>::Add(T value)
	{
		if (current_count_ >= max_count_)
		{
			DoubleSize();
		}
		array_[current_count_++] = value;
	}

	template<class T> void Vector<T>::Remove(T value)
	{
		for (int i = 0; i < current_count_; ++i)
		{
			if (array_[i] == value)
			{
				RemoveAt(i);
				return;
			}
		}
	}

	template<class T> void Vector<T>::RemoveAt(int index)
	{
		for (int i = index + 1; i < current_count_; i++)
		{
			array_[i - 1] = array_[i];
		}
		current_count_--;
	}

	template<class T> T Vector<T>::Get(int index)
	{
		return array_[index];
	}

	template<class T> void Vector<T>::Clear(void)
	{
		delete[] array_;
		array_ = new T[kInitialMaxCount]{ 0 };
		max_count_ = kInitialMaxCount;
		current_count_ = 0;
	}

	template<class T> void Vector<T>::DoubleSize(void)
	{
		int new_max_count = max_count_ * 2;
		T *temp = new T[new_max_count];
		std::memcpy(temp, array_, sizeof(T)*current_count_);
		delete[] array_;
		array_ = temp;
		max_count_ = new_max_count;
	}

	template<class T> void Vector<T>::Print(void)
	{
		//std::cout << "Start print..." << std::endl;
		std::cout << "current count: " << current_count_ << " max count: " << max_count_ << std::endl;
		for (int i = 0; i < current_count_; ++i)
		{
			std::cout << array_[i] << ",";
		}
		std::cout << "\b \b" << std::endl << std::endl;
	}

}
#endif //MYSTL_VECTOR_H_