#pragma once
#include <iostream>
#include <string>
#include <list>
#include <assert.h>

using namespace std;

list<string> allInstructorNames =
{"������ ������ ������������",
"������� �������� �����������",
"����� ������� ��������" };

class Course {
protected:
	string courseName; // �������� �����
	string instructorName; // ��� �������������
	unsigned duration; // ������� ����� ����������� �� ����
	unsigned price; // ���� �� ����
	unsigned enrolledStudents; // ���-�� ������������ ���������
	bool hasCertificate; // ������� ������������ �� ��������� �����
public:
	// ����������� 
	Course(const string& name, const string& instructor, unsigned dur, unsigned prc, bool cert)
	: courseName(name), instructorName(instructor), duration(dur), price(prc), hasCertificate(cert), enrolledStudents(0) {}

	// �������
	string getCourseName() const { return courseName; }
	string getInstructorName() const { return instructorName; }
	unsigned getDuration() const { return duration; }
	unsigned getPrice() const { return price; }
	unsigned getEnrolledStudents() const { return enrolledStudents; }
	bool getHasCertificate() const { return hasCertificate; }

	// �������
	void setCourseName(const string& newName) { courseName = newName; }
	// �������� �� �� ���, ��� � ����� ���� ��� �������������
	/*
	find � ��� ��������, ������� ���� ������ ������� � ��������� ���������, ����������� � �������� ���������.
	���������: allInstructorNames.begin() � �������� �� ������ ������ allInstructorNames
	allInstructorNames.end() � �������� �� ����� ������ allInstructorNames
	newInstructorName � ��������, ������� ����� �����
	���� ������������ �������� �� ����� allInstructorNames.end(), ��� ��������, ��� newInstructorName ���������� � ������.
	���� �������� ����� allInstructorNames.end(), ������� �� ������.
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
			cout << "������������ ����� �� ����� ���� ����� 0." << endl;
		}
	}
	void setPrice(unsigned newPrice) { price = newPrice; }
	void setEnrolledStudents(unsigned enStudents) { enrolledStudents = enStudents; }
	void setHasCertificate(bool newHasCertificate) { hasCertificate = newHasCertificate; }

	// ����� ��� ����������� ��������
	void addStudents() { ++enrolledStudents; }

	// ����� ������� �����������
	void displayHasCertificate() const {
		cout << "���������� " << (hasCertificate ? "����" : "���") << endl;
	}
	
	// ����� ��� ����������� ����������
	virtual void to_string() const {
		cout << "�������� �����: " << courseName << endl;
		cout << "�������������: " << instructorName << endl;
		cout << "������������: " << duration << " �����" << endl;
		cout << "����: " << price << " ���." << endl;
		cout << "���������� ���������: " << enrolledStudents << endl;
		displayHasCertificate();
	}

};

class offlineCourse: public Course {
public:
	string platform; // �� ����� ���������

	// ����������� 
	offlineCourse(const string& name, const string& instructor, unsigned dur, unsigned prc, bool cert, const string& platformName)
	: Course(name, instructor, dur, prc, cert), platform(platformName) {}

	// �������
	string getPlatform() const { return platform; }

	// �������
	void setPlatform(const string& newPlatform) { platform = newPlatform; }

	// ��������������� ����� ��� ����������� ����������
	void to_string () const override {
		Course::to_string();
		cout << "��������� ����������: " << platform << endl;
	}
};

class onlineCourse : public Course {
public:

	string location; // ����� ���������� ������
	bool liveSession; // ���� �� �������� � �����

	// ����������� 
	onlineCourse(const string& name, const string& instructor, unsigned dur, unsigned prc, bool cert, const string& courseLocation, bool live)
		: Course(name, instructor, dur, prc, cert), location(courseLocation), liveSession(live) {}

	// �������
	string getLocation() const { return location; }
	bool isLiveSession() const { return liveSession; }

	// �������
	void setLocation(const string& newLocation) { location = newLocation; }
	void setLiveSession(bool live) { liveSession = live; }

	// �������� �� ����� ������
	void displayLiveSession() const {
		cout << "����� ������ " << (liveSession ? "����������" : "�� ����������") << endl;
	}

	// ��������������� ����� ��� ����������� ����������
	void to_string() const override {
		Course::to_string();
		cout << "����� ����������: " << location << endl;
		displayLiveSession();
	}

};

// ������� ������������
void testCourse() {

	// ������� �����
	Course course("������ ����������������", "������ ������ ������������", 30, 3000, true);

	// �������� ��������
	assert(course.getCourseName() == "������ ����������������");
	assert(course.getInstructorName() == "������ ������ ������������");
	assert(course.getDuration() == 30);
	assert(course.getPrice() == 3000);
	assert(course.getHasCertificate() == true);
	assert(course.getEnrolledStudents() == 0);

	// �������� ��������
	course.setCourseName("�������������� ����������");
	assert(course.getCourseName() == "�������������� ����������");

	course.setInstructorName("������� �������� �����������");
	assert(course.getInstructorName() == "������� �������� �����������");

	course.setDuration(40);
	assert(course.getDuration() == 40);

	course.setPrice(4000);
	assert(course.getPrice() == 4000);

	course.setHasCertificate(false);
	assert(course.getHasCertificate() == false);

	// �������� ������ ���������� ���������
	course.addStudents();
	assert(course.getEnrolledStudents() == 1);

	// ����� ��� ������ ������
	onlineCourse online("�������������� ������", "����� ������� ��������", 60, 10000, true, "Zoom", true);

	// �������� ��������
	assert(online.getLocation() == "Zoom");
	assert(online.isLiveSession() == true);

	// �������� ��������
	online.setLocation("Microsoft Teams");
	assert(online.getLocation() == "Microsoft Teams");

	online.setLiveSession(false);
	assert(online.isLiveSession() == false);


	// ��� ������� ������
	offlineCourse offline("���", "������ ������ ������������", 50, 5000, true, "Skillbox");

	// �������� ��������
	assert(offline.getPlatform() == "Skillbox");

	// �������� ��������
	offline.setPlatform("Coursera");
	assert(offline.getPlatform() == "Coursera");
}




