#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class Employee
{
private: 
    string name;
    int id;
    double salary;

public: 
    Employee() : name(""), id(0), salary(0.0) {}
    Employee(string empName, int empId, double empSalary)
    {
        name = empName;
        id = empId;
        salary = empSalary;
    }
    string getName() const { return name; }
    int getId() const { return id; }
    double getSalary() const { return salary; }
    
    void setSalary(double newSalary)
    {
        if (newSalary >= 0) {
            salary = newSalary;
        } else {
            cout << "ойой чет в минус уходим" << endl;
        }
    }
};

void saveToFile(const Employee employees[], int size, const string& filename) {
    ofstream outFile(filename);
    if (!outFile.is_open()) {
        cout << "о неттт не удалось открыть файл " << filename << endl;
        return;
    }
    for (int i = 0; i < size; i++) {
        outFile << employees[i].getId() << " " << employees[i].getName() << " " << employees[i].getSalary() << endl;
    }
    outFile.close(); 
    cout << "инфа успешно сохранена в файл " << filename << endl;
}

bool isValidEmployeeData(const std::string& name, int id, double salary) {
    if (name.empty()) {
        cout << "о неттт mame пустое" << endl;
        return false;
    }
    if (id <= 0) {
        cout << "о неттт id не положительный" << endl;
        return false;
    }
    if (salary < 0) {
        cout << "о неттт salary отрицательная" << endl;
        return false;
    }
    return true;
}

int main() {
    Employee employees[5];
    int validEmpCount = 0;
    for (int i = 0; i <3 ; i++) {
        cout << "введите данные для работничка #" << (i + 1) << endl;
        string name;
        cout << "имя: ";
        getline(cin, name);
        
        int id;
        cout << "айди: ";
        cin >> id;
        
        double salary;
        cout << "зпшка: ";
        cin >> salary;

        if (isValidEmployeeData(name, id, salary)) {
            employees[validEmpCount] = Employee(name, id, salary);
            validEmpCount++;
            cout << "успешно сохранено~" << endl;
        }
        else {
            cout << "данные некорректны, потому ввод пропущен!" << endl;
        }
        cin.clear();
        cin.ignore(1000, '\n');
    }   
    for (int i = 0; i < 3; i++) {
        cout << "ID: " << employees[i].getId() << ", Name: " << employees[i].getName() << ", Salary: " << employees[i].getSalary() << endl;
    }
    saveToFile(employees, validEmpCount, "employees.txt");
    return 0;
}
