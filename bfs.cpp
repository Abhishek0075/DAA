#include<iostream>
using namespace std;
class node{
public:
    int info;
    node* leftSide;
    node* rightSide;
    node(){
        leftSide=NULL;
        rightSide=NULL;
        info=0;
    }
    node(int num){
        leftSide=NULL;
        rightSide=NULL;
        info=num;
    }
};
class tree{
    node* start=NULL;
public:
    tree(int arr[],int no_element){
        for(int i=0;i<no_element;i++){
            insert_node(arr[i]);
        }
    }
    void insert_node(int num){
        node* newNode=new node(num);
        if(newNode==NULL){
            cout<<"Over Flow"<<endl;
            return;
        }
        if(start==NULL){
            start=newNode;
            return;
        }else{
            node* ptr=start;
            while(ptr!=NULL){
                if(ptr->leftSide==NULL){
                    ptr->leftSide=newNode; 
                    return;
                }else if(ptr->rightSide==NULL){
                    ptr->rightSide=newNode;
                    return;
                }else{
                    ptr=ptr->leftSide;
                }
            }
            ptr=newNode;
        }
    }
    void BFS(int no_nodes){
        list node;
        node* nodeList[no_nodes];
        node* ptr;
        count=0;
        nodeList[count]=ptr;
        while(ptr!=NULL){
            nodeList[count]
        }
    }
};
int main(){
    int insert_info,no_nodes,inserter,d,selector=1;
    cout<<"Enter the number of nodes to be created : "<<endl;
    cin>>no_nodes;
    int a[no_nodes];
    cout<<"Enter the number to be inserted in the list : "<<endl;
    for(int i=0;i<no_nodes;i++){
        cin>>a[i];
    }
    tree t(a,no_nodes);
    cout<<"Inserted nodes";
    return 0;
}