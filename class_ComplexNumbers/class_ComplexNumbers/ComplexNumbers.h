#pragma once
#include <string>
#include <iostream>
#include <cmath>
#include <stdexcept>
#include <cassert>
#include <fstream>

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


    // �������� ����� static ������������ ��� �������� �������, ������� ����� ������������ ���������� �� �����-���� �����������, ��������� ��� ������.
    // ����� ��� ��������� ���������� �������������
    string to_string() const {
        string s;
        s = ::to_string(real) + (imagi >= 0 ? " + " : " - ") + ::to_string(abs(imagi)) + "i";
        return s;
    }

    
    // ����� ��� �������� ���� ����������� �����
    static ComplexNumber sum(const ComplexNumber& num1, const ComplexNumber& num2) {
        return ComplexNumber(num1.real + num2.real, num1.imagi + num2.imagi);
    }


    // ���������� ��������� +. real � imagi ��������� � �������� ������� (num1), � other.real � other.imagi � � ����������� ������� (num2).
    ComplexNumber operator+(const ComplexNumber& other) const {
       return  sum(*this, other);//todo;
       // return ComplexNumber(real + other.real, imagi + other.imagi);
    }

    // ����� ��� ��������� ���� ����������� �����
    static ComplexNumber sub(const ComplexNumber& num1, const ComplexNumber& num2) {
        return ComplexNumber(num1.real - num2.real, num1.imagi - num2.imagi);
    }

    // ���������� ��������� -. real � imagi ��������� � �������� ������� (num1), � other.real � other.imagi � � ����������� ������� (num2).
    ComplexNumber operator- (const ComplexNumber& other) {
        return ComplexNumber(real - other.real, imagi - other.imagi);
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
            throw invalid_argument("������� �� ����!");
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

    // ����� ���� ����������� �����, ������������ � ��������
    double angl() const {
        return atan2(imagi, real);
    }

    // ����� ��� ������������������ ����� ������������ �����
    string trigonometric_form() const {
        // ���������� ������
        double modulus = sqrt(real * real + imagi * imagi);

        // ���������� ���������, atan2 - ���������� �� 2 ����������
        double theta = angl();

        // ������������������ �����
        return std::to_string(modulus) + " * (cos(" + std::to_string(theta) + ") + i*sin(" + std::to_string(theta) + "))";
    }



    // ����� ��� ��������� ���� ����������� �����
    bool is_equal(const ComplexNumber& other) const {
        return (real == other.real) && (imagi == other.imagi);
    }


};


/// ������� ������ ��������
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

/// �����
void run_tests() {
    ComplexNumber num1(3, 4);   // �����: 3 + 4i
    ComplexNumber num2(1, -1);  // �����: 1 - i
    ComplexNumber num3(-2, 5);  // �����: -2 + 5i

    // ���� ������� set � get
    ComplexNumber test_num;
    test_num.set_real(5.0);
    test_num.set_imagi(-3.0);

    assert(test_num.get_real() == 5.0);
    assert(test_num.get_imagi() == -3.0);

    test_num.set_real(-7.5);
    test_num.set_imagi(2.5);

    assert(test_num.get_real() == -7.5);
    assert(test_num.get_imagi() == 2.5);

    // ���� ���������
    assert(num1.is_equal(ComplexNumber(3, 4)));
    assert(!num1.is_equal(num2));
    assert(!num2.is_equal(num3));
    assert(num3.is_equal(ComplexNumber(-2, 5)));


    // ���� ��������
    ComplexNumber result_sum1 = ComplexNumber::sum(num1, num2);
    assert(result_sum1.is_equal(ComplexNumber(4, 3)));

    ComplexNumber result_sum2 = ComplexNumber::sum(num2, num3);
    assert(result_sum2.is_equal(ComplexNumber(-1, 4)));

    ComplexNumber result_sum3 = ComplexNumber::sum(num1, num3);
    assert(result_sum3.is_equal(ComplexNumber(1, 9)));


    // ���� ���������
    ComplexNumber result_sub1 = ComplexNumber::sub(num1, num2);
    assert(result_sub1.is_equal(ComplexNumber(2, 5)));

    ComplexNumber result_sub2 = ComplexNumber::sub(num2, num3);
    assert(result_sub2.is_equal(ComplexNumber(3, -6)));

    ComplexNumber result_sub3 = ComplexNumber::sub(num3, num1);
    assert(result_sub3.is_equal(ComplexNumber(-5, 1)));


    // ���� ���������
    ComplexNumber result_multiply1 = ComplexNumber::multiply(num1, num2);
    assert(result_multiply1.is_equal(ComplexNumber(7, 1)));

    ComplexNumber result_multiply2 = ComplexNumber::multiply(num2, num3);
    assert(result_multiply2.is_equal(ComplexNumber(3, 7)));

    ComplexNumber result_multiply3 = ComplexNumber::multiply(num1, num3);
    assert(result_multiply3.is_equal(ComplexNumber(-26, 7)));

    // ���� �������
    ComplexNumber result_divide1 = ComplexNumber::divide(num1, num2);
    assert(std::abs(result_divide1.get_real() - (-0.5)) < 0.000001);
    assert(std::abs(result_divide1.get_imagi() - 3.5) < 0.000001);

    ComplexNumber result_divide2 = ComplexNumber::divide(num1, num3);
    assert(std::abs(result_divide2.get_real() - 0.4827586) < 0.000001);
    assert(std::abs(result_divide2.get_imagi() - (-0.793103448)) < 0.000001);

    ComplexNumber result_divide3 = ComplexNumber::divide(num2, num3);
    assert(std::abs(result_divide3.get_real() - (-0.24137931034)) < 0.000001);
    assert(std::abs(result_divide3.get_imagi() - (-0.10344827586)) < 0.000001);


    // ���� ������
    double mod1 = num1.modulus();
    assert(std::abs(mod1 - 5.0) < 0.000001);

    double mod2 = num2.modulus();
    assert(std::abs(mod2 - sqrt(2)) < 0.000001);

    double mod3 = num3.modulus();
    assert(std::abs(mod3 - sqrt(29)) < 0.000001);

}

/// ������� ������ ������ �� �����
void read_from_file(const string& input_filename, ComplexNumber arr[], int max_size) {
    ifstream infile(input_filename);
    if (!infile.is_open()) {
        cout << "������ �������� �����: " << input_filename << endl;
    }

    double real, imag;
    int i = 0;
    while (i < max_size && infile >> real >> imag) {
        arr[i] = ComplexNumber(real, imag);
        i++;
    }

    infile.close();
}

/// ������� ��� ������ ���������� � ���� ��� 1 �����
void write_to_file(const string& filename, const ComplexNumber& number, const string& result) {
    ofstream file(filename);
    if (!file.is_open()) {
        cout << "�� ������� ������� ���� ��� ������: " << filename << endl;
        return;
    }
    file << "����������� �����:\n" << number.to_string() << endl;
    file << "\n���������:\n" << result << endl;
    file.close();
}

/// ������� ��� ������ ���������� � ���� ��� 2 �����
void write_to_file(const string& filename, const ComplexNumber numbers[], const string& result) {
    ofstream file(filename);
    if (!file.is_open()) {
        cout << "�� ������� ������� ���� ��� ������: " << filename << endl;
        return;
    }
    file << "����������� �����:\n";
    for (int i = 0; i < 2; ++i) {
        file << "����� " << i + 1 << ": " << numbers[i].to_string() << endl;
    }
    file << "\n���������:\n" << result << endl;
    file.close();
}

/// ������� ��� ������� ����� ������ �����
void manual_input_one(ComplexNumber& number) {
    double real, imag;
    cout << "������� �������������� � ������ ����� �����: ";
    cin >> real >> imag;
    number = ComplexNumber(real, imag);
}

/// ������� ��� ������� ����� ���� �����
void manual_input_two(ComplexNumber numbers[]) {
    for (int i = 0; i < 2; ++i) {
        double real, imag;
        cout << "������� �������������� � ������ ����� ����� " << i + 1 << ": ";
        cin >> real >> imag;
        numbers[i] = ComplexNumber(real, imag);
    }
}