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
    // Конструктор по умолчанию
    ComplexNumber() {
        real = 0;
        imagi = 0;
    }

    // Конструктор с параметрами
    ComplexNumber(double r, double im) {
        set_real(r);
        set_imagi(im);
    }

    // Установка значения действительной части
    void set_real(double r) { real = r; }

    // Установка значения мнимой части
    void set_imagi(double im) { imagi = im; }

    // Получение значения действительной части
    double get_real() const { return real; }

    // Получение значения мнимой части
    double get_imagi() const { return imagi; }


    // Ключевое слово static используется для создания методов, которые будут существовать независимо от каких-либо экземпляров, созданных для класса.
    // Метод для получения строкового представления
    string to_string() const {
        string s;
        s = ::to_string(real) + (imagi >= 0 ? " + " : " - ") + ::to_string(abs(imagi)) + "i";
        return s;
    }

    
    // Метод для сложения двух комплексных чисел
    static ComplexNumber sum(const ComplexNumber& num1, const ComplexNumber& num2) {
        return ComplexNumber(num1.real + num2.real, num1.imagi + num2.imagi);
    }


    // Перегрузка оператора +. real и imagi относятся к текущему объекту (num1), а other.real и other.imagi — к переданному объекту (num2).
    ComplexNumber operator+(const ComplexNumber& other) const {
       return  sum(*this, other);//todo;
       // return ComplexNumber(real + other.real, imagi + other.imagi);
    }

    // Метод для вычитания двух комплексных чисел
    static ComplexNumber sub(const ComplexNumber& num1, const ComplexNumber& num2) {
        return ComplexNumber(num1.real - num2.real, num1.imagi - num2.imagi);
    }

    // Перегрузка оператора -. real и imagi относятся к текущему объекту (num1), а other.real и other.imagi — к переданному объекту (num2).
    ComplexNumber operator- (const ComplexNumber& other) {
        return ComplexNumber(real - other.real, imagi - other.imagi);
    }

    // Метод для умножения двух комплексных чисел
    static ComplexNumber multiply(const ComplexNumber& num1, const ComplexNumber& num2) {
        double r = (num1.real * num2.real) - (num1.imagi * num2.imagi);
        double im = (num1.real * num2.imagi) + (num1.imagi * num2.real);
        return ComplexNumber(r, im);
    }

    // Метод для деления двух комплексных чисел
    static ComplexNumber divide(const ComplexNumber& num1, const ComplexNumber& num2) {
        if (num2.real == 0 && num2.imagi == 0) {
            throw invalid_argument("Деление на ноль!");
        }
        ComplexNumber conjugate(num2.real, -num2.imagi);
        ComplexNumber numerator = multiply(num1, conjugate);
        double denominator = multiply(num2, conjugate).real;
        return ComplexNumber(numerator.real / denominator, numerator.imagi / denominator);
    }

    // Метод для вычисления модуля комплексного числа
    double modulus() const {
        return sqrt(real * real + imagi * imagi);
    }

    // Метод угла комлексного числа, возвращается в радианах
    double angl() const {
        return atan2(imagi, real);
    }

    // Метод для тригонометрической формы комплексного числа
    string trigonometric_form() const {
        // Вычисление модуля
        double modulus = sqrt(real * real + imagi * imagi);

        // Вычисление аргумента, atan2 - аркатнгенс от 2 аргументов
        double theta = angl();

        // Тригонометрическая форма
        return std::to_string(modulus) + " * (cos(" + std::to_string(theta) + ") + i*sin(" + std::to_string(theta) + "))";
    }



    // Метод для сравнения двух комплексных чисел
    bool is_equal(const ComplexNumber& other) const {
        return (real == other.real) && (imagi == other.imagi);
    }


};


/// Функция выбора действия
int chois() {
    int choise;
    cout << " Операции над комплексными числами\n";
    cout << "1 - Сложение\n";
    cout << "2 - Вычитание\n";
    cout << "3 - Умножение\n";
    cout << "4 - Деление\n";
    cout << "5 - Сравнение\n";
    cout << "6 - Модуль\n";
    cout << "7 - Тригонометрическая формула\n";
    cout << "\n Выберите действие : \n";
    cin >> choise;
    return choise;
}

/// Тесты
void run_tests() {
    ComplexNumber num1(3, 4);   // Число: 3 + 4i
    ComplexNumber num2(1, -1);  // Число: 1 - i
    ComplexNumber num3(-2, 5);  // Число: -2 + 5i

    // Тест методов set и get
    ComplexNumber test_num;
    test_num.set_real(5.0);
    test_num.set_imagi(-3.0);

    assert(test_num.get_real() == 5.0);
    assert(test_num.get_imagi() == -3.0);

    test_num.set_real(-7.5);
    test_num.set_imagi(2.5);

    assert(test_num.get_real() == -7.5);
    assert(test_num.get_imagi() == 2.5);

    // Тест сравнения
    assert(num1.is_equal(ComplexNumber(3, 4)));
    assert(!num1.is_equal(num2));
    assert(!num2.is_equal(num3));
    assert(num3.is_equal(ComplexNumber(-2, 5)));


    // Тест сложения
    ComplexNumber result_sum1 = ComplexNumber::sum(num1, num2);
    assert(result_sum1.is_equal(ComplexNumber(4, 3)));

    ComplexNumber result_sum2 = ComplexNumber::sum(num2, num3);
    assert(result_sum2.is_equal(ComplexNumber(-1, 4)));

    ComplexNumber result_sum3 = ComplexNumber::sum(num1, num3);
    assert(result_sum3.is_equal(ComplexNumber(1, 9)));


    // Тест вычитания
    ComplexNumber result_sub1 = ComplexNumber::sub(num1, num2);
    assert(result_sub1.is_equal(ComplexNumber(2, 5)));

    ComplexNumber result_sub2 = ComplexNumber::sub(num2, num3);
    assert(result_sub2.is_equal(ComplexNumber(3, -6)));

    ComplexNumber result_sub3 = ComplexNumber::sub(num3, num1);
    assert(result_sub3.is_equal(ComplexNumber(-5, 1)));


    // Тест умножения
    ComplexNumber result_multiply1 = ComplexNumber::multiply(num1, num2);
    assert(result_multiply1.is_equal(ComplexNumber(7, 1)));

    ComplexNumber result_multiply2 = ComplexNumber::multiply(num2, num3);
    assert(result_multiply2.is_equal(ComplexNumber(3, 7)));

    ComplexNumber result_multiply3 = ComplexNumber::multiply(num1, num3);
    assert(result_multiply3.is_equal(ComplexNumber(-26, 7)));

    // Тест деления
    ComplexNumber result_divide1 = ComplexNumber::divide(num1, num2);
    assert(std::abs(result_divide1.get_real() - (-0.5)) < 0.000001);
    assert(std::abs(result_divide1.get_imagi() - 3.5) < 0.000001);

    ComplexNumber result_divide2 = ComplexNumber::divide(num1, num3);
    assert(std::abs(result_divide2.get_real() - 0.4827586) < 0.000001);
    assert(std::abs(result_divide2.get_imagi() - (-0.793103448)) < 0.000001);

    ComplexNumber result_divide3 = ComplexNumber::divide(num2, num3);
    assert(std::abs(result_divide3.get_real() - (-0.24137931034)) < 0.000001);
    assert(std::abs(result_divide3.get_imagi() - (-0.10344827586)) < 0.000001);


    // Тест модуля
    double mod1 = num1.modulus();
    assert(std::abs(mod1 - 5.0) < 0.000001);

    double mod2 = num2.modulus();
    assert(std::abs(mod2 - sqrt(2)) < 0.000001);

    double mod3 = num3.modulus();
    assert(std::abs(mod3 - sqrt(29)) < 0.000001);

}

/// Функция чтения данных из файла
void read_from_file(const string& input_filename, ComplexNumber arr[], int max_size) {
    ifstream infile(input_filename);
    if (!infile.is_open()) {
        cout << "Ошибка открытия файла: " << input_filename << endl;
    }

    double real, imag;
    int i = 0;
    while (i < max_size && infile >> real >> imag) {
        arr[i] = ComplexNumber(real, imag);
        i++;
    }

    infile.close();
}

/// Функция для записи результата в файл для 1 числа
void write_to_file(const string& filename, const ComplexNumber& number, const string& result) {
    ofstream file(filename);
    if (!file.is_open()) {
        cout << "Не удалось открыть файл для записи: " << filename << endl;
        return;
    }
    file << "Комплексное число:\n" << number.to_string() << endl;
    file << "\nРезультат:\n" << result << endl;
    file.close();
}

/// Функция для записи результата в файл для 2 чисел
void write_to_file(const string& filename, const ComplexNumber numbers[], const string& result) {
    ofstream file(filename);
    if (!file.is_open()) {
        cout << "Не удалось открыть файл для записи: " << filename << endl;
        return;
    }
    file << "Комплексные числа:\n";
    for (int i = 0; i < 2; ++i) {
        file << "Число " << i + 1 << ": " << numbers[i].to_string() << endl;
    }
    file << "\nРезультат:\n" << result << endl;
    file.close();
}

/// Функция для ручного ввода одного числа
void manual_input_one(ComplexNumber& number) {
    double real, imag;
    cout << "Введите действительную и мнимую часть числа: ";
    cin >> real >> imag;
    number = ComplexNumber(real, imag);
}

/// Функция для ручного ввода двух чисел
void manual_input_two(ComplexNumber numbers[]) {
    for (int i = 0; i < 2; ++i) {
        double real, imag;
        cout << "Введите действительную и мнимую часть числа " << i + 1 << ": ";
        cin >> real >> imag;
        numbers[i] = ComplexNumber(real, imag);
    }
}