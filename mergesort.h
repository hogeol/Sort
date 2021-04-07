#ifndef __mergesort
#define __mergesort

void Mer_divide(int left, int right, int sort_selection);
void Mer_ascending_sort(int left, int right);
void Mer_descending_sort(int left, int right);


int* merge_tmp;
int* merge_sort;

void Mer_divide(int left, int right, int sort_selection)
{
	int mid = 0;
	if (left < right) {
		mid = (left + right) / 2;
		Mer_divide(left, mid, sort_selection);
		Mer_divide(mid + 1, right, sort_selection);
		if (sort_selection == 1)
			Mer_ascending_sort(left, right);
		else if (sort_selection == 2)
			Mer_descending_sort(left, right);
	}
}

void Mer_ascending_sort(int left, int right)
{
	int mid = (left + right) / 2;
	int i = left, j = left;
	int k = mid + 1;

	while (i <= mid && k <= right) {
		if (merge_sort[i] <= merge_sort[k])
			merge_tmp[j++] = merge_sort[i++];
		else
			merge_tmp[j++] = merge_sort[k++];
	}

	while (j <= right) {
		if (i > mid)
			merge_tmp[j++] = merge_sort[k++];
		else
			merge_tmp[j++] = merge_sort[i++];
	}
	for (int i = left; i <= right; i++)
		merge_sort[i] = merge_tmp[i];
}

void Mer_descending_sort(int left, int right)
{
	int mid = (left + right) / 2;
	int i = left, j = left;
	int k = mid + 1;

	while (i <= mid && k <= right) {
		if (merge_sort[i] >= merge_sort[k])
			merge_tmp[j++] = merge_sort[i++];
		else
			merge_tmp[j++] = merge_sort[k++];
	}

	while (j <= right) {
		if (i > mid)
			merge_tmp[j++] = merge_sort[k++];
		else
			merge_tmp[j++] = merge_sort[i++];
	}
	for (int i = left; i <= right; i++)
		merge_sort[i] = merge_tmp[i];
}


#endif __mergesort
