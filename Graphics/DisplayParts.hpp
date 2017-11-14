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

    static const int windowHeight = 610;
    static const int windowWidth = 950;

    static const int boardStartX = 2;
    static const int boardStartY = 2;
    static const int boardEndX = 610;
    static const int boardEndY = 610;

    static const int stashStartX = 630;
    static const int stashStartY = 2;
    static const int stashEndX = 935;
    static const int stashEndY = 485;

    static const int cellHeight = 58;
    static const int cellWidth = 58;

    static const int cardHeight = 58;
    static const int cardWidth = 58;
    static const int cardGap = 3;

    static const int okStartX = 630;
    static const int okStartY = 500;
    static const int okWidth = 150;
    static const int okHeight = 100;

    static const int rStartX = 800;
    static const int rStartY = 500;
    static const int rstStartY = 553;
    static const int rWidth = 100;
    static const int rHeight = 45;

    static DisplayPart getPart(int x, int y) {
        if (x>boardStartX && y>boardStartY && x<boardEndX && y<boardEndY) return BOARD;
        if (x>stashStartX && y>stashStartY && x<stashEndX && y<stashEndY) return STASH;
        if (x>okStartX && y>okStartY && x<okStartX+okWidth && y<okStartY+okHeight) return OK;
        if (x>rStartX && y>rstStartY && x<rStartX+rWidth && y<rstStartY+rHeight) return RESET;
        if (x>rStartX && y>rStartY && x<rStartX+rWidth && y<rStartY+rHeight) return RESTART;
        return INVALID;
    }

};

#endif //CPP_STRATEGO_LOONYLEMMINGS_DISPLAYPARTS_HPP
