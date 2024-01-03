#include <iostream>

using namespace std;

int main()
{
    char my_string[] = "Hello\0, World!";
    // don't use cout << my_string << endl;

    for (int i = 0; i < sizeof(my_string); i++)
    {
        if (my_string[i] == '\0')
            break;
        cout << my_string[i];
    }
    cout << endl;

    return 0;
}