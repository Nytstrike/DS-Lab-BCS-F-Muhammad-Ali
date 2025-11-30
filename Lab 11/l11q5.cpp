#include <iostream>
#include <string>
using namespace std;

class StudentHashTable {
private:
    static const int TABLE_SIZE = 15;
    struct Student {
        int rollNumber;
        string name;
        bool isOccupied;

        Student() : rollNumber(-1), isOccupied(false) {}
    };
    
    Student table[TABLE_SIZE];
    
    int hashFunction(int rollNumber) {
        return rollNumber % TABLE_SIZE;
    }
    
public:
    StudentHashTable() {
        for (int i = 0; i < TABLE_SIZE; i++) {
            table[i] = Student(); }
    }
    
    void InsertRecord(int rollNumber, string name) {
        int index = hashFunction(rollNumber);
        int attempt = 0;       
        while (attempt < TABLE_SIZE) {
            int currentIndex = (index + attempt * attempt) % TABLE_SIZE;
            if (!table[currentIndex].isOccupied) {
                table[currentIndex].rollNumber = rollNumber;
                table[currentIndex].name = name;
                table[currentIndex].isOccupied = true;
                cout << "Record inserted at index " << currentIndex << endl;
                return; }
            attempt++; }
        cout << "Hash table is full. Cannot insert record." << endl;
    }
    
    void SearchRecord(int rollNumber) {
        int index = hashFunction(rollNumber);
        int attempt = 0;
        while (attempt < TABLE_SIZE) {
            int currentIndex = (index + attempt * attempt) % TABLE_SIZE;
            if (table[currentIndex].isOccupied && table[currentIndex].rollNumber == rollNumber) {
                cout << "Record found: " << table[currentIndex].name << endl;
                return; }
            if (!table[currentIndex].isOccupied) {
                break; }
            attempt++; }
        cout << "Record not found" << endl;
    }
    
    void DisplayTable() {
        cout << "Hash Table Contents:" << endl;
        for (int i = 0; i < TABLE_SIZE; i++) {
            cout << "Index " << i << ": ";
            if (table[i].isOccupied) {
                cout << "Roll: " << table[i].rollNumber << ", Name: " << table[i].name; } 
			else {
                cout << "Empty"; }
            cout << endl; }
    }
};

int main() {
    StudentHashTable studentTable;   
    studentTable.InsertRecord(101, "Murtaza");
    studentTable.InsertRecord(102, "Adnan");
    studentTable.InsertRecord(116, "Turab");
    studentTable.InsertRecord(131, "Rayyan");
    studentTable.InsertRecord(103, "Zain");    
    cout << "\nSearch operations:" << endl;
    studentTable.SearchRecord(101);
    studentTable.SearchRecord(116);
    studentTable.SearchRecord(999);   
    cout << "\nHash table:" << endl;
    studentTable.DisplayTable();  
    cout << "\nCollision with quadratic probing:" << endl;
    studentTable.InsertRecord(101 + 15, "Arham");
    studentTable.InsertRecord(101 + 30, "Usman");    
    cout << "\nFinal:" << endl;
    studentTable.DisplayTable();   
    return 0;
}