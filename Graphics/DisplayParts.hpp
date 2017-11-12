//
// Created by jeannie on 2017.11.12..
//

#ifndef CPP_STRATEGO_LOONYLEMMINGS_DISPLAYPARTS_HPP
#define CPP_STRATEGO_LOONYLEMMINGS_DISPLAYPARTS_HPP

class DisplayParts {

public:
    DisplayParts() = delete;
    ~DisplayParts() = delete;

    enum DisplayPart {BOARD, STASH, OK, RESET, RESTART, INVALID};

    static const int windowHeight = 602;
    static const int windowWidth = 602;

    static const int boardStartX = 12;
    static const int boardStartY = 12;
    static const int boardEndX = 586;
    static const int boardEndY = 586;

    static const int cellHeight = 57;
    static const int cellWidth = 57;

    static const int cardHeight = 53;
    static const int cardWidth = 53;

    //TODO: declare all the screen parts coordinates/dimensions

    static DisplayPart getScreenPart(int x, int y) {
        if (x>boardStartX && y>boardStartY && x<boardEndX && y<boardEndY) return BOARD;
        return INVALID;
    }

};

#endif //CPP_STRATEGO_LOONYLEMMINGS_DISPLAYPARTS_HPP
