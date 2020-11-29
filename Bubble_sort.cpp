#include<iostream>
using namespace std;

void Bubble_sort(int*p, int size){
    int temp;
    bool sorted=false;
    for (int i = 0; !sorted && i < size; i++)
    {   sorted=true;
        for (int j = 0; j < size-i-1; j++)
        {   temp=p[j];
            if (temp>p[j+1])
            {   
                sorted=false;
                p[j]=p[j+1];
                p[j+1]=temp;
            }
            
        }
    }
}

int main(){
    int size;
	cout<<"Enter the size of the array:";
	cin>>size;
	int arr[size];
	cout<<"Enter the elements of the array:";
	for(int i=0;i<size;i++)
		cin>>arr[i];
    Bubble_sort(arr, size);
    for(int i=0;i<size;i++)
		cout<<arr[i];
    return 0;
}