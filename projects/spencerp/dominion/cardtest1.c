// test adventurer card
#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include "dominion_helpers.h"
#include <stdlib.h>


// test should check the following:
// 1. Last two cards in hand should be treasure cards
// 2. Two cards are added to hand
// 3. Deck + discard is decreased by two cards
void testAdventurerCard(struct gameState *state) {
    printf("\n\n********************************************\n");
    printf("***       Testing Adventurer Card        ***\n");
    printf("********************************************\n\n");
    
    // Add a card to deck that is not a treasure card
    state->deck[0][state->deckCount[0]] = 1;
    state->deckCount[0]++;
    
    // Put adventurer card in 0 position in player's hand.
    state->whoseTurn = 0;
    state->hand[0][0] = adventurer;
    
    // remember counts before adventure card is played
    int preDeckCount = state->deckCount[0];
    int preDiscardCount = state->discardCount[0];
    int preHandCount = state->handCount[0];
    
    // Play adventurer card
    playCard(0, 0, 0, 0, state);
    
    // Test if two cards have been added to hand
    printf("Test 1: handCount increased by 2.\n");
    if((preHandCount + 2) == state->handCount[0]) {
        printf("  Passed.\n");
    }
    else {
        printf("  Failed.\n");
    }
    
    // Test if two cards are removed from deck + discard
    printf("Test 2: Deck + discard count decreased by 2.\n");
    if((preDeckCount + preDiscardCount - 2) == (state->deckCount[0] + state->discardCount[0])) {
        printf("  Passed.\n");
    }
    else {
        printf("  Failed.\n");
    }
    
    // Test if last two cards in hand are treasure cards
    printf("Test 3: Last two cards in hand are treasure cards.\n");
    int lastCard = state->hand[0][state->handCount[0] - 1];
    int lastCard2 = state->hand[0][state->handCount[0] - 2];
    if((lastCard == copper || lastCard == silver || lastCard == gold) && (lastCard2 == copper || lastCard2 == silver || lastCard2 == gold)) {
        printf("  Passed.\n");
    }
    else {
        printf("  Failed.\n");
    }
    
}

int main (int argc, char** argv) {
    struct gameState G;
    int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};
    
    initializeGame(2, k, 2, &G);
      
    testAdventurerCard(&G);
    
    return 0;
}
    
    