#include <iostream>
#include <string>
#include "..\mymainset\mainset.h"
using namespace std;
using namespace mainset;

int main() {
	
	int iarray1[] = { 1, 2, 3, 7, 8, 9}; //6
	int iarray2[] = { 4, 5, 6, 7, 8}; //5
	int iarray3[] = { 1, 2, 3, 4, 5}; //5
	int iarray4[] = { 1, 2, 3, 4, 5, 6, 7}; //7
	float farray1[] = { 1.12, 2.12, 1.45, 5.76, 2.33, 2.33, 9.875 };//7
	float farray2[] = { 1.34, 3.23, 1.45, 5.76, 8.34 };//5
	string sarray1[] = { "aisd", "love", "laptop", "python" };//4
	string sarray2[] = { "python", "aisd", "laptop", "python", "github"}; //5
	pair<int, double> parray1[] = { make_pair(1, 1.12), make_pair(5, 3.12), make_pair(3, 7.12), make_pair(9, 4.12), make_pair(5, 3.12) };//5
	pair<int, double> parray2[] = { make_pair(3, 1.12), make_pair(5, 3.12), make_pair(1, 1.12), make_pair(5, 7.12), make_pair(6, 8.88) };//5

	Set<int> set1(iarray1, 6);
	Set<int> set2(iarray2, 5);
	Set<int> set11(iarray3, 5);
	Set<int> set22(iarray4, 7);
	Set<float> set3(farray1, 7);
	Set<float> set4(farray2, 5);
	Set<string> set5(sarray1, 4);
	Set<string> set6(sarray2, 5);
	Set<pair<int, double>> set7(parray1, 5);
	Set<pair<int, double>> set8(parray2, 5);
	
	cout << "Ex. 1" << endl;
	// Для 2 входящих массивов чисел найти все элементы, которое встречаются только в одном из массивов, но не в обоих сразу.	
	Set test1 = set1.FindUniqueElements(set2); 
	test1.PrintSet();
	Set test2 = set3.FindUniqueElements(set4);
	test2.PrintSet();
	Set test3 = set5.FindUniqueElements(set6);
	test3.PrintSet();
	Set test4 = set7.FindUniqueElements(set8);
	test4.PrintSet();
	cout << "Ex. 2" << endl;
	// Для 2 входящих массивов чисел проверить, что все элементы первого массива хотя бы раз встречаются во втором. 	
	if (set1.IsAllElementsInSet(set2)) {
		cout << "All nice!" << endl;
	}
	else {
		cout << "All bad!" << endl;
	}
	if (set11.IsAllElementsInSet(set22)) {
		cout << "All nice!" << endl;
	}
	else {
		cout << "All bad!" << endl;
	}
	cout << "Ex. 3" << endl;
	// В заданном массиве найти все повторяющиеся числа.
	Set test9 = set1.RepeatElementsInSet();
	test9.PrintSet();
	Set test10 = set3.RepeatElementsInSet();
	test10.PrintSet();
	Set test11 = set5.RepeatElementsInSet();
	test11.PrintSet();
	Set test12 = set7.RepeatElementsInSet();
	test12.PrintSet();
	cout << "Ex. 4" << endl;
	// Определить отношения между 2мя множествами: является ли одно множество подмножеством/надмножеством другого множества?
	bool isSubset = set1.IsRelation(set2, "subset");
	bool isSuperset = set1.IsRelation(set2, "superset");

	if (isSubset) {
		std::cout << "All nice!" << std::endl;
	}
	else {
		std::cout << "All bad!" << std::endl;
	}

	if (isSuperset) {
		std::cout << "All nice!" << std::endl;
	}
	else {
		std::cout << "All bad!" << std::endl;
	}
	
	
	
	return 0;
}
