
#include <iostream>
#include "Class_course.h"
#include <vector>

using namespace std;

int main()
{
    setlocale(LC_ALL, "RU");
    testCourse();
    // Создаем объект базового класса
    Course baseCourse("Основы ООП", "Ветров Сергей Владимирович", 40, 6000, true);
    baseCourse.to_string();

    cout << endl;

    // Создаем объект производного класса offlineCourse
    offlineCourse offline("Курс по машинному обучению", "Коган Евгения Семёновна", 60, 8000, true, "Coursera");
    offline.to_string();

    cout << endl;

    // Создаем объект производного класса onlineCourse
    onlineCourse online("Вычислительная математика", "Забелин Анатолий Анатольевич", 30, 5000, false, "https://online.learning.com", true);
    online.to_string();

    cout << endl;

    // Создание объекта динамически производного класса OnlineCourse 
    Course* online2 = new onlineCourse("Вычислительная математика", "Забелин Анатолий Анатольевич", 50, 7000, false, "Zoom", true);
    online2->to_string();

    //online2->getPlatform();//Ошибка:метода нет в базовом классе

    // Преобразуем указатель на объект базового классса к указателю на объект производного класса и вызываем метод производного класса
    dynamic_cast<offlineCourse*> (online2)->getPlatform();

    // Содержит данные базового класса
    Course basecourse2 = offlineCourse("Курс по машинному обучению", "Коган Евгения Семёновна", 60, 8000, true, "Coursera");
    return 0;
}

