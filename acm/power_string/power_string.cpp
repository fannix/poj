#include <cstdio>
#include <cstring>

#define NMAX 1000001
char s[NMAX];

int main(){
	while(1){
		scanf("%s", s);
		if (strcmp(s, ".") == 0)
			return 0;

		int len = strlen(s);
		int half = len / 2;

		int i;
		int sucess = 0;
		for (i = 1; i <= half; i++){
			if (len % i != 0)
				continue;
			int match = 1;
			for (int k = 0; k < len - i; k++){
				if (s[k] != s[i+k]){
					match = 0;
					break;
				}
			}
			if (match){
				sucess = 1;
				printf("%d\n", len / i);
				break;
			}
		}

		if (!sucess)
			printf("1\n");

	}

	return 0;
}
