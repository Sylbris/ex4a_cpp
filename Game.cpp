#include "Game.hpp"

using namespace std;
using namespace coup;

//std::vector<std::string> Game::_player_list;

vector<string> Game::players()
{
    return _player_list;
}
string Game::turn()
{
return _player_list[_turn];
}
string Game::winner()
{
    return "";
}

bool Game::check_turn(std::string name)
{
    if(_player_list[_turn] == name)
    {
        return true;
    }
    return false;
}

void Game::update_turn()
{
    _turn++;
    if(_turn == _player_list.size() - 1)
    {
        _round ++;
    }
    _turn %= _player_list.size();
}
/**
 * @brief Add a player to the game
 * 
 * @param name 
 */
void Game::add_player(std::string name)
{   
    //cout << _player_list.size();
    if(_player_list.size() == 6)
    {
        throw invalid_argument("Game is full!");
    }
    else 
    {
        _player_list.push_back(name);
    }
    
}
/**
 * @brief Remove a player from the game
 * 
 * @param name 
 */
void Game::remove_player(std::string name)
{
    for(int i=0; i<_player_list.size();i++)
    {
        if(_player_list[(size_t)i] == name)
        {
            _player_list.erase(_player_list.begin()+i);
        }
    }
}