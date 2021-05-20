#include "Player.hpp"

namespace pandemic{
    class Virologist: public Player{
        private:

        public:
        using Player::Player;
        Player& treat(const City &city) override;
    };
}