//
// Created by jeannie on 2017.11.12..
//

#ifndef CPP_STRATEGO_LOONYLEMMINGS_COORDINATECONVERTER_HPP
#define CPP_STRATEGO_LOONYLEMMINGS_COORDINATECONVERTER_HPP

#include "DisplayParts.hpp"

class CoordinateConverter {

public:

    static void getCoordinates(int index, int (&coordinates)[2]) {
        int x = index%10;
        int y = (index-x)/10;
        coordinates[0] = x*DisplayParts::cardWidth
                         + DisplayParts::boardStartX
                         + 5*x;
        coordinates[1] = y*DisplayParts::cardHeight
                         + DisplayParts::boardStartY
                         + 5*y;
    }

    static int getIndex(int x, int y) {
        return (y-DisplayParts::boardStartY)/DisplayParts::cellHeight * 10
               + (x-DisplayParts::boardStartX)/DisplayParts::cellWidth;
    }
};

#endif //CPP_STRATEGO_LOONYLEMMINGS_COORDINATECONVERTER_HPP
