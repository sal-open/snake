/*
 * Bachelor's degree in Computer Science.
 *
 * Course: Programmazione (00819).
 * Author: Andrei Pirva, Pietro Tombaccini e Salvatore Bruzzese.
 *
 * Description: Entry point for the compiler.
 */
#include "iostream"
#include "levels/levels.hpp"
using namespace std;

int main()
{
    Levels livello(10);
    livello.stampaLivelli();
    cout << "Livello current: " << livello.getCurrentIndex() << endl;

    livello.completaLivello(livello.getCurrentIndex());
    
    cout << "Livello current: " << livello.getCurrentIndex() << endl;
    
    
}
