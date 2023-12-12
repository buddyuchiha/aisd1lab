#include <iostream>
#include <cstdlib>  // Библиотека была подключена для реализации рандомного заполнения множества

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
    Set(const T* values, int numValues) {
        elements = new T[numValues];
        for (int i = 0; i < numValues; i++) {
            elements[i] = values[i];
        }
        size = numValues;
    }
    Set(int numValues, const T& min, const T& max) {
        elements = new T[numValues];
        for (int i = 0; i < numValues; i++) {
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

    bool IsContained(const T& element) {
        for (int i = 0; i < size; i++) {
            if (elements[i] == element) {
                return true;
            }
        }
        return false;
    }

    void add(const T& element) {
        if (!IsContained(element)) {
            T* newElements = new T[size + 1];
            for (int i = 0; i < size; i++) {
                newElements[i] = elements[i];
            }
            newElements[size] = element;
            delete[] elements;
            elements = newElements;
            size++;
        }
    }

    void remove(const T& element) {
        if (IsContained(element)) {
            T* newElements = new T[size - 1];
            int index = 0;
            for (int i = 0; i < size; i++) {
                if (elements[i] != element) {
                    newElements[index] = elements[i];
                    index++;
                }
            }
            delete[] elements;
            elements = newElements;
            size--;
        }
    }

    void print() const {
        for (int i = 0; i < size; i++) {
            std::cout << elements[i] << " ";
        }
        std::cout << std::endl;
    }

    T& operator[](int index) {
        return elements[index];
    }
    Set operator+(const Set& otherSet) const {
        Set result(*this);
        for (int i = 0; i < otherSet.size; i++) {
            result.add(otherSet.elements[i]);
        }
        return result;
    }
    Set operator-(const Set& otherSet) const {
        Set result(*this);
        for (int i = 0; i < otherSet.size; i++) {
            result.remove(otherSet.elements[i]);
        }
        return result;
    }
    Set& operator+=(const T& element) {
        add(element);
        return *this;
    }
    Set& operator-=(const T& element) {
        remove(element);
        return *this;
    }
    Set operator&(const Set& other) const {
        Set result;
        for (int i = 0; i < size; i++) {
            if (other.IsContained(elements[i])) {
                result.add(elements[i]);
            }
        }
        return result;
    }
};

std::ostream& operator<<(std::ostream& os, const std::pair<int, double>& pair) {
    os << "(" << pair.first << ", " << pair.second << ")";
    return os;
}

int main() {
    Set<int> intSet;
    intSet.add(1);
    intSet.add(2);
    intSet.add(3);
    intSet.print();  
    intSet -= 2;
    intSet.print(); 
    Set<float> floatSet;
    floatSet.add(1.5f);
    floatSet.add(2.5f);
    floatSet.add(3.5f);
    floatSet.print();  
    floatSet += 4.5f;
    floatSet.print();  
    Set<std::string> stringSet;
    stringSet.add("Hello");
    stringSet.add("World");
    stringSet.add("!");
    stringSet.print();  
    stringSet -= "World";
    stringSet.print(); 
    Set<std::pair<int, double>> pairSet;
    pairSet.add(std::make_pair(1, 1.5));
    pairSet.add(std::make_pair(2, 2.5));
    pairSet.add(std::make_pair(3, 3.5));
    pairSet.print();  
    pairSet += std::make_pair(4, 4.5);
    pairSet.print();
    return 0;
}