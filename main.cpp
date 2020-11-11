//
//  main.cpp
//  SystemsProgrammingChap7CardDeck
//
//  Created by Jack Timothy VanSlooten on 11/10/20.
//  Copyright © 2020 Jack Timothy VanSlooten. All rights reserved.
//

#include <iostream>
#include "Card.hpp"
#include "CardDeck.hpp"
using namespace std;

void kingAce(int nSim);
void twoPairs(int nSim);
void printHand(vector<Card> h);

int main(int argc, const char * argv[]) {
    
    // Declare objects
    int nSim, selection;
    
    cout << "Which simulation would you like to run?\n";
    cout << "Enter 1 to estimate the probability of drawing a 5-card hand that holds 2 Kings and 1 Ace.\nEnter 2 to estimate the probability of drawing a 5-card hand that holds 2 pairs.\n";
    cin >> selection;
    
    // Make sure user entered valid selection
    while (selection != 1 && selection != 2)
    {
        cout << "That is in invalid choice.\n";
        cout << "Enter 1 to estimate the probability of drawing a 5-card hand that holds 2 Kings and 1 Ace.\n Enter 2 to estimate the probability of drawing a 5-card hand that holds 2 pairs.\n";
        cin >> selection;
    }
    
    cout << "Enter # of simulations to run: ";
    cin >> nSim;
    
    // Return results for whichever simulation chosen
    if (selection == 1)
    {
        kingAce(nSim);
    }
    else
    {
        twoPairs(nSim);
    }
    
    return 0;
}


void kingAce(int nSim)
{
    CardDeck deck;
    vector<Card> hand;
    Card card;
    int eventCount = 0;
    int simulationsRan = 0;
    for (int i=0; i<nSim; i++)
    {
        simulationsRan++;
        int nKings = 0;
        int nAces = 0;
        
        // Shuffle the deck
        deck.shuffleDeck();
        
        // Draw 5 cards and increment counter variables if necessary
        for (int j=0; j<5; j++)
        {
            card = deck.draw();
            hand.push_back(card);
            if (card.getRank() == 13)
                {
                    nKings++;
                }
            else if (card.getRank() == 14)
                {
                    nAces++;
                }
        }
        
        //Check if event occured
        if (nKings == 2 && nAces == 1)
        {
            cout << "Event occured on simulation #" << simulationsRan << endl;
            printHand(hand);
            eventCount++;
        }
        
        // Clear the hand vector
        hand.resize(0);
    }
   cout << "Your event occured " << eventCount << " times out of " << nSim << " simulations ran." << endl;
}


void twoPairs(int nSim)
{
    CardDeck deck;
    vector<Card> hand;
    Card card1, card2, card3, card4, card5;
    int eventCount = 0;
    int simulationsRan = 0;
    
    for (int i=0; i<nSim; i++)
    {
        simulationsRan++;
        int matchingPairs = 0;
        
        // Shuffle the deck
        deck.shuffleDeck();
        
        // Draw and set cards
        card1 = deck.draw();
        hand.push_back(card1);
        card2 = deck.draw();
        hand.push_back(card2);
        card3 = deck.draw();
        hand.push_back(card3);
        card4 = deck.draw();
        hand.push_back(card4);
        card5 = deck.draw();
        hand.push_back(card5);

        
        //Check if card ranks match, and if so, increment matchingPairs variable counter
        if (card1.getRank() == card2.getRank() || card1.getRank() == card3.getRank() || card1.getRank() == card4.getRank() || card1.getRank() == card5.getRank())
            matchingPairs++;
        
        if (card2.getRank() == card3.getRank() || card2.getRank() == card4.getRank() || card2.getRank() == card5.getRank())
            matchingPairs++;
        
        if (card3.getRank() == card4.getRank() || card3.getRank() == card5.getRank())
            matchingPairs++;
        
        if (card4.getRank() == card5.getRank())
            matchingPairs++;
        
        //Check if event occured using matchingPairs variable counter
        if (matchingPairs == 2)
        {
            cout << "Event occured on simulation #" << simulationsRan << endl;
            printHand(hand);
            eventCount++;
        }
        
        // Clear the hand vector
        hand.resize(0);
        
    }

    cout << "Your event occured " << eventCount << " times out of " << nSim << " simulations ran." << endl;
}

void printHand(vector<Card> h)
{
    for (int i=0; i<h.size(); ++i)
    {
        h[i].displayCard(cout);
        cout << "  ";
        
    }
    cout << endl;
}




