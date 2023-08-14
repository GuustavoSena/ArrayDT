#include <iostream>

template<class T>
class Array {
private:
	T* A;
	int size;
	int length;
	void swap(T* x, T* y);
public:
	Array() {
		size = 10;
		length = 0;
		A = new T[size];
	}
	Array(int sz) {
		size = sz;
		length = 0;
		A = new T[size];
	}
	~Array() {
		delete[] A;
	}

	void Display();
	void Append(T x);
	void Insert(int index, T x);
	T Remove(int index);
	T LinearSearch(T key);
	T BinarySearch(T key);
	T Get(int index);
	void Set(int index, T x);
	T Max();
	T Min();
	T Sum();
	double Avg();
	void Reverse();
	void InsertSort(T x);
	int isSorted();
	void Rearrange();
	Array* Merge(Array arr2);
	Array* Union(Array arr2);
	Array* Intersection(Array arr2);
	Array* Difference(Array arr2);
};

template<class T>
void Array<T>::Display() {

	std::cout << " Elements are: ";

	for (int i = 0; i < length; i++) {
		std::cout << " " << A[i] << " ";
	}
	std::cout << std::endl;
}

template<class T>
void Array<T>::Append(T x) {
	if (length < size) {
		A[length++] = x;
	}
}

template<class T>
void Array<T>::Insert(int index, T x) {
	if (length < size) {
		if (index >= 0 && index <= length) {
			for (int i = length; i > index; i--) {
				A[i] = A[i - 1];
			}
			A[index] = x;
			length += 1;
		}
	}
}

template<class T>
T Array<T>::Remove(int index) {
	if (index >= 0 && index <= (length)-1) {
		T x = A[index];
		for (int i = index; i < (length)-1; i++) {
			A[i] = A[i + 1];
		}
		length = (length)-1;
		return x;
	}
	return 0;
}

template<class T>
void Array<T>::swap(T* x, T* y) {
	int temp;
	temp = *x;
	*x = *y;
	*y = temp;
}

template<class T>
T Array<T>::LinearSearch(T key) {
	for (int i = 0; i < length; i++) {
		if (key == A[i]) {
			if (i != 0) {
				swap(&A[i], &A[i - 1]);
			}
			return i;
		}
	}
	return -1;
}

template<class T>
T Array<T>::BinarySearch(T key) {
	int l, h, mid;
	l = 0;
	h = length - 1;
	while (l <= h) {
		mid = (l + h) / 2;
		if (key == A[mid]) {
			return mid;
		}
		else if (key < A[mid]) {
			h = mid - 1;
		}
		else {
			l = mid + 1;
		}
	}
	return -1;
}

template<class T>
T Array<T>::Get(int index) {
	if (index >= 0 && index < length) {
		return A[index];
	}
	return -1;
}

template<class T>
void Array<T>::Set(int index, T x) {
	if (index >= 0 && index < length) {
		A[index] = x;
	}
}

template<class T>
T Array<T>::Max() {
	int max = A[0];
	for (int i = 1; i < length; i++) {
		if (A[i] > max) {
			max = A[i];
		}
	}
	return max;
}

template<class T>
T Array<T>::Min() {
	int min = A[0];
	for (int i = 1; i < length; i++) {
		if (A[i] < min) {
			min = A[i];
		}
	}
	return min;
}

template<class T>
T Array<T>::Sum() {
	int total = 0;
	for (int i = 0; i < length; i++) {
		total += A[i];
	}
	return total;
}

template<class T>
double Array<T>::Avg() {
	return ((double)Sum() / (length));
}

template<class T>
void Array<T>::Reverse() {
	int i, j;
	for (i = 0, j = length - 1; i < j; i++, j--) {
		swap(&A[i], &A[j]);
	}
}

template<class T>
void Array<T>::InsertSort(T x) {
	int i = length - 1;
	if (length < size) {
		while (A[i] > x) {
			A[i + 1] = A[i];
			i--;
		}
		A[i + 1] = x;
		length = length + 1;
	}
}

template<class T>
int Array<T>::isSorted() {
	for (int i = 0; i < length - 2; i++) {
		if (A[i] > A[i + 1]) {
			return 0;
		}
	}
	return 1;
}

template<class T>
void Array<T>::Rearrange() {
	int i = 0;
	int j = length - 1;
	while (i < j) {
		while (A[i] < 0) i++;
		while (A[j] >= 0) j--;
		if (i < j) {
			swap(&A[i], &A[j]);
		}
	}
}

template<class T>
Array<T>* Array<T>::Merge(Array<T> arr2) {
	Array* arr3 = new Array(size + arr2.size);
	arr3->length = length + arr2.length;
	int i, j, k;
	i = j = k = 0;
	while (i < length && j < arr2.length) {
		if (A[i] < arr2.A[j]) {
			arr3->A[k++] = A[i++];
			arr3->A[k++] = arr2.A[j++];
		}
		else {
			arr3->A[k++] = arr2.A[j++];
			arr3->A[k++] = A[i++];
		}
	}
	for (; i < length; i++) {
		arr3->A[k++] = A[i];
	}
	for (; j < arr2.length; j++) {
		arr3->A[k++] = arr2.A[j];
	}
	return arr3;
}

template<class T>
Array<T>* Array<T>::Union(Array<T> arr2) {
	Array* arr3 = new Array(size + arr2.size);
	int i, j, k;
	i = j = k = 0;
	while (i < length && j < arr2.length) {
		if (A[i] == arr2.A[j]) {
			arr3->A[k++] = A[i++];
			j++;
		}
		else {
			if (A[i] < arr2.A[j]) {
				arr3->A[k++] = A[i++];
				arr3->A[k++] = arr2.A[j++];
			}
			else {
				arr3->A[k++] = arr2.A[j++];
				arr3->A[k++] = A[i++];
			}
		}
	}
	for (; i < length; i++) {
		arr3->A[k++] = A[i];
	}
	for (; j < arr2.length; j++) {
		arr3->A[k++] = arr2.A[j];
	}
	arr3->length = k;
	return arr3;
}

template<class T>
Array<T>* Array<T>::Intersection(Array<T> arr2) {
	Array* arr3 = new Array(size + arr2.size);
	int i, j, k;
	i = j = k = 0;
	while (i < length && j < arr2.length) {
		if (A[i] == arr2.A[j]) {
			arr3->A[k++] = A[i++];
			j++;
		}
		else {
			if (A[i] < arr2.A[j]) {
				i++;
			}
			else {
				j++;
			}
		}
	}
	arr3->length = k;
	return arr3;
}

template<class T>
Array<T>* Array<T>::Difference(Array<T> arr2) {
	Array* arr3 = new Array(size + arr2.size);
	int i, j, k;
	i = j = k = 0;
	while (i < length && j < arr2.length) {
		if (A[i] == arr2.A[j]) {
			i++;
			j++;
		}
		else {
			if (A[i] < arr2.A[j]) {
				arr3->A[k++] = A[i++];
			}
			else {
				j++;
			}
		}
	}
	for (; i < length; i++) {
		arr3->A[k++] = A[i];
	}
	arr3->length = k;
	return arr3;
}


template<class T>
void manipulateArrays(Array<T> arr) {
	int index, x, choice;
	do {
		std::cout << "What do you want to do?" << std::endl;
		std::cout << "1. Display Array" << std::endl;
		std::cout << "2. Append a number on Array" << std::endl;
		std::cout << "3. Insert a number on Array" << std::endl;
		std::cout << "4. Remove a number of the Array" << std::endl;
		std::cout << "5. Find a number on Array" << std::endl;
		std::cout << "6. Insert a number on Array" << std::endl;
		std::cout << "7. Get a number of the Array" << std::endl;
		std::cout << "8. Set a number on Array" << std::endl;
		std::cout << "9. Find the max number of the Array" << std::endl;
		std::cout << "10. Find the min number of the Array" << std::endl;
		std::cout << "11. Find the numbers's sum of the Array" << std::endl;
		std::cout << "12. Find the number's avg of the Array" << std::endl;
		std::cout << "13. Reverse the Array" << std::endl;
		std::cout << "14. Check if Array is sorted" << std::endl;
		std::cout << "15. Insert a number on a sorted Array" << std::endl;
		std::cout << "16. Rearrange the Array" << std::endl;
		std::cin >> choice;

		switch (choice) {
		case 1:
			arr.Display();
			break;
		case 2:
			std::cout << "Which number do you want to append?" << std::endl;
			std::cin >> x;
			arr.Append(x);
			break;
		case 3:
			std::cout << "Which number do you want to insert and on which index?" << std::endl;
			std::cin >> x >> index;
			arr.Insert(index, x);
			break;
		case 4:
			std::cout << "From which index do you want to remove a number?" << std::endl;
			std::cin >> index;
			arr.Remove(index);
			break;
		case 5:
			std::cout << "Which number do you want to find?" << std::endl;
			std::cin >> x;
			index = arr.LinearSearch(x);
			if (index == -1) {
				std::cout << "The number is not on Array" << std::endl;
			}
			else {
				std::cout << "The number was on index " << index << ", now is on index " << index - 1 << std::endl;
			}
			break;
		case 6:

			break;
		case 7:

			break;
		case 8:

			break;
		case 9:

			break;
		case 10:

			break;
		case 11:

			break;
		case 12:

			break;
		case 13:

			break;
		case 14:

			break;
		case 15:

			break;
		case 16:

			break;
		default:
			std::cout << "Valor indefinido" << std::endl;
			break;
		}
	} while (choice >= 1 && choice <= 16);
}


int main() {
	int sz, type;

	std::cout << "Enter the size of the array: " << std::endl;
	std::cin >> sz;
	do {
		std::cout << "Enter the member's type of the array: " << std::endl;
		std::cout << "1. Integer members" << std::endl;
		std::cout << "2. Decimal members" << std::endl;
		std::cin >> type;

		if (type == 1) {
			Array<int> arr1(sz);
			manipulateArrays(arr1);
		}
		else if (type == 2) {
			Array<double> arr1(sz);

		}
		else {
			std::cout << "Valor indefinido" << std::endl;
		}
	} while (type != 1 && type != 2);

	return 0;
}
