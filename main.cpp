#include "home/menu.hpp"
#include "home/info.hpp"
#include "levels/levels.hpp"
#include "score/data.hpp"
#include "game/snake.hpp"
#include "game/apple.hpp"

int main() {
    Menu menu{};

    /*
    Data a("Giovanni", 5656.0);
    Data b("Maria", 2003.0);
    Data c("Luca", 12.0);
    Data d("Anna", 495.0);

    a.Save();
    b.Save();
    c.Save();
    d.Save();

    */

    menu.init();
    menu.run();

    Apple* app = new Apple(10);
    



}