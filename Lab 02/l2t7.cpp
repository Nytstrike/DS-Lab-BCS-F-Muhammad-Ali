#include <iostream>
using namespace std;
using  std::cout;

int main() {
    //salaries
    double dept1[] = {50000, 65000, 72000, 58000}; 
    double dept2[] = {45000, 52000, 61000, 67000, 54000, 59000};
    double dept3[] = {75000, 82000, 95000};
    double dept4[] = {42000, 48000, 55000, 62000, 51000};
    
    double* departments[] = {dept1, dept2, dept3, dept4};
    int sizes[] = {4, 6, 3, 5};
    string departmentNames[] = {"IT", "Sales", "Management", "HR"};
    cout << "Highest salary in each department:" << endl;
    double maxSalaries[4];
    
    for (int i = 0; i < 4; i++) {
        double max = departments[i][0];
        for (int j = 1; j < sizes[i]; j++) {
            if (departments[i][j] > max) {
                max = departments[i][j];
            }
        }
        maxSalaries[i] = max;
        cout << departmentNames[i] << ": $" << max << endl;
    }
    
    cout << "\nDepartment with highest average salary:" << endl;
    double maxAverage = 0;
    int maxAverageDept = 0;
    
    for (int i = 0; i < 4; i++) {
        double sum = 0;
        for (int j = 0; j < sizes[i]; j++) {
            sum += departments[i][j];
        }
        double average = sum / sizes[i];
        cout << departmentNames[i] << " average: $" << average << endl;
        
        if (average > maxAverage) {
            maxAverage = average;
            maxAverageDept = i;
        }
    }
    
    cout << "\nDepartment with overall maximum average salary: " 
         << departmentNames[maxAverageDept] << " ($" 
         << maxAverage << ")" << endl;
    
    return 0;
}