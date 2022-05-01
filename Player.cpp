#include "Player.hpp"
using namespace std;
using namespace coup;

const int COUP_COST = 7;
const int DOUBLE_SALARY = 2;
const int MAX_COIN_CAP = 10;

/**
 * @brief Take one coin from the bank.
 * 
 */
void Player::income()
{
    if(_game.players().size() < 2)
    {
        throw invalid_argument("Not enough players");
    }
    if(_game.check_turn(_name))
    {
        if(_coins > MAX_COIN_CAP )
        {
            throw invalid_argument("Must perform a coup!");
        }
        _can_be_blocked = false;
        _coins++;
        _game.update_turn();

        //add the last action, remember nothing can block an income.
        Action la = INCOME;
        _last_action = la;
    }
    else 
    {
        throw invalid_argument("Its not this players turn now !");
    }
    
}
/**
 * @brief Perform the foreign aid operation.
 * 
 */
void Player::foreign_aid()
{   
    if(_game.players().size() < 2)
    {
        throw invalid_argument("Not enough players");
    }
    _can_be_blocked = true;
    Action la = FOREIGN_AID;
    _last_action = la;
    _coins+=DOUBLE_SALARY;
}
/**
 * @brief Overthrow a player from the game.
 * 
 * @param p 
 */
void Player::coup(Player &p)
{
    if(p._name == this->_name)
    {
        throw invalid_argument("Cannot coup yourself!");
    }

    if(_coins < COUP_COST ) 
    {
        throw invalid_argument("Insufficient coins to make a coup");
    }
    else 
    {
        //Overthrow a player.
        _game.remove_player(p.get_name());
        update_coins(-COUP_COST);
    }
}
string Player::role()
{
    return "Player";
}

int Player::coins()
{
    return _coins;
}
void Player::update_operation()
{

}
/**
 * @brief Update players coins with the amount specified, keep in mind
 * amount is always positive.
 * and a players coin can never go under 0!
 * 
 * @param amount 
 */
void Player::update_coins(int amount)
{

    if(_coins  + amount < 0 )
    {
        _coins = 0;
    }
    else
    {
        _coins += amount;
    }

}
//Blocks the last action performed by player.
void Player::block(Player &player)
{
    if(player._name == this->_name)
    {
        throw invalid_argument("Cannot block yourself!");
    }
    if(player._last_action == INCOME)
    {
        throw invalid_argument("Cannot block an income action");
    }

    if(player._last_action == TAX && player.role() == "Duke")
    {
        throw invalid_argument("Cannot stop the Duke from taking taxes!");
    }
}

bool Player::get_block_status()
{
    return _can_be_blocked;
}

std::string Player::get_name()
{
    return _name;
}