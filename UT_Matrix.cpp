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
    void store(int, int, T) const;
    T retrive(int, int) const;
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
Matrix<T> :: Matrix(int r, int c)
{
    if (r < 1 || c < 1)
        throw "Bad Initializers ";
    this->rows = r;
    this->cols = c;
    element = new T[(rows*(rows+1))/2];
}

template<class T>
Matrix<T> :: Matrix(const Matrix<T>& obj){
    this.rows = obj.rows;
    this.cols = obj.cols;
    element = new T[rows*cols];
    for (int i = 0; i < (rows*(rows+1))/2; i++)
       (*this).element[i] = obj.element[i];

}

template <class T>
void Matrix<T> :: store(int i, int j, T value) const{
    if (i<1||i>rows||j<1||j>cols)
    throw "Out of bound";
    if (i>j)
    throw "Error : The value must be 0 ";
    this->element[((j*(j-1))/2)+i-1] = value;     // Row wise
    // this->element[((i*(i-1))/2)+j-1] = value;     // Column wise

} 

template <class T>
T Matrix<T> :: retrive(int i, int j) const{
    if (i<1||i>rows||j<1||j>cols)
    throw "Out of bound";
    if (i>j)
    return 0;
    this->element[((j*(j-1))/2)+i-1];                 // Row wise
    // this->element[((i*(i-1))/2)+j-1] = value;     // column wise

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
    for (int i = 0; i < (rows*(rows+1))/2; i++)
            temp.element[i] = (*this).element[i] + b.element[i];

    return temp;
}

template <class T>
Matrix<T> Matrix<T>::operator-(const Matrix<T> &b)
{
    if ((*this).rows != b.rows || (*this).cols != b.cols)
        throw "Invalid size of arrray is being adding ";
    Matrix temp((*this).rows, (*this).cols);
    for (int i = 0; i < (rows*(rows+1))/2; i++)
            temp.element[i] = (*this).element[i] - b.element[i];

    return temp;
}

template <class T>
Matrix<T> Matrix<T>::operator*(const Matrix<T> &b)
{
    if ((*this).rows != b.rows || (*this).cols != b.cols)
        throw "Invalid size of arrray is being adding ";
    Matrix temp((*this).rows, (*this).cols);
    for (int i = 0; i < (rows*(rows+1))/2; i++)
            temp.element[i] = (*this).element[i] * b.element[i];

    return temp;
}

template <class T>
Matrix<T> Matrix<T>::operator/(const Matrix<T> &b)
{
    if ((*this).rows != b.rows || (*this).cols != b.cols)
        throw "Invalid size of arrray is being adding ";
    Matrix temp((*this).rows, (*this).cols);
    for (int i = 0; i < (rows*(rows+1))/2; i++)
            temp.element[i] = (*this).element[i] / b.element[i];

    return temp;
}

template <class U>
istream& operator>>(istream& in,const Matrix<U>& obj)
{
    cout<<"Enter the element of upper triangular matrix only ";
    for (int i = 0; i < (rows*(rows+1))/2; i++)
                in >> obj.element[i];
    return in;
}

template <class U>
ostream& operator<<(ostream& out, const Matrix<U> obj)
{
    
    for (int i = 0; i < obj.rows; i++)
        {
            for (int j = 0; j <= i; j++)
                out << " " << obj.retrive(i,j);
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