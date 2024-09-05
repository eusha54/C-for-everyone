/*
Then deal out 7 card hands and evaluate the probability that a hand has no pair, 
one pair, two pair, three of a kind, full house and 4 of a kind.  
This is a Monte Carlo method to get an approximation to these probabilities.  
Use at least 1 million randomly generated hands.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


enum suit{spades, hearts, clubs, diamonds};
typedef enum suit suit;

typedef struct card{
    suit s;
    int num;
} card;


#define DECK_SIZE 52
#define HAND_SIZE 7
#define SHUFFLE_SIZE 500
#define TEST_SIZE 1000000
#define SHUFFLE for(i=0; i<SHUFFLE_SIZE; i++){\
            indx = rand()%DECK_SIZE;\
            temp = deck[indx];\
            deck[indx] = deck[(indx*i)%52];\
            deck[(indx*i)%DECK_SIZE] = temp;\
        }

#define FILL for(i=0; i<DECK_SIZE; i++){\
            deck[i].s = i/13;\
            deck[i].num = (i%13) + 1;\
        }

#define FILL_HAND for(i=0; i<HAND_SIZE; i++){\
            hand[i]=deck[i];\
        }


void deck_print(card deck[], int size){
    char* suits[] = {"Spd", "Hrt", "Clb", "Dmnd"};
    char*nums[] = {"A","2","3","4","5","6","7","8","9","10","J","Q","K"};
    for(int i=0; i<size; i++){
        if(!(i%13))printf("\n");
        printf("%s %s\t", suits[deck[i].s], nums[deck[i].num-1]);
    }
}

void hand_analyze(card hand[HAND_SIZE], int stat[6]){
    int cards[13] = {0};
    int i;
    for(i=0; i<HAND_SIZE; i++){
        cards[hand[i].num-1]++;
    }
    int pair_count = 0, three_count = 0, four_count = 0;
    for(i=0; i<13; i++){
        if(cards[i]==2){
            pair_count++;
        }else if(cards[i]==3){
            three_count++;
        }else if(cards[i]==4){
            four_count++;
        }
    }

    if (four_count>0){
        stat[4]+=1;
    }else if(three_count>0 && pair_count>0){
        stat[5]+=1;
    }else if(three_count>0){
        stat[3]+=1;
    }else if(pair_count>1){
        stat[2]+=1;
    }else if(pair_count>0){
        stat[1]+=1;
    }else{
        stat[0]+=1;
    }
}


int main(){
    int indx, i;
    int no_pair=0, one_pair = 0, two_pair = 0, three_kind = 0, four_kind = 0, full_house = 0, t=0;
    int stat[6]={0};

    card deck[DECK_SIZE];
    card hand[HAND_SIZE];
    card temp;
    srand(time(NULL));

    while (t<TEST_SIZE){
        FILL;
        SHUFFLE;
        FILL_HAND;
        hand_analyze(hand, stat);
        t++;
    }
    printf("\nNo pair \t%f\nOne pair\t%f\nTwo pairs\t%f\nThree of a kind\t%f\nFour of a kind\t%f\nFull House\t%f\n", (float)stat[0]/TEST_SIZE,(float)stat[1]/TEST_SIZE,(float)stat[2]/TEST_SIZE,(float)stat[3]/TEST_SIZE,(float)stat[4]/TEST_SIZE,(float)stat[5]/TEST_SIZE);
}