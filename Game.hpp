#pragma once
#include <iostream>
#include <stdexcept>
#include <vector>
#include <map>

namespace coup {

    class Game {

        //Will hold all our players, Whenever a player joins we add him to the map.
        std::vector<std::string> _player_list;
        //holds the winner of the game.
        int _winner;
        //will contain a number between 0-6 (as there can only be max 6 players.)
        size_t _turn = 0;
        size_t _round = 0;

        public:
            Game(){}
            std::vector<std::string> players();
            std::string turn();
            std::string winner();
            void update_turn();
            bool check_turn(std::string name);
            void add_player(std::string name);
            void remove_player(std::string name);
    };
}