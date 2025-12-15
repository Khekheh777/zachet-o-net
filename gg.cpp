#include <iostream>
#include <string>
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

int main() {
    Employee employees[5];
    for (int i = 0; i <3 ; i++) {
        cout << "введите данные для работничка #" << (i + 1) << endl;
        string name;
        cout << "имя: ";
        cin >> name;
        
        int id;
        cout << "айди: ";
        cin >> id;
        
        double salary;
        cout << "зпшка: ";
        cin >> salary;
       
        employees[i] = Employee(name, id, salary);
    }   
    for (int i = 0; i < 3; i++) {
        cout << "ID: " << employees[i].getId() << ", Name: " << employees[i].getName() << ", Salary: " << employees[i].getSalary() << endl;
    }
    return 0;
}