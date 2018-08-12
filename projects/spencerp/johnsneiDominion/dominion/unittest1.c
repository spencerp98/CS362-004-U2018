// test buy card
#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include "dominion_helpers.h"
#include <stdlib.h>


// test should check the following:
// 1. buycard fails if player does not have any buys left
// 2. buycard fails if there is not any of this card left
// 3. buycard fails if player does not have enough treasure
// 4. phase should equal 1 if buycard succeeds
// 5. should be one less of the card bought in supply
// 6. player loses a buy if sucessful
// 7. player loses appropriate number of coins if sucessful.
void testBuyCard(int supplyPos, struct gameState *state) {
    printf("\n\n********************************************\n");
    printf("***            Testing buyCard           ***\n");
    printf("********************************************\n");
    
    printf("\n***Testing for buycard failures.***\n");
    // Test if buycard fails if player does not have any buys left
    printf("Test 1: player does not have buys left.\n");
    state->numBuys = 0;
    if(buyCard(supplyPos, state) == -1) {
           printf("  Passed: player could not buy a card.\n");
    }
    else {
        printf("  Failed: player could buy a card with no buys.\n");
    }
    
    // test if buycard fails if there is not any of this card left
    printf("Test 2: This card not in supply.\n");
    state->numBuys = 1;
    state->supplyCount[supplyPos] = 0;
    if(buyCard(supplyPos, state) == -1) {
           printf("  Passed: player could not buy a card.\n");
    }
    else {
        printf("  Failed: player could buy a card even though there were none left.\n");
    }
    
    // test if buycard fails if player does not have enough treasure
    printf("Test 3: player does not have enough coins to buy card.\n");
    state->numBuys = 1;
    state->supplyCount[supplyPos] = 1;
    state->coins = 0;
    if(buyCard(supplyPos, state) == -1) {
           printf("  Passed: player could not buy a card.\n");
    }
    else {
        printf("  Failed: player could buy a card even though they didn't have enough coins.\n");
    }
    
    // Test game state after a successful buycard
    printf("\n***Testing game state after a successful buycard***\n");
    state->numBuys = 1;
    state->supplyCount[supplyPos] = 1;
    state->coins = getCost(supplyPos) + 1;
    if(buyCard(supplyPos, state) != 0) {
           printf("  Failed: buycard was unsuccessful.\n");
    }
    else {
        
        // Test phase
        printf("Test 4: Phase should equal 1 if buycard succeeds.\n");
        if(state->phase != 1) {
            printf("  Failed: phase does not equal 1.\n");
        }
        else {
            printf("  Passed: Phase is 1.\n");
        }
        
        // Test supply
        printf("Test 5: One less card in supply.\n");
        if(state->supplyCount[supplyPos] != 0) {
             printf("  Failed: Card Supply not decreased by one.\n");
        }
        else {
            printf("  Passed: One less card in supply.\n");
        }
        
        // Test supply
        printf("Test 6: Player loses a buy.\n");
        if(state->numBuys != 0) {
             printf("  Failed: buy count not decreased by one.\n");
        }
        else {
            printf("  Passed: Player lost a buy.\n");
        }
        
        // Test supply
        printf("Test 7: One less card in supply.\n");
        if(state->coins != 1) {
             printf("  Failed: Player did not lose correct number of coins.\n");
        }
        else {
            printf("  Passed: Player lost correct number of coins.\n");
        }
    }
}

int main (int argc, char** argv) {
    struct gameState G;
    int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};
    
    initializeGame(2, k, 2, &G);
      
    testBuyCard(1, &G);
    
    return 0;
}
    
    