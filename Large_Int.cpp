#include<iostream>
using namespace std;

class Large_in;

class Node{
    int ele;
    Node *pre=NULL;
    Node *next=NULL;
    friend class Large_in;
    friend ostream& operator<<(ostream&, const Large_in&);
};

class Large_in{
    Node *head, *tail;
    public:
    Large_in(){
        head=new Node;
        tail=new Node;
        head->next=tail;
        tail->pre=head;
    }
    void addFront(const int& obj);
    void addLast(const int& obj);
    void insert(string s);
    bool empty() const;
    string operator+(const string&);
    Large_in operator+(const Large_in&);
    friend ostream& operator<<(ostream&, const Large_in&);
};

void Large_in :: addFront(const int& obj){
    Node *temp = new Node;
    temp->ele=obj;
    temp->pre=head;
    temp->next=head->next;
    head->next=temp;
    temp->next->pre=temp;
}

void Large_in :: addLast(const int& obj){
    Node *temp = new Node;
    temp->ele=obj;
    tail->pre->next=temp;
    temp->pre=tail->pre;
    temp->next=tail;
    tail->pre=temp;
}

void Large_in::insert(string s){
    int count=0;
    string num;
    bool added;
    for (int i = 0; i < s.length(); i++)
    {
        added=false;
        num+=s[i];
        count++;
        if(count%4==0){
            addFront(stoi(num));
            added=true;   
        }
    }
        if(added==false)
            addFront(stoi(num));
}

bool Large_in::empty() const{
    return head->next==tail;
}

string Large_in::operator+(const string& obj){
    Large_in temp;
    temp.insert(obj);
    temp=temp+(*this);
    Node *node=temp.head->next;
    string num="";
    while (node!=tail)
    {
        num=num+to_string(node->ele);
    }
    return num;
    
}

Large_in Large_in::operator+(const Large_in& obj){
    if(obj.empty())
        return *this;
    if(this->empty())
        return obj;
    Large_in p3;
    Node *p1=this->tail->pre;
    Node *p2=obj.tail->pre;
    int carry=0;
    while (p1!=this->head || p2!=obj.head)
    {
        carry=0;
        if(p1==this->head){
            int temp=carry+p2->ele;
            carry=temp/10000;
            p3.addFront(temp%10000);
            p2=p2->pre;
        }
        else if(p2==obj.head){
            int temp=carry+p1->ele;
            carry=temp/10000;
            p3.addFront(temp%10000);
            p1=p1->pre;
        }
        else{
            int temp=carry+p1->ele+p2->ele;
            carry=temp/10000;
            p3.addFront(temp%10000);
            p1=p1->pre;
            p2=p2->pre;
        }
    }
    if(carry!=0)
        p3.addFront(carry);
    return p3;
}

ostream& operator<<(ostream& out, const Large_in& obj){
    if(obj.empty()){
        out<<"Empty list ";
        return out;
    }
    Node *temp=obj.head->next;
    while (temp!=obj.tail)
    {
        out<<temp->ele;
        temp=temp->next;
    }
    return out;
}


int main(){
    string num;
    int size;
    cout<<"Enter the no. of element you want to add : ";
    cin>>size;
    Large_in numbers[size];
    string result;
    for (int i = 0; i < size; i++)
    {
        cout<<"Enter the large integer : ";
        cin>>num;
        numbers[i].insert(num);
        result=numbers[i]+result;
    }
    cout<<"Result : "<<result;

    return 0;
}