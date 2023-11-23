#include<stdio.h>


struct Procedure {
    int Proc, at, bt, tt, wt;
};


struct Procedure p[10];


void sort(int);


void calculate(int);

int main() {
    int n;

   
    printf("Enter the number of processes you want to enter:\t");
    scanf("%d", &n);

   
    printf("Enter your Process Number, Arrival time, Burst Time\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &p[i].Proc);
        scanf("%d", &p[i].at);
        scanf("%d", &p[i].bt);
    }

    
    printf("PROCEDURE\tAT\tBT\n");
    for (int i = 0; i < n; i++)
        printf("P%d\t\t%d\t%d\n", p[i].Proc, p[i].at, p[i].bt);

    
    sort(n);

    
    calculate(n);

    
    printf("PROCEDURE\tAT\tBT\tTT\tWT\n");
    for (int i = 0; i < n; i++)
        printf("P%d\t\t%d\t%d\t%d\t%d\n", p[i].Proc, p[i].at, p[i].bt, p[i].tt, p[i].wt);

    return 0;
}


void sort(int n) {
    struct Procedure temp;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (p[i].at > p[j].at) {
                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }

    
    printf("SORTED\n\nPROCEDURE\tAT\tBT\n");
    for (int i = 0; i < n; i++)
        printf("P%d\t\t%d\t%d\n", p[i].Proc, p[i].at, p[i].bt);
}


void calculate(int n) {
    p[0].tt = p[0].at + p[0].bt;
    for (int i = 1; i < n; i++) {
        if (p[i].at < p[i - 1].tt)
            p[i].tt = p[i].bt + p[i - 1].tt;
        else
            p[i].tt = p[i].bt + (2 * p[i - 1].tt - p[i].at);
    }

   
    double avgtt = 0, avgwt = 0;
    for (int i = 0; i < n; i++) {
        p[i].tt = p[i].tt - p[i].at;
        p[i].wt = p[i].tt - p[i].bt;
        avgtt += p[i].tt;
        avgwt += p[i].wt;
    }

   
    printf("Average TT is %f and Average WT is %f\n", avgtt / n, avgwt / n);
}
