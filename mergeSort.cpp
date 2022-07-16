#include <iostream>
#include <ctime>
using namespace std;

int comp_count = 0;
int assign_count = 0;

void merge(int a[], int begin, int mid, int end)
{
    int temp[end - begin + 1];

    int i = begin, j = mid + 1, k = 0;
    assign_count += 3;

    while (i <= mid && j <= end)
    {
        comp_count++;
        comp_count++;
        if (a[i] <= a[j])
        {
            temp[k] = a[i];
            k += 1;
            i += 1;
            assign_count += 3;
        }
        else
        {
            temp[k] = a[j];
            k += 1;
            j += 1;
            assign_count += 3;
        }
    }

    comp_count++;

    while (i <= mid)
    {
        comp_count++;
        temp[k] = a[i];
        k += 1;
        i += 1;
        assign_count += 3;
    }
    comp_count++;
    
    while (j <= end)
    {
        comp_count++;
        temp[k] = a[j];
        k += 1;
        j += 1;
        assign_count += 3;
    }
    comp_count++;

    for (int i = begin; i <= end; i++)

    {
        comp_count++;
        a[i] = temp[i - begin];
        assign_count++;
    }
    comp_count++;
}

void mergeSort(int arr[], int start, int end)
{
    comp_count++;
    if (start >= end)
    {
        return;
    }

    int mid = (start + end) / 2;
    assign_count++;
    mergeSort(arr, start, mid);
    mergeSort(arr, mid + 1, end);
    merge(arr, start, mid, end);
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
        mergeSort(arr, 0, size - 1);
        cout << assign_count + comp_count << "          ";

        assign_count = comp_count = 0;
        //for worst case-->
        for (int i = 0; i < size; i++)
        {
            arr[i] = last;
            last--;
        }

        mergeSort(arr, 0, size - 1);
        cout << assign_count + comp_count << "          ";

        cout << endl;
        size += 5;
    }

    return 0;
}