#include<iostream>
using namespace std;
template<class T>
class Stack{
    T *data;
    int t,N;
    public:
    Stack(){
        t=-1;
        N=10;
        data=new T[N];
    }
    const T& front() const;
    bool empty() const;
    void push(T);
    void pop();
    int size() const;
    ~Stack(){
        delete data;
    }
};

template<class T>
const T& Stack<T> :: front() const{
    if(empty())
        throw "Empty stack";
    return data[0];
}

template<class T>
bool Stack<T> :: empty() const{
    return !(t==N-1);
}
template<class T>
void Stack<T>:: push(T obj){
    if(!empty())
        throw "Stack Full";
    data[++t]=obj;
}

template<class T>
void Stack<T>::pop(){
    if(empty())
        throw "Empty Stack";
    t--;
}

template<class T>
int Stack<T>::size() const{
    return t+1;
}

int main(){

    return 0;
}
template class Stack<int>;