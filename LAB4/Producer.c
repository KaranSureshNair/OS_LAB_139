#include<stdio.h>
#include<math.h>

int mutex=1;
int full = 0;
int empty=3;
int x =0;

void wait(int *s){
    --(*s);
}

void signal(int *s){
    ++(*s);
}

void producer(){
    if(mutex==1 && empty !=0){
        wait(&mutex);
        signal(&full);
        wait(&empty);
        x++;
        printf("Producer has produced : item %d\n",x);
        signal(&mutex);
    }
    else{
        printf("Buffer is full\n");
    }
}

void consumer(){
    if(mutex==1 && empty !=0){
        wait(&mutex);
        signal(&full);
        signal(&empty);
        printf("Consumer has consumed : item %d\n", x--);
        signal(&mutex);
    }
    else{
        printf("Buffer is empty\n");
    }
}

int main(){
    int choice;
    while(1){
        printf("\n enter 1)Producer, 2)Consumer, 3)Exit\n");
        printf("Enter your choice:");
        scanf("%d", &choice);
        switch(choice){
            case 1 :
                producer();
                break;
            case 2 :
                consumer();
                break;
            case 3 :
                printf("Exiting...");
                exit(0);
            default : printf("Invalid Input\n");
            
        }
    }
    return 0;
}
