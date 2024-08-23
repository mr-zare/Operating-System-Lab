 #include <stdio.h>
struct process 
{   
    int id,st,wt,tt;
};
int main(){
    int n;
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
    }
    int i,j;
    struct process tmp;
    for (i = 0; i < n - 1; i++){
        for (j = 0; j < n - i - 1; j++){
            if (a[j].st>a[j+1].st){
                tmp=a[j];
                a[j]=a[j+1];
                a[j+1]=tmp;
            }
        }
    }
    int time = 0;
    int wait = 0;
    for (int i=0 ; i<n ; i++){
        wait += time;
        a[i].wt=time;
        time += a[i].st;
        a[i].tt = a[i].wt + a[i].st;
        printf("process number %d had waited for %d seconds and had total time of %d seconds\n",a[i].id,a[i].wt,a[i].tt);
    }
    printf("the average waiting time is %d\n",wait/n);
    return 0;
}