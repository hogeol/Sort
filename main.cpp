#include <iostream>
#include "gui.h"
#include "insertsort.h"
#include "mergesort.h"
#include "heapsort.h"

using namespace std;

int main() 
{
	int num = Initiallize();
	int sort_select = Sort_selection();
	int order = Selection();

	if (sort_select == 1) {
		int* sort_arr = new int[num];
		bool cnt = Display(sort_arr, num);
		if (cnt != 1) {
			delete[] sort_arr;
			sort_arr = nullptr;
			return -1;
		}

		if (order == 1) {
			Ins_ascending_sort(sort_arr, num);
			Display_after_sort(sort_arr, num, sort_select, order);
		}
		else if (order == 2) {
			Ins_descending_sort(sort_arr, num);
			Display_after_sort(sort_arr, num, sort_select, order);
		}
		else {
			Error_display();
			return -1;
		}
		delete[] sort_arr;
		sort_arr = nullptr;
		return 0;
	}

	else if (sort_select == 2) {
		merge_tmp = new int[num];
		merge_sort = new int[num];
		bool cnt = Display(merge_sort, num);

		if (order == 1) {
			Mer_divide(0, num - 1, order);
			Display_after_sort(merge_sort, num, sort_select, order);
		}
		else if (order == 2) {
			Mer_divide(0, num - 1, order);
			Display_after_sort(merge_sort, num, sort_select, order);
		}
		else {
			Error_display();
			return -1;
		}
		return 0;
	}

	else if (sort_select == 3) {
		int* heapsort_arr = new int[num];
		bool cnt = Display(heapsort_arr, num);
		if (cnt != 1) {
			delete[] heapsort_arr;
			heapsort_arr = nullptr;
			return -1;
		}
		if (order == 1) {
			Heap_sort(heapsort_arr, num, order);
			Display_after_sort(heapsort_arr, num, sort_select, order);
		}
		else if (order == 2) {
			Heap_sort(heapsort_arr, num, order);
			Display_after_sort(heapsort_arr, num, sort_select, order);
		}
		else {
			Error_display();
			return -1;
		}
		delete[] heapsort_arr;
		heapsort_arr = nullptr;
	}
	return -1;
}
