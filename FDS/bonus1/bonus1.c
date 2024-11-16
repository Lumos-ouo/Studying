#include <stdio.h>  
#include <stdlib.h>   
#define N 100000  
int pos1[N], pos2[N]; // pos1/2[i]分别统计i在q1和q2两个队列中的有效位置  
int vis[N]; // vis[i]统计i在第一个队列中被几次命中  
int idx = 0;   
typedef struct {  
    int val;  
    int idx;  
} Elem;    
Elem q1[N], q2[N]; // 使用数组模拟队列  
int front1 = 0, rear1 = 0; // q1队列的头和尾  
int front2 = 0, rear2 = 0; // q2队列的头和尾  
int t1 = 0, t2 = 0; // t1,t2分别记录q1和q2两个队列中的有效元素个数  
void enqueue1(int val,int idx) {  
    q1[rear1].val = val;  
    q1[rear1].idx = idx;  
    rear1 = (rear1 + 1) % N; // 循环队列  
}   
void dequeue1() {  
    front1 = (front1 + 1) % N;  
}  
Elem* front1_elem() {  
    return &q1[front1];  
}  
 void enqueue2(int val,int idx) {  
    q2[rear2].val = val;  
    q2[rear2].idx = idx;  
    rear2 = (rear2 + 1) % N; // 循环队列  
}  
void dequeue2() {  
    front2 = (front2 + 1) % N;  
}   
Elem* front2_elem() {  
    return &q2[front2];  
}    
int main() {  
    int k, n, m;  
    scanf("%d %d %d", &k, &n, &m);  
    for (int i = 0; i < m; i++) {  
    while (t1 > n) {  
        Elem* e = front1_elem();
        dequeue1(); 
        if(pos1[e->val] == e->idx)
		{
			t1--;
            vis[e->val]=0;
			pos1[e->val]=0;
		}
    }  
      while (t2 > n ) {  
        Elem* e = front2_elem();
        dequeue2(); 
        if(pos2[e->val] == e->idx)
		{
			t2--;
			pos2[e->val]=0;
		}  
    }  
        int x;  
        scanf("%d", &x);  
  
        if (pos2[x]) { // 在第二个队列里面  
            pos2[x] = ++idx;  
            enqueue2(x,idx);  
        } else if (pos1[x]) { // 在第一个队列里面  
            vis[x]++;  
            if (vis[x] == k) {  
                pos1[x] = 0; // 将其从队列1中移除  
                t1--;
                vis[x] = 0; // 将其在队列1中出现次数设置为0  
                pos2[x] = ++idx; // 加入队列2中  
                t2++;
                enqueue2(x,idx);  
                  
            } else {  
                pos1[x] = ++idx;  
                enqueue1(x,idx);  
            }  
        } else { // 既不在队列1里面，也不在队列2里面，就将其加入至队列1  
            vis[x]++;  
            pos1[x] = ++idx;  
            t1++;  
            enqueue1(x,idx);  
        }  
    }  
    while (t1 > n) {  
        Elem* e = front1_elem();
        dequeue1(); 
        if(pos1[e->val] == e->idx)
		{
			t1--;
            vis[e->val]=0;
			pos1[e->val]=0;
		}
    }  
    while (t2 > n ) {  
        Elem* e = front2_elem();
        dequeue2(); 
        if(pos2[e->val] == e->idx)
		{
			t2--;
			pos2[e->val]=0;
		}  
    }  
    if (!t1) printf("-");  
    else {  
        while (t1) {  
            Elem* e = front1_elem(); 
            dequeue1(); 
            if (pos1[e->val] == e->idx) {  
                printf("%d", e->val);  
                t1--;
                if (t1) printf(" ");  
            }  
        }  
    }  
    printf("\n");  
  
    if (!t2) printf("-");  
    else {  
        while (t2) {  
            Elem* e = front2_elem();
            dequeue2(); 
            if (pos2[e->val] == e->idx) {  
                printf("%d", e->val);  
                t2-- ; 
                if (t2) printf(" ");  
            }  
        }  
    }  
    printf("\n"); 
    return 0;
}