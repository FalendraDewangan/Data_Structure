#include<iostream>
using namespace std;

void Linear_search(int *p, int size, int x){
    bool flag=false;
    int index;
    for(int i=0;i<size;i++)
	{
			if(p[i]==x)
			{
				flag=true;
				index=i+1;
				break;
			}
		
		}
		if(flag)
		{
			cout<<"The element present at index "<<index<<endl;
		}
		else
			cout<<"The element is not in the array"<<endl;
}

int main()
{
	int size;
	cout<<"Enter the size of the array:";
	cin>>size;
	int arr[size],x;
	cout<<"Enter the elements of the array:";
	for(int i=0;i<size;i++)
		cin>>arr[i];
	cout<<"Enter the element want to search:";
	cin>>x;
    Linear_search(arr, size, x);
	return 0;
}
