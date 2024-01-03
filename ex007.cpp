#include <iostream>

using namespace std;

int main()
{
    int i = 0;
    
    while (true) // == for(;true;)
    {
        if (i >= 10)
            break;

        cout << i << " ";
        i++;
    }

    return 0;
}