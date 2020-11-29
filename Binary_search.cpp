#include<iostream>
using namespace std;

void Binary_search(int *p, int size, int find){
	int first = 0;
	int last = size-1;
	int middle = (first+last)/2;
	while (first <= last)
	{
		if(p[middle] < find)
		{
			first = middle + 1;

		}
		else if(p[middle] == find)
		{
			cout<<find<<" is preent at location "<<middle+1<<"\n";
			return;
		}
		else
		{
			 last = middle - 1;
		}
		middle = (first + last)/2;
	}
	if(first > last)
	{
		cout<<"Not found! "<<find<<" is not in the given array";
	}
}

int main()
{
	int n;
	cout<<"Enter total number of elements :";
	cin>>n;
	int arr[n],x;
	
	cout<<"Enter "<<n<<" number by ascending order:";
	for (int i=0; i<n; i++)
	{
		cin>>arr[i];
	}
	cout<<"Enter the number to find :";
	cin>>x;
	Binary_search(arr, n, x);
	
	return 0;
}
