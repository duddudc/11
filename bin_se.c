#include <stdio.h>
#include <stdlib.h>

int bin_search(const int a[], int n, int key)
{
	int pl=0;
	int pr=n-1;
	int pc;
	
	do{
		pc=(pl+pr)/2;
		if(a[pc]==key)
			return pc;
		else if(a[pc] < key)
			pl =pc +1;
		else
			pr = pc -1;
	} while(pl <= pr);
	
	return -1;
}

int main()
{
	int i, nx, ky, idx, s;
	int *x;
	
	printf("=====================\n");
	printf("입력할 개수 : ");
	scanf("%d", &nx);
	x= calloc(nx, sizeof(int));
	
	printf("\n\n오름차순으로 입력하세요.\n\n");
	printf("x[0] : ");
	scanf("%d",&x[0]);
	
	for (i = 1; i < nx; i++) {
		do {
			printf("x[%d] : ", i);
			scanf("%d", &x[i]);
		} while (x[i] < x[i - 1]);	
	}
	printf("\n검색 값 : ");
	scanf("%d", &ky);

	idx = bin_search(x, nx, ky);	
	
	if(idx == -1)
		printf("검색에 실패했습니다.\n\n");
	else
		printf("%d는 x[%d]에 있습니다.\n\n", ky, idx);
	
	printf("다시 검색할까요? (1)예 / (0)아니오 : ");
	scanf("%d", &s);
	
	while(s==1){
		printf("\n검색 값 : ");
		scanf("%d", &ky);
		
		idx = bin_search(x, nx, ky);
		
	if(idx == -1)
		printf("검색에 실패했습니다.\n");
	else
		printf("%d는 x[%d]에 있습니다.\n", ky, idx);
	
	printf("\n다시 검색할까요? (1)예 / (0)아니오 : ");
	scanf("%d", &s);
	}
	
	if(s==0){
		free(x);	
		return 0;
	}
	
	
}
