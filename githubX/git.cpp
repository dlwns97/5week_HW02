#include <iostream>
using namespace std;

#define MAX_SIZE 30
int sorted[MAX_SIZE]; // 임시 복사처

void Merge(int list[], int left, int mid, int right)
{
	int i, j, k, l;
	i = left;
	j = mid + 1;
	k = left;

	while (i <= mid && j <= right)
	{
		if (list[i] <= list[j])
			sorted[k++] = list[i++];
		else
			sorted[k++] = list[j++];
	}
	// 남아있는 원소들을 일괄 복사
	if (i > mid)
		for (; j <= right;)
			sorted[k++] = list[j++];
	else
		for (; i <= mid;)
			sorted[k++] = list[i++];

	for (l = left; l <= right; l++)
		list[l] = sorted[l];
}

void Merge_Sort(int list[], int left, int right)
{
	int mid;

	if (left < right)
	{
		mid = (left + right) / 2;

		Merge_Sort(list, left, mid);
		Merge_Sort(list, mid + 1, right);
		Merge(list, left, mid, right);
	}
}
int main(void)
{
	int i = 0;
	int n = MAX_SIZE;
	int list[11] = { 10,20,3,4,6,30,2,8,1,44,55 };

	Merge_Sort(list, 0, 10);

	for (; i <= 10;)
		cout << list[i++] << " ";
	cout << endl;

	return 0;
}