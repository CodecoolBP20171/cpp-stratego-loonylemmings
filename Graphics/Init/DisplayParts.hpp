//
// Created by jeannie on 2017.11.12..
//

#ifndef CPP_STRATEGO_LOONYLEMMINGS_DISPLAYPARTS_HPP
#define CPP_STRATEGO_LOONYLEMMINGS_DISPLAYPARTS_HPP

#include "DPElem.hpp"
#include "DPField.hpp"
#include "DPContainer.hpp"

class DisplayParts {

public:
    DisplayParts() = default;
    ~DisplayParts() = default;

    enum DisplayPart {BOARD, STASH, OK, RESET, RESTART, INVALID};

    const DPElem window = DPElem(0, 0, 960,630);
    const DPField field = DPField(61, 61, 2);
    const DPContainer board = DPContainer(12, 12, 10, 10, field);
    const DPContainer stash = DPContainer(640, 12, 5, 8, field);
    const DPElem okBTN = DPElem(640, 510, 150, 100);
    const DPElem resetBTN = DPElem(810, 510, 100, 45);
    const DPElem restartBTN = DPElem(810, 563, 100, 45);

    DisplayPart getPart(DPBase& index) {
        if (board.isInside(index)) return BOARD;
        if (okBTN.isInside(index)) return OK;
        if (stash.isInside(index)) return STASH;
        if (restartBTN.isInside(index)) return RESTART;
        if (resetBTN.isInside(index)) return RESET;
        return INVALID;
    }

};


#endif //CPP_STRATEGO_LOONYLEMMINGS_DISPLAYPARTS_HPP
