#include <iostream>
using namespace std;

template <class T>
class Array2D
{
    T *element;
    int rows, cols;

public:
    Array2D(int, int);
    Array2D(const Array2D<T>&);
    T& operator()(int,int) const;
    Array2D<T> operator+(const Array2D<T> &);
    Array2D<T> operator-(const Array2D<T> &);
    Array2D<T> operator*(const Array2D<T> &);
    Array2D<T> operator/(const Array2D<T> &b);
    template <class U>
    friend istream& operator>>(istream& ,const Array2D<U>& );
    template <class U>
    friend ostream& operator<<(ostream&,const Array2D<U>& );
    ~Array2D()
    {
        delete[] element;
    }
};

template <class T>
Array2D<T> :: Array2D(int rows, int column)
{
    if (rows < 0 || column < 0)
        throw "Bad Initializers ";
    this->rows = rows;
    this->cols = column;
    element = new T[rows*cols];
}

template<class T>
Array2D<T> :: Array2D(const Array2D<T>& obj){
    this->rows = obj.rows;
    this->cols = obj.cols;
    element = new T[rows*cols];
    for (int i = 0; i < rows*cols; i++)
       (*this).element[i] = obj.element[i];

}

template <class T>
T& Array2D<T> :: operator()(int i, int j) const{
    if (i>=rows||j>=cols)
    throw "Out of bound";
    return this->element[(i*cols)+j];     // Row wise
    // return element[(j*rows)+i];     // Column wise
}

template <class T>
Array2D<T> Array2D<T>::operator+(const Array2D &b)
{
    if ((*this).rows != b.rows || (*this).cols != b.cols)
        throw "Invalid size of arrray is being adding ";
    Array2D temp((*this).rows, (*this).cols);
    for (int i = 0; i < rows*cols; i++)
            temp.element[i] = (*this).element[i] + b.element[i];

    return temp;
}

template <class T>
Array2D<T> Array2D<T>::operator-(const Array2D<T> &b)
{
    if ((*this).rows != b.rows || (*this).cols != b.cols)
        throw "Invalid size of arrray is being adding ";
    Array2D temp((*this).rows, (*this).cols);
    for (int i = 0; i < rows*cols; i++)
            temp.element[i] = (*this).element[i] - b.element[i];

    return temp;
}

template <class T>
Array2D<T> Array2D<T>::operator*(const Array2D<T> &b)
{
    if ((*this).rows != b.rows || (*this).cols != b.cols)
        throw "Invalid size of arrray is being adding ";
    Array2D temp((*this).rows, (*this).cols);
    for (int i = 0; i < rows*cols; i++)
            temp.element[i] = (*this).element[i] * b.element[i];

    return temp;
}

template <class T>
Array2D<T> Array2D<T>::operator/(const Array2D<T> &b)
{
    if ((*this).rows != b.rows || (*this).cols != b.cols)
        throw "Invalid size of arrray is being adding ";
    Array2D temp((*this).rows, (*this).cols);
    for (int i = 0; i < rows*cols; i++)
            temp.element[i] = (*this).element[i] / b.element[i];

    return temp;
}

template <class U>
istream& operator>>(istream& in,const Array2D<U>& obj)
{
    for (int i = 0; i < obj.rows*obj.cols; i++)
                in >> obj.element[i];
    return in;
}

template <class U>
ostream& operator<<(ostream& out, const Array2D<U>& obj)
{
    
    for (int i = 0; i < obj.rows; i++)
        {
            for (int j = 0; j < obj.cols; j++)
                out << " " << obj(i,j);
            out<<endl;
        }

    return out;
}

int main()
{
    Array2D<int> a(2, 2);
    Array2D<int> b(2, 2);
    Array2D<int> c(2, 2);

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            a(i,j)=i;
            b(i,j)=i;
        }
        
    }
    

    // cin >> a;
    // cin >> b;
    c= a+b;
    cout << c;

    return 0;
}
template class Array2D<int>;
// template class Array2D<char>;
// template class Array2D<float>;