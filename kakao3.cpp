#include <string>
#include <vector>
#include <algorithm>
#include <iostream>


using namespace std;

vector<int>pre;
vector<int>post;
typedef struct node *treepointer;
typedef struct node {
    int data;
    treepointer leftChild, rightChild;
}node;

void preorder(treepointer ptr)
{
    if(ptr)
    {
        pre.push_back(ptr->data);
        if(ptr->leftChild)
        {
            preorder(ptr->leftChild);
        }
        if(ptr->rightChild)
        {
            preorder(ptr->rightChild);
        }
    }
}
void postorder(treepointer ptr)
{
    if(ptr)
    {
        if(ptr->leftChild)
        {
            preorder(ptr->leftChild);
        }
        if(ptr->rightChild)
        {
            preorder(ptr->rightChild);
        }
        pre.push_back(ptr->data);
    }
}
int getdep(treepointer ptr, int cnt)
{
    if(ptr->leftChild) getdep(ptr->leftChild, cnt++);
    if(ptr->rightChild) getdep(ptr->rightChild, cnt++);
    return cnt;
}

int solution(vector<vector<int>> nodeinfo) {
    vector<vector<int>> answer;
    node nodes[nodeinfo.size()];
    int right = -1;
    int left = -1;
    int rer = -1;
    int rel = -1;
    int max = 0;
    int midx = 0;
    for(int i = 0; i < nodeinfo.size(); i++)
    {
        nodes[i].data = i;
        nodes[i].leftChild = NULL;
        nodes[i].rightChild = NULL;
    }
    for(int i = 0; i < nodeinfo.size(); i++)
    {
        int right = nodeinfo[i][0];
        int rt = nodeinfo[i][1];
        int left = nodeinfo[i][0];
        int lt = nodeinfo[i][1];
        for(int j = 0; j < nodeinfo.size(); j++)
        {
            if(right<nodeinfo[j][0]&&rt>nodeinfo[j][1])
            {
                rt = nodeinfo[j][1];
                rer = j;
            }
            if(left>nodeinfo[j][0]&&lt>nodeinfo[j][1])
            {
                lt = nodeinfo[j][1];
                rel = j;
            }
        }
        if(rer != -1)
        {
            nodes[i].rightChild = &nodes[rer];
        }
        if(rel != -1)
        {
            nodes[i].leftChild = &nodes[rel];
        }
        rer = -1;
        rel = -1;
    }
    max = getdep(&nodes[0], 0);
    for(int i = 1; i < nodeinfo.size() ;i++)
    {
        if(max<getdep(&nodes[i], 0))
        {
            max = getdep(&nodes[i], 0);
            midx = i;
        }
    }
    preorder(&nodes[midx]);
    for(int i = 0 ; i < pre.size();i++)
    {
        cout<<pre[i]<<"\n";
    }
    postorder(&nodes[midx]);
    return 1;
}