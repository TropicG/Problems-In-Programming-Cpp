#include <iostream>
#include <cstring>
using namespace std;

struct intarray {

	//members for the struct
	int* arr;
	size_t size;

	//default constructor, used to return sturct var if the memory allocation failed inside append function
	intarray() : arr(nullptr), size(0) {}



};


bool inside(const int& num, const intarray& array) {


	for (int i = 0; i < array.size; ++i) {

		if (num == array.arr[i]) {
			return true;
		}

	}

	return false;
}

intarray unionarray(intarray a, intarray b) {

	//here we store all the elements from a and b without dublicate
	intarray unionArray;

	//allocating enough memory if there are no dublicates
	unionArray.arr = new int[a.size + b.size];

	//memory allocation check
	if (unionArray.arr == nullptr) {
		return unionArray;
	}


	//adding all the elements to unionArray from a without dublicate
	for (int i = 0; i < a.size; ++i) {

		//checks if the current symbol in a is inside unionArray
		if (!inside(a.arr[i], unionArray)) {
			unionArray.arr[unionArray.size] = a.arr[i];
			unionArray.size++;
		}

	}

	//adding all the elements to unionArray from b without dublicate
	for (int i = 0; i < b.size; ++i) {

		//checks if the current symbol in b is inside unionArray
		if (!inside(b.arr[i], unionArray)) {
			unionArray.arr[unionArray.size] = b.arr[i];
			unionArray.size++;
		}

	}

	return unionArray;

}



int main() {

	//storing the first two arrays
	intarray a, b;
	cout << "How many numbers do you want to push into the first array: ";
	if (!(cin >> a.size)) {
		cout << "Invalid argument";
		return -1;
	}

	cout << "How many numbers do you want to push into the second array: ";
	if (!(cin >> b.size)) {
		cout << "Invalid argument";
		return -2;
	}

	//creating the array member of the struct
	a.arr = new int[a.size];
	if (!a.arr) {
		cout << "Failed memory allocation";
		delete[] a.arr;
		return -3;
	}

	//creating the array member of the struct
	b.arr = new int[b.size];
	if (!b.arr) {
		cout << "Failed memory allocation";
		delete[] b.arr;
		return -4;
	}

	//inputting elements for a
	cout << "Enter the elements for the first array: ";
	for (int i = 0; i < a.size; ++i) {
		cin >> a.arr[i];
		while (cin.fail()) {
			cin.clear();
			cin.ignore(256, '\n');
			cout << "Invalid argument, try again";
			cin >> a.arr[i];
		}
	}

	//inputting elements for b
	cout << "Enter the elements for the second array: ";
	for (int i = 0; i < b.size; ++i) {
		cin >> b.arr[i];
		while (cin.fail()) {
			cin.clear();
			cin.ignore(256, '\n');
			cout << "Invalid argument, try again";
			cin >> b.arr[i];
		}
	}


	intarray unionArray = unionarray(a, b);
	if (unionArray.arr == nullptr) {
		cout << "Failed allocation";
		delete[] unionArray.arr;
		return -5;
	}

	cout << "Printing the united array: ";
	for (int i = 0; i < unionArray.size; ++i) {
		cout << unionArray.arr[i] << " ";
	}


}
