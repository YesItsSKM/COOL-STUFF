// Scheduling processes according to FCFS scheduling algorithm.

#include <stdio.h>      // For basic I/O.
#include <malloc.h>     // For dynamic memory allocation and deletion.
#include "process.h"    // Custom header file which defines structure the 'Process' and 'print_process_schedule()' to print the schedule.

void main(){
    int number_of_process = 0;

    int i, j;
    int id, at, cpu;

    printf("Enter number of processes : ");
    scanf("%d", &number_of_process);

    Process *queue = calloc(number_of_process, sizeof(Process));

    for(i = 0; i < number_of_process; i++){
        printf("\nProcess[%d] - Enter [ARRIVAL_TIME & CPU_BURST_TIME] respectively : ", i);
        scanf("%d %d", &at, &cpu);
        
        queue[i].id = i;
        queue[i].arrival_time = at;
        queue[i].cpu_burst_time = cpu;

        if(i == 0)
            queue[i].waiting_time = 0;

        else
            queue[i].waiting_time = queue[i-1].turn_arround_time;
        
        queue[i].turn_arround_time = queue[i].cpu_burst_time + queue[i].waiting_time;

        while(getchar() != '\n');   // Clearing the buffer. You can also use fflush(stdin);
    }

    print_process_schedule(queue, number_of_process);   // Defined in "process.h"

    printf("\n");
}
