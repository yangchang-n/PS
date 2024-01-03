#include <iostream>

using namespace std;

int main()
{
    int my_array[] = {1, 2, 3, 2, 5, 4, 3, 2, 1};

    for (int i = 0; i < sizeof(my_array)/sizeof(int); i++)
    {
        if (i > 0 && my_array[i - 1] > my_array[i])
            break;
        cout << my_array[i] << " ";
    }
    cout << endl;

    return 0;
}