#include <stdlib.h>
#include <stdio.h>

void merge(int arr[], int l, int m, int r) {
    int L[m-l+1];
    int R[r-m];

    for(int i=0; i<(m-l+1); i++) {
        L[i] = arr[l+i];
    }
    for(int j=0; j<(r-m); j++) {
        R[j] = arr[m+1+j];
    }

    int i=0, j=0, k=l;

    while((i < (m-l+1)) && (j < (r-m))) {
        if(L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while(i<(m-l+1)) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while(j<(r-m)) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r) {
    if(l < r) {
        mergeSort(arr, l, (l+(r-l)/2));
        mergeSort(arr, (l+(r-l)/2)+1, r);
        merge(arr, l, (l+(r-l)/2), r);
    }
}

int main() {
    int data[] = {1,9,2,8,3,7,4,6,5};
    for(int i=0; i<9; i++) {
        printf("%d", data[i]);
    }
    printf("\n");
    mergeSort(data, 0, (sizeof(data)/sizeof(data[0])) - 1);
    for(int i=0; i<9; i++) {
        printf("%d", data[i]);
    }
    printf("\n");
    return 0;
}
