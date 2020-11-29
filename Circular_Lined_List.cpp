#include<iostream>
using namespace std;

struct Node{
    int ele;
    Node * next;
};

class C_List{
    Node *cursor;
    public:
    C_List(){
        cursor=NULL;
    }
    
    void addFront(int);
    void addLast(int);
    void insert(int, int);
    void removeFront();
    void removeLast();
    void remove(int);                   // Remove an element x from the list
    int& search(int) const;
    void operator+(C_List&);        // To concatinate
    friend ostream& operator<<(ostream&, const C_List&);
    ~C_List(){
        Node *temp=cursor->next;
        cursor->next=NULL;
        cursor=temp;
        while(cursor!=NULL){
            cursor=cursor->next;
            delete temp;
            temp=cursor; 
        }
    }
};

void C_List::addFront(int value){
    Node *temp=new Node;
    temp->ele=value;
    if(cursor==NULL){
        cursor=temp;
        temp->next=cursor;
        return;
    }
    temp->next=cursor->next;
    cursor->next=temp;
}

void C_List::addLast(int value){
    if(cursor==NULL){
        addFront(value);
        return;
    }
    Node *temp=new Node;
    temp->ele=value;
    temp->next=cursor->next;
    cursor->next=temp;
    cursor=temp;
}
void C_List::insert(int pos, int value){
    if(pos==1){
        addFront(value);
        return;
    }
    int count=1;
    Node *temp=cursor->next;
}

void C_List::removeFront(){
    if(cursor==NULL)
        return;
    bool last=false;
    if(cursor->next==cursor)
        last=true;
    Node *temp=cursor->next;
    cursor->next=temp->next;
    delete temp;
    if(last)
        cursor=NULL;
}

void C_List::removeLast(){
    if(cursor==NULL)
        return;
    if(cursor->next==cursor){
        delete cursor;
        cursor=NULL;
        return;
    }
    Node *temp=cursor->next;
    while (temp->next!=cursor)
        temp=temp->next;
    temp->next=cursor->next;
    delete cursor;
    cursor=temp;
}

void C_List::remove(int value){
    if(cursor==NULL)
        return;
    Node *temp=cursor->next;
    Node *previous=cursor;
    while(temp!=cursor){
        if(temp->ele==value)
            break;
        previous=temp;
        temp=temp->next;
    }
    if(temp==cursor && temp->ele==value){
        removeLast();
        return;
    }
    previous->next=temp->next;
    delete temp;
}

int& C_List::search(int value) const{
    if(cursor==NULL)
        throw "Empty List ";
    Node *temp=cursor->next;
    do
    {
        if(temp->ele==value)
            return temp->ele;
        temp=temp->next;
    } while (temp!=cursor->next);
    throw "Element is not present in list ";
}

void C_List::operator+(C_List& obj){
    if(obj.cursor==NULL)
        return;
    Node *temp=this->cursor->next;
    this->cursor->next=obj.cursor->next;
    this->cursor=obj.cursor;
    this->cursor->next=temp;
    obj.cursor=NULL;
}

ostream& operator<<(ostream& out, const C_List& obj){
    if(obj.cursor==NULL){
        out<<"Empty List ";
        return out;
    }
    Node *temp=obj.cursor->next;
    do
    {
        out<<temp->ele<<" ";
        temp=temp->next;
    } while (temp!=obj.cursor->next);
    return out;
}

int main(){
    char c;
    int choice;
    C_List c1,c2;
    c1.addFront(5);
    c1.addFront(4);
    c1.addFront(3);
    c1.addFront(2);
    c1.addFront(1);
    cout<<"c1 after calling addFront for 5,4,3,2,1 : "<<c1<<endl;
    c2.addLast(6);
    c2.addLast(7);
    c2.addLast(8);
    c2.addLast(9);
    c2.addLast(10);
    cout<<"c2 after calling addLast for 6,7,8,9,10 : "<<c2<<endl;
    c1+c2;
    cout<<"c1 after c1=c1+c2 : "<<c1<<endl;
    c1.insert(5,77);
    cout<<"c1 after c1.insert(5,77) : "<<c1<<endl;
    c1.removeFront();
    cout<<"c1 after c1.removeFront() : "<<c1<<endl;
    c1.removeLast();
    cout<<"c1 after c1.removeLast() : "<<c1<<endl;
    c1.remove(8);
    cout<<"c1 after c1.remove(8) : "<<c1<<endl;
    int a=c1.search(7);
    cout<<"a after a=c1.search(7) : "<<a<<endl;
    
return 0;
}