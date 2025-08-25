#include <iostream>
using namespace std;
class Box
{
private:
    int *num;

public:
    Box()
    {
        num = new int(0);
    }
    Box(const Box &obj)
    {
        num = new int(*obj.num);
    }
    Box &operator=(const Box &obj)
    {
        if (this != &obj)
        {
            delete num;
            num = new int(*obj.num);
        }
        return *this;
    }
    void setNum(int number)
    {
        *num = number;
    }
    void displayNum()
    {
        cout << "\tValue:" << *num<<endl;
    }
     ~Box()
    {
        delete num;
    }
};
// -- using deep copy -- 
int main()
{
    Box b1;
    b1.displayNum();

    b1.setNum(123);

    Box b2 = b1;
    b1.displayNum();
    b2.displayNum();
    b1.setNum(567);
    b1.displayNum();
    b2.displayNum();
    b2 = b1;
    b2.displayNum();
    b1.displayNum();

    return 0;
}

// Instead of shallow copying; each obj keeps its copy of the data.
// Modifying one obj will not affect others
// No double deletion