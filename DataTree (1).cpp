#include "DataTree.h"
#include <iostream>
#include <cstdlib>
#include <iomanip>
using namespace std;

//Member method inserts node into the tree pointed to by the TreeNode pointer(called recursively)
void DataTree::insert(TreeNode *&nodePtr, TreeNode *&newNode)
{
    if (nodePtr==nullptr)
        nodePtr=newNode; //insert the node
        
    else if (newNode->value < nodePtr->value)
        insert(nodePtr->left, newNode); //search the left branch
        
    else 
        insert(nodePtr->right, newNode); //search the right branch
}

//Member method creates new node to hold num as its value and passes it to insert function

void DataTree::insertNode(int num)
{
    TreeNode *newNode=nullptr; //pointer to a new node
    
    //Create new node and store num in it
    newNode=new TreeNode;
    newNode->value=num;
    newNode->left=newNode->right=nullptr;
    
    //Insert the node
    insert(root, newNode);
}

//Member method called by destructor, deletes all nodes in Tree (called recursively)
void DataTree::destroySubTree(TreeNode *nodePtr)
{
    if (nodePtr)
    {
        if (nodePtr->left)
            destroySubTree(nodePtr->left);
            
        if (nodePtr->right)
            destroySubTree(nodePtr->right);
        delete nodePtr;
    }
}

//Member method displays the values in the subtree pointed to by nodePtr via inorder traversal (called recursively)
void DataTree::displayInOrder(TreeNode *nodePtr) const
{
    if (nodePtr)
    {
        displayInOrder(nodePtr->left);
        cout<<nodePtr->value<<endl;
        displayInOrder(nodePtr->right);
    }
}

//Member method returns value of leaves in Tree (called recursively)
int DataTree::numberLeaves(TreeNode *nodePtr)
{
    if (nodePtr==nullptr)
        return 0;
    if (nodePtr->left==nullptr && nodePtr->right==nullptr)
        return 1;
    return numberLeaves(nodePtr->left) + numberLeaves(nodePtr->right);
}

//Member method returns the largest number of nodes in the same level 
int DataTree::getWidthFinal(TreeNode *nodePtr)
{
    int widthFinal=0;
    int width;
    int h=getHeight(nodePtr);
    int i;
    
    //Get width at each level and compare
    for (i=1; i<=h; i++)
    {
        width=getWidth(nodePtr, i);
        if(width>widthFinal)
            widthFinal=width;
    }
    
    return widthFinal;
}

//Member method returns the number of nodes in a given level, called by getWidthFinal (called recursively)
int DataTree::getWidth(TreeNode *nodePtr, int level)
{
    if (nodePtr==nullptr)
        return 0;
    if (level==1)
        return 1;
    else if (level>1)
        return getWidth(nodePtr->left, level-1) + getWidth(nodePtr->right, level-1);
}

//Method finds height of Tree (called recursively)
int DataTree::getHeight(TreeNode *nodePtr)
{
    if (nodePtr==nullptr)
        return 0;
    else 
    {
        int leftHeight=getHeight(nodePtr->left);
        int rightHeight=getHeight(nodePtr->right);
        
        if (leftHeight>rightHeight)
            return leftHeight+1;
        else 
            return rightHeight+1;
    }
}

//Member method that can return height from main file
int DataTree::getHeightFinal(TreeNode *nodePtr)
{
    if (nodePtr==nullptr)
        return 0;
    else 
    {
        int leftHeight=getHeight(nodePtr->left);
        int rightHeight=getHeight(nodePtr->right);
        
        if (leftHeight>rightHeight)
            return leftHeight+1;
        else 
            return rightHeight+1;
    }
}