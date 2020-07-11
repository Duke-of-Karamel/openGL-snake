#include "shape.hpp"

class GameObject
{
    public:

    // GameObject();
    // ~GameObject();

    void getPos();
    void getVerticies();



    private:

    int x;
    int y;

    Shape::Shape* shape;
};