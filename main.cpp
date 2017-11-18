#include <iostream>
#include <sstream>
#include <utility>
#include <cstdlib>

using namespace std;

bool read(int &size) {
	string stroka;
	getline(cin, stroka);
	istringstream stream(stroka);

	bool success = true;

	if (stream >> size && size > 0) {

	}
	else {
		success = false;
	}

	return success;
}

bool create(double * & mass, int resultsize) {
	bool success = true;

	string stroka;
	getline(cin, stroka);
	istringstream stream(stroka);

	int size = 0;
	double element;

	mass = new double[resultsize];
	int i = 0;
	while (stream >> element) {
		if (size < resultsize) {
			mass[i] = element;
			i++;
			size++;
		}
		else {
			success = false;
			break;
		}
	}

	if (resultsize > size) {
		success = false;
	}

	return success;
}

void write(double * mass, int size) {
	for (int i = 0; i < size; i++) {
		cout << mass[i];
		if (i != size - 1) {
			cout << ' ';
		}
		else {
			cout << '\n';
		}
	}
}

void merge_sort(double * mass, int left, int right) {
	if (left == right) {
		return;
	}
	
	int mid = (left + right) / 2;
	merge_sort(mass, left, mid);
	merge_sort(mass, mid + 1, right);

	double* tmp = new double[right + 1];
	int i = left, j = mid + 1;

	for (int k = left; k < right + 1; k++) {
		if (i < mid + 1 && j < right + 1) {
			if (mass[i] < mass[j]) {
				tmp[k] = mass[i];
				i++;
			}
			else {
				tmp[k] = mass[j];
				j++;
			}
		}
		else if (i < mid + 1) {
			tmp[k] = mass[i];
			i++;
		}
		else {
			tmp[k] = mass[j];
			j++;
		}
	}

	for (int k = left; k < right + 1; k++) {
		mass[k] = tmp[k];
	}
	delete[] tmp;
}

void error() {
	cout << "An error has occured while reading input data.\n";
}

int main()
{
	int size = 0;
	double * mass = nullptr;

	if (read(size)) {
		if (create(mass, size)) {
			merge_sort(mass, 0, size - 1);
			write(mass, size);
			delete[] mass;
		}
		else {
			error();
		}
	}
	else {
		error();
	}

	system("pause");
	return 0;
}
