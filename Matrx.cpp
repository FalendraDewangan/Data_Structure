#include <iostream>
using namespace std;

template <class T>
class Matrix
{
    T *element;
    int rows, cols;

public:
    Matrix(int, int);
    Matrix(const Matrix<T> &);
    T& operator()(int,int);
    int getRow();
    int getColumn();
    Matrix<T> operator+(const Matrix<T> &);
    Matrix<T> operator-(const Matrix<T> &);
    Matrix<T> operator*(const Matrix<T> &);
    Matrix<T> operator/(const Matrix<T> &b);
    template <class U>
    friend istream& operator>>(istream& ,const Matrix<U>& );
    template <class U>
    friend ostream& operator<<(ostream&,const Matrix<U> );
    ~Matrix()
    {
        delete[] element;
    }
};

template <class T>
Matrix<T> :: Matrix(int rows, int column)
{
    if (rows < 1 || column < 1)
        throw "Bad Initializers ";
    this->rows = rows;
    this->cols = column;
    element = new T[rows*cols];
}

template<class T>
Matrix<T> :: Matrix(const Matrix<T>& obj){
    this.rows = obj.rows;
    this.cols = obj.cols;
    element = new T[rows*cols];
    for (int i = 0; i < rows*cols; i++)
       (*this).element[i] = obj.element[i];

}

template <class T>
T& Matrix<T> :: operator()(int i, int j){
    if (i<1||i>rows||j<1||j>cols)
    throw "Out of bound";
    return this->element[(i-1)*cols+j-1];     // Row wise
    // return this->element[(j-1)*rows+i-1];     // Column wise
} 

template <class T>
int Matrix<T> :: getRow(){
    return rows;
}

template <class T>
int Matrix<T> :: getColumn(){
    return cols;
}

template <class T>
Matrix<T> Matrix<T>::operator+(const Matrix &b)
{
    if ((*this).rows != b.rows || (*this).cols != b.cols)
        throw "Invalid size of arrray is being adding ";
    Matrix temp((*this).rows, (*this).cols);
    for (int i = 0; i < rows*cols; i++)
            temp.element[i] = (*this).element[i] + b.element[i];

    return temp;
}

template <class T>
Matrix<T> Matrix<T>::operator-(const Matrix<T> &b)
{
    if ((*this).rows != b.rows || (*this).cols != b.cols)
        throw "Invalid size of arrray is being adding ";
    Matrix temp((*this).rows, (*this).cols);
    for (int i = 0; i < rows*cols; i++)
            temp.element[i] = (*this).element[i] - b.element[i];

    return temp;
}

template <class T>
Matrix<T> Matrix<T>::operator*(const Matrix<T> &b)
{
    if ((*this).rows != b.rows || (*this).cols != b.cols)
        throw "Invalid size of arrray is being adding ";
    Matrix temp((*this).rows, (*this).cols);
    for (int i = 0; i < rows*cols; i++)
            temp.element[i] = (*this).element[i] * b.element[i];

    return temp;
}

template <class T>
Matrix<T> Matrix<T>::operator/(const Matrix<T> &b)
{
    if ((*this).rows != b.rows || (*this).cols != b.cols)
        throw "Invalid size of arrray is being adding ";
    Matrix temp((*this).rows, (*this).cols);
    for (int i = 0; i < rows*cols; i++)
            temp.element[i] = (*this).element[i] / b.element[i];

    return temp;
}

template <class U>
istream& operator>>(istream& in,const Matrix<U>& obj)
{
    for (int i = 0; i < obj.rows*obj.cols; i++)
                in >> obj.element[i];
    return in;
}

template <class U>
ostream& operator<<(ostream& out, const Matrix<U> obj)
{
    
    for (int i = 0; i < obj.rows; i++)
        {
            for (int j = 0; j < obj.cols; j++)
                // out << " " << obj(i,j);      //error
                out << " " << obj.element[i*obj.cols+j];
            out<<endl;
        }

    return out;
}

int main()
{
    try
    {
        Matrix<int> a(2, 2);
        Matrix<int> b(2, 2);
    // Matrix b(2, 2);

    // for (int i = 0; i < 2; i++)
    // {
    //     for (int j = 0; j < 2; j++)
    //     {
    //         a(i,j)=i;
    //         b(i,j)=i;
    //     }
        
    // }
    

    cin >> a;
    cin >> b;
    // cout << (a+b);
    cout << a+b;
    }
    catch(char* e)
    {
        cout << endl <<endl<<*e<< '\n';
    }
    
    

    return 0;
}
template class Matrix<int>;
// template class Matrix<char>;
// template class Matrix<float>;