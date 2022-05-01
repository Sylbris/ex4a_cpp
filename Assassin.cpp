#include "Assassin.hpp"
using namespace std;
using namespace coup;

void Assassin::coup(Player &p) 
{
    if(_coins < 3)
    {
        throw invalid_argument("Insufficient coins to make a coup");
    }
    else 
    {
        //Overthrow a player.
    }
}
void Assassin::block(Player &player) {}
string Assassin::role()
{
    return "Assassin";
}