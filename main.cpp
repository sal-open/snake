#include "home/screen.hpp"
#include "home/menu.hpp"
#include "levels/levels.hpp"
#include "score/data.hpp"
#include "game/snake.hpp"

int main() {
    Screen terminal{};
    
    terminal.init();

    terminal.menu.run();
}