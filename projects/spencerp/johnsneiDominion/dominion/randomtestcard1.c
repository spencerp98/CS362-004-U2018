// test smithy card
#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include "dominion_helpers.h"
#include <stdlib.h>


// test should check the following:
// 1. Hand count increases by 3
// 2. Deck + discard count decreases by 3
void testSmithyCard(struct gameState *state, int testIndex, int* failedCount, int* passedCount) {
    // Randomize gamestate data
    int p = rand() % 2;
    state->whoseTurn = p;
    state->deckCount[p] = rand() % MAX_DECK;
    state->discardCount[p] = rand() % MAX_DECK;
    state->handCount[p] = rand() % (MAX_HAND - 2);
    
    // add random cards to deck top of deck
    int i;
    for(i = 0; i < 5; i++) {
        state->deck[p][state->deckCount[p] + i] = rand() % treasure_map;
    }
    
    // Put smithy card in 0 position in player's hand.
    state->hand[p][0] = smithy;
    
    // remember counts before adventure card is played
    int preDeckCount = state->deckCount[p];
    int preDiscardCount = state->discardCount[p];
    int preHandCount = state->handCount[p];
    
    // Play smithy card
    playCard(0, 0, 0, 0, state);
    
    // Test if two cards have been added to hand (three cards drawn and one played)
    if((preHandCount + 2) == state->handCount[p]) {
        (*passedCount)++;
    }
    else {
        (*failedCount)++;
        printf("--  Failed. Test %ia: handCount increased by 2.\n", testIndex);
    }
    
    // Test if two cards are removed from deck + discard
    if((preDeckCount + preDiscardCount - 3) == (state->deckCount[p] + state->discardCount[p])) {
        (*passedCount)++;
    }
    else {
        (*failedCount)++;
        printf("--  Failed. Test %ib: Deck + discard count decreased by 3.\n", testIndex);
    }
    
    // Test if smithy is removed from hand
    if(state->hand[p][0] != smithy) {
        (*passedCount)++;
    }
    else {
        (*failedCount)++;
        printf("--  Failed. Test %ic: Smithy is removed from hand.\n", testIndex);
    }
}

int main (int argc, char** argv) {
    struct gameState G;
    int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};
    
    printf("\n\n********************************************\n");
    printf("***         Testing Smithy Card          ***\n");
    printf("********************************************\n\n");
    
    //perform random tests
    int i, failedCount, passedCount;
    int numTests = 2000;
    for(i = 0; i < numTests; i++) {
        initializeGame(2, k, 2, &G);
        testSmithyCard(&G, i, &failedCount, &passedCount);
    }
    printf("\nFinished testing.\n");
    printf("%i tests run: %i passed, %i failed\n\n", failedCount + passedCount, passedCount, failedCount);

    return 0;
}
    
    