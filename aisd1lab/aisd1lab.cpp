#include <iostream>


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