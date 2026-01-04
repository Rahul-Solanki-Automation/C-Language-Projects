#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
     int random, guess;
    int no_of_guess = 0;
    srand(time(NULL));


    printf("welcome to the world of guessing numbers\n");
    random = rand() % 100 + 1; // generating between 0 to 100

    do {
        printf("\nplease enter your guess between(1 to 100):");
        scanf("%d", &guess);
        no_of_guess++;
        
        if (guess < random) {
            printf("guess a larger number.\n");
        }
        else if (guess > random){
            printf("guess a smaller number.\n");
        }
        else{
            printf("congratulation !!!you have successfuly guessed the number in %d attempts\n", no_of_guess);

        }

    }
    while (guess!= random);
    

printf("\n Bye Bye, thanks for playing.");
printf("\n Developed by: Rahul Solanki");

return 0;
}
