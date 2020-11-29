#include <iostream>
using namespace std;

void Insertion_sort(int *p, int size)
{
    int temp;
    for (int i = 0; i < size-1; i++)
    {
        int j = i + 1;
        while (j > 0 && p[j - 1] > p[j])
        {
            temp = p[j - 1];
            p[j - 1] = p[j];
            p[j] = temp;
            j--;
        }
    }
}

int main()
{
    int size;
    cout << "Enter the size of the array:";
    cin >> size;
    int arr[size];
    cout << "Enter the elements of the array:";
    for (int i = 0; i < size; i++)
        cin >> arr[i];
    Insertion_sort(arr, size);
    for (int i = 0; i < size; i++)
        cout << arr[i];
    return 0;
}