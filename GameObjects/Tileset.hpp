//
// Created by jeannie on 2017.11.11..
//

#ifndef CPP_STRATEGO_LOONYLEMMINGS_TILESET_HPP
#define CPP_STRATEGO_LOONYLEMMINGS_TILESET_HPP

#include <string>
#include <map>

class Tileset {

public:
    Tileset() {
        loadSWTheme();
    }

    virtual ~Tileset() {}

    std::map<std::string, std::string>themeSet;

private:
    void loadSWTheme() {
        themeSet["P1R0"] = "EF.png"; themeSet["P1R1"] = "E1.png"; themeSet["P1R2"] = "E2.png";
        themeSet["P1R3"] = "E3.png"; themeSet["P1R4"] = "E4.png"; themeSet["P1R5"] = "E5.png";
        themeSet["P1R6"] = "E6.png"; themeSet["P1R7"] = "E7.png"; themeSet["P1R8"] = "E8.png";
        themeSet["P1R9"] = "E9.png"; themeSet["P1R10"] = "E10.png"; themeSet["P1R11"] = "B.png";
        themeSet["P1BG"] = "EBG.png"; themeSet["P2BG"] = "RBG.png"; themeSet["P2R0"] = "RF.png";
        themeSet["P2R1"] = "R1.png"; themeSet["P2R2"] = "R2.png"; themeSet["P2R3"] = "R3.png";
        themeSet["P2R4"] = "R4.png"; themeSet["P2R5"] = "R5.png"; themeSet["P2R6"] = "R6.png";
        themeSet["P2R7"] = "R7.png"; themeSet["P2R8"] = "R8.png"; themeSet["P2R9"] = "R9.png";
        themeSet["P2R10"] = "R10.png"; themeSet["P2R11"] = "B.png";
        themeSet["Board"] = "Base_Board.png";
    }

};

#endif //CPP_STRATEGO_LOONYLEMMINGS_TILESET_HPP
