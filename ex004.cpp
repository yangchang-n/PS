#include <iostream>

using namespace std;

int main()
{
    int number;

    cin >> number;

    if (number % 2 == 0)
        printf("even\n");
    else
        cout << "odd\n";

    cout << (number % 3 == 0 ? "divided by 3" : "can't") << endl;

    switch (number)
    {
        case 0 :
            cout << "is 0" << endl;
            break;
        default :
            cout << "is not 0" << endl;
            break;
    }
    
    return 0;
}
