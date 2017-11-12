//
// Created by jeannie on 2017.11.11..
//

#ifndef CPP_STRATEGO_LOONYLEMMINGS_OUTPUT_HPP
#define CPP_STRATEGO_LOONYLEMMINGS_OUTPUT_HPP

class Display {

public:
    Display() = default;
    virtual ~Display() = default;

    virtual void printOut() = 0;
    virtual void close() = 0;
};

#endif //CPP_STRATEGO_LOONYLEMMINGS_OUTPUT_HPP