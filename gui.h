#ifndef __gui
#define __gui

int Initiallize();
bool Display(int* before_sort, int num_of_elements);
int Selection();
char Sort_selection();
void Display_after_sort(int* after_sort, int num_of_elements, int sort_selection, int order);
void Error_display();
void swap(int& A, int& B);
int Flush();

inline int Initiallize()
{
	int tmp = 0;
	std::cout << "Enter number of numbers to input" << std::endl;

	std::cout << ">> ";
	std::cin >> tmp;
	return tmp;
}

bool Display(int* before_sort, int num_of_elements)
{
	std::cin.ignore(256, '\n');
	std::cout << std::endl;
	std::cout << "Input 0~99 numbers to sort" << std::endl;
	std::cout << "If you enter more than " << num_of_elements << " numbers, the excess numbers will be ignore" << std::endl;
	std::cout << ">> ";
	for (int i = 0; i < num_of_elements; i++)
	{
		std::cin >> before_sort[i];
		if (before_sort[i] < 0 || before_sort[i] >99) {
			std::cerr << "Error!! Wrong number, Program will be die" << std::endl;
			return false;
		}
	}
	int cnt = Flush();
	std::cout << std::endl;
	std::cout << "The last " << cnt << " numbers were ignored" << std::endl << std::endl;
	std::cout << "The number you input is ";
	for (int i = 0; i < num_of_elements; i++)
	{
		std::cout << before_sort[i] << " ";
	}
	std::cout << std::endl;
	return true;
}

int Selection()
{
	std::cin.ignore(256, '\n');
	int select = 0;
	std::cout << std::endl;
	std::cout << "Select an sort method" << std::endl;
	std::cout << "1. Ascending order (오름차순)" << std::endl << "2. Descending order (내림차순)" << std::endl << ">> ";
	std::cin >> select;
	if (select == 1)
		return 1;
	else if (select == 2)
		return 2;
}

char Sort_selection()
{
reselect:
	std::cin.ignore(256, '\n');
	int select = 0;
	std::cout << std::endl;
	std::cout << "Select method of sorts" << std::endl;
	std::cout << "1. Insert sort" << std::endl;
	std::cout << "2. Merge sort" << std::endl;
	std::cout << "3. Heap sort" << std::endl;
	std::cout << ">> ";
	std::cin >> select;
	if (select == 1)
		return 1;
	else if (select == 2)
		return 2;
	else if (select == 3)
		return 3;
	else {
		std::cerr << "Error!! Input 1 or 2" << std::endl;
		select = 0;
		goto reselect;
	}
}

inline void Display_after_sort(int* after_sort, int num_of_elements, int sort_selection, int order)
{
	std::cout << std::endl;
	std::cout << "After ";
	if (sort_selection == 1) {
		if (order == 1)
			std::cout << "Ascending Insert sort" << std::endl;
		else
			std::cout << "Descending Insert sort" << std::endl;
	}
	else if (sort_selection == 2) {
		if (order == 1)
			std::cout << "Ascending Merge sort" << std::endl;
		else
			std::cout << "Descending Merge sort" << std::endl;
	}
	else {
		if (order == 1)
			std::cout << "Ascending Heap sort" << std::endl;
		else
			std::cout << "Descending Heap sort" << std::endl;
	}
	std::cout << ">> ";
	for (int i = 0; i < num_of_elements; i++)
	{
		std::cout << after_sort[i] << ' ';
	}
	std::cout << std::endl;
}

inline void Error_display()
{
	std::cout << std::endl;
	std::cerr << "Program Error on select method of sort" << std::endl;
}

inline void swap(int& A, int& B)
{
	int tmp = A;
	A = B;
	B = tmp;
}

int Flush()
{
	int cnt = 0;
	while (getchar() != '\n')
		if (getchar() != ' ')
			cnt++;
	return cnt;
}
#endif __gui
