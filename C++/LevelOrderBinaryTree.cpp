#include<iostream>
#include <stack>
#include<queue>
#include<vector>
using namespace std;

class Node{
    public:
    int data;
    Node * left;
    Node * right;
    
    Node(int d,Node* left, Node * right){
        data=d;
        left=left;
        right=right;
    }
};
void display(Node * root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<"  ";
    display(root->left);
    display(root->right);
}

void LevelOrder(Node * root){
    
    queue<Node * > q;
    q.push(root);

    while(!q.empty()){
        int size=q.size();
        for(int i=0;i<size;i++)
        {
            Node * fr=q.front();
        
        
        q.pop();
        cout<<fr->data<<" ";
            if(fr->left!=NULL){
                q.push(fr->left);
            }
            if(fr->right!=NULL){
                q.push(fr->right);
            }

        }
        cout<<endl;
        

    }


}
int main(){
    int arr[]={ 10, 20, 30,-1,-1,1,-1,-1,11,-1,-1};
    int n = sizeof(arr) / sizeof(arr[0]);
 
    vector<int> vect(arr, arr + n);

    stack <pair<Node *,int> > st;
    Node * rp=new Node(arr[0],NULL,NULL);

    pair<Node *,int> rpair=make_pair(rp,1);
    st.push(rpair);
    int i=0;
    while(!st.empty()){

        pair<Node *,int> topp=st.top();
            st.pop();
        if(topp.second==1){
            topp=make_pair(topp.first,topp.second+1);
            st.push(topp);
            i++;
            if(arr[i]!=-1){
            Node * newnode= new Node(arr[i],NULL,NULL);
            topp.first->left=newnode;
            pair<Node * ,int> pp=make_pair(newnode,1);
        
            
                st.push(pp);
            }
            else{
                topp.first->left=NULL;
            }
                //top.second++;
        }
        else if(topp.second==2){
            topp=make_pair(topp.first,topp.second+1);
            st.push(topp);
             i++;
            if(arr[i]!=-1){
            Node * rnewnode= new Node(arr[i],NULL,NULL);
            topp.first->right=rnewnode;
            pair<Node * ,int> pp=make_pair(rnewnode,1);
        
            
                st.push(pp);
            }
            else{
                
                topp.first->right=NULL;
            }
           
        }
        else{
            st.pop();
        }

    }

//display(rp);
LevelOrder(rp);
return 0;
}
