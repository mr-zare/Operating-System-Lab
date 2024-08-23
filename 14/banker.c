#include <stdio.h>
int main()
{
	//dar hal soal baraye rahati va test,meqdar avalie be barkhi maqaadir daadam.
	int n, m;
	scanf("%d",&n);
	scanf("%d",&m);
	int allocati[5][3] = { { 0, 1, 0 },  
						{ 2, 0, 0 },  
						{ 3, 0, 2 }, 
						{ 2, 1, 1 }, 
						{ 0, 0, 2 }}; 

	int maxim[5][3] = { { 7, 5, 3 },
					{ 3, 2, 2 }, 
					{ 9, 0, 2 }, 
					{ 2, 2, 2 }, 
					{ 4, 3, 3 }}; 

	int mojod[3] = { 3, 3, 2 };
	int i,j,k;
	int fin[n], javab[n], ind = 0;
	for (k = 0; k < n; k++) {
		fin[k] = 0;
	}
	int niaz[n][m];
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++)
			niaz[i][j] = maxim[i][j] - allocati[i][j];
	}
	int y = 0;
	for (k = 0; k < 5; k++) {
		for (i = 0; i < n; i++) {
			if (fin[i] == 0) {

				int flag = 0;
				for (j = 0; j < m; j++) {
					if (niaz[i][j] > mojod[j]){
						flag = 1;
						break;
					}
				}

				if (flag == 0) {
					javab[ind++] = i;
					for (y = 0; y < m; y++)
						mojod[y] += allocati[i][y];
					fin[i] = 1;
				}
			}
		}
	}

	int flag = 1;
	
	for(int i=0;i<n;i++)
	{
	if(fin[i]==0)
	{
		flag=0;
		printf("system not safe");
		break;
	}
	}
	
	if(flag==1)
	{
	printf("system SAFE tavali\n");
	for (i = 0; i < n - 1; i++)
		printf(" P%d ->", javab[i]);
	printf(" P%d", javab[n - 1]);
	}
	return (0);
}
