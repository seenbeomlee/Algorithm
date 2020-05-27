#include<stdio.h>

/* reference : https://gmlwjd9405.github.io/2018/05/06/algorithm-bubble-sort.html */

void swap(int* A, int* B) {
	int temp = *A;
	*A = *B;
	*B = temp;
}

void bubble_sort(int* arr, int num) {

	int temp = 0;

	while (1) { /* it is little hard to build repeat condition for bubble sort */
		if (temp == num) break;

		for (int i = 0; i < num - 1 - temp; i++) {
			if (arr[i] > arr[i + 1]) swap(&arr[i], &arr[i + 1]);
		}

		temp++;
	}
}

int main() {

	int arr[10] = { 200 , 0 , 13 , 55 , 70 , 164, 333, 2, 94, 150 };
	printf("Before sort: ");
	for (int i = 0; i < 10; i++) printf("%d ", arr[i]);
	bubble_sort(arr, 10);
	printf("\nAfter sort: ");
	for (int i = 0; i < 10; i++) printf("%d ", arr[i]);

	return 0;
}