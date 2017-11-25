#ifndef CPP_STRATEGO_LOONYLEMMINGS_GAMEPARTS_H
#define CPP_STRATEGO_LOONYLEMMINGS_GAMEPARTS_H

#include "Player.hpp"
#include "Card.hpp"
#include "Board.hpp"
#include <map>
#include <vector>

using card_uptr = std::unique_ptr<Card>;
using card_vector = std::vector<std::unique_ptr<Card>>;
using player_sptr = std::shared_ptr<Player>;

class GameParts {

public:

    GameParts();

    virtual ~GameParts() = default;

    //player operations

    void switchPlayers();
    int getPlayerAreaStart();
    bool isInPlayerArea(int index);

    //stash operations

    bool isActualStashEmpty();
    int getStashSize();

    void clearPlayerStash();
    void createCardInActualStash(int piece);
    bool isCardInStashAt(int index);
    card_uptr& getCardFromStash(int index);

    //board operations

    void flipCardsDown();
    void flipPlayerCardsUp();
    void destroyPlayerCards();
    void flipCard(int index);

    bool isCardInBoardAt(int index);

    card_uptr& getCardFromBoard(int index);

    //swaps

    void boardSwap(int first, int second);
    void moveCardFromStashToBoard(int from, int to);
    void moveCardFromBoardToStash(int from);

    //button operations

    void hideButtons() {
        buttons["okBtn"] = false;
        buttons["resetBtn"] = false;
    }
    void showOk() { buttons["okBtn"] = true; }
    void showReset() { buttons["resetBtn"] = true; }
    void hideOk() { buttons["okBtn"] = false; }
    void hideReset() { buttons["resetBtn"] = false; }

    std::map<std::string, bool>& getButtons() { return buttons; }

    //selection operations

    int getSelected() { return selected; }
    void setSelected(int index) { selected = index; }

    int getError() { return wrong; }
    void setError(int index) { wrong = index; }

private:

    std::shared_ptr<Player> player1;
    std::shared_ptr<Player> player2;
    std::unique_ptr<Board> board;

    std::shared_ptr<card_vector> p1stash;
    std::shared_ptr<card_vector> p2stash;

    std::weak_ptr<card_vector> activeStash;
    std::weak_ptr<Player> activePlayer;

    int selected;
    int wrong;

    std::map<std::string, bool> buttons;

};

#endif //CPP_STRATEGO_LOONYLEMMINGS_GAMEPARTS_H