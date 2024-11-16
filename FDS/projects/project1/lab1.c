#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// 算法一：暴力遍历


int algorithms1(int a[],int c,int n){
	int i,j,flag=0;	          //flag标记是否找到
	for(i=0;i<n-1;i++){
		for(j=i+1;j<n;j++){
			if( a[i]+a[j]==c){
				flag=1;        //找到时flag值变为1
				
				break;       
			}
		}
       if(flag==1){
			break;       //找到就退出
		}
	}
	
		  //没找到
	return 0;
}

//算法二：排序后运用二分查找
int cmp(const void* p, const void* q){  // qsort()的外部自定义比较函数
    return ((int*)p)[0] - ((int*)q)[0];}


int algorithms2(int a[],int c,int n){
	 qsort(a, n, sizeof(a[0]), cmp);     // 运用qsort()按值排序
     int i,mid,left,right,flag=0;
	 for(i=0;i<n;i++)
	  { 
		 left=i;
		 right=n-1;
	 while(left<=right){    //二分查找
         mid=(left+right)/2;
	    if((c-a[i])>a[mid]){    //值偏大
         left=mid+1;
	     }
	  else if((c-a[i])<a[mid]){   //值偏小
		right=mid-1;
	  }
	  else{                     //找到了
		flag=1;
		
		break;
}
	 }
	 if(flag==1){
		break;
	 }}
	 
	       
		   //遍历结束，没找到
        return 0;
}
// 主程序

clock_t start,stop;
double duration,total;

int main(void)
{
  	int v,i,c,n=0;
	scanf("%d",&n); //输入n
	v=2*n;
	int a[n];
	srand((unsigned int)time(NULL));   //生成随机数
	
	for(i=0;i<n;i++){
		a[i]=10*rand()%v;
	    
	
	     //%v确保随机数小于	
	}
	
	start=clock();      //设置开始时间
	
	for(i=0;i<200;i++){    //运行200次
	  c=10*rand()%v;
	  algorithms1(a,c,n);
	    }

	stop=clock();      //记录结束时间
	total=((double)(stop-start))/CLK_TCK;  //统计total
	duration=total/200;     //计算duration
	printf(" %f %f\n",total,duration);    //输出算法一的运行时间
	
	start=clock();    //设置开始时间
	
	for(i=0;i<200;i++){    //运行200次
		c=10*rand()%v;
	    algorithms2(a,c,n);
		}

	stop=clock();    //记录结束时间
	total=((double)(stop-start))/CLK_TCK;    //统计total
	duration=total/200;              //计算duration
	printf("\n%f %f",total,duration);    //输出算法二的运行时间
	
	return 0;
}


