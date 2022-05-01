#include "Ambassador.hpp"
using namespace std;
using namespace coup;

void Ambassador::transfer(Player& p1, Player& p2)
{
    if(p1.coins() > 0 && p2.coins() > 0)
    {
        //Transfer a coin from p1 to p2.
    }
}
void Ambassador::block(Player &player)
{

}
string Ambassador::role()
{
    return "Ambassador";
}