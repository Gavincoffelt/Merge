#include <iostream>
using namespace std;
void MergeSort(int * arr, size_t p, size_t r);
void Merge(int * arr, size_t p, size_t q, size_t r);
int sortarr[8]{8,7,6,5,4,3,2,1};

int main() {
	for (int i = 0; i < 8; i++) {
		cout << "original array :" << sortarr[i] << endl;
	}
	MergeSort(sortarr, 0, 8);
	for (int i = 0; i < 8; i++) {
		cout << "Sorted Array:" << sortarr[i] << endl;
	}
	return 0;
}
void MergeSort(int * arr, size_t p, size_t r)
{
	if (p < r)
	{
	size_t	q = (p + r) / 2;
		MergeSort(arr, p, q);
		MergeSort(arr, q + 1, r);
		Merge(arr, p, q, r);
	}
}
void Merge(int * arr, size_t p, size_t q, size_t r)
{
	size_t leftEnd = q - p + 1;
	size_t rightEnd = r - q;
	int * L = new int[leftEnd];
	int * R = new int[rightEnd];
	for (int i = 0; i < leftEnd; i++) {
		L[i] = arr[p + i];
	}
	for (int j = 0; j < rightEnd; j++) {
		R[j] = arr[q + j+1];
	}
	int i = 0;
	int j = 0;
	for(int k = p; k <= r; k++)
	{ 
		if ((j >= rightEnd) || (i < leftEnd && L[i] <= R[j])) {
			arr[k] = L[i];
				i++;
		}
		else {
			arr[k] = R[j];
				j++;
		}
	}
	delete[] L;
	delete[] R;
	}
