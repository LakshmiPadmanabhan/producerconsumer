#include <stdio.h>
int mutex=1,full=0,empty,c=1;
int b[100]; //buffer
int wait(int s){ // wait function
    s--;
    return s;
}
int signal(int s){ //signal function
    s++;
    return s;
}
void produce(){ // producer
    mutex=wait(mutex);
    empty=wait(empty);
    full=signal(full);
    printf("\nMutex Value is: %d",mutex);
    printf("\nConsumption Not allowed now");
    printf("\nItem number %d is produced",c++);
    mutex=signal(mutex);
    printf("\nMutex Value is: %d",mutex);
    printf("\nConsumption allowed now");
}
void consume(){ //consumer
    mutex=wait(mutex);
    empty=signal(empty);
    full=wait(full);
    printf("\nMutex Value is: %d",mutex);
    printf("\nProduction Not Allowed now");
    printf("\nItem number %d is consumed",--c);
    mutex=signal(mutex);
    printf("\nMutex Value is: %d",mutex);
    printf("\nProduction Allowed now");
}
void main(){
    int n,ch;
    printf("Enter Size of the Buffer: ");
    scanf("%d",&n);
    b[n];
    empty=n;
    //display menu
    printf("Choices:\n  1.Produce an item \n  2.Consume an item \n  3.Exit");
    printf("\nEnter choice: ");
    scanf("%d",&ch);
    while(ch!=3){
        if(ch==1){
            if ((full!=n)&&(mutex==1))
            {
                produce();
            }
            else
            {
                printf("Error: Buffer Full::Unable to Produce Item");
            }

        }
        else if (ch==2)
        {
            if ((empty!=n)&&(mutex==1))
            {
                consume();
            }
            else
            {
                printf("Error:Buffer Empty::Unable to Consume Item");
            }
            
        }
        else if(ch==3){
            printf("TERMINATING...");
        }
        else
            printf("Invalid Choice");
        printf("\n\nEnter Choice: ");
        scanf("%d",&ch);
    }
}