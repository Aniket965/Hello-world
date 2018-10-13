#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void print_dijkstra(vector<pair<int, int>>* vetor, int n_estations, int* distance, int caso){
    cout << "caso " << caso << endl;
    bool flag = true;
    for(int i = 0; i < n_estations; i++){
        if(vetor[i].size() != 2){
           if(flag){
            cout << distance[i];
            flag = false;
           }
           else
            cout << " ";
            cout << distance[i];
        }
    }
    cout << endl;
    cout << endl;
}
int search_begin(vector<pair<int,int>>* vetor){
    int i = 0;
    while(vetor[i].size() == 2){
        i++;
    }
    return i;
}
void dijkstra(vector<pair<int, int>>* vetor, int n_estations, int begin, int caso){
    int distance[n_estations];
    int f[n_estations];
    for(int i = 0; i < n_estations; i++){
        distance[i] = 100000;
        f[i] = -1;
    }
    distance[begin] = 0;
    priority_queue <pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> rip;
    rip.emplace(0,begin);
    while(!rip.empty()){
         pair<int, int>extract;
         extract = rip.top();
         rip.pop();
         int toddynho = extract.second;

         for(auto nesquik: vetor[toddynho]){

             int vertice = nesquik.first; // vertice
             int aresta = nesquik.second; //distancia
             if((distance[toddynho] + aresta) < distance[vertice]){

                 distance[vertice] = distance[toddynho] + aresta;
                 rip.emplace(distance[vertice], vertice);
                 f[vertice] = toddynho;
             }
         }
    }
     print_dijkstra(vetor, n_estations, distance, caso);
}

int main(void){
    int n_estations, m_conetions, u, v, d, begin, caso = 0; // n = número total de estações, sejam paradas ou terminais, englobando todas as linhas
    // m = = número total de conexões (bidirecionais) entre estações "vizinhas"
    //uj vj = indica uma conexão entre as estações uj e vj, para 0<=uj<vj<N.
    //dj = indica a distância entre as estações consecutivas uj e vj, para 0<=uj<vj<N.
    vector<vector<int> > matrix;
    
    while(scanf("%d %d", &n_estations, &m_conetions) != EOF){

        vector<pair<int, int>> vetor[n_estations];

        for(int i = 0; i < m_conetions; i++){
            cin >> u;
            cin >> v;
            cin >> d; 
            vetor[u].push_back(make_pair(v, d));
            vetor[v].push_back(make_pair(u, d));
        }
        begin = search_begin(vetor);
        dijkstra(vetor, n_estations, begin, caso);
        caso ++;
    }
}