//
//  CardDeck.cpp
//  SystemsProgrammingChap7CardDeck
//
//  Created by Jack Timothy VanSlooten on 11/10/20.
//  Copyright © 2020 Jack Timothy VanSlooten. All rights reserved.
//

/* CardDeck implementation */
/* filename: CardDeck.cpp */
#include "CardDeck.hpp"
#include "Card.hpp"
#include<ctime> //Required for time()
#include<algorithm> //Required for random_shuffle()
using namespace std;
CardDeck::CardDeck()
{
    /* 13 cards in each suit. */
    /* 52 new cards. */
    for(int i= 2; i<15; ++i)
    {
        theDeck.push_back(Card('S',i));
        theDeck.push_back(Card('H',i));
        theDeck.push_back(Card('D',i));
        theDeck.push_back(Card('C',i));
    }
    srand(time(NULL)); //Must seed RNG 1 time!
}
Card CardDeck::draw()
{
    /* Draw and return one card. */
    if(theDeck.empty())
    {
        exit(1);
    }
    Card aCard = theDeck.back(); //Draw card.
    theDeck.pop_back();//Remove card.
    //Retain card for shuffle.
    deltCards.push_back(aCard);
    return(aCard);
}
void CardDeck::shuffleDeck()
{
    /* Replace drawn cards */
    for(int i=0; i<deltCards.size(); ++i)
    {
        theDeck.push_back(deltCards[i]);
    }
    //Clear the vector.
    deltCards.resize(0);
    //Use the top level function from algorithm.
    random_shuffle(theDeck.begin(), theDeck.end());
}
