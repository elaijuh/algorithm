#include <stdio.h>

void shell_sort(int v[], int n) {
    int gap, i, j, temp;
    for (gap=n/2; gap>0; gap/=2) {
        for (i=gap; i<n; i++) {
            for (j=i-gap; j>=0 && v[j]>v[j+gap]; j-=gap) {
                temp=v[j];
                v[j]=v[j+gap];
                v[j+gap]=temp;
            }
        }
    }
}

// demo
int main() {
    int v[] = {3,4,11,65,4,19,345,12,435,6};
    shell_sort(v, 10);
    for (int i=0; i<10; i++) printf("%d ", v[i]);
}
