#include "dijkstry.hh"
#include <iostream>
#include <climits>
#include <fstream>

using namespace std;

/* Climits used for INT_MAX , there is no infinity value typr */
// We have to simulate Infinity value

const int MAXINT = 2147483647;


/*A method to find the vertex with minimum distance*/

int minimumDist(int dist[], bool Dset[], int vertex)
{

/* Initialize min with the maximum
possible value as infinity does not exist */

	int min=INT_MAX;
  int index;

	for(int v=0;v<vertex;v++)
	{
		if(Dset[v]==false && dist[v]<=min)
		{
			min=dist[v];
			index=v;
		}
	}
	return index;
}

// A body of function
// of dijkstry algorithm for the matrix representation
// src == source

void dijkstryMatrixAlgorithm(matrix *newGraph){

// Do odczytywania z pliku
newGraph->loadFromFile();

int vertexTmp = newGraph->returnVertex();
int srcTmp    = newGraph->returnSrc();

int dist[vertexTmp]; // A table for distances
bool Dset[vertexTmp];
int sptr = 0;

int *p;
int *S;
p = new int [vertexTmp];
S = new int [vertexTmp];

for(int i=0;i<vertexTmp;i++)
	{
		dist[i]=INT_MAX;
		Dset[i]=false;
		p[i] = -1;
	}
	dist[srcTmp]=0;
  for(int c=0;c<vertexTmp;c++)
  	{
  		int u=minimumDist(dist,Dset,vertexTmp);
  		Dset[u]=true;
      for(int v=0;v<vertexTmp;v++)
			{
        int tmp;
        // To find the sortest path we only need
        // graph weights dynamic table
        tmp = newGraph->graphWeights[u][v];

  			if(!Dset[v] && tmp && dist[u]!=INT_MAX && dist[u]+tmp<dist[v])
        {
  			dist[v]=dist[u]+tmp;
				p[v] = u;
        }
  		}
  	}

// Saving resaults in txt "wyniki" file

fstream plik;

plik.open("wynikiMatrix.txt",ios::out|ios::app);

if(plik.good()==true)
{

	plik<< endl;
		for(int i=0;i<vertexTmp;i++){
									 plik<<i;
									 plik<< ": ";
									 // Wyświetlamy ścieżkę, pobierając wierzchołki ze stosu
                   for(int j = i; j > -1; j = p[j]) S[sptr++] = j;
									 while(sptr) plik << S[--sptr] << " ";
									 plik<<"#"<<dist[i]<<endl;
								 }

	plik.close();
}

}
