//
// Created by jeannie on 2017.11.11..
//

#ifndef CPP_STRATEGO_LOONYLEMMINGS_PLAYER_HPP
#define CPP_STRATEGO_LOONYLEMMINGS_PLAYER_HPP

#include <string>

class Player {

public:
    Player() = delete;

    explicit Player(int number)
        : id(number)
    {
    shortName = 'P' + std::to_string(id);
    }

    int getId() const { return id; }
    const std::string &getShortName() const { return shortName; }

    virtual ~Player() = default;

private:
    int id;
    std::string shortName;
};

#endif //CPP_STRATEGO_LOONYLEMMINGS_PLAYER_HPP
