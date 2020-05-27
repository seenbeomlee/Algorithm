#include<stdio.h>

/* reference : https://gmlwjd9405.github.io/2018/05/06/algorithm-selection-sort.html */

void swap(int* A, int* B) {
	int temp = *A;
	*A = *B;
	*B = temp;
}

void selection_sort(int* arr, int num) {

	int* min_num; /* if should be 'pointer' to change elements of the array (if not, all elements will be min_num) */

	for (int i = 0; i < 10; i++) {
		min_num = &arr[i];
		for (int j = i; j < 10; j++) {
			if (arr[j] < *min_num) min_num = &arr[j];
		}
		swap(&arr[i], min_num);
	}

}

int main() {

	int arr[10] = { 200 , 0 , 13 , 55 , 70 , 164, 333, 2, 94, 150 };
	printf("Before sort: ");
	for (int i = 0; i < 10; i++) printf("%d ", arr[i]);
	selection_sort(arr, 10);
	printf("\nAfter sort: ");
	for (int i = 0; i < 10; i++) printf("%d ", arr[i]);

	return 0;
}