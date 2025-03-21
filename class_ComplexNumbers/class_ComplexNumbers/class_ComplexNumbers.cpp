#include <iostream>
#include <math.h>
#include <vector> 
#include <iomanip>
#include "ComplexNumbers.h"

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");

    ComplexNumber* numbers = nullptr; // Указатель на динамический массив
    ComplexNumber single_number;      // Объект для операций с одним числом
    string result;

    int choice = chois();
    if (choice == 6 || choice == 7) {
        // Ввод только одного числа
        manual_input_one(single_number);

        if (choice == 6) {
            result = "Модуль числа: " + to_string(single_number.modulus());
        }
        else if (choice == 7) {
            result = "Тригонометрическая форма числа: " + single_number.trigonometric_form();
        }

        cout << result << endl;

        // Сохранение результата в файл
        string output_filename;
        cout << "Введите имя файла для записи результатов: ";
        cin >> output_filename;
        write_to_file(output_filename, single_number, result);
    }
    else {
        // Выделяем память для двух чисел
        numbers = new ComplexNumber[2];

        manual_input_two(numbers);

        try {
            switch (choice) {
            case 1:
                result = "Результат сложения: " + (numbers[0] + numbers[1]).to_string();
                break;
            case 2:
                result = "Результат вычитания: " + (numbers[0] - numbers[1]).to_string();
                break;
            case 3:
                result = "Результат умножения: " + ComplexNumber::multiply(numbers[0], numbers[1]).to_string();
                break;
            case 4:
                result = "Результат деления: " + ComplexNumber::divide(numbers[0], numbers[1]).to_string();
                break;
            case 5:
                result = numbers[0].is_equal(numbers[1]) ? "Комплексные числа равны." : "Комплексные числа не равны.";
                break;
            default:
                cout << "Неверный выбор операции!" << endl;
                delete[] numbers; 
                return 1;
            }

            cout << result << endl;

            // Сохранение результата в файл
            string output_filename;
            cout << "Введите имя файла для записи результатов: ";
            cin >> output_filename;
            write_to_file(output_filename, numbers, result);

        }
        catch (const std::invalid_argument& e) {
            cout << "Ошибка: " << e.what() << endl;
        }

        delete[] numbers;
    }

    ComplexNumber* obj = new ComplexNumber;
    (*obj).set_imagi(5);
    obj->set_real(7);
    std::cout << obj->to_string();
    delete obj;

    return 0;
}

//#include <iostream>
//#include <math.h>
//#include <vector> 
//#include <iomanip>
//#include "ComplexNumbers.h"
//
//using namespace std;
//
//
//int main() {
//    setlocale(LC_ALL, "Russian");
//
//    ComplexNumber numbers[2];
//    ComplexNumber single_number;
//    string result;
//
//    // Выбор операции
//    int choice = chois();
//
//    if (choice == 6 || choice == 7) {
//        // Ввод только одного числа
//        manual_input_one(single_number);
//
//        if (choice == 6) {
//            result = "Модуль числа: " + to_string(single_number.modulus());
//        }
//        else if (choice == 7) {
//            result = "Тригонометрическая форма числа: " + single_number.trigonometric_form();
//        }
//
//        cout << result << endl;
//
//        // Сохранение результата в файл
//        string output_filename;
//        cout << "Введите имя файла для записи результатов: ";
//        cin >> output_filename;
//        write_to_file(output_filename, single_number, result);
//
//    }
//    else {
//        // Ввод двух чисел
//        cout << "Вы выбрали операцию, требующую двух чисел.\n";
//        manual_input_two(numbers);
//
//        try {
//            switch (choice) {
//            case 1:
//                result = "Результат сложения: " + (numbers[0] + numbers[1]).to_string();
//                break;
//            case 2:
//                result = "Результат вычитания: " + (numbers[0] - numbers[1]).to_string();
//                break;
//            case 3:
//                result = "Результат умножения: " + ComplexNumber::multiply(numbers[0], numbers[1]).to_string();
//                break;
//            case 4:
//                result = "Результат деления: " + ComplexNumber::divide(numbers[0], numbers[1]).to_string();
//                break;
//            case 5:
//                result = numbers[0].is_equal(numbers[1]) ? "Комплексные числа равны." : "Комплексные числа не равны.";
//                break;
//            default:
//                cout << "Неверный выбор операции!" << endl;
//                return 1;
//            }
//
//            cout << result << endl;
//
//            // Сохранение результата в файл
//            string output_filename;
//            cout << "Введите имя файла для записи результатов: ";
//            cin >> output_filename;
//            write_to_file(output_filename, numbers, result);
//
//        }
//        catch (const std::invalid_argument& e) {
//            cout << "Ошибка: " << e.what() << endl;
//        }
//    }
//
//    return 0;
//}