#include "Player.hpp"

namespace pandemic{
    class OperationsExpert: public Player{
        private:
        public:
            using Player::Player;
            Player& build();
    };
}