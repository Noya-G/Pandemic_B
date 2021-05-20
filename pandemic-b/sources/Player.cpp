#include <iostream>
#include "Player.hpp"

namespace pandemic{
    Player::Player(const Board &board, const City &city){}
    Player::Player(){}
    Player::~Player(){}
    Player& Player::drive(const City &city){ return *this; }
    Player& Player::fly_direct(const City &city){ return *this; }
    Player& Player::fly_charter(const City &city){ return *this; }
    Player& Player::fly_shuttle(const City &city){ return *this; }
    Player& Player::build(){ return *this; }
    Player& Player::discover_cure(const Color &color){ return *this; }
    Player& Player::treat(const City &city){ return *this; }
    Player& Player::take_card(const City &city){ return *this; }
    std::string Player::role(){ return "role"; }
    City& Player::get_city(){ return this->city; } 
    int Player::num_of_cards(){ return 0; };
}
