#pragma once
#include <iostream>
#include <string>
#include <cstdlib>  // Библиотека была подключена для реализации рандомного заполнения множества
using namespace std;

namespace mainset {
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
        bool IsContained(const T& element) const {
            for (int i = 0; i < size; i++) {
                if (elements[i] == element) {
                    return true;
                }
            }
            return false;
        }
        void AddElement(const T& element) {
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
        void RemoveElement(const T& element) {
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
        void PrintSet() const {
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
                result.AddElement(otherSet.elements[i]);
            }
            return result;
        }
        Set operator-(const Set& otherSet) const {
            Set result(*this);
            for (int i = 0; i < otherSet.size; i++) {
                result.RemoveElement(otherSet.elements[i]);
            }
            return result;
        }
        Set& operator+=(const T& element) {
            AddElement(element);
            return *this;
        }
        Set& operator-=(const T& element) {
            RemoveElement(element);
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

        template <typename U>
        Set<U> FindUniqueElements(Set<U>& other) { // Для 2 входящих массивов чисел найти все элементы, которое встречаются только в одном из массивов, но не в обоих сразу.	
            Set result;
            for (int i = 0; i < size; i++) {
                if (!other.IsContained(elements[i])) {
                    result.AddElement(elements[i]);
                }
            }
            for (int i = 0; i < other.size; i++) {
                if (!IsContained(other.elements[i])) {
                    result.AddElement(other.elements[i]);
                }
            }
            return result;
        }

        template <typename U>
        Set<U> AllElementsInSet(Set<U>& other) { // Для 2 входящих массивов чисел проверить, что все элементы первого массива хотя бы раз встречаются во втором. 	
            Set result;
            int mainsize;
            if (size > other.size) {
                mainsize = size;
            }
            else {
                mainsize = other.size;
            }
            for (int i = 0; i < mainsize; i++) {
                if (other.IsContained(elements[i]))
                    result.AddElement(elements[i]);
            }
            return result;
        }

        Set<T> RepeatElementsInSet() const { // В заданном массиве найти все повторяющиеся числа.
            Set result;
            for (int i = 0; i < size; i++) {
                for (int j = i + 1; j < size; j++) {
                    if (elements[i] == elements[j]) {
                        result.AddElement(elements[i]);
                    }
                }
            }
            return result;
        }

        bool IsSubset(const Set& other) const {
            for (int i = 0; i < size; i++) {
                if (!other.IsContained(elements[i])) {
                    return false;
                }
            }
            return true;
        }
        bool IsSuperset(const Set& other) const {
            return other.IsSubset(*this);
        }

    };

    std::ostream& operator<<(std::ostream& os, const std::pair<int, double>& pair) {
        os << "(" << pair.first << ", " << pair.second << ")";
        return os;
    }
}

