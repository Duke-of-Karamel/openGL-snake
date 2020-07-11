#include "game.hpp"

extern float verticies_in[8];
extern unsigned int indexing_in[6];
extern float colors_in[12];

Game::Game()
{

}

Game::~Game()
{
    for(auto del: this->objects){
        delete del;
    }
}

void Game::update(Direction direc, std::vector<float>& verticies, std::vector<unsigned int>& indexes, std::vector<float>& colors)
{
    verticies.insert(verticies.end(), std::begin(verticies_in), std::end(verticies_in));
    indexes.insert(indexes.end(), std::begin(indexing_in), std::end(indexing_in));
    colors.insert(colors.end(), std::begin(colors_in), std::end(colors_in));
}