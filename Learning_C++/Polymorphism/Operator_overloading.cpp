#include <iostream>

class Complex {
private:
    float real;
    float imag;

public:
    Complex(float r = 0, float i = 0) : real(r), imag(i) {}

    // Overloading the + operator
    Complex operator+(const Complex& other) const {
        return Complex(real + other.real, imag + other.imag);
    }
    Complex operator-( Complex& obj)
    {
        Complex temp;
        temp.real = this->real - obj.real;
        temp.imag = this->imag - obj.imag;
        return temp;
    }

    // Overloading the pre-increment operator
    Complex& operator++() {
        ++real;
        ++imag;
        return *this;
    }

    // Overloading the post-increment operator
    Complex operator++(int) {
        Complex temp = *this;
        (this->real)++;
        imag++;
        return temp;
    }
    void display() const {
        std::cout << real << " + " << imag << "i" << std::endl;
    }
};

int main() {
    Complex c1(3.0, 4.0);
    Complex c2(1.0, 2.0);
    Complex c3 = c1 + c2; // Using the overloaded + operator
    Complex c4 = c1 - c2; // Using the overloaded - operator

    c3.display(); // Output: 4 + 6i
    c4.display(); // Output: 4 + 6i
    ++c1; // Using the pre-increment operator
    c1.display(); // Output: 4 + 5i
    
    return 0;
}