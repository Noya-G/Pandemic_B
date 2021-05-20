#include "Player.hpp"

namespace pandemic{
    class Dispatcher: public Player{
        private:
        Board board;
        City city;
        public:
            using Player::Player;
            Player& fly_direct(const City &city) override;
            inline Dispatcher(Board board, City city):Player(board,city,"Dispatcher"){}
    };
}