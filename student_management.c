//School Record Management System
#include<stdio.h>
#include<stdlib.h>
struct node{
    char name[50];
    float marks;
    struct node*next;
    int id,class;
};
struct node*head=NULL;
void addStudent(){
    struct node*ptr,*temp;
    ptr=(struct node*)malloc(sizeof(struct node));
    printf("\nenter name:\t");
    scanf("%s",&ptr->name);

    printf("\nenter ID:\t");
    scanf("%d",&ptr->id);

    printf("\nenter class:\t");
    scanf("%d",&ptr->class);

    printf("\nenter marks:\t");
    scanf("%f",&ptr->marks);

    if(ptr==NULL){
        printf("\nOVERFLOW\n");
    }else{
        if(head==NULL){
            ptr->next=NULL;
            head=ptr;
             printf("\nstudent record is added\n");
        }else{
            temp=head;
            while(temp->next!=NULL){
                temp=temp->next;
            }
            ptr->next=NULL;
            temp->next=ptr;
            printf("\nstudent record is added\n");


        }

    }
}

void deletestudent(){
    struct node*ptr,*temp;
    int id;
    if(head==NULL){
        printf("list is empty\n");
    }else{
        printf("\nenter id to deleted:\t");
        scanf("%d",&id);
        if(head->id==id){
            ptr=head;
            head=head->next;
            free(ptr);
            printf("\nDeleted\n");
            return;
        }
        ptr=head;
        while(ptr!=NULL && ptr->id!=id){
            temp=ptr;
            ptr=ptr->next;
            

        }if(ptr==NULL){
                printf("\nStudent not found\n");
                return;
            }

        temp->next=ptr->next;
        free(ptr);
        printf("Student record is deleted\n");

    }
}
void display(){
    struct node*ptr;
    if(head==NULL){
        printf("No record\n");
    }else{
        ptr=head;
        while(ptr->next!=NULL){
           
            printf("\nName: %s\nID: %d\nclass: %d\nmarks: %f\n",ptr->name,ptr->id,ptr->class,ptr->marks);
            ptr=ptr->next;

        }
         printf("\nName: %s\nID: %d\nclass: %d\nmarks: %f\n",ptr->name,ptr->id,ptr->class,ptr->marks);
    }
}

void search(){
    struct node*ptr;
    int id;
    ptr=head;
    printf("enter the ID that you want to search:\t");
    scanf("%d",&id);
    if(head==NULL){
        printf("\nList is empty\n");
    }else{

        while(ptr->next!=NULL){
            if(ptr->id==id){
                printf("\nName: %s\nID: %d\nclass: %d\nmarks: %f\n",ptr->name,ptr->id,ptr->class,ptr->marks);
            }
            ptr=ptr->next;
        }
    }
}

int main(){
    int choice;
   
    while(choice!=5){
         printf("........................................................................\n");
    printf(".................STUDENT MANAGEMENT SYSTEM..............................\n");
    printf("\n1.Add student record\n2.Display student record\n3.delete record\n4.search student record\n5.exit\n");
    printf("..........................................................................\n");
    printf("\nenter choice:\t");
    scanf("%d",&choice);
        switch(choice){
            case 1:addStudent();
            break;
            case 2:display();
            break;
            case 3:deletestudent();
            break;
            case 4: search();
            break;
            case 5:exit(0);
            break;
            default:printf("\n Invalid choice\n");
            break;
        }
    }
}