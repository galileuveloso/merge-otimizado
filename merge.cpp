void insertionSort(int * arr, int n) {
  for (int i = 1; i < n; i++) {
    int tmp = arr[i];
    int j = i - 1;

    
    while (tmp < arr[j] && j >= 0) {
      arr[j + 1] = arr[j];
      --j;
    }
    arr[j + 1] = tmp;
  }
}

void merge(int * a, int l, int m, int r)
{
	int i,j,k;
	int *aux;
	
	aux = (int *) malloc(sizeof(int) * r+1);
	
	for(k=l; k<=r; k++)
	{
		if(aux[j] < aux[i])
			a[k] = aux[j--];
	else
		a[k] = aux[i++];
	}
}

void mergesort(int * a, int*aux, int l, int r){
	if(l < r-1){
		if(l < 10)
			insertionSort(a, l); //insertion sort em arrays menors que 10
		else
			mergesort(aux, a, l, r);	//passo o aux pra evitar a copia deles 
		if(r < 10)
			insertionSort(a, r);
		else
			mergesort(aux, a, (l/2 +1),r);
		int q = (l + r) / 2;
	
		if(a[q] <= a[q+1]) return;	//impede o merge desnecessario
		merge(a, l, q, r);
	}
}
