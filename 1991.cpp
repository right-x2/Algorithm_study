#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v[20000];

typedef struct node *nodePointer;
typedef struct node
{
    char ele;
    char rele;
    char lele;

    nodePointer right;
    nodePointer left;
}node;
void preOrder(nodePointer nde)
{
    cout<<nde->ele<<"";
    if(nde->left) preOrder(nde->left);
    if(nde->right) preOrder(nde->right);
}
void inOrder(nodePointer nde)
{
    if(nde->left) inOrder(nde->left);
    cout<<nde->ele<<"";
    if(nde->right) inOrder(nde->right);
}
void postOrder(nodePointer nde)
{
    if(nde->left) postOrder(nde->left);
    if(nde->right) postOrder(nde->right);
    cout<<nde->ele<<"";
}
int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int n;
    char a,b,c;
    cin>>n;
    node arr[n];
    for (int i = 0; i < n; ++i)
    {
        cin>>a>>b>>c;
        node nde;
        nde.ele = a;
        nde.lele = b;
        nde.rele = c;
        nde.right = NULL;
        nde.left = NULL;
        arr[i] = nde;
    }
    for(int i = 0; i < n; i++)
    {
        for(int j = i+1; j < n; j++)
        {
            if(arr[i].rele!='.'&&arr[i].rele==arr[j].ele)
            {
                arr[i].right = &arr[j];
            }
            if(arr[i].lele!='.'&&arr[i].lele==arr[j].ele)
            {
                arr[i].left = &arr[j];
            }
        }
    }
    preOrder(&arr[0]);
    cout<<"\n"<<"";
    inOrder(&arr[0]);
    cout<<"\n"<<"";
    postOrder(&arr[0]);
    return 0;
}