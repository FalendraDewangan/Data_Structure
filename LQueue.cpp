#include<iostream>
using namespace std;

template<class T>
struct Node{
    T ele;
    Node<T> *next=NULL;
};

template<class T>
class Queue{
    Node<T> *head;
    Node<T> *tail;
    int count;
    public:
    Queue() {
        head=tail=NULL;
        count=0;
    }      
    const T& front() const;
    bool empty() const;
    void push(T);
    int size() const;
    void pop();
    ~Queue(){
        delete head;
    }
};

template<class T>
const T& Queue<T> :: front() const{
    if(empty())
        throw "Empty List ";
    return head->ele;
}

template<class T>
bool Queue<T>::empty() const{
    return head==NULL;
}

template<class T>
void Queue<T> :: push(T obj){
    Node<T> *temp_obj=new Node<T>;
    temp_obj->ele=obj;
    if(empty()){
        head=tail=temp_obj;
        count++;
        return;
    }
    tail->next=temp_obj;
    tail=temp_obj;
    count++;
}

template<class T>
void Queue<T>::pop(){
    if(empty())
        throw "Empty list";
    Node<T> *old=head;
    head=head->next;
    delete old;
    count--;
}

template<class T> 
int Queue<T>:: size() const{
    return count;
}

int main(){
    return 0;
}
template class Queue<int>;