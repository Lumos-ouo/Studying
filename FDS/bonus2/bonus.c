#include <stdio.h>  
#include <stdlib.h>  
#include <stdbool.h>  
#define MAX_SIZE 200000  
int n, m;  
int a[MAX_SIZE];  
int q[MAX_SIZE]; // 使用数组模拟小根堆  
int size = 0; // 堆的大小    
// 向上调整堆  
void sift_up(int k) {  
    int t = q[k];  
    while (k > 0) {  
        int parent = (k - 1) / 2;  
        if (q[parent] <= t) break;  
        q[k] = q[parent];  
        k = parent;  
    }  
    q[k] = t;  
}  
  
// 插入元素到堆  
void heap_insert(int value) {  
    if (size == MAX_SIZE) {   
        return;  
    }  
    q[size] = value;  
    sift_up(size++);  
}  
// 弹出堆顶元素  
int heap_extract_min() {  
    if (size == 0) {    
        return -1;  
    }  
    int min = q[0];  
    q[0] = q[--size]; 
    int root=0;
    int tmp = q[root];  
    for (int child = 2 * root + 1; child <= size; child = 2 * child + 1) {  
        if (child < size && q[child] > q[child + 1]) {  
            child++;  
        }  
        if (tmp <= q[child]) {  
            break;      }  
        q[root] = q[child];  
        root = child;  
    }  
    q[root] = tmp;  
    return min;  
}  
    
int compare(const void *a, const void *b) {  
    return (*(int *)a - *(int *)b);  
}  
int main() {  
    scanf("%d %d", &n, &m);  
    for (int i = 0; i < n; i++) {  
        scanf("%d", &a[i]);  
    }  
    for (int i = 0; i < m && i < n; i++) {  
        heap_insert(a[i]);  
    }  
    int idx = m;  
    int cnt = 0;  
    int now[MAX_SIZE], next[MAX_SIZE], now_size = 0, next_size = 0;  
    while (cnt < n) {  
        int t = heap_extract_min();  
        cnt++;  
        now[now_size++] = t;  
  
        if (idx < n) {  
            if (t <= a[idx]) {  
                heap_insert(a[idx++]);  
            } else {  
                next[next_size++] = a[idx++];  
            }  
        }  
        if (size==0) {  
            qsort(now, now_size, sizeof(int), compare); 
            // 输出本轮结果  
            for (int i = 0; i < now_size; i++) {  
                if (i) printf(" ");  
                printf("%d", now[i]);  
            }  
            printf("\n");    
            now_size = 0;  
            for (int i = 0; i < next_size; i++) {  
                heap_insert(next[i]);  
            }  
            next_size = 0;}  
        }  
    return 0;  
}