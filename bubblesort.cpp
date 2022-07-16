#include <iostream>
#include <ctime>
using namespace std;

int Comparisons = 0, assign = 0;

void bubbleSort(int arr[], int s);
void swap(int *x, int *y);
void print(int arr[], int s);

int main()
{
    cout << "INPUT AS PER QUESTION" << endl;
    srand(time(0));

    int size = 10;
    cout << "Bubble Sort Analysis \n";
    cout << "Input Size\tBest(comps.)\tBest(Assigns.)\tWorst(Comps.)\tWorst(Assigns.)\tAverage(Comps.)\tAverage(Assigns.)" << endl;

    for (size = 10; size <= 100; size += 5)
    {
        cout << size << "\t\t";
        int *arr = new int[size];

        for (int i = 0; i < size; i++)              // for best Case
        {
            arr[i] = i + 1;
        }

        
        Comparisons = assign = 0;
        bubbleSort(arr, size);
        cout << Comparisons << "\t\t" << assign << "\t\t";

      
        int x = size;
        for (int i = 0; i < size; i++)                     // for worst case
        {
            arr[i] = x--;
        }

        Comparisons = assign = 0;
        bubbleSort(arr, size);
        cout << Comparisons << "\t\t" << assign << "\t\t";

       
        for (int i = 0; i < size; i++)                 // for average case
        {
            arr[i] = rand() % 100 + 1;
        }

        Comparisons = assign = 0;
        bubbleSort(arr, size);
        cout << Comparisons << "\t\t" << assign << "\t\t";

        cout << "\n";
    }

    return 0;
}

// function to print array
void print(int arr[], int s)
{
    for (int i = 0; i < s; i++)
    {
        cout << arr[i] << "\t";
    }
    cout << endl;
}

// function to swap two elements
void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

// function to perform bubble sort on the given array
void bubbleSort(int arr[], int s)
{
    int counter = 1;
    bool f;

    while (counter < s)
    {
        f = false;
        for (int i = 0; i < s - counter; i++)
        {
            Comparisons++;
            if (arr[i] > arr[i + 1])
            {
                swap(&arr[i + 1], &arr[i]);

                assign += 3;
                f = true;
            }

            Comparisons++;
        }
        Comparisons++;

        if (f == false)
        {
            break;
        }

        counter++;
        Comparisons++;
    }
    Comparisons++;
}
