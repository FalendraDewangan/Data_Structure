#include<iostream>
using namespace std;

int Fibonacii(int n){
    if(n==1 || n==2)
        return 1;
    else if(n==0)
        return 0;
    return Fibonacii(n-1)+Fibonacii(n-2);
}

int main(){
    int n;
    cout<<"Enter the no. of term : ";
    cin>>n;
    cout<<"The "<<n<<"th term is : "<<Fibonacii(n);
    return 0;
}