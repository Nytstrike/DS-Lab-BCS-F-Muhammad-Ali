#include <iostream>
using namespace std;
float totaling(const float *arr, const int s)
{
    int total=0;
    for(int i=0; i<s; i++) {
        total += arr[i];
    }
    return total;
}
float average (int t, int s){
    return t/s;
}
int main()
{
    float *expenseSheet;
    int n, n2;
    char choice;
    float *copy, avg, total;
    cout << "Enter No of Months: ";
    cin >> n;
    expenseSheet = new float[n];
    cout << "Enter monthly expenses: ";
    for (int i = 0; i < n; i++)
    {
        cout << "\n- For Month# " << 1 + i<<": ";
        cin >> expenseSheet[i];
    }
    cout << "Do you want to expand expense sheet size?(y or n)" << endl;
    cin >> choice;
    if (choice == 'N' || choice == 'n')
    {   
        total=totaling(expenseSheet,n);
        cout << "\nTotal for "<<n<<"is:"<<total<<endl;
        cout<<"\nAverage is: "<<average(total,n)<<endl;
        return 0;
    }
    // if yes
    copy = new float[n];
    for (int i = 0; i < n; i++)
    {
        copy[i] = expenseSheet[i];
    }
    cout << "Enter new Size: ";
    cin >> n2;
    delete expenseSheet;
    expenseSheet = new float[n2];
    for (int i = 0; i < n; i++)
    {
        expenseSheet[i] = copy[i];
    }
    cout << "\nEnter New Expenses: ";
    cout << "\nEnter monthly expenses: ";
    for (int i = n; i < n2; i++)
    {
        cout << "\n- For Month# " << 1 + i<<": ";
        cin >> expenseSheet[i];
    }
     total=totaling(expenseSheet,n2);
        cout << "\nTotal for "<<n<<"is:"<<total<<endl;
        cout<<"\nAverage is: "<<average(total,n2)<<endl;
}