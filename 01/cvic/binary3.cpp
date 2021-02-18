/**
 * Napište program, ve kterém si vytvoříte vhodnou strukturu. 
 * Tento program načte ze standardního vstupu 15 čísel a uloží je do této struktury. 
 * Obsah struktury následně uložte do binárního souboru. 
 * Poté přečtěte data z tohoto souboru a uložte je do další struktury stejného typu,
 * tuto další strukturu vypište na stadardní výstup.
 *  a)  Vylepšete tuto úlohu tak, že po načtení obsahu souboru, před jeho vypsáním, tato čísla vzestupně seřaďte.
 *  b)  Vyřešte toto rozšíření bez použití cyklu a s tím omezením, že můžete použít pouze jedno čtení ze souboru.
 * 
 * Zkuste předchozí úlohu ještě rozšířit pro předem neznámý počet prvků, kdy použijete nulu jako ukončení vstupní sekvence čísel.
 */

#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

int* readNumbers( int &i )
{
    i = 0;
    int a,n = 2;
    int *numbers = new int[n];
    while ( cin >> a )
    {
         if( a == 0)
            break;

        if( i == n )
        {
            int *tmp = new int[2*n];
            for (int j = 0; j < n; j++)
                tmp[j] = numbers[j];
            n *= 2;
            delete [] numbers;
            numbers = tmp;
        }

        numbers[i] = a;
        ++i;
    }

    if( a != 0 )
    {
        delete [] numbers;
        return NULL;
    }

    // only i numbers in array of n are used shrink the array down
    int *tmp = new int[i];
    for (int j = 0; j < i; j++)
        tmp[j] = numbers[j];

    delete [] numbers;
    return tmp;
}


int main()
{
    // get numbers
    cout << "Write numbers and put zero at the end:" << endl;

    int n = 0;
    int *numbers = readNumbers(n);

    if(!numbers)
    {
        cout << "load failed." << endl;
        return 1;
    }

    // save numbers
    fstream outfile("number_list", ios::out | ios::binary );
    if( outfile.is_open() )
    {
        outfile.write( (char*)numbers, 4 * n );
        outfile.close();
    }
    else
        cout << "failed to open file to write." << endl;

    // read numbers
    int *numbersRead = new int[n];
    fstream infile( "number_list",ios::in | ios::binary );
    if( infile.is_open() )
    {
        infile.read( (char*)numbersRead, 4 * n );
        infile.close();
    }
    else
        cout << "failed to open file to read." << endl;

    // sort numbers
    sort( numbersRead , numbersRead + n  );

    // print numbers
    for (int i = 0; i < n; i++)
    {
        cout << numbersRead[i] << " ";
    }
    cout << endl;

    delete [] numbers;
    delete [] numbersRead;
}
