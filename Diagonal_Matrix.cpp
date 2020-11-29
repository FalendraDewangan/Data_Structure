#include <iostream>
using namespace std;

template <class T>
class Diagonal_Matrix
{
    T *element;
    int rows, cols;

public:
    Diagonal_Matrix(int, int);
    Diagonal_Matrix(const Diagonal_Matrix<T> &);
    void store(int, int, T) const;
    T retrive(int, int) const;
    int getRow();
    int getColumn();
    Diagonal_Matrix<T> operator+(const Diagonal_Matrix<T> &);
    Diagonal_Matrix<T> operator-(const Diagonal_Matrix<T> &);
    Diagonal_Matrix<T> operator*(const Diagonal_Matrix<T> &);
    Diagonal_Matrix<T> operator/(const Diagonal_Matrix<T> &);
    template <class U>
    friend istream &operator>>(istream &, const Diagonal_Matrix<U> &);
    template <class U>
    friend ostream &operator<<(ostream &, const Diagonal_Matrix<U>);
    ~Diagonal_Matrix()
    {
        delete[] element;
    }
};

template <class T>
Diagonal_Matrix<T>::Diagonal_Matrix(int r, int c)
{
    if (r < 1 || c < 1 || r != c)
        throw "Bad Initializers ";
    this->rows = r;
    this->cols = c;
    element = new T[rows];
}

template <class T>
Diagonal_Matrix<T>::Diagonal_Matrix(const Diagonal_Matrix<T> &obj)
{
    this->rows = obj.rows;
    this->cols = obj.cols;
    element = new T[rows];
    for (int i = 0; i < rows; i++)
        (*this).element[i] = obj.element[i];
}

template <class T>
void Diagonal_Matrix<T>::store(int i, int j, T value) const
{
    if (i < 1 || i > rows || j < 1 || j > cols)
        throw "Out of bound";
    
    if (i != j)
        throw "Error : The value must be zero ";

     this->element[i - 1] = value;
}

template <class T>
T Diagonal_Matrix<T>::retrive(int i, int j) const
{
    if (i < 1 || i > rows || j < 1 || j > cols)
        throw "Out of bound";
    
    if (i != j)
        return 0;

     this->element[i - 1];
}

template <class T>
int Diagonal_Matrix<T>::getRow()
{
    return rows;
}

template <class T>
int Diagonal_Matrix<T>::getColumn()
{
    return cols;
}

template <class T>
Diagonal_Matrix<T> Diagonal_Matrix<T>::operator+(const Diagonal_Matrix &b)
{
    if ((*this).rows != b.rows || (*this).cols != b.cols)
        throw "Invalid size of arrray is being adding ";
    Diagonal_Matrix temp((*this).rows, (*this).cols);
    for (int i = 0; i < rows; i++)
        temp.element[i] = (*this).element[i] + b.element[i];

    return temp;
}

template <class T>
Diagonal_Matrix<T> Diagonal_Matrix<T>::operator-(const Diagonal_Matrix<T> &b)
{
    if ((*this).rows != b.rows || (*this).cols != b.cols)
        throw "Invalid size of arrray is being substracting ";
    Diagonal_Matrix temp((*this).rows, (*this).cols);
    for (int i = 0; i < rows; i++)
        temp.element[i] = (*this).element[i] - b.element[i];

    return temp;
}

template <class T>
Diagonal_Matrix<T> Diagonal_Matrix<T>::operator*(const Diagonal_Matrix<T> &b)
{
    if ((*this).rows != b.rows || (*this).cols != b.cols)
        throw "Invalid size of arrray is being multiplying ";
    Diagonal_Matrix temp((*this).rows, (*this).cols);
    for (int i = 0; i < rows; i++)
        temp.element[i] = (*this).element[i] * b.element[i];

    return temp;
}

template <class T>
Diagonal_Matrix<T> Diagonal_Matrix<T>::operator/(const Diagonal_Matrix<T> &b)
{
    if ((*this).rows != b.rows || (*this).cols != b.cols)
        throw "Invalid size of arrray is being dividing ";
    Diagonal_Matrix temp((*this).rows, (*this).cols);
    for (int i = 0; i < rows; i++)
        temp.element[i] = (*this).element[i] / b.element[i];

    return temp;
}

template <class U>
istream &operator>>(istream &in, const Diagonal_Matrix<U> &obj)
{
    cout << "Enter only diagonal element :" << endl;
    for (int i = 0; i < obj.rows; i++)
        in >> obj.element[i];
    return in;
}

template <class U>
ostream &operator<<(ostream &out, const Diagonal_Matrix<U> obj)
{

    for (int i = 1; i <= obj.rows; i++)
    {
        for (int j = 1; j <= obj.cols; j++)
            out << " " << obj.retrive(i, j);
        out << endl;
    }
    return out;
}

int main()
{
    try
    {
        Diagonal_Matrix<int> a(2, 2);
        // Matrix<int> b(2, 2);
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
        // cin >> b;
        // cout << (a+b);
        cout << a;
    }
    catch (char const *e)
    {
        cout << endl
             << endl
             << e << '\n';
    }
}
template class Diagonal_Matrix<int>;
// template class Diagonal_Matrix<char>;
// template class Diagonal_Matrix<float>;