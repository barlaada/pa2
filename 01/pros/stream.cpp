#include <iostream>

using namespace std;

int main()
{
    int a, b;

    if ( ! ( cin >> a >> b ) )
        cout << "chyba" << endl;
    else
        cout << "a + b = " << a+b << endl;

    return 0;
}