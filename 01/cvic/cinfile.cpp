/**Napište program, který si vyžádá od uživatele název souboru a číslo.
 * Program následně zkusí přečíst číslo z textového souboru zadaného názvu a porovná ho s tím zadaným od uživatele,
 * poté uživatele informuje, zda se čísla shodují.
 */

#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    string filename;
    int num1;
    cout << "Zadajedte cislo a nazev souboru:" << endl;
    cin  >> num1 >> filename;

    ifstream myfile( filename );

    if( myfile.is_open() )
    {
        int num2;
        myfile >> num2;
        myfile.close();

        if( num1 == num2 )
            cout << "cisla sa zhoduju" << endl;
        else    
            cout << "cisla sa nezhoduju" << endl;
    }
    else
        cout << "Nepodarilo se otevrit soubor." << endl;
}