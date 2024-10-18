#pragma once
#include <cassert>

using namespace std;

/// ������������ ��� � ��������� ��� ������ � ���������
namespace vector_space {
    /// ������� ��� ��������� ������ �� ������������ � ���������� �������, ��� v - ������
    template <typename T>
    void receive_data(vector<T> &v) {
        for (size_t i = 0; i < v.size(); i++) { // ���� �� ���� ��������� �������
            cout << "������� " << i + 1 << " ������� �������: "; // ������ ����� ��������
            cin >> v[i]; // ������ �������� � ���������� � ������
        }
    }

    /// ������� ��� ���������� ������� ���������� �������, ��� v - ������
    template <typename T>
    void rand_mas(vector<T>& v) {
        for (size_t i = 0; i < v.size(); i++) { // ���� �� ���� ��������� �������
            v[i] = 1 + rand() % 100; // ��������� ���������� ����� �� 1 �� 100
        }
    }

    /// ������� �������� ����� ������� ��������� �������, ��� v - ������
    template <typename T>
    float calculate(vector<T>& v) {
        float res = 0; // ���������� ��� �������� �����
        for (size_t i = 0; i < v.size(); i++) { // ���� �� ���� ��������� �������
            res += abs(v[i]); // ���������� ������ �������� �������� � �����
        }
        return res; // ������� �������� �����
    }

    ///������� ��� ������ ������ � �������, ��� v - ������
    template <typename T>
    void output_terminal(vector<T>& v) {
        for (size_t i = 0; i < v.size(); i++) {
            cout << v[i] << ' '; // ����� ������� �������� �������
        }
    }

    /// ������� ��� ������ ������� � ��������� ����, ��� v - ������, namef - ��� �����
    template <typename T>
    void input_txt_file(vector<T>& v, const string& namef) {
        ofstream file(namef, ios_base::out); // �������� ����� ��� ������
        if (file.is_open()) { // ��������, ������� �� ������ ����
            for (size_t i = 0; i < v.size(); i++) { // ���� �� ���� ��������� �������
                file << v[i] << endl; // ������ ������� �������� � ���� � ��������� ������
            }
        }
    }


    /// ������� ��� ������ ������ ��  ���������� ����� � ���������� �������, ��� v - ������, namef - ��� �����
    template <typename T>
    void output_txt_file(vector<T>& v, const string& namef) {
        ifstream file(namef); // �������� ����� ��� ������
        if (file.is_open()) { // ��������, ������� �� ������ ����
            for (size_t i = 0; i < v.size(); i++) { // ���� �� ���� ��������� �������
                file >> v[i]; // ������ �������� �� ����� � ���������� � ������
            }
        }
    }


    /// ������� ��� ������
    void test() {
        // ���� 1: ������������� �����
        float test_v1[] = { 3, 5, 6 };
        assert(calculate(test_v1, 3) == 14);

        // ���� 2: ������������� �����
        float test_v2[] = { -3, -5, -6 };
        assert(calculate(test_v2, 3) == 14);

        // ���� 3: ����� � �������
        float test_v3[] = { 3.5f, 5.3f, 6.8f };
        assert(fabs(calculate(test_v3, 3) - 15.6f) <= 0.0000000001);
    }

    /// ������� ��� ������ ������� � �������� ����, ��� v - ������, namef - ��� �����
    template <typename T>
    void input_bin_file(vector<T>& v, const string& namef) {
        ofstream file(namef, ios::binary); // �������� ��������� ����� ��� ������
        if (file.is_open()) { // ��������, ������� �� ������ ����
            file.write(reinterpret_cast<char*>(v), v.size() * sizeof(T)); // ������ ������� � ����
            file.close(); // �������� �����
        }
        else {
            cerr << "�� ������� ������� ���� ��� ������." << endl; // ��������� �� ������
        }
    }

    /// ������� ��� ������ ������ �� ��������� ����� � ���������� �������, ��� v - ������, namef - ��� �����
    template <typename T>
    void output_bin_file(vector<T>& v, const string& namef) {
        ifstream file(namef, ios::binary); // �������� ��������� ����� ��� ������
        if (file.is_open()) { // ��������, ������� �� ������ ����
            file.read(reinterpret_cast<char*>(v), v.size() * sizeof(T)); // ������ ������� �� �����
            file.close(); // �������� �����
        }
        else {
            cerr << "�� ������� ������� ���� ��� ������." << endl; // ��������� �� ������
        }
    }

}
