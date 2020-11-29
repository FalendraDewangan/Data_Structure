#include<iostream>
using namespace std;

class Singly_LinkedList;

class Node{
    private:
    int element;
    Node *next = NULL;
    friend class Singly_LinkedList;
    friend ostream& operator<<(ostream& out, Singly_LinkedList& obj);
};

class Singly_LinkedList{
    Node *head, *tail;
    public:
    Singly_LinkedList(){
        head=tail=NULL;
    }
    ~Singly_LinkedList();
    void add(int, int);                                  // Add at any position
    void addFront(int);                                  // Funcintion into add at Front
    void addLast(int);                                   // Function into add at tail
    int& search(int value);
    bool isEmpty() const;
    int  size();                                         
    void remove(int);                                      // to remove from position               
    void removeFront();                                    //to remove from front
    void removeLast();                                     // to remove from tail
    void reverse();                                         // to reverse linked list
    void operator+(const Singly_LinkedList&);                    // To concatinate
    friend ostream& operator<<(ostream&, Singly_LinkedList&);
};


void Singly_LinkedList :: add(int obj, int position){
    Node *temp_obj=new Node;
    temp_obj->element=obj;
    if(isEmpty()){
        head=tail=temp_obj;
        return;
    }
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
    if(isEmpty()){
        head=tail=temp;
        return;
    }
    temp->next = head;
    head = temp;
}

 
void Singly_LinkedList :: addLast(int obj){
    if(head==NULL){
        addFront(obj);
        return;
    }
    Node *temp_obj = new Node;
    temp_obj->element=obj;
    tail->next=temp_obj;
    tail=temp_obj;
}

int& Singly_LinkedList :: search(int value){
    Node *temp=head;
    while (temp!=NULL)
    {
        if(temp->element==value)
            return temp->element;
        temp=temp->next;
    }
    throw "Element not found ";
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
    if(temp->next==NULL)
        tail=temp;
    delete old;
}


void Singly_LinkedList :: removeFront(){
    if(head==NULL)
    throw "Removing from Empinty list";
    Node *old=head;
    head=head->next;
    delete old;
}

void Singly_LinkedList :: removeLast(){
    Node *old=head;
    if(head==tail){
        delete old;
        head=tail=NULL;
        return;
    }
    Node *temp;
    while (old->next!=NULL)
    {
        temp=old;
        old=old->next;
    }
    tail = temp;
    tail->next=NULL;
    delete old;

}

void Singly_LinkedList :: reverse(){
    if(head==NULL)
        return;
    Node *p1, *p2, *p3;
    p1 = head;
    p2 = head->next;
    if(p1==NULL)
        return;
    while (p2!=NULL ){
        p3=p2->next;
        p2->next=p1;
        p1=p2;
        p2=p3;
    }
    head->next=NULL;
    tail=head;
    head=p1;
}

void Singly_LinkedList:: operator +(const Singly_LinkedList& obj){
    this->tail->next=obj.head;
}

ostream& operator<<(ostream& out, Singly_LinkedList& obj){
    if(obj.head == NULL)
        out<<"Empty List ";
    else
    {
        Node* temp=obj.head;
        while (temp!=NULL)
        {
            out<<temp->element<<" ";
            temp=temp->next;
        }  
    }
    return out;
}
Singly_LinkedList :: ~Singly_LinkedList(){
    Node *temp=head;
    while (head!=NULL)
    {
        head=head->next;
        delete temp;
        temp=head;
    }
    tail=head;
}

int main(){

    // Just checking the Function 

    Singly_LinkedList l1;
    Singly_LinkedList l2;
    
    l1.addFront(4);
    l1.addFront(3);
    l1.addFront(2);
    l1.addFront(1);
    cout<<"LIST l1 after adding element : "<<l1<<endl;
    l1.add(9,2);
    cout<<"List l1 after calling add(9, 2) : "<<l1<<endl;
    l2.addFront(5);
    l2.addLast(6);
    l2.addLast(7);
    cout<<"LIST l2 after adding by addFront() and addLast() element : "<<l2<<endl;

    l1+l2;
    cout<<"List l1 after concatination of l1 and l2 : "<<l1<<endl;

    int a=l1.search(6);
    cout<<"Element after search(6) function called : "<<a<<endl;
    l1.remove(5);
    cout<<"List l1 after remove(5) function called : "<<l1<<endl;
    l1.reverse();
    cout<<"The list l1 after reversing it : "<<l1<<endl;
    l1.removeLast();
    cout<<"The list l3 after removing last element : "<<l1<<endl;
    cout<<"\nSize of l1 : "<<l1.size();
    return 0;
}