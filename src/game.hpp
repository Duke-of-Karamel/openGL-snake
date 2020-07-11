// This is basically a model
#include <vector>

#include "gameobject.hpp"

typedef enum Direction{
    UP, LEFT, DOWN, RIGHT
} Direction;

class Game
{
    public:

    int x;
    int y;

    Game();
    ~Game();

    void update(Direction direc, std::vector<float>& verticies, std::vector<unsigned int>& indexes, std::vector<float>& colors);



    private:

    std::vector<GameObject*> objects;
};