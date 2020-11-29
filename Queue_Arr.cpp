#include<iostream>
using namespace std;

// template<class T>
class Queue {
    int list[10], f, r, n, N;
    public:
    Queue(){
        f=r=n=0;
        N=10;
    }
    const int& front() const{
        if(empty())
            throw "Empty Queue ";
        return list[f];
    }
    const int& rear() const{
        if(empty())
            throw "Empty Queue ";
        return list[r];
    }
    void push(int T){
        if(n==N)
            throw "Queue full ";
        r++;
        if(r==N)
            r=0;
        list[r]=T;
        n++;
    }
    void pop(){
        if(n==0)
            throw "Empty Queue ";
        f++;
        if(f==N)
            f=0;
        n--;
    }
    bool empty() const{
        return n==0;
    }
    int size() const{
        return n;
    }
};

int main(){
    Queue q;
    q.push(5);
    q.push(3);
    q.front();
    q.size();
    q.pop();
    q.push(7);
    q.pop();
    q.front();
    q.pop();
    // q.empty();
    return 0;
}
// template class Queue<int>;
// template class queueI<int>;