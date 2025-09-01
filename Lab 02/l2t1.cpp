#include <iostream>
using namespace std;

int main()
{
    int u_index;
    int check = 0;
    cout << "Enter Index: ";
    cin >> u_index;
    int *arr = new int[u_index];
    for (int i = 0; i < u_index; i++)
    {
        arr[i] = 0;
    }
    do
    {
        cout << "Enter Index or Enter -1 to exit" << endl;
        cin >> check;
        if(check == -1)
        break;
        if(check < 0 || check>= u_index){
            cout<<"Invalid Value"<<endl;
        }
        cout << "Editing Array at " << check <<"\n"<< endl;
        cout << "Enter integer: " << endl;
        cin>>arr[check];
    } while (check != -1 );

    for (int i = 0; i < u_index; i++)
    {
        cout << "\nFinal Array is: " << arr[i] << endl;
    }

    delete []arr;
    return 0;
}