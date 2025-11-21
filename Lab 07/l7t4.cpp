#include <iostream>
#include <string>
using namespace std;

class Product {
public:
    string name;
    double price;
    string description;
    bool available;

    Product(string n = "", double p = 0.0, string d = "", bool a = false)
        : name(n), price(p), description(d), available(a) {}

    void display() const {
        cout << name << " - $" << price;
        if (!available) {
            cout << " out of stock";
        }
        cout << "\n";
    }
};

int partition(Product arr[], int start, int end)
{
    double pivot = arr[end].price;
    int i = start - 1;

    for (int j = start; j < end; ++j) {
        if (arr[j].price <= pivot) {
            ++i;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[end]);
    return i + 1;
}

void quickSort(Product arr[], int start, int end)
{
    if (start < end) {
        int p = partition(arr, start, end);
        quickSort(arr, start, p - 1);
        quickSort(arr, p + 1, end);
    }
}

int main() {
    const int N = 3;

    Product product1("Product 1", 10.99, "This is product 1.", true);
    Product product2("Product 2", 5.99,  "This is product 2.", false);
    Product product3("Product 3", 2.99,  "This is product 3.", true);

    Product products[N] = {product1, product2, product3};

    quickSort(products, 0, N - 1);

    cout << "Product list sorted by price (ascending):\n";
    for (int i = 0; i < N; ++i) {
        products[i].display();
    }

    return 0;
}
