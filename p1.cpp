#include <iostream>
using namespace std;

class Complex
{
    int real, imag;

public:
    // Default constructor
    Complex()
    {
        real = 0;
        imag = 0;
    }

    // Parameterized constructor
    Complex(int r, int i)
    {
        real = r;
        imag = i;
    }

    // Copy constructor
    Complex(Complex &c)
    {
        real = c.real;
        imag = c.imag;
    }

    // Member function to get data
    void getdata()
    {
        cout << "Enter real part: ";
        cin >> real;
        cout << "Enter imaginary part: ";
        cin >> imag;
    }

    // Member function to display data
    void showdata()
    {
        cout << real << " + " << imag << "i" << endl;
    }

    // Function to add two complex numbers
    Complex add_complex(Complex c1, Complex c2)
    {
        Complex temp;
        temp.real = c1.real + c2.real;
        temp.imag = c1.imag + c2.imag;
        return temp;
    }

    // Destructor
    ~Complex()
    {
        // Destructor message (optional)
    }
};

int main()
{
    Complex c1, c2, c3;

    cout << "Enter first complex number:\n";
    c1.getdata();

    cout << "Enter second complex number:\n";
    c2.getdata();

    c3 = c3.add_complex(c1, c2);

    cout << "Sum of complex numbers: ";
    c3.showdata();

    return 0;
}
