/** 
 * Napište program, který čte ze standarního vstupu text 
 * a průběžně ho ukládá do textového souboru, dokud nepřijde EOF.
 */

#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    string filename;

    cout << "Program na vkladanie textu na koniec suboru\nnazov suboru:" << endl;
    cin  >> filename;

    ofstream myfile( filename, ios::binary | ios::app );

    if( myfile.is_open() )
    {
        char c;
        cout << "Napis text, eof ukonci vkladanie:" << endl;
        while ( cin >> noskipws >> c )
        {
            myfile.write( &c, sizeof(c) );
        }
        myfile.close();
    }
    else
        cout << "Nepodarilo se otevrit soubor." << endl;
}