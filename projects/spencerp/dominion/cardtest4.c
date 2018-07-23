// test feast card
#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include "dominion_helpers.h"
#include <stdlib.h>


// test should check the following:
// 1. Hand count stays the same
// 2. deck + discard reduced by one
void testFeastCard(struct gameState *state) {
    printf("\n\n********************************************\n");
    printf("***          Testing Feast Card          ***\n");
    printf("********************************************\n\n");
    
    // Put feast card in 0 position in player's hand.
    state->whoseTurn = 0;
    state->hand[0][0] = feast;
    
    // remember counts before adventure card is played
    int preSupplyCount = state->supplyCount[estate];
    int preHandCount = state->handCount[0];
    
    // Play feast card to get estate cards
    playCard(0, estate, 0, 0, state);
    
    // Test if hand count stays the same (feast trashed, one card added)
    printf("Test 1: handCount stays the same.\n");
    if((preHandCount) == state->handCount[0]) {
        printf("  Passed.\n");
    }
    else {
        printf("  Failed.\n");
    }
    
    // Test if one cards are removed from supply
    printf("Test 2: supply count of choice decreased by one.\n");
    if((preSupplyCount - 1) == (state->supplyCount[estate])) {
        printf("  Passed.\n");
    }
    else {
        printf("  Failed.\n");
    }
    
    // Test if adding province card fails
    printf("Test 3: Adding province card fails.\n");
    // Put feast card in 0 position in player's hand.
    state->whoseTurn = 0;
    state->hand[0][0] = feast;
    
    // remember counts before card is played
    preSupplyCount = state->supplyCount[province];
    
    // Play feast card to get estate cards
    playCard(0, province, 0, 0, state);
    
    if((preSupplyCount) == (state->supplyCount[province])) {
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
      
    testFeastCard(&G);
    
    return 0;
}