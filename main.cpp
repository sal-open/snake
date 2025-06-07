#include "home/menu.hpp"
#include "home/info.hpp"
#include "levels/levels.hpp"
#include "score/data.hpp"
#include "game/snake.hpp"

int main() {
    Menu menu{};

    menu.init();
    menu.run();
}