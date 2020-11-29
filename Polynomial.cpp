#include <iostream>
using namespace std;

class Polynomial;

class Term
{
    int cof;
    int exp;
    Term *next = NULL;
    friend class Polynomial;
    friend ostream &operator<<(ostream &, const Polynomial &);
};

class Polynomial
{
    Term *head, *tail;

public:
    Polynomial()
    {
        head = tail = NULL;
    }
    void addFront(int cofficient, int exponent);
    void addLast(int cofficient, int exponent);
    void insert();
    Polynomial operator+(const Polynomial &);
    friend ostream &operator<<(ostream &, const Polynomial &);
};

void Polynomial ::addFront(int cofficient, int exponent)
{
    if (head == NULL)
    {
        Term *temp = new Term;
        temp->cof = cofficient;
        temp->exp = exponent;
        head = temp;
        tail = temp;
        return;
    }
    Term *temp = new Term;
    temp->cof = cofficient;
    temp->exp = exponent;
    temp->next = head->next;
    head = temp;
}

void Polynomial::addLast(int cofficient, int exponent)
{
    if (head == NULL)
    {
        addFront(cofficient, exponent);
        return;
    }
    Term *temp = new Term;
    temp->cof = cofficient;
    temp->exp = exponent;
    tail->next = temp;
    tail = temp;
}

void Polynomial::insert()
{
    int e, c;
    cout << "Enter the Exponent : ";
    cin >> e;
    cout << "Enter the Cofficient : ";
    cin >> c;
    addLast(c, e);
}

Polynomial Polynomial::operator+(const Polynomial &obj)
{
    if (obj.head == NULL)
        return *this;
    if ((*this).head == NULL)
        return obj;
    Term *p1 = this->head;
    Term *p2 = obj.head;
    Polynomial p3;
    while (p1 != NULL || p2 != NULL)
    {   
        if (p1 == NULL)
        {   
            p3.addLast(p2->cof, p2->exp);
            p2 = p2->next;
        }
        if (p2 == NULL)
        {
            p3.addLast(p1->cof, p1->exp);
            p1 = p1->next;
        }

        if (p1->exp == p2->exp)
        {
            p3.addLast(p1->cof + p2->cof, p1->exp);
            p1 = p1->next;
            p2 = p2->next;
        }
        else if (p1->exp > p2->exp)
        {
            p3.addLast(p1->cof, p1->exp);
            p1 = p1->next;
        }
        else
        {
            p3.addLast(p2->cof, p2->exp);
            p2 = p2->next;
        }
    }
    return p3;
}

ostream &operator<<(ostream &out, const Polynomial &obj)
{
    if (obj.head == NULL){
        out << "Empty List ";
        return out;
    }
    Term *temp = obj.head;
    while (temp != NULL)
    {
        out << temp->cof << "x^" << temp->exp;
        if (temp->next != NULL)
            out << " + ";
        temp = temp->next;
    }
}

int main()
{
    Polynomial m1, m2, m3;
    int n, m;
    cout << "Enter the degree of first polynomial : ";
    cin >> n;
    for (int i = 0; i <= n; i++)
        m1.insert();
    cout << "\nYour first polynomial is : \n";
    cout << m1;

    cout << "\nEnter the degree of second polynomial : ";
    cin >> n;
    for (int i = 0; i <= n; i++)
        m2.insert();
    cout << "\nYour second polynomial is : \n";
    cout << m2;
    m3 = m1 + m2;
    cout << "\nYour resultant polynomial is : " << endl;
    cout << m3;
    return 0;
}