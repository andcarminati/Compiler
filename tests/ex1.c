int main(){
	
	int i = 2;
	int j = 5;
	
	printf("Teste de operadores:\n");

	printf("& -> ");
	if(i & i){
		printf("Certo\n");
	} else {
		printf("Errado\n");
	}

	printf("< -> ");
	if(i < j){
		printf("Certo\n");
	} else {
		printf("Errado\n");
	}

	printf("> -> ");
	if(i > j){
		printf("Errado\n");
	} else {
		printf("Certo\n");
	}

	printf("<= -> ");
	if(i <= j){
		printf("Certo\n");
	} else {
		printf("Errado\n");
	}

	printf(">= -> ");
	if(i >= j){
		printf("Errado\n");
	} else {
		printf("Certo\n");
	}

	printf("+ -> ");
	if((2 + 3) == 5){
		printf("Certo\n");
	} else {
		printf("Errado\n");
	}

	printf("- -> ");
	if((10 - 5) == 5){
		printf("Certo\n");
	} else {
		printf("Errado\n");
	}

	printf("* -> ");
	if((2 * 3) == 6){
		printf("Certo\n");
	} else {
		printf("Errado\n");
	}

}