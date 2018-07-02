#ifndef GAMEENTITY_HPP
# define GAMEENTITY_HPP
# include <ncurses.h>

class GameEntity {
  public:
    GameEntity(char piece);
	GameEntity(GameEntity const & src);
	~GameEntity();
    GameEntity &operator= (const GameEntity &obj);

    int getYLoc();
    int getXLoc();

  protected:
    bool visible;
    int xLoc, yLoc, xMax, yMax;
    char character;
};
#endif
