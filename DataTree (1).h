//Specification file for tree class
#ifndef DATATREE_H
#define DATATREE_H
#include <iostream>
#include <string>
using namespace std;

class DataTree 
{
    private:
    //Structure for nodes
    
         struct TreeNode
         {
                int value;
                TreeNode *left; //pointer to left child node
                TreeNode *right; //pointer to right child node
          };
          
          TreeNode *root; //pointer to the root node
          
          //Private member functions
          void insert(TreeNode *&, TreeNode *&);
          void destroySubTree(TreeNode *);
          void displayInOrder(TreeNode *) const;
          int numberLeaves(TreeNode *);
          int getHeight(TreeNode *);
          int getWidthFinal(TreeNode *);
          int getWidth(TreeNode*, int);
          int getHeightFinal(TreeNode *);
          

          
    public:
    //Constructor
            DataTree()
            {
                root=nullptr;
            }
            
    //Destructor
            ~DataTree()
            {
                destroySubTree(root);
            }
            
    //Binary tree operations
            void insertNode(int);
            
            void displayInOrder() const
            {
                displayInOrder(root);
            }
            int numberLeaves()
            {
                numberLeaves(root);
            }
            int getWidthFinal()
            {
                getWidthFinal(root);
            }
            int getHeightFinal()
            {
                getHeightFinal(root);
            }
            

};

#endif