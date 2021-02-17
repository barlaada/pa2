#include <iostream>

using namespace std;

int main()
{
    int sum = 0, x;

    while ( cin >> x )
    {
        sum += x;
    }

    if ( !cin.eof() )
        cout << "chyba" << endl;
    else
        cout << "sum = " << sum << endl;

    return 0;
}