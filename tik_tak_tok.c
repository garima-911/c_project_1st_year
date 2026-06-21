#include<stdio.h>
#include<stdlib.h>
char arr[3][3]={
        {'1','2','3'},
        {'4','5','6'},
        {'7','8','9'}
    };
int move=0;
char currentplayer='x';
void displayboard(){
   printf("%c || %c || %c ",arr[0][0],arr[0][1],arr[0][2]);
   printf("\n-----------------------------------------\n");
   printf("%c || %c || %c ",arr[1][0],arr[1][1],arr[1][2]);
   printf("\n-----------------------------------------\n");
   printf("%c || %c || %c ",arr[2][0],arr[2][1],arr[2][2]);
   printf("\n");
}

void switchplayer(){
    if(currentplayer=='x'){
        currentplayer='o';
    }else{
        currentplayer='x';
    }
}

int winplayer(){
for(int i=0;i<3;i++){
    if(arr[i][0]==arr[i][1] && arr[i][1]==arr[i][2]){
       
        return 1;
    }
}
for(int i=0;i<3;i++){
    if(arr[0][i]==arr[1][i] && arr[1][i]==arr[2][i]){
       
        return 1;
    }
}
if(arr[0][0]==arr[1][1] && arr[1][1]==arr[2][3]){
   
    return 1;
}
if(arr[0][2]==arr[1][1] && arr[1][1]==arr[2][0]){
   
    return 1;
}
return 0;

}

void playermove(){
    int pos, row,column;
    printf("\nenter position: ");
    scanf("%d",&pos);
    row=(pos-1)/3;
    column=(pos-1)%3;
    if(pos<1 || pos>9){
        printf("\ninvalid input!\n");
        playermove();
        return;
    }
    if(arr[row][column]=='x' || arr[row][column]=='o'){
        printf("\nalready occupied\n");
        playermove();
        return;
    }
    arr[row][column]=currentplayer;
   move++;
}
int draw(){
    if(move==9){
        printf("\ngame is draw!");
        return 1;
    }
    return 0;
}



int main(){

    while(1){
        displayboard();

         playermove();
        
         if(winplayer()){
             displayboard();
             printf("\nplayer %c wins!\n",currentplayer);
             break;
         }
         
        

        if (draw()){
            break;
        }

        switchplayer();
        }
    }
    
