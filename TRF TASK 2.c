#include <stdio.h>
#define INFINITY 15
#define n 9
#define s 8
#define d 3
#define vv 3
#define NILL -1
void graph(int adjmatrix[n][n]);
int adjmatrix[n][n];
int n1,s1,d1;
int MinDistance(int*, int*);
void PrintPath(int*, int);


void Dijkstra(int adjmatrix[n][n], int n1, int s1, int d1)
{

	int i, u, v, count;
	int dist[n];
	int visited[n] = { 0 };
	int pathlength[n] = { 0 };
	int parent[n];
	parent[s1] = NILL;


	for (i = 0; i < n; i++)
		dist[i] = INFINITY;

	dist[s1] = 0;
	for (count = 0; count < n - 1; count++) {
		u = MinDistance(dist, visited);

		if (u == INFINITY)
			break;
		else {
			visited[u] = 1;
			for (v = 0; v < n; v++) {
				if (!visited[v] && adjmatrix[u][v]
					&& dist[u] + adjmatrix[u][v] < dist[v]) {
					parent[v] = u;
					pathlength[v] = pathlength[parent[v]] + 1;
					dist[v] = dist[u] + adjmatrix[u][v];
				}
				else if (!visited[v] && adjmatrix[u][v]
						&& dist[u] + adjmatrix[u][v] == dist[v]
						&& pathlength[u] + 1 < pathlength[v]) {
					parent[v] = u;
					pathlength[v] = pathlength[u] + 1;
				}
			}
		}
	}

	if (dist[d1] != INFINITY)
		PrintPath(parent, d1);
	else
		printf("There is no path between vertex %d to vertex %d",s,d);

}

int MinDistance(int* dist, int* visited)
{
	int min = INFINITY, min_index, v;
	for (v = 0; v < n; v++)
		if (!visited[v] && dist[v] < min) {
			min = dist[v];
			min_index = v;
		}
	return min == INFINITY ? INFINITY : min_index;
}


void PrintPath(int* parent, int d1)
{
	if (parent[d1] == NILL) {
		 printf("%d",d1);
		 return;
	}
	PrintPath(parent, parent[d1]);
	printf("->%d",d1);
}


int main()
{
    char maze[vv][vv],val=1;
    int i,j;
    printf("Enter the maze");
    for( i=0;i<vv;i++)
    {
        for( j=0;j<vv;j++)
        {
            scanf("%c",&maze[i][j]);
        }
    }
    printf("\n");

    for( i=0;i<n;i++)
    {
        for( j=0;j<n;j++)
        {
            if(i==j)
            {
                adjmatrix[i][j]=0;
            }
            else
            {
              adjmatrix[i][j]=INFINITY;
            }
        }
    }

    printf("Start point is = %d\n",s);
    printf("End point is = %d\n",d);

    for( i=0;i<vv;i++)
    {
       for( j=0;j<vv;j++)
       {
           printf("%d.%c\t ",val,maze[i][j]);
           val++;
       }
       printf("\n");
    }
    printf("\n\n");

    graph(adjmatrix);

    Dijkstra(adjmatrix, n, s, d);

    return 0;
}
void graph(int adjmatrix[n][n])
{
    int count,origin,destin,weight,i,vertex;
    printf("Enter the number of vertices");
    scanf("%d",&vertex);
    count=vertex*(vertex-1);

    for ( i=0;i<count;i++)
    {
        printf("Do not include the edge which includes obstacle\n");
        printf("Enter the origin vertex or press -1 to exit\n");
        scanf("%d",&origin);
        if(origin==-1)
        {
            break;
        }

        printf("Enter the destiation point\n");
        scanf("%d",&destin);

        printf("Enter the weight\n");
        scanf("%d",&weight);

        if(origin>=vertex || origin<0 || destin>=vertex || destin<0)
        {
            count--;
        }
        else
        {
            adjmatrix[origin][destin]=weight;
            adjmatrix[destin][origin]=weight;
        }
    }

}
