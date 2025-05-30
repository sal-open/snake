#include "graphics/screen.hpp"
#include "graphics/menu.hpp"
#include "levels/levels.hpp"
#include "score/data.hpp"
#include "snake/snake.hpp"

int main() {
    Screen terminal{};
    
    terminal.init();

    terminal.menu.run();

    terminal.end();
}