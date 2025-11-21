
//sen n rec 05.c
Program -05
#include <stdio.h>
#include <mpi.h>
int main(int argc, char *argv[])
{
    int rank, size;
    int number;
    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    if (size < 2)
    {
        if (rank == 0)
        {
            printf("This program requires at least 2 processes.\n");
        }
        MPI_Finalize();
        return 0;
    }
    if (rank == 0)
    {
        number = 100;
        printf("Process 0 is sending number %d to Process 1\n", number);
        MPI_Send(&number, 1, MPI_INT, 1, 0, MPI_COMM_WORLD);
    }
    else if (rank == 1)
    {
        // Process 1 receives a number from Process 0
        MPI_Recv(&number, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        printf("Process 1 received number %d from Process 0\n", number);
    }
    MPI_Finalize();
    return 0;
}
 //Program -06
#include <mpi.h>
#include <stdio.h>

int main(int argc, char** argv) {
    int rank, size, data = 0;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    if (size < 2) {
        if (rank == 0) printf("This program requires at least 2 processes.\n");
        MPI_Abort(MPI_COMM_WORLD, 1);
    }

    if (rank == 0) printf("\n---- Deadlock Demonstration ----\n");

    if (rank == 0) {
        MPI_Send(&data, 1, MPI_INT, 1, 0, MPI_COMM_WORLD);
        printf("Process 0 sent data to Process 1 (deadlock)\n");
        MPI_Recv(&data, 1, MPI_INT, 1, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        printf("Process 0 received data from Process 1 (deadlock)\n");
    } else if (rank == 1) {
        MPI_Send(&data, 1, MPI_INT, 0, 0, MPI_COMM_WORLD);
        printf("Process 1 sent data to Process 0 (deadlock)\n");
        MPI_Recv(&data, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        printf("Process 1 received data from Process 0 (deadlock)\n");
    }

    MPI_Barrier(MPI_COMM_WORLD); 

    if (rank == 0) printf("\n---- Deadlock Avoidance ----\n");

    if (rank == 0) {
        MPI_Send(&data, 1, MPI_INT, 1, 0, MPI_COMM_WORLD);
        printf("Process 0 sent data to Process 1 (avoidance)\n");
        MPI_Recv(&data, 1, MPI_INT, 1, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        printf("Process 0 received data from Process 1 (avoidance)\n");
    } else if (rank == 1) {
        MPI_Recv(&data, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        printf("Process 1 received data from Process 0 (avoidance)\n");
        MPI_Send(&data, 1, MPI_INT, 0, 0, MPI_COMM_WORLD);
        printf("Process 1 sent data to Process 0 (avoidance)\n");
    }

    MPI_Finalize();
    return 0;
}

//broad 07.c
#include <stdio.h>
#include <mpi.h>

int main(int argc, char** argv)
{
    int rank, data = 0;
    MPI_Init(&argc, &argv);                 
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);    

    if (rank == 0)
        data = 100;     
    MPI_Barrier(MPI_COMM_WORLD);
    printf("BEFORE the broadcast, process %d's data = %d\n", rank, data);
    fflush(stdout);
    MPI_Bcast(&data, 1, MPI_INT, 0, MPI_COMM_WORLD);  
    MPI_Barrier(MPI_COMM_WORLD);
    printf("AFTER the broadcast, process %d's data = %d\n", rank, data);
    fflush(stdout);
    MPI_Finalize();  
    return 0;
}

//program 08 – 
#include <stdio.h>
#include <mpi.h>

int main(int argc, char** argv) 
{
    int rank, size;
    int send_data[4] = {10, 20, 30, 40};
    int recv_data;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    MPI_Scatter(send_data, 1, MPI_INT, &recv_data, 1, MPI_INT, 0, MPI_COMM_WORLD);
    printf("Process %d received: %d\n", rank, recv_data);
    MPI_Gather(&recv_data, 1, MPI_INT, send_data, 1, MPI_INT, 0, MPI_COMM_WORLD);
    if (rank == 0) {
        printf("Gathered data: ");
        for (int i = 0; i < size; i++)
            printf("%d ", send_data[i]);
        printf("\n");
    }

    MPI_Finalize();
    return 0;
}
