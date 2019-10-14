/*

Using Topological Sorting, find the ordering of tasks from given dependencies. There are a total of n tasks you have to pick, labelled from 0 to n-1. Some tasks may have prerequisites tasks, for example to pick task 0 you have to first finish tasks 1, which is expressed as a pair: [0, 1]
Given the total number of tasks and a list of prerequisite pairs, return the ordering of tasks you should pick to finish all tasks.
There may be multiple correct orders, you just need to return one of them. If it is impossible to finish all tasks, return an empty array.
*/

#include<iostream>
using namespace std;

int tasks[10][10],n;

void input(){
    int prev_task=0, task=0;
    cout<<"enter no. of tasks \n";
    cin>>n;
    for(int i =0;i<n;i++){
        for(int j=0;j<n;j++){
            tasks[i][j]=0;
        }
    }
    while(task != -1 || prev_task !=-1){
        cout<<"enter dependencies [task dependency]........[-1 -1] to stop\n";
        cin>>task>>prev_task;
        if(task!= -1 || prev_task!=-1)
            tasks[prev_task][task]=1;
        }
}

void topologicalOrder(){
    int indegree[10],k,stack[10],top=-1;
    for(int i=0;i<n;i++){
        indegree[i]=0;
        for(int j=0;j<n;j++){
            indegree[i] +=tasks[j][i];
        }
    }
    for(int i=0;i<n;i++){
            if(indegree[i]==0){
                stack[++top]=i;
            }
    }
    while(top!=-1 ){
            k=stack[top--];
            cout<<k<<"\t";
            indegree[k]=-1;
            for(int l=0;l<n;l++){
                if(tasks[k][l]==1){
                    indegree[l] -=1;
                    if(indegree[l]== 0)
                        stack[++top]=l;
                }
            }
    }
    cout<<"\n";
}
int main(){
    input();
    topologicalOrder();
    return 0;
}
