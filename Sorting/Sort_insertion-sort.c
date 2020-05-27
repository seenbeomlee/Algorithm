#include<stdio.h>

/* reference : https://gmlwjd9405.github.io/2018/05/06/algorithm-insertion-sort.html */

void swap(int* A, int* B) {
	int temp = *A;
	*A = *B;
	*B = temp;
}

void insertion_sort(int* arr, int num) {

	for (int i = 1; i < num; i++) {
		
		for (int j = i; j > 0; j--) {
			if (arr[j] > arr[j - 1]) break;
			swap(&arr[j], &arr[j - 1]);
		}
	}

}

int main() {

	int arr[10] = { 200 , 0 , 13 , 55 , 70 , 164, 333, 2, 94, 150 };
	printf("Before sort: ");
	for (int i = 0; i < 10; i++) printf("%d ", arr[i]);
	insertion_sort(arr, 10);
	printf("\nAfter sort: ");
	for (int i = 0; i < 10; i++) printf("%d ", arr[i]);

	return 0;
}