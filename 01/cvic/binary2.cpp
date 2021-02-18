/**
 * Napište program, ve kterém si vytvoříte vhodnou strukturu. 
 * Tento program načte ze standardního vstupu 15 čísel a uloží je do této struktury. 
 * Obsah struktury následně uložte do binárního souboru. 
 * Poté přečtěte data z tohoto souboru a uložte je do další struktury stejného typu,
 * tuto další strukturu vypište na stadardní výstup.
 *  a)  Vylepšete tuto úlohu tak, že po načtení obsahu souboru, před jeho vypsáním, tato čísla vzestupně seřaďte.
 *  b)  Vyřešte toto rozšíření bez použití cyklu a s tím omezením, že můžete použít pouze jedno čtení ze souboru.
 */

#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

#define N 15

int main()
{
    int numbers[N], numbersRead[N];

    // get numbers
    cout << "Write " << N << " numbers:" << endl;
    for (int i = 0; i < N; i++)
    {
        cin >> numbers[i];
    }
    
    // save numbers
    fstream outfile("number_list", ios::out | ios::binary );
    if( outfile.is_open() )
    {
        outfile.write( (char*)&numbers, 4 * N );
        outfile.close();
    }
    else
        cout << "failed to open file to write." << endl;

    // read numbers
    fstream infile( "number_list",ios::in | ios::binary );
    if( infile.is_open() )
    {
        infile.read( (char*)&numbersRead, 4 * N );
        infile.close();
    }
    else
        cout << "failed to open file to read." << endl;

    // sort numbers
    sort( numbersRead , numbersRead + N  );

    // print numbers
    for (int i = 0; i < N; i++)
    {
        cout << numbersRead[i] << " ";
    }
    cout << endl;
}
