//
// Created by jeannie on 2017.11.12..
//

#ifndef CPP_STRATEGO_LOONYLEMMINGS_COORDINATECONVERTER_HPP
#define CPP_STRATEGO_LOONYLEMMINGS_COORDINATECONVERTER_HPP

#include "DisplayParts.hpp"

class CoordinateConverter {

public:

    static void getCoordinates(int index, int (&coordinates)[2]) {
        coordinates[0] = index%10 * DisplayParts::cardWidth
                         + DisplayParts::boardStartX;
        coordinates[1] = (index - index%10) * DisplayParts::cardHeight
                         + DisplayParts::boardStartY;
    }

    static int getIndex(int x, int y) {
        return (y-DisplayParts::boardStartX)/DisplayParts::cellHeight * 10
               + (x-DisplayParts::boardStartX)/DisplayParts::cellWidth;
    }
};

#endif //CPP_STRATEGO_LOONYLEMMINGS_COORDINATECONVERTER_HPP
