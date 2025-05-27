#include <ctime>
#include <fstream>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include "punteggi/data.hpp"


int main()
{
    Data a("Giovanni", 5656.0);
    Data b("Maria", 2003.0);
    Data c("Luca", 12.0);
    Data d("Anna", 495.0);

    a.Save();
    b.Save();
    c.Save();
    d.Save();

    Data::Print();
}
