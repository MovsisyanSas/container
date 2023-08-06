#pragma once
#include <vector>
#include <list>


namespace sort {

	template<typename T>
	void swap(T& item1, T& item2) {
		T temp = item1;
		item1 = item2;
		item2 = temp;
	}

	template<typename T>
	int max(T a, T b) {
		return a > b ? a : b;
	}

	template<typename T>
	void bubble_sort(std::vector<T>& arr) {
		for (int step = 0; step < arr.size(); step++) {
			for (int i = 0; i < arr.size() - step - 1; i++) {
				if (arr[i] > arr[i + 1]) {
					swap(arr[i], arr[i + 1]);
				}
			}
		}
	}

	template<typename T>
	void bubble_sort(std::list<T>& list) {
		for (auto it = list.begin(); it != list.end(); ++it) {
			for (auto innerIt = list.begin(); std::next(innerIt) != list.end(); ++innerIt) {
				auto nextIt = std::next(innerIt);
				if (*innerIt > *nextIt) {
					std::iter_swap(innerIt, nextIt);
				}
			}
		}
	}

	//int partition(int arr[], int low, int high) {
	//	int pivot = arr[high];

	//	int i = low - 1;

	//	for (int j = low; j <= high - 1; j++)
	//	{
	//		if (arr[j] < pivot)
	//		{
	//			i++;
	//			swap(&arr[i], &arr[j]);
	//		}
	//	}
	//	swap(&arr[i + 1], &arr[high]);

	//	return (i + 1);
	//}

	//void QuickSort(int arr[], int low, int high) {
	//	if (low < high)
	//	{
	//		int pi = partition(arr, low, high);
	//		QuickSort(arr, low, pi - 1);
	//		QuickSort(arr, pi + 1, high);
	//	}
	//}

	//void selectionSort(int arr[], int size) {
	//	for (int step = 0; step < size - 1; step++)
	//	{
	//		int min_idx = step;
	//		for (int i = step + 1; i < size; i++)
	//		{
	//			if (arr[i] < arr[min_idx])
	//			{
	//				min_idx = i;
	//			}
	//		}
	//		int temp = arr[step];
	//		arr[step] = arr[min_idx];
	//		arr[min_idx] = temp;
	//	}
	//}

	//void insertionSort(int arr[], int size) {
	//	int key, j;
	//	for (int i = 1; i < size; i++)
	//	{
	//		key = arr[i];
	//		j = i - 1;
	//		while (arr[j] > key && j >= 0)
	//		{
	//			arr[j + 1] = arr[j];
	//			j++;
	//		}
	//		arr[j + 1] = key;
	//	}
	//}

	//void merge(int arr[], int left, int middle, int right) {
	//	int size_1 = middle - left + 1;
	//	int size_2 = right - middle;

	//	int* arr1 = new int[size_1];
	//	int* arr2 = new int[size_2];

	//	for (int i = 0; i < size_1; i++) {
	//		arr1[i] = arr[left + i];
	//	}

	//	for (int i = 0; i < size_2; i++) {
	//		arr2[i] = arr[middle + i + 1];
	//	}

	//	int i = 0;
	//	int j = 0;
	//	int k = left;
	//	while (i < size_1 && j < size_2) {
	//		if (arr1[i] <= arr2[j]) {
	//			arr[k] = arr1[i];
	//			i++;
	//		}
	//		else {
	//			arr[k] = arr2[j];
	//			j++;
	//		}
	//		k++;
	//	}

	//	while (i < size_1) {
	//		arr[k] = arr1[i];
	//		i++;
	//		k++;
	//	}

	//	while (j < size_2) {
	//		arr[k] = arr2[j];
	//		j++;
	//		k++;
	//	}
	//}


	//void MergeSort(int arr[], int left, int right) {
	//	if (left < right) {
	//		int middle = left + (right - left) / 2;

	//		MergeSort(arr, left, middle);
	//		MergeSort(arr, middle + 1, right);

	//		merge(arr, left, middle, right);
	//	}
	//}

	//bool binarySearch(int* arr, int low, int high, int item) {
	//	if (low <= high)
	//	{
	//		int mid = low + (high - low) / 2;

	//		if (arr[mid] == item)
	//		{
	//			return true;
	//		}
	//		if (item < arr[mid])
	//		{
	//			return binarySearch(arr, low, mid - 1, item);
	//		}
	//		else
	//		{
	//			return binarySearch(arr, mid + 1, high, item);
	//		}
	//	}

	//	return false;
	//}
}