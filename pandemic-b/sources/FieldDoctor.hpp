#include "Player.hpp"

namespace pandemic{
    class FieldDoctor: public Player{
        private:
        Board board;
        City city;
        public:
            using Player::Player;
            Player& treat(const City &city) override;
            inline FieldDoctor(Board board, City city):Player(board,city,"FieldDoctor"){}
    };
}