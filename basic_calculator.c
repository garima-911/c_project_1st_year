#include<stdio.h>
#include<stdlib.h>
void addition(){
    int a,b;
    printf("enter the first number : ");
    scanf("%d",&a);
    printf("\nenter the second number:  ");
    scanf("%d",&b);
    int add=a+b;
    printf("\nAddition of %d and %d is %d",a,b,add);
}

void subtraction(){
    int a,b;
    printf("enter the first number : ");
    scanf("%d",&a);
    printf("\nenter the second number:  ");
    scanf("%d",&b);
    int sub=a-b;
    printf("\nSubtraction of %d and %d is %d",a,b,sub);
}

void multiplication(){
    int a,b;
    printf("enter the first number : ");
    scanf("%d",&a);
    printf("\nenter the second number:  ");
    scanf("%d",&b);
    int mul=a*b;
    printf("\nMultiplication of %d and %d is %d",a,b,mul);
};

void division(){
    int div;
    int a,b;
    printf("enter the first number : ");
    scanf("%d",&a);
    printf("\nenter the second number:  ");
    scanf("%d",&b);
    if(b==0){
        printf("\nERROR");
    }else{
    div=a/b;
    printf("Division of %d and %d is %d",a,b,div);
    }
}


int main(){
     printf("\n...........................................BASIC CALCULATOR........................................\n");
    int choice;

    while(choice!=5){
        printf("\n1.Addition\n2.Subraction\n3.Multiplication\n4.Division\n5.Exit");
         printf("\nenter your choice:  ");
        scanf("%d",&choice);
         printf("\n.....................................................................................................\n");
        switch(choice){
            case 1:addition();
            break;
            case 2: subtraction();
            break;
            case 3:multiplication();
            break;
            case 4:division();
            break;
            case 5:exit(0);
            break;
            default:printf("Invalid choice");
            break;
        }
    }
}