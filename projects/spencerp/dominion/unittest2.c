// test supply count
#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include "dominion_helpers.h"
#include <stdlib.h>


// test should check the following:
void testSupplyCount(int supplyPos, struct gameState *state) {
    printf("\n\n********************************************\n");
    printf("***          Testing SupplyCount         ***\n");
    printf("********************************************\n\n");
    int i;
    int result;
    for(i = 0; i < treasure_map; i++) {
        state->supplyCount[i] = i;
        result = supplyCount(i, state);
        if (result == i) {
            printf("Test %d:\n  Passed: supply count is correct.\n", i + 1);
        }
        else {
            printf("Test %d:\n  Failed: supply count returned %d, it should be %d\n", i + 1, result, i);
        }
    }
}

int main (int argc, char** argv) {
    struct gameState G;
    int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};
    
    initializeGame(2, k, 2, &G);
      
    testSupplyCount(1, &G);
    
    return 0;
}
    
    