//
// Created by jeannie on 2017.11.07..
//

#ifndef CPP_STRATEGO_LOONYLEMMINGS_CARD_HPP
#define CPP_STRATEGO_LOONYLEMMINGS_CARD_HPP

#include <string>

//ranks:
// 0 - flag, 1 - spy, 2 - scout, 3 - miner,
// 4...9 - soldiers, 10 - general, 11 - bomb

#include "Player.hpp"

class Card {

public:

    Card(int rank, Player& player)
        : rank(rank)
    {
        faceUp = true;
        maxMove = ((rank == 0)||(rank == 11)) ? 0 : (rank == 2) ? 10 : 1;
        shortName = player.getShortName() + "R" + std::to_string(rank);
        backSide = player.getShortName() + "BG";
    }

    int getRank() const { return rank; }
    bool isFaceUp() const { return faceUp; };
    int getMaxMove() const{ return maxMove; }
    std::string getBackSide() const { return backSide; }
    std::string getShortName() const { return shortName; };

    Card* getBattleResult(Card* attacker) {

        int attackerRank = attacker->getRank();

        if (attackerRank > rank) return attacker;
        if (attackerRank == rank) return nullptr;
        if ((attackerRank == 1)&&(rank == 10)) return attacker;
        if ((attackerRank == 3)&&(rank == 11)) return attacker;
        return this;
    }

    bool isAvailableMoveRange(int move) { return maxMove >= move; }

    void flip() { faceUp = !faceUp; }

    virtual ~Card() = default;

private:
    const int rank;
    int maxMove;
    bool faceUp;
    std::string shortName;
    std::string backSide;
};

#endif //CPP_STRATEGO_LOONYLEMMINGS_CARD_HPP
