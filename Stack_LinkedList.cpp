#include<iostream>
using namespace std;

template <class T>
struct Node{
    T ele;
    Node<T> *next=NULL;
};

template<class T>
class LStack{
    Node<T> *head;
    int count;
    public:
    LStack(){
        head=NULL;
        count=0;
    }
    const T& front() const;
    bool empty() const;
    void push(T);
    void pop();
    int size() const;
    ~LStack(){
        delete head;
    }
};

template<class T>
const T& LStack<T>::front() const{
    if(empty())
        throw "Empty stack";
    return head->ele;
}
template <class T>
bool LStack<T>::empty() const{
    return count==0;
}

template <class T>
void LStack<T> ::push(T obj){
    Node<T> *temp=new Node<T>;
    temp->ele=obj;
    temp->next=head;
    head=temp;
    count++;
}

template <class T>
void LStack<T>::pop(){
    if(empty())
        throw "Empty Stack";
    Node<T> *old=head;
    head=head->next;
    delete old;
}

template<class T>
int LStack<T>::size() const{
    return count;
}
int main(){
    LStack<int> q;
    q.push(5);
    q.push(3);
    q.front();
    q.size();
    q.pop();
    q.push(7);
    q.pop();
    q.front();
    q.pop();
    return 0;
}
template class LStack<int>;