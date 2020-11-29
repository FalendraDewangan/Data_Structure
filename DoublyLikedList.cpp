#include<iostream>
using namespace std;

class DList;

class Node{
    int element;
    Node *prev=NULL; 
    Node *next=NULL;
    friend DList;
    friend ostream& operator<<(ostream&, const DList&);
};

class DList{
    Node *head;
    Node *tail;
    public:
    DList(){
        head=new Node;
        tail=new Node;
        head->next=tail;
        tail->prev=head;
    }
    void addFront(const int&) const;
    void insert(const int&, const int&);
    void addLast(const int&);
    bool empty() const;
    const int& front()const;
    const int& back()const;
    void removeFront();
    void removeLast();
    void remove(const int&);
    void reverse();
    void operator+(DList&);
    friend ostream& operator<<(ostream&, const DList&);
    ~DList(){
        while(!empty())
            removeFront();
        delete head;
        delete tail;
    }
};

bool DList :: empty() const{
    return head->next==tail;
}

void DList :: addFront(const int& obj) const{
    Node *temp = new Node;
    temp->element=obj;
    temp->prev=head;
    temp->next=head->next;
    head->next=temp;
    temp->next->prev=temp;
}

void DList :: addLast(const int& obj){
    Node *temp = new Node;
    temp->element=obj;
    tail->prev->next=temp;
    temp->prev=tail->prev;
    temp->next=tail;
    tail->prev=temp;
}

void DList :: insert(const int& position, const int& value){
    Node *temp = head;
    int count=0;
    while (temp!=tail && count<position-1)
    {
        temp=temp->next;
        count++;
    }
    if(temp==tail)
        throw "Invalid Position ";
    Node *temp_obj = new Node;
    temp_obj->next=temp->next;
    temp_obj->prev = temp;
    temp->next=temp_obj;
    temp->next->prev=temp;
}

const int& DList :: front() const{
    if(empty())
        throw "Empty list ";
    return head->next->element;
}

const int& DList :: back() const{
    if(empty())
        throw "Empty list ";
    return tail->prev->element;
}

void DList :: removeFront(){
    if(empty())
        throw "Empty list ";
    Node *temp=head->next;
    head->next=head->next->next;
    delete temp;
}

void DList :: removeLast(){
    if(empty())
        throw "Empty list ";
    Node *temp=tail->prev;
    tail->prev=temp->prev;
    delete temp;
}

void DList :: remove(const int& position){
    if(empty())
        throw "Empty List ";
    Node *temp=head->next;
    int count=1;
    while (temp!=tail && count<position-1)
    {
        temp=temp->next;
        count++;
    }
    Node *temp_obj=temp->next;
    temp->next=temp_obj->next;
    temp_obj->next->prev=temp_obj->prev;
    delete temp_obj;
}

void DList :: reverse(){
    if(empty())
        throw "Empty List ";
    Node *head_obj=head->next;
    Node *tail_obj=tail->prev;
    int temp;
    while(head->next!=tail || head!=tail){
        temp=head_obj->element;
        head_obj->element=tail_obj->element;
        tail_obj->element=temp;
        head_obj=head_obj->next;
        tail_obj=tail_obj->prev;
    }
}

void DList :: operator+(DList& obj){
    this->tail->prev->next=obj.head->next;
    obj.head->next->prev=this->tail->prev;
    this->tail->prev=obj.tail->prev;
    obj.tail->prev->next=this->tail;
    obj.head->next=obj.tail;
    obj.tail->prev=head;
}

ostream& operator<<(ostream&, const DList& obj){
    if(obj.empty()){
        cout<<"Empty List "<<endl;
        return;
    }
    Node *temp=obj.head->next;
    while (temp!=obj.tail){
        cout<<temp->element<<" ";
        temp=temp->next;
    }
}

int main(){
cout<<"hello";
return 0;
}