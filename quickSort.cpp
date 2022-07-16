#include <iostream>
#include <ctime>
using namespace std;

int comp_count = 0;
int assign_count = 0;

int partition(int a[], int begin, int end)
{
    int count = 0, temp;
    assign_count++;

    for (int i = begin; i <= end; i++)
    {
        comp_count++;
        comp_count++;
        if (a[begin] > a[i])
        {
            count++;
        }
    }
    comp_count++;

    temp = a[begin + count];
    a[begin + count] = a[begin];
    a[begin] = temp;
    assign_count += 3;

    int i = begin, j = end;
    assign_count += 2;

    while (i < (begin + count) && j > (begin + count))
    {
        comp_count++;
        comp_count++;

        if (a[i] <= a[begin + count])
        {
            i++;
        }
        else if (a[j] > a[begin + count])
        {
            j--;
        }
        else
        {
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
            assign_count += 3;
        }
    }
    comp_count++;

    return begin + count;
}

void quickSort(int arr[], int start, int end)
{
    comp_count++;
    if (start >= end)
    {
        return;
    }
    int c = partition(arr, start, end);
    assign_count++;
    quickSort(arr, start, c - 1);
    quickSort(arr, c + 1, end);
    return;
}

int main()
{
    int size = 10;
    cout << "Input Size          Bestc case(comp+assign)          worstCase (comp+assign)\n";
    while (size <= 100)
    {
        int last = size;
        cout << size << "          ";

        int *arr = new int[size];

        assign_count = comp_count = 0;
        //for best case-->
        srand(time(0));
        for (int i = 0; i < size; i++)
        {
            arr[i] = rand() % 100;
        }
        quickSort(arr, 0, size - 1);
        cout << assign_count + comp_count << "          ";

        assign_count = comp_count = 0;
        //for worst case-->
        for (int i = 0; i < size; i++)
        {
            arr[i] = last;
            last--;
        }

        quickSort(arr, 0, size - 1);
        cout << assign_count + comp_count << "          ";

        cout << endl;
        size += 5;
    }

    return 0;
}