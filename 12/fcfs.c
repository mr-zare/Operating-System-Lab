 #include <stdio.h>
struct process 
{
    int st,wt,tt;
};
int main(){
    int n;
    printf("input num processes\n");
    scanf("%d" , &n);
    struct process a[n];
    for (int i=0 ; i<n ; i++){
        int tmp;
        printf("input service_time process %d\n",i+1);
        scanf("%d",&tmp);
        a[i].st=tmp;
    }
    int time = 0;
    int wait = 0;
    for (int i=0 ; i<n ; i++){
        wait += time;
        a[i].wt=time;
        time += a[i].st;
        a[i].tt = a[i].wt + a[i].st;
        printf("process n %d  waited for %d s and  total time  %d s \n",i+1,a[i].wt,a[i].tt);
    }
    printf(" average waiting time is %d\n",wait/n);
    return 0;
}