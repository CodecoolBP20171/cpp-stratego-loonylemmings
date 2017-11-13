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
        loadBaseTheme();
    }

    virtual ~Tileset() {}

    std::map<std::string, std::string>themeSet;

private:
    void loadSWTheme() {
        themeSet["P1R0"] = "StarWars/EF.png"; themeSet["P1R1"] = "StarWars/E1.png";
        themeSet["P1R2"] = "StarWars/E2.png"; themeSet["P1R3"] = "StarWars/E3.png";
        themeSet["P1R4"] = "StarWars/E4.png"; themeSet["P1R5"] = "StarWars/E5.png";
        themeSet["P1R6"] = "StarWars/E6.png"; themeSet["P1R7"] = "StarWars/E7.png";
        themeSet["P1R8"] = "StarWars/E8.png"; themeSet["P1R9"] = "StarWars/E9.png";
        themeSet["P1R10"] = "StarWars/E10.png"; themeSet["P1R11"] = "StarWars/B.png";
        themeSet["P1BG"] = "StarWars/EBG.png"; themeSet["P2BG"] = "StarWars/RBG.png";
        themeSet["P2R0"] = "StarWars/RF.png"; themeSet["P2R1"] = "StarWars/R1.png";
        themeSet["P2R2"] = "StarWars/R2.png"; themeSet["P2R3"] = "StarWars/R3.png";
        themeSet["P2R4"] = "StarWars/R4.png"; themeSet["P2R5"] = "StarWars/R5.png";
        themeSet["P2R6"] = "StarWars/R6.png"; themeSet["P2R7"] = "StarWars/R7.png";
        themeSet["P2R8"] = "StarWars/R8.png"; themeSet["P2R9"] = "StarWars/R9.png";
        themeSet["P2R10"] = "StarWars/R10.png"; themeSet["P2R11"] = "StarWars/B.png";
        themeSet["Board"] = "Base_Board.png";
    }

    void loadBaseTheme() {
        themeSet["P1R0"] = "Base/R0.png"; themeSet["P1R1"] = "Base/R1.png";
        themeSet["P1R2"] = "Base/R2.png"; themeSet["P1R3"] = "Base/R3.png";
        themeSet["P1R4"] = "Base/R4.png"; themeSet["P1R5"] = "Base/R5.png";
        themeSet["P1R6"] = "Base/R6.png"; themeSet["P1R7"] = "Base/R7.png";
        themeSet["P1R8"] = "Base/R8.png"; themeSet["P1R9"] = "Base/R9.png";
        themeSet["P1R10"] = "Base/R10.png"; themeSet["P1R11"] = "Base/R11.png";
        themeSet["P1BG"] = "Base/RBG.png"; themeSet["P2BG"] = "Base/BBG.png";
        themeSet["P2R0"] = "Base/B0.png"; themeSet["P2R1"] = "Base/B1.png";
        themeSet["P2R2"] = "Base/B2.png"; themeSet["P2R3"] = "Base/B3.png";
        themeSet["P2R4"] = "Base/B4.png"; themeSet["P2R5"] = "Base/B5.png";
        themeSet["P2R6"] = "Base/B6.png"; themeSet["P2R7"] = "Base/B7.png";
        themeSet["P2R8"] = "Base/B8.png"; themeSet["P2R9"] = "Base/B9.png";
        themeSet["P2R10"] = "Base/B10.png"; themeSet["P2R11"] = "Base/B11.png";
        themeSet["Board"] = "Base/Baseboardfull.png"; themeSet["OkBTN"] = "Base/OkBTN.png";
        themeSet["ResetBTN"] = "Base/ResetBTN.png"; themeSet["RestartBTN"] = "Base/RestartBTN.png";
        themeSet["Splash"] = "Base/splash.jpg";
    }

};

#endif //CPP_STRATEGO_LOONYLEMMINGS_TILESET_HPP
