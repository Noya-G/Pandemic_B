#include "Player.hpp"

namespace pandemic{
    class Scientist: public Player{
        private:
        public:
            using Player::Player;
            Scientist(const Board &board, const City &city, int n);
            Player &discover_cure(const Color &color);
    };
}