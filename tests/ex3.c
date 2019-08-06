
int fatorial(int n){

	if(n <= 0){
		return 1;
	} else {
		printf("%d\n", n);
		return n * fatorial(n-1);
	}

}

int main(){
	

	int m = fatorial(5);
	
	printf("Fatorial de 5 => %d\n", m);
	
}