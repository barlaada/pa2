#include <iostream>
#include <iomanip>

using namespace std;

int main() 
{
    /*
    int x;
    char c[11];
    printf("Zadej cislo a slovo:\n");
    scanf("%d %10s", &x, c);
    printf("Zadal jsi: %d %s\n", x, c);
    return 0;
    */
    int x;
    char c[11];
    cout << "Zadej cislo a slovo:" << endl;
    cin  >> x >> setw(11) >> c;
    cout << "Zadal jsi: " << x << " " << c << endl;
    return 0;
}