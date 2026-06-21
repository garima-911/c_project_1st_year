#include<stdio.h>
#include<stdlib.h>
struct node{
    int accNo;
    char name[50];
    float balance;
};
void createAccount(){
    struct node a;
    FILE *ptr=fopen("account.txt","w");
    printf("\nEnter Account number: ");
    scanf("%d",&a.accNo);
    printf("\nEnter name: ");
    scanf("%s",&a.name);
    printf("\nEnter balance: ");
    scanf("%f",&a.balance);
    fprintf(ptr,"%d %s %f",a.accNo,a.name,a.balance);
    fclose(ptr);

}

void deposit(){
     struct node a;
    float amount;

    FILE *fp = fopen("account.txt", "r");

    fscanf(fp, "%d %s %f", &a.accNo, a.name, &a.balance);
    fclose(fp);

    printf("Enter Amount to Deposit: ");
    scanf("%f", &amount);

    a.balance = a.balance + amount;

    fp = fopen("account.txt", "w");
    fprintf(fp, "%d %s %f", a.accNo, a.name, a.balance);
    fclose(fp);

    printf("Updated Balance = %.2f\n", a.balance);

}

void withdraw(){
    struct node a;
    float amount;
    FILE *ptr=fopen("account.txt","r");
    fscanf(ptr, "%d %s %f", &a.accNo, a.name, &a.balance);
    fclose(ptr);

    printf("\nEnter Amount to Withdraw: ");
    scanf("%f", &amount);

    if(amount > a.balance)
    {
        printf("\nInsufficient Balance!\n");
    }
    else
    {
        a.balance = a.balance - amount;

        ptr = fopen("account.txt", "w");
        fprintf(ptr, "%d %s %f", a.accNo, a.name, a.balance);
        fclose(ptr);

        printf("Remaining Balance = %.2f\n", a.balance);
    }


}
void balanceEnquiry()
{
    struct node a;

    FILE *fp = fopen("account.txt", "r");

    fscanf(fp, "%d %s %f", &a.accNo, a.name, &a.balance);

    fclose(fp);

    printf("\nAccount Number: %d", a.accNo);
    printf("\nName: %s", a.name);
    printf("\nBalance: %.2f\n", a.balance);
}

int main(){
    int choice;
    while(choice!=5){
        printf("\n------------BANK MANAGEMENT SYSTEM-----------\n");
        printf("1.create account\n2.deposite\n3.withdraw\n4.balance enquiry\n5.exit");
        printf("\nenter your choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1: createAccount();
            break;
            case 2:deposit();
            break;
            case 3: withdraw();
            break;
            case 4: balanceEnquiry();
            break;
            case 5: exit(0);
            break;
            default: printf("\ninvalid choice.Try again!");
            break;
        }
    }
}