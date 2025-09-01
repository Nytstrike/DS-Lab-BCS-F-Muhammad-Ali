#include <iostream>
int main()
{
    int benches, seats, check, c2;
    std::cout << "Enter number of Benches: ";
    std::cin >> benches;
    std::cout << "Enter number of Seats for each bench: ";
    std::cin >> seats;
    int **arr = new int *[benches];
    for (int i = 0; i < benches; i++)
    {
        arr[i] = new int[seats];
    }
    do
    {
        std::cout << "\nEnter Bench Number: ";
        std::cin >> check;
        if (check > benches)
        {
            std::cout << "\nInvalid" << std::endl;
            continue;
        }
        if (check == -1)
        {
            break;
        }
        std::cout << "\nEnter Seat Number: ";
        std::cin >> c2;
        if (c2 > seats)
        {
            std::cout << "\nInvalid" << std::endl;
            continue;
        }
        arr[check][c2] = 1;
        std::cout << "\nSeat: " << c2 << " of the Bench: " << check << " is now occupied" << std::endl;
    } while (check != -1);
    return 0;
}