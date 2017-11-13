//
// Created by jeannie on 2017.11.12..
//

#ifndef CPP_STRATEGO_LOONYLEMMINGS_COORDINATECONVERTER_HPP
#define CPP_STRATEGO_LOONYLEMMINGS_COORDINATECONVERTER_HPP

#include "DisplayParts.hpp"

class CoordinateConverter {

public:

    static void getBoardCoordinates(int index, int (&coordinates)[2]) {
        getCoordinates(index, DisplayParts::boardStartX, DisplayParts::boardStartY, 10, coordinates);
    }
    static void getStashCoordinates(int index, int (&coordinates)[2]) {
        getCoordinates(index, DisplayParts::stashStartX, DisplayParts::stashStartX, 10, coordinates);
    }

    static void getCoordinates(int index, int startX, int startY, int row, int (&coordinates)[2]) {
        int x = index%row;
        int y = (index-x)/row;
        coordinates[0] = x*DisplayParts::cardWidth + startX + DisplayParts::cardGap*x;
        coordinates[1] = y*DisplayParts::cardHeight + startY + DisplayParts::cardGap*y;
    }

    static int getBoardIndex(int x, int y) {
        return getIndex(x, y, DisplayParts::boardStartX, DisplayParts::boardStartY, 10);
    }

    static int getStashIndex(int x, int y) {
        return getIndex(x, y, DisplayParts::stashStartX, DisplayParts::stashStartY, 5);
    }

    static int getIndex(int x, int y, int startX, int startY, int row) {
        return (y-startY)/(DisplayParts::cellHeight+DisplayParts::cardGap) * row
               + (x-startX)/(DisplayParts::cellWidth+DisplayParts::cardGap);
    }
};

#endif //CPP_STRATEGO_LOONYLEMMINGS_COORDINATECONVERTER_HPP
