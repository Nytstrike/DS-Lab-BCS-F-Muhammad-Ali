#include <iostream>
using namespace std;
class Exam
{
private:
    string *studName;
    string *examDate;
    int *score;

public:
    void setStudName(string name)
    {
        *studName = name;
    }
    void setExam_Date(string Date)
    {
        *examDate = Date;
    }
    void setScore(int Score)
    {
        *score = Score;
    }
    void displayExamDetails()
    {
        cout << "Student Name: " << *studName << endl;
        cout << "Exam Date: " << *examDate << endl;
        cout << "Score: " << *score << "/100\n" << endl;
    }
    Exam()
    {
        studName = new string;
        examDate = new string;
        score = new int;
    }
    ~Exam()
    {
        delete studName;
        delete examDate;
        delete score;
    }
};

int main()
{
    Exam s1;
    s1.setStudName("Muhammmad Ali");
    s1.setExam_Date("7 Dec 27");
    s1.setScore(78);
    s1.displayExamDetails();
    Exam s2(s1);
    s2.setStudName("Neeraj Khemani");
    s2.setExam_Date("12 Dec 27");
    s2.setScore(89);
    s2.displayExamDetails();
    s1.displayExamDetails();

    return 0;
}

// Shallow copy will share the same memory for DMA attributes(studName & examDate). 
// Change 1 object will change the others, since both point to the same data(pointers). 
// Deleting will cause double deletion, which may cause crashes