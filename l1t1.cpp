#include<iostream>
using namespace std;
int factorial (int i){
    if(i ==0){
        return 1;
    }
    else {
        return i * factorial(i-1);
    }
}
int main () {
int n;
cout<<"Enter a number"<<endl;
cin>>n;
cout<<"\n";
int temp = factorial(n);
cout<<"The factorial of "<< n << " is "<<temp<<endl;
}
