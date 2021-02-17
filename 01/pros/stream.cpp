#include <iostream>
#include <climits>

using namespace std;

int main()
{
    int a = 0, b = 0;

    while ( ! ( cin >> a >> b ) && !cin.eof() )
    {
        cout << "error, try again!" << endl;
        cin.clear();
        cin.ignore( INT_MAX, '\n' );
    }
    cout << "a + b = " << a + b << endl;

    return 0;
}