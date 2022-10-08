//Using First Approach
#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node* left,right;
}
Node* newNode(int x){
    Node* node=new Node;
    node->data=x;
    node->left=node->right=NULL;
    return node;
}
Node* buildTree(string str){
    if(str.length()==0 || str[0]=='N')return NULL;
    vector<string> ip;
    istringstream iss(str);
    for(string str;iss>>str;){
        ip.push_back(str);
    }
    Node* root=newNode(stoi(ip[i]));
    queue<Node*> q;
    q.push(root);
    int i=1;
    wihle(!q.empty() && i<ip.size()){
        Node* currNode=q.front();
        q.pop();
        string currVal=ip[i];
        if(currVal!='N'){
            currNode->left=newNode(stoi(ip[i]));
            q.push(currNode->left);
        }
        i++;
    }
    return root;
}
void inorder(Node* root){
    if(root==NULL)return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
class Solution{
    public :
    Node* prev=NULL;
    void flatten(Node* root){
        if(root==NULL){
            return;
        }
        flatten(root->right);
        flatten(root->left);
        root->right=prev;
        root->left=NULL;
        prev=root;
    }
};
int main(){
    int t;
    cin>>t;
    getchar();
    while(t--){
        string str;
        getline(cin,str);
        Node* root=buildTree(str);
        Solution ob;
        ob.flatten(root);
        inorder(root);

        cout<<endl;
    }
    return 0;
}