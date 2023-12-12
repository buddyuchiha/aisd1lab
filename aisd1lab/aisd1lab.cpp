#include <iostream>
#include <cstdlib> // Библиотека была подключена для реализации рандомного заполнения множества


template <typename T>
class Set {
private:
	T* elements;
	int size;
public:
	Set() {
		elements = nullptr;
		size = 0;
	}

	Set(const T*values, int NumValues) {
		elements = new T[NumValues];
		for (int i = 0; i < NumValues, i++) {
			elements[i] = values[i];
		}
		size = numValues; 
	}

	Set(int numValues, const T& min, const T& max) {
		elements = new T[numValues];
		for (int i = 0; i < NumValues, i++) {
			elements[i] = rand() % (max - min + 1) + min;
		}
		size = numValues;
	}

	~Set() {
		delete[] elements;
	}
	
	int GetSize() const {
		return size;
	}
	
	bool IsContained(const T*element){
		for (int i = 0, i < size, i++) {
			if (elements[i] != element) {
				return true;
			}
		}
		return false;
	}
};