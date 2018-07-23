// test CouncilRoom card
#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include "dominion_helpers.h"
#include <stdlib.h>


// test should check the following:
// 1. Hand count increases by 3
// 2. Deck + discard count decreases by 4
// 3. Council room card is discarded
// 4. buys increase by one
void testCouncilRoomCard(struct gameState *state) {
    printf("\n\n********************************************\n");
    printf("***      Testing Council Room Card       ***\n");
    printf("********************************************\n\n");
    
    // Put CouncilRoom card in 0 position in player's hand.
    state->whoseTurn = 0;
    state->hand[0][0] = council_room;
    
    // remember counts before adventure card is played
    int preDeckCount = state->deckCount[0];
    int preDiscardCount = state->discardCount[0];
    int preHandCount = state->handCount[0];
    int preBuys = state->numBuys;
    
    // Play CouncilRoom card
    playCard(0, 0, 0, 0, state);
    
    // Test if two cards have been added to hand (four cards drawn and one played)
    printf("Test 1: handCount increased by 3.\n");
    if((preHandCount + 3) == state->handCount[0]) {
        printf("  Passed.\n");
    }
    else {
        printf("  Failed.\n");
    }
    
    // Test if two cards are removed from deck + discard
    printf("Test 2: Deck + discard count decreased by 4.\n");
    if((preDeckCount + preDiscardCount - 4) == (state->deckCount[0] + state->discardCount[0])) {
        printf("  Passed.\n");
    }
    else {
        printf("  Failed.\n");
    }
    
    // Test if CouncilRoom is removed from hand
    printf("Test 3: CouncilRoom is removed from hand.\n");
    if(state->hand[0][0] != council_room) {
        printf("  Passed.\n");
    }
    else {
        printf("  Failed.\n");
    }
    
    // Test if buys is increased
    printf("Test 4: Buys is increased by one.\n");
    if(state->numBuys == preBuys + 1) {
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
      
    testCouncilRoomCard(&G);
    
    return 0;
}