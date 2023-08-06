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
			bool swapped = false;
			for (int i = 0; i < arr.size() - step - 1; i++) {
				if (arr[i] > arr[i + 1]) {
					sort::swap(arr[i], arr[i + 1]);
					swapped = true;
				}
			}
			if (!swapped) {
				break;
			}
		}
	}



	template<typename T>
	void bubble_sort(std::list<T>& list) {
		for (auto it = list.begin(); it != std::prev(list.end()); ++it) {
			bool swapped = false;
			for (auto inner_it = list.begin(); std::next(inner_it) != std::end(list); ++inner_it) {
				auto next_it = std::next(inner_it);
				if (*inner_it > *next_it) {
					std::iter_swap(inner_it, next_it);
					swapped = true;
				}
			}
			if (!swapped) {
				break;
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

	template<typename T>
	void selection_sort(std::list<T>& list) {
		for (auto it = list.begin(); it != list.end(); ++it) {
			auto min_it = it;
			for (auto it2 = std::next(it); it2 != list.end(); ++it2) {
				if (*it2 < *min_it) {
					min_it = it2;
				}
			}
			if (min_it != it) {
				std::iter_swap(it, min_it);
			}
		}
	}

	template<typename T>
	void selection_sort(std::vector<T>& arr) {
		for (int step = 0; step < arr.size() - 1; step++)
		{
			int min_idx = step;
			for (int i = step + 1; i < arr.size(); i++)
			{
				if (arr[i] < arr[min_idx])
				{
					min_idx = i;
				}
			}
			sort::swap(arr[min_idx], arr[step]);
		}
	}

	template<typename T>
	void insertion_sort(std::vector<T>& arr) {
		T key;
		int j;
		for (int i = 1; i < arr.size(); i++) {
			key = arr[i];
			j = i - 1;
			while (j >= 0 && arr[j] > key) {
				arr[j + 1] = arr[j];
				j--;
			}
			arr[j + 1] = key;
		}
	}


	template<typename T>
	void insertion_sort(std::list<T>& list) {
		for (auto it = std::next(list.begin()); it != list.end(); ++it) {
			T key = *it;
			auto j = std::prev(it);
			while (j != list.begin() && *j > key) {
				*std::next(j) = std::move(*j); //use std::move to not hurt list
				--j;
			}
			*std::next(j) = key;
		}
	}



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