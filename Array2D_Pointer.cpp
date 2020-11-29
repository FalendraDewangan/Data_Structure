#include <iostream>
using namespace std;

template <class T>
class Array2D
{
    T **element;
    int rows, cols;

public:
    Array2D(int, int);
    Array2D(const Array2D<T>&);
    T& operator()(int,int) const;
    Array2D<T> operator+(const Array2D<T> &);
    Array2D<T> operator-(const Array2D<T> &);
    Array2D<T> operator*(const Array2D<T> &);
    template <class U>
    friend istream& operator>>(istream& ,const Array2D<U>& );
    template <class U>
    friend ostream& operator<<(ostream&,const Array2D<U>& );
    ~Array2D()
    {
        for (int i = 0; i < cols; i++)
            delete[] element[i];
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
    element = new int *[rows];
    for (int i = 0; i < rows; i++)
        element[i] = new int[cols];
}


template<class T>
Array2D<T> :: Array2D(const Array2D<T>& obj){
    this->rows = obj.rows;
    this->cols = obj.cols;
    element = new T*[rows*cols];        
    for (int i = 0; i < rows*cols; i++){
        element[i] = new int[cols];
        for (int j = 0; j < rows*cols; j++)
       (*this).element[i][j] = obj.element[i][j];
    }   
}

template <class T>
T& Array2D<T> :: operator()(int i, int j)const{
    if (i>=rows||j>=cols)
    throw "Out of bound";
    return element[i][j];
}

template <class T>
Array2D<T> Array2D<T>::operator+(const Array2D &b)
{
    if ((*this).rows != b.rows || (*this).cols != b.cols)
        throw "Invalid size of arrray is being adding ";
    Array2D<T> temp((*this).rows, (*this).cols);
    for (int i = 0; i < (*this).rows; i++)
        for (int j = 0; j < (*this).cols; j++)
            temp.element[i][j] = (*this).element[i][j] + b.element[i][j];

    return temp;
}

template <class T>
Array2D<T> Array2D<T>::operator-(const Array2D<T> &b)
{
    if ((*this).rows != b.rows || (*this).cols != b.cols)
        throw "Invalid size of arrray is being subtracting ";
    Array2D temp((*this).rows, (*this).cols);
    for (int i = 0; i < (*this).rows; i++)
        for (int j = 0; j < (*this).cols; j++)
            temp.element[i][j] = (*this).element[i][j] - b.element[i][j];

    return temp;
}

template <class T>
Array2D<T> Array2D<T>::operator*(const Array2D<T> &b)
{
    if ((*this).rows != b.rows || (*this).cols != b.cols)
        throw "Invalid size of arrray is being multipling ";
    Array2D<T> temp((*this).rows, (*this).cols);
    for (int i = 0; i < (*this).rows; i++)
        for (int j = 0; j < (*this).cols; j++)
            temp.element[i][j] = (*this).element[i][j] * b.element[i][j];

    return temp;
}

template <class U>
istream& operator>>(istream& in,const Array2D<U>& obj)
{
    for (int i = 0; i < obj.rows; i++)
            for (int j = 0; j < obj.cols; j++)
                in >> obj.element[i][j];
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
    
    c=a+b;
    // cin >> a;
    // cout << (a+b);
    cout << c;

    return 0;
}
template class Array2D<int>;
// template class Array2D<char>;
// template class Array2D<float>;