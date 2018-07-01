#include "Game.hpp"

int main()
{


	initscr();
  cbreak();
  noecho();
  curs_set(0);
  nodelay(stdscr, true);
  keypad(stdscr, true);
  // refresh();
  // box(stdscr, 0, 0);
  // refresh();  Game game;
  Game game;
  game.start();
  getch();
	endwin();
  return 0;
}
