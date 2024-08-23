 #include <stdio.h>
struct process 
{   
    int id,st,wt,tt,done;
};
int main(){
    int n,q;
    printf("enter number of processes\n");
    scanf("%d" , &n);
    struct process a[n];
    // a is the list of the processes
    for (int i=0 ; i<n ; i++){
        int tmp;
        printf("enter service time of process %d\n",i+1);
        scanf("%d",&tmp);
        a[i].st=tmp;    
        a[i].id=i+1;
        a[i].tt += tmp;
        a[i].wt=0;
    }
    printf("enter time quantum\n");
    scanf("%d", &q);
    int time = 0;
    int wait = 0;
    int done = 0;
    int i = 0;
    while (done != n){
        if (a[i].done == 1)
            goto there;
        if (q <= a[i].st){
            a[i].st -= q;
            printf("process number %d is serviced for %d seconds\n",a[i].id,q);
            for (int j=0 ; j<n ; j++){
                if (j != i  && a[j].done!=1)
                    a[j].wt += q;
            }
        }
        else{
            printf("process number %d is serviced for %d seconds\n",a[i].id,a[i].st);
            for (int j=0 ; j<n ; j++){
                if (j != i && a[j].done!=1)
                    a[j].wt += a[i].st;
            }
            a[i].st=0;
        }
        if (a[i].st == 0 && a[i].done!=1){
            done += 1;
            a[i].done = 1;
        }
        there:
        i += 1;
        if (i==n)
            i=0;
    }
    for (int i=0 ; i<n ; i++){
        printf("process number %d had waited for %d seconds\n",i+1,a[i].wt);
        wait+=a[i].wt;
    }
    printf("the average waiting time is %d\n",wait/n);
    return 0;
}