// test adventurer card
#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include "dominion_helpers.h"
#include <stdlib.h>
#include <string.h>


// test should check the following:
// 1. Last two cards in hand should be treasure cards
// 2. Two cards are added to hand
// 3. Deck + discard is decreased by two cards
void testAdventurerCard(struct gameState *state, int testIndex, int* failedCount, int* passedCount) {
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
    
    // Put adventurer card in 0 position in player's hand.
    state->hand[p][0] = adventurer;
    
    // remember counts before adventure card is played
    int preDeckCount = state->deckCount[p];
    int preDiscardCount = state->discardCount[p];
    int preHandCount = state->handCount[p];
    
    // Play adventurer card
    playCard(0, 0, 0, 0, state);
    
    // Test if two cards have been added to hand
    if((preHandCount + 2) == state->handCount[p]) {
        (*passedCount)++;
    }
    else {
        (*failedCount)++;
        printf("--  Failed. Test %ia: handCount increased by 2.\n", testIndex);
    }
    
    // Test if two cards are removed from deck + discard
    if((preDeckCount + preDiscardCount - 2) == (state->deckCount[p] + state->discardCount[p])) {
        (*passedCount)++;
    }
    else {
        (*failedCount)++;
        printf("--  Failed. Test %ib: Deck + discard count decreased by 2.\n", testIndex);
    }
    
    // Test if last two cards in hand are treasure cards
    int lastCard = state->hand[p][state->handCount[p] - 1];
    int lastCard2 = state->hand[p][state->handCount[p] - 2];
    if((lastCard == copper || lastCard == silver || lastCard == gold) && (lastCard2 == copper || lastCard2 == silver || lastCard2 == gold)) {
        (*passedCount)++;
    }
    else {
        (*failedCount)++;
        printf("--  Failed. Test %ic: Last two cards in hand are treasure cards.\n", testIndex);
    }
    
}

int main (int argc, char** argv) {
    struct gameState G;
    int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};
    
    
    printf("\n\n********************************************\n");
    printf("***       Testing Adventurer Card        ***\n");
    printf("********************************************\n\n");
    
    //perform random tests
    int i, failedCount, passedCount;
    int numTests = 2000;
    for(i = 0; i < numTests; i++) {
        initializeGame(2, k, 2, &G);
        testAdventurerCard(&G, i, &failedCount, &passedCount);
    }
    printf("\nFinished testing.\n");
    printf("%i tests run: %i passed, %i failed\n\n", failedCount + passedCount, passedCount, failedCount);
    
    
    return 0;
}