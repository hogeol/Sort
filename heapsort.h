#ifndef __heapsort
#define __heapsort

void Max_heapify(int* before_sort, int parent, int num_of_index);
void Min_heapify(int* before_sort, int parent, int num_of_index);
void Heap_sort(int* before_sort, int num_of_elements, int order);

inline void Max_heapify(int* before_sort, int parent, int num_of_index)
{
	int left_child = (parent * 2) + 1;
	int right_child = left_child + 1;
	int child = left_child;
	if ((num_of_index + 1) >= right_child && before_sort[left_child] < before_sort[right_child])
		child = right_child;
	if (before_sort[parent] < before_sort[child])
		swap(before_sort[parent], before_sort[child]);
	if (child <= num_of_index / 2)
		Max_heapify(before_sort, child, num_of_index);
}

inline void Min_heapify(int* before_sort, int parent, int num_of_index)
{
	int left_child = (parent * 2) + 1;
	int right_child = left_child + 1;
	int child = left_child;
	if ((num_of_index + 1) >= right_child && before_sort[left_child] > before_sort[right_child])
		child = right_child;
	if (before_sort[parent] > before_sort[child])
		swap(before_sort[parent], before_sort[child]);
	if (child <= num_of_index / 2)
		Min_heapify(before_sort, child, num_of_index);
}

void Heap_sort(int* before_sort, int num_of_elements, int order)
{
	do {
		int num_of_index = num_of_elements - 2;
		if (order == 1)
			for (int i = (num_of_elements - 2) / 2; i >= 0; i--)
				Max_heapify(before_sort, i, num_of_index);
		if (order == 2)
			for (int i = (num_of_elements - 2) / 2; i >= 0; i--)
				Min_heapify(before_sort, i, num_of_index);
		swap(before_sort[0], before_sort[num_of_elements - 1]);
		num_of_elements--;
	} while (num_of_elements >= 2);
}

#endif __heapsort