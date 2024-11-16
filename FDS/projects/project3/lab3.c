#include<stdio.h>
#include<stdlib.h>
int g[1001][1001];    //Define a two-dimensional array//
int Dijkstra(int g[][1001],int n, int a[]){   //The Dijkstra algorthim//
    int dis[n+1];        // Array of distances from storage point to source  //
    int set[n+1];        // Set of inculded the vertex //
    int i,j,index=0; 
    for(i=1;i<=n;i++){
        dis[i]=65535;     // Initialize the array//
        set[i]=0;         // Initialize the set//
    }
    dis[a[index]]=0;      //a[index] is the source vertex//
    for(i=0;i<n;i++){
        for(j=1; j<=n;j++){
            if(!set[j]){    // If j is not included//
                if(dis[a[index]]>dis[j]){         //Compare the element with j//
                    return 0;            // False//
                }
            }
        }
        set[a[index]]=1;     // The vertex is included in the set//
        for(j=1;j<=n;j++){
            if(dis[j]>dis[a[index]]+g[a[index]][j]){
                dis[j]=dis[a[index]]+g[a[index]][j];    //Update the distance from the vertex to the source//
            }
        }
        index++;
    }
    return 1;  // True//
}
int main()
{
    int Nv,Ne;  
    scanf("%d",&Nv);
    scanf("%d",&Ne);
    // Input the value of vertex and edge//
    int i,j;
    for(i=1;i<=Nv;i++){
    for(j=1;j<=Nv;j++){
        g[i][j]=65535;   //Initialize the two-dimensional array//
        }
        }
    for(i=0;i<Ne;i++){
        int v1,v2,c;
        scanf("%d %d %d",&v1,&v2,&c);
        g[v1][v2]=c; 
        g[v2][v1]=c;    // Insert the edge//
        }
    int a[Nv];   //Array to store Data//
    int n;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        for(j=0;j<Nv;j++){
        scanf("%d",&a[j]);      // Input data //
        }
        if(Dijkstra(g,Nv,a)){   // Use funtion to judge//
        printf("Yes\n");
        }
        else{
        printf("No\n");     // Print the outputs//
        } 
        }
        system("pause");
    return 1;
}