#include <iostream>

using namespace std;

int main()
{
    char my_str[] = {'h', 'e', 'l', 'l', 'o'};

    char *ptr = my_str;

    cout << *ptr << " " << ptr[4] << " " << *(ptr + 4) << endl;

    cout << *ptr << " " << ptr << " " << size_t(&ptr) << endl;

    cout << *my_str << " " << my_str << " " << size_t(&my_str) << endl;

    return 0;
}