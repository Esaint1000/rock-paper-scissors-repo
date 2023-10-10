#include <stdio.h>
#include <stdlib.h> 
#include <string.h>

struct shoot{
    int ROCK;
    int PAPER;
    int SCISSORS;
};

struct shoot game = {0, 1, 2};


//Simulate computer as a person who shoots rock, hands, scissors
int GenerateRandomNum (){
    //Limit the range of number generator: rand() % (max_number + 1 - minimum_number) + minimum_number
    int random_num = rand() % (2 + 1 - 0) + 0;
    return random_num;
}

//Check win, lose, same
char checkWinLose(int myChoice, int computerChoice){
    char result;
    //Paper - Rock = 1
    //Scissors - paper = 1
    //Rock - scissors = -2
    if ((myChoice  - computerChoice == -2) || (myChoice - computerChoice == 1)){
        result = 'w';
    } else if ((myChoice - computerChoice == -1) || (myChoice - computerChoice ==2)){
        result = 'l';
    } else {
        result = 'o';
    }
    return result;
}

void printMessage (char result){
    if (result == 'w'){
        printf("You won!");
    } else if (result == 'l'){
        printf("You lose!");
    } else if (result == 'o'){
        printf("It's a tie!");
    }
}

char* getChoiceString (int choice){
    if (choice == 0){
        char *word = "Rock";
    } else if (choice == 1){
        char *word = "Paper";
    } else {
        char *word = "Scissors";
    }
    return word;
}

//Input & Output

int main(){


    int computer_choice = GenerateRandomNum();
    int hand;
    printf("Input corresponding numbers. Get ready, rock (0), paper (1), scissors (2), shoot: ");
    scanf("%d", &hand);
    hand = 2;

    char result = checkWinLose(hand, computer_choice);
    printMessage(result);

    char* my_word = getChoiceString(hand); //
    char* computer_word = getChoiceString(computer_choice); //

    printf("\nYour choice is %s, while computer choice is %s.", getChoiceString(hand), getChoiceString(computer_choice));

    return 0;
}