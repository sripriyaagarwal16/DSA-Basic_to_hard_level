void heapSort(int pq[], int n) {
	// Build the heap in input array
	for(int i = 1; i < n; i++) {
		
		int childIndex = i;
		while(childIndex > 0) {
			int parentIndex = (childIndex - 1) / 2;

			if(pq[childIndex] < pq[parentIndex]) {
				int temp = pq[childIndex];
				pq[childIndex] = pq[parentIndex];
				pq[parentIndex] = temp;
			}
			else {
				break;
			}
			childIndex = parentIndex;
		}
	}

	// Remove elements

	int size = n;

	while(size > 1) {
		int temp = pq[0];
		pq[0] = pq[size - 1];
		pq[size-1] = temp;

		size--;

		int parentIndex = 0;
		int leftChildIndex = 2 * parentIndex + 1;
		int rightChildIndx = 2 * parentIndex + 2;

		while(leftChildIndex < size) {
			int minIndex = parentIndex;
			if(pq[minIndex] > pq[leftChildIndex]) {
				minIndex = leftChildIndex;
			}
			if(rightChildIndx < size && pq[rightChildIndx] < pq[minIndex]) {
				minIndex = rightChildIndx;
			}
                        if (minIndex == parentIndex) {
                                break;
                        }
                        int temp = pq[minIndex];
                        pq[minIndex] = pq[parentIndex];
                        pq[parentIndex] = temp;

                        parentIndex = minIndex;
                        leftChildIndex = 2 * parentIndex + 1;
                        rightChildIndx = 2 * parentIndex + 2;
                }
        }
 }

int kthLargest(vector<int>&arr, int k) {
    // Write your code here
    int n =arr.size();
    int input[n];
    for(int i =0;i<n;i++){
        input[i]=arr[i];
    }
    heapSort(input, n);
   
       return input[k-1];
   
}
int main(){
    vector<int>arr;
    int k ;
    cout<<"enter the value of k"<<endl;
    cin>>k;
    kthLargest(arr,k);

}