// test whoseTurn
#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include "dominion_helpers.h"
#include <stdlib.h>


// test should check the following:
void testWhoseTurn(struct gameState *state) {
    printf("\n\n********************************************\n");
    printf("***          Testing whoseTurn           ***\n");
    printf("********************************************\n\n");
    
    //Test count of 0
    printf("Test 1: whoseturn = 0\n");
    state->whoseTurn = 0;
    if(numHandCards(state) == 0) {
        printf("  Passed.\n");
    }
    else {
        printf("  Failed.\n");
    }
    
    //Test count of 1
    printf("Test 2: whoseTurn = 1\n");
    state->whoseTurn = 1;
    if(numHandCards(state) == 1) {
        printf("  Passed.\n");
    }
    else {
        printf("  Failed.\n");
    }
    
    //Test count of 0
    printf("Test 3: whoseTurn = 1024\n");
    state->whoseTurn = 1024;
    if(numHandCards(state) == 1024) {
        printf("  Passed.\n");
    }
    else {
        printf("  Failed.\n");
    }
    
    //Test count of 0
    printf("Test 4: whoseTurn = -1\n");
    state->whoseTurn = -1;
    if(numHandCards(state) == -1) {
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
      
    testWhoseTurn(&G);
    
    return 0;
}