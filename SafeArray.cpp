#include <iostream>
using namespace std;


class Array1D
{
    int *elearr;
    int lb, ub;

public:
    // Constructor for array with lowerbound and upperbound
    Array1D(int lb = 0, int ub = 0)
    {
        this->ub = ub;
        this->lb = lb;
        elearr = new int[ub - lb + 1];
    }

    // Functions of the class
    int &operator[](int);
    Array1D operator+(Array1D &);
    Array1D operator-(Array1D &);
    Array1D operator*(Array1D &);
    Array1D operator/(Array1D &);
    int getSize() const;
    friend istream& operator >>(istream&,Array1D&);
    friend ostream& operator <<(istream&,Array1D&);
    ~Array1D(){
        delete[] elearr;
    }
};


int &Array1D ::operator[](int i)
{
    if(i<lb)
        throw "Invalid index";
    return elearr[i-lb];
}


Array1D Array1D ::operator+(Array1D &obj)
{
    if (this->getSize() != obj.getSize())
        throw "Unequal ize of array is being added";

    Array1D temp(obj.getSize());
    for (int i = 0; i < this->getSize(); i++)
    {
        temp[i] = (*this)[i] + obj[i];
    }
    return temp;
}


Array1D Array1D ::operator-(Array1D &obj)
{
    if (this->getSize() != obj.getSize())
        throw "Unequal ize of array is being added";

    Array1D temp(obj.getSize());
    for (int i = 0; i < this->getSize(); i++)
    {
        temp[i] = (*this)[i] - obj[i];
    }
    return temp;
}


Array1D Array1D ::operator*(Array1D &obj)
{
    if (this->getSize() != obj.getSize())
        throw "Unequal ize of array is being added";

    Array1D temp(obj.getSize());
    for (int i = 0; i < this->getSize(); i++)
    {
        temp[i] = (*this)[i] * obj[i];
    }
    return temp;
}


Array1D Array1D ::operator/(Array1D &obj)
{
    if (this->getSize() != obj.getSize())
        throw "Unequal ize of array is being added";

    Array1D temp(obj.getSize());
    for (int i = 0; i < this->getSize(); i++)
    {
        temp[i] = (*this)[i] / obj[i];
    }
    return temp;
}


int Array1D ::getSize() const
{
    return ub-lb+1;
}

istream& operator >>(istream& in,Array1D& obj){
    for (int i = 0; i < obj.getSize(); i++)
        cin>>obj[i];
    return in;
}

ostream& operator <<(ostream& out,Array1D& obj) {
    cout<<"{";
    for (int i = 0; i < obj.getSize(); i++){
        cout<<" "<<obj[i];
        if(i<obj.getSize()-1)
        cout<<",";
    }
    cout<<"} ";
    return out;
}



  
class Array2D
{
    Array1D  **element;
    int rows, cols;

public:
    Array2D(int, int);
    // Array2D(const Array2D &);
    Array1D & operator[](int) const;
    Array2D  operator+(const Array2D  &);
    Array2D  operator-(const Array2D  &);
    Array2D  operator*(const Array2D  &);
    Array2D  operator/(const Array2D  &b);
    friend istream& operator>>(istream& ,const Array2D& );
    friend ostream& operator<<(ostream&,const Array2D& );
    ~Array2D()
    {
        delete[] element;
    }
};

  
Array2D  :: Array2D(int rows, int column)
{
    if (rows < 0 || column < 0)
        throw "Bad Initializers ";
    this->rows = rows;
    this->cols = column;
    element = new Array1D* [rows];
    for (int i = 0; i < rows; i++)
        element[i] = new Array1D [cols];
}

// Array2D :: Array2D(const Array2D & obj){
//     this->rows = obj.rows;
//     this->cols = obj.cols;
//     element = new Array1D [rows];
//     for (int i = 0; i < rows; i++)
//         this->element[i]=obj.element[i];
// }

  
Array1D & Array2D  :: operator[](int i) const{
    if (i>=rows)
    throw "Out of bound";
    return element[i];     
}

  
Array2D  Array2D ::operator+(const Array2D &b)
{
    if ((*this).rows != b.rows || (*this).cols != b.cols)
        throw "Invalid size of arrray is being adding ";
    Array2D temp((*this).rows, (*this).cols);
    for (int i = 0; i < rows; i++)
            temp.element[i] = (*this).element[i] + b.element[i];

    return temp;
}

  
Array2D  Array2D ::operator-(const Array2D  &b)
{
    if ((*this).rows != b.rows || (*this).cols != b.cols)
        throw "Invalid size of arrray is being adding ";
    Array2D temp((*this).rows, (*this).cols);
    for (int i = 0; i < rows; i++)
            temp.element[i] = (*this).element[i] - b.element[i];

    return temp;
}

  
Array2D  Array2D ::operator*(const Array2D  &b)
{
    if ((*this).rows != b.rows || (*this).cols != b.cols)
        throw "Invalid size of arrray is being adding ";
    Array2D temp((*this).rows, (*this).cols);
    for (int i = 0; i < rows; i++)
            temp.element[i] = (*this).element[i] * b.element[i];

    return temp;
}

  
Array2D  Array2D ::operator/(const Array2D  &b)
{
    if ((*this).rows != b.rows || (*this).cols != b.cols)
        throw "Invalid size of arrray is being adding ";
    Array2D temp((*this).rows, (*this).cols);
    for (int i = 0; i < rows; i++)
            temp.element[i] = (*this).element[i] / b.element[i];

    return temp;
}

istream& operator>>(istream& in,const Array2D& obj)
{
    for (int i = 0; i < obj.rows; i++)
                in >> obj.element[i];
    return in;
}

ostream& operator<<(ostream& out, const Array2D& obj)
{
    
    for (int i = 0; i < obj.rows; i++)
        {
            out << " " << obj.element[i];
            out<<endl;
        }

    return out;
}

int main()
{
    Array2D a(2, 2);
    Array2D b(2, 2);
    // Array2D b(2, 2);

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

    return 0;
}