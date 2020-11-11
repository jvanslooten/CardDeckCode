//
//  CardDeck.hpp
//  SystemsProgrammingChap7CardDeck
//
//  Created by Jack Timothy VanSlooten on 11/10/20.
//  Copyright © 2020 Jack Timothy VanSlooten. All rights reserved.
//

#ifndef CARDDECK_H
#define CARDDECK_H
/* CardDeck class declaration */
/* filename: CardDeck.h */
#include "Card.hpp" //Required for Card
#include <vector> //Required for vector */
using namespace std;
class CardDeck {
public:
    CardDeck();
    void shuffleDeck();
    Card draw();
private:
    vector<Card> theDeck;
    vector<Card> deltCards;
};
#endif
