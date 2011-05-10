#include <cstdio>
#include <cmath>
#include <cstring>
#include <cstdlib>

typedef int (*hash) (char * s);

#define BUFSIZE 1000
#define BITSIZE 1000
int bitvector[BITSIZE] = {0};
int m = sizeof(bitvector) * 8;

int hash1(char * s){
	int v = 0;

	for (char * p = s; *p != '\0'; p++){
		v += *p;
	}

	v = v % m;

	return v;
}

int hash2(char * s){
	int v = 0;

	for (char * p = s; *p != '\0'; p++){
		v += *p;
		v += 1;
	}

	v = v % m;

	return v;
}

hash hash_functions[] = {
	hash1,
	hash2,
};

void set_bit(int i){
	int n = i / (sizeof(bitvector[0]) * 8);
	int offset = i % (sizeof(bitvector[0]) * 8);
	bitvector[n] |= 1 << offset;
}

int main(){
	char input[BUFSIZE] = {0};
	while(fgets(input, BUFSIZE-1, stdin) != NULL){
		input[strlen(input) - 1] = '\0';
		printf("%s", input);
		int size = sizeof(hash_functions) / sizeof(hash_functions[0]);
		for (int i = 0; i < size; i++){
			printf("index : %d\n", hash_functions[i](input));
			set_bit(hash_functions[i](input));
		}
		for (int i = 0; i < sizeof(bitvector)/sizeof(bitvector[0]); i++)
			printf("bits : %x\n", bitvector[i]);
		}
	return 0;
}

