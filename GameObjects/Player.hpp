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
        : id(number), state(false)
    {
    shortName = 'P' + std::to_string(id);
    }

    int getId() const { return id; }
    bool getState() { return state; }
    const std::string &getShortName() const { return shortName; }

    void setState(bool active) { state = active; }
    virtual ~Player() = default;

private:
    int id;
    bool state;
    std::string shortName;
};

#endif //CPP_STRATEGO_LOONYLEMMINGS_PLAYER_HPP
