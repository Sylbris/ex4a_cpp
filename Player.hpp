#pragma once
#include <iostream>
#include <stdexcept>
#include <vector>
#include "Game.hpp"

namespace coup {

    enum Action
    {
        INCOME,
        FOREIGN_AID,
        COUP,
        TAX
    };

    class Player {

        protected:
            std::string _name;
            size_t _player_turn; //in each round indicate this player turn;
            int _coins = 0;
            Game& _game;
            Action _last_action;
            bool _can_be_blocked;
            
        public:
            //Constructor with default settings.
            Player(Game& g, std::string n): _game(g), _name(n)
            {
                _game.add_player(_name);
            }
            void income();
            void foreign_aid();
            virtual void coup(Player &p);
            virtual std::string role();

            int coins();
            void update_operation();
            //Blocks the last action performed by player.
            virtual void block(Player &player);
            void update_coins(int amount);
            bool get_block_status();
            std::string get_name();
    };
}