#include <iostream>

using namespace std;

template <class T>
class Array1D
{
    T *elearr;
    int lb, ub;

public:
    // Constructor for array with lowerbound and upperbound
    Array1D(int lb = 0, int ub = -1)
    {
        this->ub = ub;
        this->lb = lb;
        if (lb > ub)
            elearr = new T[lb];
        else
            elearr = new T[ub - lb + 1];
    }

    // Functions of the class
    T &operator[](int);
    Array1D<T> operator+(const Array1D<T> &);
    Array1D<T> operator-(const Array1D<T> &);
    Array1D<T> operator*(const Array1D<T> &);
    Array1D<T> operator/(const Array1D<T> &);
    int getSize();
    void reSize(int);
    template <class U>
    friend istream& operator >>(istream&,const Array1D<U>&);
    template <class U>
    friend ostream& operator <<(istream&,const Array1D<U>);
    ~Array1D(){
        delete[] elearr;
    }
};

template <class T>
T &Array1D<T> ::operator[](int i)
{
    if (lb > ub)
    {
        if (i < lb)
            return elearr[i];
        else
            throw "Array Index out of bond";
    }

    if (i << lb || i > ub)
        throw "Array Index out of bond";
    else
        return elearr[i - lb];
}

template <class T>
Array1D<T> Array1D<T> ::operator+(const Array1D<T> &obj)
{
    if (this->getSize() != obj.getSize())
        throw "Unequal ize of array is being added";

    Array1D<T> temp(obj.getSize());
    for (int i = 0; i < this->getSize(); i++)
    {
        temp[i] = (*this)[i] + obj[i];
    }
    return temp;
}

template <class T>
Array1D<T> Array1D<T> ::operator-(const Array1D<T> &obj)
{
    if (this->getSize() != obj.getSize())
        throw "Unequal ize of array is being added";

    Array1D<T> temp(obj.getSize());
    for (int i = 0; i < this->getSize(); i++)
    {
        temp[i] = (*this)[i] - obj[i];
    }
    return temp;
}

template <class T>
Array1D<T> Array1D<T> ::operator*(const Array1D<T> &obj)
{
    if (this->getSize() != obj.getSize())
        throw "Unequal ize of array is being added";

    Array1D<T> temp(obj.getSize());
    for (int i = 0; i < this->getSize(); i++)
    {
        temp[i] = (*this)[i] * obj[i];
    }
    return temp;
}

template <class T>
Array1D<T> Array1D<T> ::operator/(const Array1D<T> &obj)
{
    if (this->getSize() != obj.getSize())
        throw "Unequal ize of array is being added";

    Array1D<T> temp(obj.getSize());
    for (int i = 0; i < this->getSize(); i++)
    {
        temp[i] = (*this)[i] / obj[i];
    }
    return temp;
}

template <class T>
int Array1D<T> ::getSize()
{
    if (ub<lb)
    return lb;

    return ub-lb+1;
}

template <class T>
void Array1D<T> ::reSize(int size)
{
    int *p = new int[size];

    lb = size;
    for (int i = 0; i < this->getSize(); i++)
    {
        p[i] = (*this)[i];
    }
    delete[] this->elearr;
    this->elearr = p;
}

template<class U>
istream& operator >>(istream& in,const Array1D<U>& obj){
    for (int i = 0; i < obj.getSize(); i++)
        cin>>obj[i];
    return in;
}

template<class U>
ostream& operator <<(ostream& out,const Array1D<U> obj) {
    cout<<"{";
    for (int i = 0; i < obj.getSize(); i++){
        cout<<" "<<obj[i];
        if(i<obj.getSize()-1)
        cout<<",";
    }
    cout<<"} ";
    return out;
}

int main()
{
    Array1D<int> a(5);
    Array1D<int> b(5);

    for (int i = 0; i < 5; i++)
    {
        a[i] = i;
        b[i]=i;
    }
    
    cout << (a+b);

    return 0;
}
template class Array1D<int>;
// template class Array1D<char>;
// template class Array1D<double>;