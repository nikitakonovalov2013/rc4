#include <stdio.h>
#include <stdlib.h>

#define sz(x) (sizeof(x)/sizeof(x[0]))


int main() {

	int key[] = {1,3,19,14};
	int mod = 6;
	int z_size = 6;
	int sub[2][mod];// две строки в массиве
		
	for (int i = 0; i < 2; i++) 
		for (int j = 0; j < mod; j++)
			sub[i][j] = j;
			
	int i, j, buf;
	i = j = buf = 0;
	
	for (int t = 1; t <= mod; t++) {
		i = t - 1;
		j = (j + sub[1][i] + key[(t - 1) % (sz(key))]) % mod;
		buf = sub[1][i];
		sub[1][i] = sub[1][j];
		sub[1][j] = buf;
		
		printf("b_%i:\n", t-1);
		for (int a = 0; a < 2; a++) {
			
			for (int b = 0; b < mod; b++)
				printf("%i ", sub[a][b]);
			
			printf("\n");
		}
		printf("\n");
	}

	int z, val;
	val = i = j = buf = 0;
	
	for (int t = 1; t <= z_size; t++) {
		
		i =(i+1)%mod;
		j = (j + sub[1][i]) % mod;
		buf = sub[1][i];
		sub[1][i] = sub[1][j];
		sub[1][j] = buf;
		
		printf("s_%i:\n", t-1);
		
		for (int a = 0; a < 2; a++){
			for (int b = 0; b < mod; b++){
				printf("%i ", sub[a][b]);
			}
			printf("\n");
		}
		
		val = (sub[1][j] + sub[1][i]) % mod;
		z = sub[1][val];
		printf("Знак №%i = %i\n", t, z);
		printf("\n");
	}
	return 0;
}
