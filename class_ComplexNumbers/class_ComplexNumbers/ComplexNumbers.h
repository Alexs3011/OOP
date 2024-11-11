#pragma once
#include <string>
#include <iostream>
#include <cmath>
#include <stdexcept>

using namespace std;

class ComplexNumber {

private:
    double real;
    double imagi;

public:
    // ����������� �� ���������
    ComplexNumber() {
        real = 0;
        imagi = 0;
    }

    // ����������� � �����������
    ComplexNumber(double r, double im) {
        set_real(r);
        set_imagi(im);
    }

    // ��������� �������� �������������� �����
    void set_real(double r) { real = r; }

    // ��������� �������� ������ �����
    void set_imagi(double im) { imagi = im; }

    // ��������� �������� �������������� �����
    double get_real() const { return real; }

    // ��������� �������� ������ �����
    double get_imagi() const { return imagi; }

    // ����� ��� ��������� ���������� �������������
    string to_string() const {
        return std::to_string(real) + (imagi >= 0 ? " + " : " - ") + std::to_string(abs(imagi)) + "i";
    }

    ..
    // ����� ��� �������� ���� ����������� �����
    static ComplexNumber sum(const ComplexNumber& num1, const ComplexNumber& num2) {
        return ComplexNumber(num1.real + num2.real, num1.imagi + num2.imagi);
    }

    // ����� ��� ��������� ���� ����������� �����
    static ComplexNumber sub(const ComplexNumber& num1, const ComplexNumber& num2) {
        return ComplexNumber(num1.real - num2.real, num1.imagi - num2.imagi);
    }

    // ����� ��� ��������� ���� ����������� �����
    static ComplexNumber multiply(const ComplexNumber& num1, const ComplexNumber& num2) {
        double r = (num1.real * num2.real) - (num1.imagi * num2.imagi);
        double im = (num1.real * num2.imagi) + (num1.imagi * num2.real);
        return ComplexNumber(r, im);
    }

    // ����� ��� ������� ���� ����������� �����
    static ComplexNumber divide(const ComplexNumber& num1, const ComplexNumber& num2) {
        if (num2.real == 0 && num2.imagi == 0) {
            throw std::invalid_argument("������� �� ����!");
        }
        ComplexNumber conjugate(num2.real, -num2.imagi);
        ComplexNumber numerator = multiply(num1, conjugate);
        double denominator = multiply(num2, conjugate).real;
        return ComplexNumber(numerator.real / denominator, numerator.imagi / denominator);
    }

    // ����� ��� ���������� ������ ������������ �����
    double modulus() const {
        return sqrt(real * real + imagi * imagi);
    }

    // ����� ��� ������������������ ����� ������������ �����
    string trigonometric_form() const {
        // ���������� ������
        double modulus = sqrt(real * real + imagi * imagi);

        // ���������� ���������, atan2 - ���������� �� 2 ����������
        double theta = atan2(imagi, real);

        // ������������������ �����
        return std::to_string(modulus) + " * (cos(" + std::to_string(theta) + ") + i*sin(" + std::to_string(theta) + "))";
    }


    // ����� ��� ��������� ���� ����������� �����
    bool is_equal(const ComplexNumber& other) const {
        return (real == other.real) && (imagi == other.imagi);
    }
};

// ������� ������ ��������
int chois() {
    int choise;
    cout << " �������� ��� ������������ �������\n";
    cout << "1 - ��������\n";
    cout << "2 - ���������\n";
    cout << "3 - ���������\n";
    cout << "4 - �������\n";
    cout << "5 - ���������\n";
    cout << "6 - ������\n";
    cout << "7 - ������������������ �������\n";
    cout << "\n �������� �������� : \n";
    cin >> choise;
    return choise;
}