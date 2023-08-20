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

	void counting_sort(std::vector<int>& arr,int k) {
		std::vector<int> temp(k, 0);

		for (int i = 0; i < arr.size(); i++) {
			temp[arr[i]]++;
		}

		for (int i = 1; i < temp.size(); i++) {
			temp[i] += temp[i - 1];
		}

		std::vector<int> result(arr.size());

		for (int i = 0; i < arr.size(); i++) {
			result[temp[arr[i]] - 1] = arr[i];
			temp[arr[i]]--;
		}

		arr = result;
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
			auto key = *it;
			auto j = std::prev(it);
			while (j != list.begin() && *j > key) {
				*std::next(j) = *j; //use std::move to not hurt list
				--j;
			}
			*std::next(j) = key;
		}
	}

	
	//template<typename T>
	//typename std::list<T>::iterator partition(std::list<T>& list, typename std::list<T>::iterator low, typename std::list<T>::iterator high) {
	//	T pivot = *high;

	//	auto i = low;
	//	auto j = (low);

	//	while (j != high) {
	//		if (*j < pivot) {
	//			++i;
	//			std::swap(i, j);
	//		}
	//		++j;
	//	}

	//	std::swap(i, high);

	//	return i;
	//}

	//template<typename T>
	//void QuickSort(std::list<T>& list, typename std::list<T>::iterator low, typename std::list<T>::iterator high) {
	//	if (low != high) {
	//		auto pi = partition<T>(list, low, high);
	//		QuickSort<T>(list, low, pi);
	//		QuickSort<T>(list, std::next(pi), high);
	//	}
	//}



	template<typename T>
	int partition(std::vector<T>& arr, T low, T high) {
		T pivot = arr[high];

		T i = low - 1;

		for (T j = low; j <= high - 1; j++) {
			if (arr[j] < pivot) {
				i++;
				sort::swap(arr[i], arr[j]);
			}
		}
		sort::swap(arr[i + 1], arr[high]);

		return (i + 1);
	}

	template<typename T>
	void QuickSort(std::vector<T>& arr, T low, T high) {
		if (low < high) {
			int pi = partition(arr, low, high);
			QuickSort(arr, low, pi - 1);
			QuickSort(arr, pi + 1, high);
		}
	}

	template<typename T>
	void merge(std::vector<T>& arr, T left, T middle, T right) {
		int size_1 = middle - left + 1;
		int size_2 = right - middle;

		T* arr1 = new T[size_1];
		T* arr2 = new T[size_2];

		for (int i = 0; i < size_1; i++) {
			arr1[i] = arr[left + i];
		}

		for (int i = 0; i < size_2; i++) {
			arr2[i] = arr[middle + i + 1];
		}

		int i = 0;
		int j = 0;
		T k = left;
		while (i < size_1 && j < size_2) {
			if (arr1[i] <= arr2[j]) {
				arr[k] = arr1[i];
				i++;
			}
			else {
				arr[k] = arr2[j];
				j++;
			}
			k++;
		}

		while (i < size_1) {
			arr[k] = arr1[i];
			i++;
			k++;
		}

		while (j < size_2) {
			arr[k] = arr2[j];
			j++;
			k++;
		}
	}

	template<typename T>
	void MergeSort(std::vector<T>& arr, T left, T right) {
		if (left < right) {
			int middle = left + (right - left) / 2;

			MergeSort(arr, left, middle);
			MergeSort(arr, middle + 1, right);

			merge(arr, left, middle, right);
		}
	}

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