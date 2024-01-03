#include <iostream>
#include <limits>

using namespace std;

int main()
{
    cout << "Hello, World" << endl;

    char user_input[100];
    int number = -1;

    // cin.getline(user_input, sizeof(user_input));
    cin >> user_input;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin >> number;
    cout << user_input << " " << number;

    return 0;
}
