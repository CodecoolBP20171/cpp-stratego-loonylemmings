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

    static const int okBtnStartX = 630;
    static const int okBtnStartY = 500;
    static const int okBtnWidth = 150;
    static const int okBtnHeight = 100;

    static const int rBtnStartX = 800;
    static const int restartBtnStartY = 500;
    static const int resetBtnStartY = 553;
    static const int rBtnWidth = 100;
    static const int rBtnHeight = 45;

    static DisplayPart getScreenPart(int x, int y) {
        if (x>boardStartX && y>boardStartY && x<boardEndX && y<boardEndY) return BOARD;
        if (x>stashStartX && y>stashStartY && x<stashEndX && y<stashEndY) return STASH;
        if (x>okBtnStartX && y>okBtnStartY && x<okBtnStartX+okBtnWidth && y<okBtnStartY+okBtnHeight) return OK;
        if (x>rBtnStartX && y>resetBtnStartY && x<rBtnStartX+rBtnWidth && y<resetBtnStartY+rBtnHeight) return RESET;
        if (x>rBtnStartX && y>restartBtnStartY && x<rBtnStartX+rBtnWidth && y<restartBtnStartY+rBtnHeight) return RESTART;
        return INVALID;
    }

};

#endif //CPP_STRATEGO_LOONYLEMMINGS_DISPLAYPARTS_HPP
