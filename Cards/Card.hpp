//
// Created by jeannie on 2017.11.07..
//

#ifndef CPP_STRATEGO_LOONYLEMMINGS_CARD_HPP
#define CPP_STRATEGO_LOONYLEMMINGS_CARD_HPP

class Card {

public:
    explicit Card(unsigned rank)
        : rank(rank) {}

    virtual ~Card() = default;

    unsigned getRank() {}

private:
    unsigned rank;

};

#endif //CPP_STRATEGO_LOONYLEMMINGS_CARD_HPP
