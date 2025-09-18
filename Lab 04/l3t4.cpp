#include <iostream>
using namespace std;

class Node {
public:
    int data;
     Node* next;
    Node(int value) : data(value), next(NULL) {}
};

int main() {

    int n;
    cout<< "Enter number of People ";
    cin >> n;

    if(n<=0){
        cout<< "The number of people should be greater than zero\n";
       cout<< "Enter number of People "<<endl; 
       cin >> n;

    }

    int k;
    cout<< "Enter K:";
    cin    >> k;
    //  if(k<=0){
    //     cout<< "K should be greater than zero\n";
    //    cout<< "Enter K"<<endl; 
    //     cin    >> k;
    // }

    Node* head = new Node(1);
    Node* tail = head;

    for (int i = 2; i <= n; i++) {
        tail->next = new Node(i);
        tail = tail->next;
    }
    
    tail->next = head; 

    Node* last = tail;
    Node* cur = head;

    while (cur->next != cur) {
        for (int count = 1; count < k; count++) {
            last = cur;
            cur = cur->next;
        }
        last->next = cur->next;
             delete cur;
        
        cur = last->next;
    
        
    }

    cout   << "Survivoris at: " << cur->data << endl;

    delete cur;



    return 0;
}