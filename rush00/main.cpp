#include "Game.hpp"

int main()
{
	initscr();
  cbreak();
  noecho();
  curs_set(0);
  nodelay(stdscr, true);
  keypad(stdscr, true);
  Game game;
  game.start();
	endwin();
  return 0;
}
