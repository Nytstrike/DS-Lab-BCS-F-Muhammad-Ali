#include<iostream>
using namespace std;
 int main() {
    int students, *nCourses,*total;
    float *avg;
    cout<<"Enter Number of Students: ";
    cin>>students;
    int **jagged_arr= new int*[students];
     nCourses = new int[students];
     avg = new float[students];
     total = new int[students];
    cout<<"Enter no of courses for each respective student: ";
    for(int i=0; i<students;i++) {
        cout<<"\n For Roll no# "<<1+i;
        cin>>nCourses[i];
        jagged_arr[i] = new int[nCourses[i]];
        avg[i] = 0.0;
        total[i] = 0;
    }
    cout<<"Enter marks for each student"<<endl;
    for(int i=0; i< students;i++){
        cout<<"\nRoll no:"<<1000+i<<endl;
        for(int j=0; j<nCourses[i];j++) {
            cout<<"\nCourse #"<<1+j<<": ";
            cin>>jagged_arr[i][j];
            total[i]+=jagged_arr[i][j];
        }
    }
    for(int l =0; l< students; l++) {
        avg[l] = total[l]/nCourses[l];
        cout<<"\nRoll no: " << 1000 + l <<endl;
        cout<<avg[l]<<endl;
    }
    for(int i=0;i<students;i++) {
        delete [] jagged_arr[i];
    }
    delete total;
    delete avg;
    delete nCourses;
    return 0;
 }