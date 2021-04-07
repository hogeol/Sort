#ifndef __insertsort
#define __insertsort


void Ins_ascending_sort(int* before_sort, int num_of_elements);
void Ins_descending_sort(int* before_sort, int num_of_elements);

void Ins_ascending_sort(int* before_sort, int num_of_elements)
{
	int key = 0, j = 0;
	for (int i = 1; i < num_of_elements; i++)
	{
		key = before_sort[i];
		for (j = i - 1; j >= 0; j--) {
			if (key < before_sort[j])
				before_sort[j + 1] = before_sort[j];
			else
				break;
		}
		before_sort[j + 1] = key;
	}
}

void Ins_descending_sort(int* before_sort, int num_of_elements)
{
	int key = 0, j = 0;
	for (int i = num_of_elements - 2; i >= 0; i--)
	{
		key = before_sort[i];
		for (j = i + 1; j < num_of_elements; j++)
		{
			if (before_sort[j] > key)
				before_sort[j - 1] = before_sort[j];
			else
				break;
		}
		before_sort[j - 1] = key;
	}
}

#endif __insertsort