#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

const int BaR_LENGTH = 50;
const int MAX_TASKS = 5;

typedef struct {
    int id;
    int progress;
    int step;
} Task;

void print_bar (Task task);
void Clear_Screen ();

int main () {
  Task tasks [MAX_TASKS];
  srand(time(NULL));

for (int i = 0; i< MAX_TASKS; i++) {
  tasks[i].id = i + 1;
  tasks[i].progress = 0;
  tasks[i].step = rand() % 5 +1;
}
   
int tasks_incomplete = 1;
while (tasks_incomplete) {
    tasks_incomplete = 0;
     Clear_Screen ();
     for (int i = 0; i < MAX_TASKS; i++) {
       if(tasks[i].progress < 100)  { 
        tasks[i].progress += tasks[i].step;
           if( tasks[i].progress > 100)
               tasks[i].progress=100; 
            tasks_incomplete = 1;
        }
        print_bar(tasks[i]);
     }
      sleep(1); // sleep for 1 second
    }
printf("All tasks completed!\n");
    return 0;
}

void Clear_Screen () {
    #ifdef _WIN32
    system ("cls");
    #else
    system("clear");
    #endif
}

void print_bar (Task task) {
     int bars_to_show = (task.progress * BaR_LENGTH) / 100;
    printf("Task %d; [", task.id);
    for (int i=0; i < BaR_LENGTH; i++) {
       if (i< bars_to_show) {
          printf("=");
       } else {
        printf(" ");
       }

    }
    printf("] %d%% \n ", task.progress);
}