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
void testCouncilRoomCard(struct gameState *state, int testIndex, int* failedCount, int* passedCount) {
    // Randomize gamestate data
    int p = rand() % 2;
    state->whoseTurn = p;
    state->deckCount[p] = rand() % MAX_DECK;
    state->discardCount[p] = rand() % MAX_DECK;
    state->handCount[p] = rand() % (MAX_HAND - 3);
    state->numBuys = rand() % treasure_map;
    
    // add random cards to deck top of deck
    int i;
    for(i = 0; i < 5; i++) {
        state->deck[p][state->deckCount[p] + i] = rand() % treasure_map;
    }
    
    // Put adventurer card in 0 position in player's hand.
    state->hand[p][0] = council_room;
    
    // remember counts before adventure card is played
    int preDeckCount = state->deckCount[p];
    int preDiscardCount = state->discardCount[p];
    int preHandCount = state->handCount[p];
    int preBuys = state->numBuys;
    
    // Play CouncilRoom card
    playCard(0, 0, 0, 0, state);
    
    // Test if two cards have been added to hand (four cards drawn and one played)
    if((preHandCount + 3) == state->handCount[p]) {
        (*passedCount)++;
    }
    else {
        (*failedCount)++;
        printf("--  Failed. Test %ia: handCount increased by 3.\n", testIndex);
    }
    
    // Test if two cards are removed from deck + discard
    if((preDeckCount + preDiscardCount - 4) == (state->deckCount[p] + state->discardCount[p])) {
        (*passedCount)++;
    }
    else {
        (*failedCount)++;
        printf("--  Failed. Test %ib: Deck + discard count decreased by 4.\n", testIndex);
    }
    
    // Test if CouncilRoom is removed from hand
    if(state->hand[p][0] != council_room) {
        (*passedCount)++;
    }
    else {
        (*failedCount)++;
        printf("--  Failed. Test %ic: CouncilRoom is removed from hand.\n", testIndex);
    }
    
    // Test if buys is increased
    if(state->numBuys == preBuys + 1) {
        (*passedCount)++;
    }
    else {
        (*failedCount)++;
        printf("--  Failed. Test %id: Buys is increased by one.\n", testIndex);
    }
}

int main (int argc, char** argv) {
    struct gameState G;
    int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};
    
    
    printf("\n\n********************************************\n");
    printf("***      Testing Council Room Card       ***\n");
    printf("********************************************\n\n");
    
    //perform random tests
    int i, failedCount, passedCount;
    int numTests = 2000;
    for(i = 0; i < numTests; i++) {
        initializeGame(2, k, 2, &G);
        testCouncilRoomCard(&G, i, &failedCount, &passedCount);
    }
    printf("\nFinished testing.\n");
    printf("%i tests run: %i passed, %i failed\n\n", failedCount + passedCount, passedCount, failedCount);
    
    return 0;
}