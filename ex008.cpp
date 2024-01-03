#include <iostream>

using namespace std;

int main()
{
    char my_string[] = "Hello\0, World!";

    int i = 0;
    // while (1)
    // {
    //     if (my_string[i] == '\0')
    //         break;
        
    //     cout << my_string[i];
    //     i++;
    // }
    while (i < sizeof(my_string) && my_string[i] != '\0')
    {
        cout << my_string[i];
        i++;
    }
    cout << endl;

    return 0;
}