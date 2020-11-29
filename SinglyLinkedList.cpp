#include<iostream>
using namespace std;


class Node{
    int element;
    Node *next = NULL;
    friend class Singly_LinkedList;
};


class Singly_LinkedList{
    Node *head;
    public:
    Singly_LinkedList(){
        head=NULL;
    }
    void add(int, int);                                  // Add at any position
    void addFront(int);                                  // Funcintion into add at Front
    void addLast(int);                                   // Function into add at last
    int& search(int value);
    bool isEmpty() const;
    int  size();                                         
    void remove(int);                                   
    void removeFront();
    Singly_LinkedList operator+(const Singly_LinkedList&);                    // To concatinate
    void Display();
};


void Singly_LinkedList :: add(int obj, int position){
    Node *temp_obj=new Node;
    temp_obj->element=obj;
    if(position==1){
        temp_obj->next=head;
        head=temp_obj;
        return;
    }
    Node *temp = head;
    int count=1;
    while (temp!=NULL && count<position-1)
    {
        temp=temp->next;
        count++;
    }
    if(temp==NULL)
        throw "Invalid Position ";
    temp_obj->next=temp->next;
    temp->next=temp_obj;
}


void Singly_LinkedList :: addFront(int obj){
    Node *temp= new Node;
    temp->element = obj;
    temp->next = head;
    head = temp;
}

 
void Singly_LinkedList :: addLast(int obj){
    if(head==NULL){
        addFront(obj);
        return;
    }
    Node *temp=head;
    while (temp->next!=NULL)
    {
        temp=temp->next;
    }
    Node *temp_obj = new Node;
    temp_obj->element=obj;
    temp->next=temp_obj;
}

int& Singly_LinkedList :: search(int value){
    Node *temp=head;
    while (temp!=NULL)
    {
        if(temp->element==value)
            return temp->element;
        temp=temp->next;
    }
    throw "Element not in list is being searching ";
}

bool Singly_LinkedList :: isEmpty() const{
    return head==NULL;
}


int Singly_LinkedList :: size(){
    int count=0;
    Node* temp=head;
    while (temp!=NULL)
    {
        count++;
        temp=temp->next;
    }
    return count;
}


void Singly_LinkedList :: remove(int position){
    Node *temp = head;
    int count=1;
    if(position==1){
        Node *old=head;
        head=head->next;
        delete old;
        return;
    }
    while (temp!=NULL && count<position-1)
    {
        temp=temp->next;
        count++;
    }
    if(temp==NULL)
        throw "Invalid position ";
    Node *old=temp->next;
    temp->next=old->next;
    delete old;
}


void Singly_LinkedList :: removeFront(){
    if(head==NULL)
    throw "Removing from Empinty list";
    Node *old=head;
    head=head->next;
    delete old;
}


Singly_LinkedList Singly_LinkedList:: operator +(const Singly_LinkedList& obj){
    Node *temp=this->head;
    Singly_LinkedList temp_list;
    while (temp!=NULL)
    {
        temp_list.addLast(temp->element);
        temp=temp->next;
    }
    temp=obj.head;
    while(temp!=NULL){
        temp_list.addLast(temp->element);
        temp=temp->next;
    }
    return temp_list;
}


void Singly_LinkedList :: Display(){
    if(head == NULL)
        cout<<"Empty List ";
    else
    {
        Node* temp=head;
        while (temp!=NULL)
        {
            cout<<temp->element<<" ";
            temp=temp->next;
        }  
    }
}

int main(){
    Singly_LinkedList l1;
    Singly_LinkedList l2;
    Singly_LinkedList l3;
    
    l1.addFront(4);
    l1.addFront(3);
    l1.addFront(2);
    l1.addFront(1);
    cout<<"LIST l1 after adding element : ";
    l1.Display();
    cout<<endl;

    // l2.addFront(5);
    // l2.addLast(6);
    // l2.addLast(7);
    // cout<<"LIST l2 after adding by addFront() and addLast() element : ";
    // l2.Display();
    // cout<<endl;

    // l3=l1+l2;
    // cout<<"List l3 after concatination of l1 and l2 : ";
    // l3.Display();
    // cout<<endl;
    // int a=l3.search(6);
    // cout<<"Element after search function called : "<<a<<endl;
    // l3.remove(5);
    // cout<<"List l3 after remove(5) function called : ";
    // l3.Display();
    // cout<<"\nSize of l3 : "<<l3.size();
    
    return 0;
}