#include<iostream>
using namespace std;
class SafePointer{
    int *ptr;
    public:
    SafePointer() {
        ptr = new int(0);
    }
    void setValue(int n) {
        *ptr = n; 
    }
    int getValue() {
         return *ptr;
    }
    void release() {
        delete ptr;
        ptr = nullptr;
    }
    ~SafePointer() {
        delete ptr;
    }
};
int main () {
    SafePointer student[5];
    int m;
    for(int i=0; i<5; i++) {
        cout<<"\nEnter Marks for student "<<i+1<< ": ";
        cin>>m;
        student[i].setValue(m);
    }
    for(int i =0 ; i < 5; i++) {
        cout<<"\nPrinting Marks for student "<<i+1<<": ";
        cout<< student[i].getValue()<<endl;
    }
    
    return 0;
}