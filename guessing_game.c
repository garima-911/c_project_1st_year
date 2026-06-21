//Number guessing game!

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
    int guess,number;
    srand(time(0));
    number=rand() % 100 + 1;
// rand()      → random number
// % 100       → limit to 0–99
// + 1         → shift to 1–100
// rand() % N + start

printf("enter the number between 1 to 100\n");

do{
printf("enter your guess:");
scanf("%d",&guess);
if(guess > number){
    printf("too high! try again\n");
}
else if(number>guess){
    printf("too low! try again\n");
}
else{
    printf("congratulation! you win");
}
}while(guess != number);
return 0;
}