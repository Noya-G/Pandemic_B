#pragma once

#include "Color.hpp"
#include "Board.hpp"
#include "City.hpp"

#include <string>

namespace pandemic{
    class Player{
        private:
        Board board;
        City city;
        std::string special_role;
        
        public:
            inline Player(Board &b,City c,std::string special_role):board(b),city(c),special_role(special_role){}
            Player(const Board &board, const City &city);
            Player();
            ~Player();
            virtual Player& drive(const City &city);
            virtual Player& fly_direct(const City &city);
            virtual Player& fly_charter(const City &city);
            virtual Player& fly_shuttle(const City &city);
            virtual Player& discover_cure(const Color &color);
            virtual Player& build();
            virtual Player& treat(const City &city);
            virtual Player& take_card(const City &city);
            std::string role();
            City& get_city();
            int num_of_cards();

            
    };
}