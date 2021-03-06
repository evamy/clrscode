// Max Heapify

#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

int A[10000];

int left(int i){
	return i*2;
}

int right(int i){
	return i*2+1;
}

int max_heapify(int A[], int k, int n){
	int l = left(k);
	int r = right(k);
	int largest = l;

	// cout << k << " : " << n;

	if (l<=n and A[k]>A[largest])
		largest = k;
	if(r<=n and A[r]>A[largest])
		largest = r;

	if(largest!=k){
		int temp = A[largest];
		A[largest] = A[k];
		A[k] = temp;
		// cout <<  endl;
		max_heapify(A,largest,n);
	}
	return 1;

}

int main(){
	int n, k;
	cin >> n;
	// int A[n];

	k=n;

	srand(time(NULL));

	cout << "Numbers:" << endl;

	while(k--){
		A[n-k] = rand() % n+1;
		cout << A[n-k] << endl;
	}

	max_heapify(A,1,n);

	cout << "Heapified" <<  endl;
	k=n;
	while(k--){
		cout << A[n-k] << endl;
	}

	return 0;
}