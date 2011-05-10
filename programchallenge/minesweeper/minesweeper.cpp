#include <cstdio>
using namespace std;

#define NMAX 102
#define MMAX 102
int a[MMAX][NMAX];

void init(int m,  int n){
	for (int i = 0; i <= m; i++)
		for (int j = 0; j <= n; j++)
			a[i][j] = '.';
}

int main(){
	init(MMAX - 1, NMAX - 1);
	int m, n;
	int nfield = 0;
	while (scanf("%d %d\n", &m, &n) != EOF){
		if (m == 0 && n == 0)
			return 0;
		nfield++;
		if (nfield != 1)
			printf("\n");

		for (int i = 1; i <= m; i++){
			for (int j = 1; j <= n; j++){
				scanf("%c", &a[i][j]);
			}
			getchar();
		}

		for (int i = 1; i <= m; i++){
			for (int j = 1; j <= n; j++){
				if (a[i][j] == '*')
					continue;
				else 
					a[i][j] = (a[i-1][j-1] == '*')
						+ (a[i-1][j] == '*')
						+ (a[i-1][j+1] == '*')
						+ (a[i][j-1] == '*')
						+ (a[i][j+1] == '*')
						+ (a[i+1][j-1] == '*')
						+ (a[i+1][j] == '*')
						+ (a[i+1][j+1] == '*');
			}
		}

		printf("Field #%d:\n", nfield);
		for (int i = 1; i <= m; i++){
			for (int j = 1; j <= n; j++){
				if (a[i][j] == '*')
					printf("*");
				else
					printf("%d", a[i][j]);
				
			}
			printf("\n");
		}


		init(m, n);

	}
	return 0;
}
