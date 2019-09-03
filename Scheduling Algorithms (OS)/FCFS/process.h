#ifndef PROCESS_SCHEDULE_H
#define PROCESS_SCHEDULE_H

        #include <stdio.h>      // For basic I/O

        // Declaring a structure to store individual process's information.
        typedef struct{
            int id;
            int arrival_time;
            int cpu_burst_time;
            int waiting_time;
            int turn_arround_time;
        } Process;

        // Function to print the process schedule. Both the table and sequence.
        void print_process_schedule(Process *queue, int number_of_processes){
            int i;

            printf("\n    ---------------------------------------------------------------------------------------------------------------");
            printf("\n    | Process_ID | \t Arrival_Time   |    CPU_Burst_Time    |\t Waiting_Time      |    Turnaround_Time   |\n");
            printf("    ---------------------------------------------------------------------------------------------------------------");

            double avg_waiting_time = 0.0;
            double avg_turn_arround_time = 0.0;

            for(i = 0; i < number_of_processes; i++){
                printf("\n    | %10d | %20d | %20d | %25d | %20d |", queue[i].id, queue[i].arrival_time, queue[i].cpu_burst_time, queue[i].waiting_time, queue[i].turn_arround_time);

                avg_waiting_time += queue[i].waiting_time;
                avg_turn_arround_time += queue[i].turn_arround_time;
            }

            printf("\n    ---------------------------------------------------------------------------------------------------------------\n");

            printf("\nProcess Arrangement : \n\n\t");

            for(i = 0; i < number_of_processes; i++){
                if(i == number_of_processes - 1)
                    printf("|   P[%d]   |", queue[i].id);
                else
                    printf("|   P[%d]   | --> ", queue[i].id);
            }

            // st = Starting time of a process & ct = Ending(Completion) time of a process
            int st = 0, ct = 0;

            printf("\n\t");
            for(i = 0; i < number_of_processes; i++){
                printf("%d", st);
                ct += queue[i].cpu_burst_time;
                printf(" %10d", ct);
                st = ct;
                printf("     ");
            }

            avg_waiting_time = (avg_waiting_time/number_of_processes);
            avg_turn_arround_time = (avg_turn_arround_time/number_of_processes);

            printf("\n\nAverage Waiting_Time : %g units.", avg_waiting_time);
            printf("\nAverage Turnaround_Time : %g units.", avg_turn_arround_time);
        }

#endif
