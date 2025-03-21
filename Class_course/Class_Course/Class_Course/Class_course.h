#pragma once
#include <iostream>
#include <string>
#include <list>
#include <assert.h>

using namespace std;

list<string> allInstructorNames =
{"Ветров Сергей Владимирович",
"Забелин Анатолий Анатольевич",
"Коган Евгения Семёновна" };

class Course {
protected:
	string courseName; // Название курса
	string instructorName; // Имя преподователя
	unsigned duration; // Сколько часов потребуется на курс
	unsigned price; // Цена за курс
	unsigned enrolledStudents; // Кол-во записавшихся студентов
	bool hasCertificate; // Наличие сертефикатов об окончании курса
public:
	// Конструктор 
	Course(const string& name, const string& instructor, unsigned dur, unsigned prc, bool cert)
	: courseName(name), instructorName(instructor), duration(dur), price(prc), hasCertificate(cert), enrolledStudents(0) {}

	// Геттеры
	string getCourseName() const { return courseName; }
	string getInstructorName() const { return instructorName; }
	unsigned getDuration() const { return duration; }
	unsigned getPrice() const { return price; }
	unsigned getEnrolledStudents() const { return enrolledStudents; }
	bool getHasCertificate() const { return hasCertificate; }

	// Сеттеры
	void setCourseName(const string& newName) { courseName = newName; }
	// Проверка на то что, что в листе есть имя преподавателя
	/*
	find — это алгоритм, который ищет первый элемент в указанном диапазоне, совпадающий с заданным значением.
	Параметры: allInstructorNames.begin() — итератор на начало списка allInstructorNames
	allInstructorNames.end() — итератор на конец списка allInstructorNames
	newInstructorName — значение, которое нужно найти
	Если возвращённый итератор не равен allInstructorNames.end(), это означает, что newInstructorName существует в списке.
	Если итератор равен allInstructorNames.end(), элемент не найден.
	*/
	void setInstructorName(const std::string& newInstructorName) {
		if (std::find(allInstructorNames.begin(), allInstructorNames.end(), newInstructorName) != allInstructorNames.end()) {
			instructorName = newInstructorName;
		}
	}
	void setDuration(unsigned newDuration) {
		if (newDuration != 0) {
			duration = newDuration;
		}
		else {
			cout << "Длительность курса не может быть равна 0." << endl;
		}
	}
	void setPrice(unsigned newPrice) { price = newPrice; }
	void setEnrolledStudents(unsigned enStudents) { enrolledStudents = enStudents; }
	void setHasCertificate(bool newHasCertificate) { hasCertificate = newHasCertificate; }

	// Метод для прибавление студента
	void addStudents() { ++enrolledStudents; }

	// Метод наличие сертефиката
	void displayHasCertificate() const {
		cout << "Сертефикат " << (hasCertificate ? "есть" : "нет") << endl;
	}
	
	// Метод для отображения информации
	virtual void to_string() const {
		cout << "Название курса: " << courseName << endl;
		cout << "Преподаватель: " << instructorName << endl;
		cout << "Длительность: " << duration << " часов" << endl;
		cout << "Цена: " << price << " руб." << endl;
		cout << "Количество студентов: " << enrolledStudents << endl;
		displayHasCertificate();
	}

};

class offlineCourse: public Course {
public:
	string platform; // На какой платформе

	// Конструктор 
	offlineCourse(const string& name, const string& instructor, unsigned dur, unsigned prc, bool cert, const string& platformName)
	: Course(name, instructor, dur, prc, cert), platform(platformName) {}

	// Геттеры
	string getPlatform() const { return platform; }

	// Сеттеры
	void setPlatform(const string& newPlatform) { platform = newPlatform; }

	// Переопределённый метод для отображения информации
	void to_string () const override {
		Course::to_string();
		cout << "Платформа проведения: " << platform << endl;
	}
};

class onlineCourse : public Course {
public:

	string location; // Адрес проведение курсов
	bool liveSession; // Есть ли эказмены в живую

	// Конструктор 
	onlineCourse(const string& name, const string& instructor, unsigned dur, unsigned prc, bool cert, const string& courseLocation, bool live)
		: Course(name, instructor, dur, prc, cert), location(courseLocation), liveSession(live) {}

	// Геттеры
	string getLocation() const { return location; }
	bool isLiveSession() const { return liveSession; }

	// Сеттеры
	void setLocation(const string& newLocation) { location = newLocation; }
	void setLiveSession(bool live) { liveSession = live; }

	// Проходят ли живые сессии
	void displayLiveSession() const {
		cout << "Живые сессии " << (liveSession ? "проводятся" : "не проводятся") << endl;
	}

	// Переопределённый метод для отображения информации
	void to_string() const override {
		Course::to_string();
		cout << "Адрес проведения: " << location << endl;
		displayLiveSession();
	}

};

// Функция тестирования
void testCourse() {

	// Базовый класс
	Course course("Основы программирования", "Ветров Сергей Владимирович", 30, 3000, true);

	// Проверка геттеров
	assert(course.getCourseName() == "Основы программирования");
	assert(course.getInstructorName() == "Ветров Сергей Владимирович");
	assert(course.getDuration() == 30);
	assert(course.getPrice() == 3000);
	assert(course.getHasCertificate() == true);
	assert(course.getEnrolledStudents() == 0);

	// Проверка сеттеров
	course.setCourseName("Вычислительная математика");
	assert(course.getCourseName() == "Вычислительная математика");

	course.setInstructorName("Забелин Анатолий Анатольевич");
	assert(course.getInstructorName() == "Забелин Анатолий Анатольевич");

	course.setDuration(40);
	assert(course.getDuration() == 40);

	course.setPrice(4000);
	assert(course.getPrice() == 4000);

	course.setHasCertificate(false);
	assert(course.getHasCertificate() == false);

	// Проверка метода добавления студентов
	course.addStudents();
	assert(course.getEnrolledStudents() == 1);

	// Тесты для онлайн курсов
	onlineCourse online("Математическая логика", "Коган Евгения Семёновна", 60, 10000, true, "Zoom", true);

	// Проверка геттеров
	assert(online.getLocation() == "Zoom");
	assert(online.isLiveSession() == true);

	// Проверка сеттеров
	online.setLocation("Microsoft Teams");
	assert(online.getLocation() == "Microsoft Teams");

	online.setLiveSession(false);
	assert(online.isLiveSession() == false);


	// Для оффлайн курсов
	offlineCourse offline("ООП", "Ветров Сергей Владимирович", 50, 5000, true, "Skillbox");

	// Проверка геттеров
	assert(offline.getPlatform() == "Skillbox");

	// Проверка сеттеров
	offline.setPlatform("Coursera");
	assert(offline.getPlatform() == "Coursera");
}




