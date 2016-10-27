#include <iostream>
using namespace std;
int findset(int parent[],int i);
void link(int parent[],int rank[],int i,int j);
void un(int parent[],int rank[],int i,int j){
	link(parent,rank,findset(parent,i),findset(parent,j));
}
void link(int parent[],int rank[],int i,int j){
	if(i==j)
		return;
	if(rank[i]>rank[j]){
		parent[j] = i;
	}
	else{
		parent[i]=j;
		if(rank[i]==rank[j])
			rank[j]++;
	}
}
int findset(int parent[],int i){
	if(parent[i]!=i)
		parent[i] = findset(parent,parent[i]);
	return parent[i];
}
int main() {
	// your code goes here
	int n;
	cin>>n;
	int parent[n],rank[n];
	for(int i=0;i<n;i++){
		parent[i]=i;
		rank[i]=0;
	}
	un(parent,rank,0,1);
	un(parent,rank,1,2);
	un(parent,rank,4,5);
	for(int i=0;i<n;i++){
		cout<<parent[i]<<" "<<rank[i]<<endl;
	}
	
	return 0;
}
