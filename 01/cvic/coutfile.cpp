/**Napište program, 
 * který si vyžádá od uživatele název souboru a číslo. 
 * Program následně uloží číslo do textového souboru zadaného názvu.
 * Upravte program z předchozího příkladu tak,
 * že načtené číslo bude reprezentovat počet prvků v poli 
 * a následně bude následovat ještě samotný obsah pole. 
 * Pole uložte do paměti a následně ho uložte do textového souboru zadaného názvu.
 */

#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    string filename;
    int number;
    cout << "Zadajedte cislo a nazev souboru:" << endl;
    cin  >> number >> filename;

    fstream myfile( filename , ios::app );

    if( myfile.is_open() )
    {
        myfile << number << endl;
        myfile.close();
    }
    else
        cout << "Nepodarilo se otevrit soubor." << endl;
}