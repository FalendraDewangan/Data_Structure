#include<iostream>
using namespace std;

void Selection_sort(int*p, int size){
    int min, temp;
    for (int i = 0; i < size-1; i++)
    {
        min=i;
        for (int j = i+1; j < size; j++)
            if(p[j]<p[min])
                min=j;
        
        temp=p[min];
        p[min]=p[i];
        p[i]=temp;
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
    Selection_sort(arr, size);
    for (int i = 0; i < size; i++)
        cout << arr[i];
    return 0;
}