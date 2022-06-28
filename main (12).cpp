/* Varvara Vorobieva
* Chapter 21 Assignment
*CISC 187
* 5/19/2022
*/
 
#include <iostream>
#include <iomanip>
#include <string>
#include "DataTree.h"
using namespace std;

//Function prototypes

void DisplayMenu(DataTree &);
void AddNumber(DataTree &);
void DisplayTree(DataTree &);
void CountLeaves(DataTree &);
void DisplayHeight(DataTree &);
void DisplayWidth(DataTree &);
void Leave();

int main()
{
   DataTree TreeOne;
   DisplayMenu(TreeOne);
   
    return 0;
}


//Menu displaying function 
void DisplayMenu(DataTree &TreeOne)
{
    //While testvar is not 7, display menu
    int menuOption=0;
    string option="";
    while (menuOption!=6)
    {
      cout<<"Welcome to Chapter 21 Programming Assignment!\n";
      cout<<"1. Add an integer into the tree \n" ;
      cout<<"2. Display the tree (in order) \n";
      cout<<"3. Display the leaf count \n";
      cout<<"4. Display tree height \n";
      cout<<"5. Display tree width \n";
      cout<<"6. Exit Menu \n";
      cout<<"Please choose your menu option.\n";
      
      getline(cin,option);
      menuOption=stoi(option);
      
      if (menuOption==1)
      {
         AddNumber(TreeOne);
      }
      else if (menuOption==2)
      {
         DisplayTree(TreeOne);
      }  
      else if (menuOption==3)
      {
         CountLeaves(TreeOne);
      }
      else if (menuOption==4)
      {
         DisplayHeight(TreeOne);
      }
      else if (menuOption==5)
      {
         DisplayWidth(TreeOne);
      }

      else if (menuOption==6)
      {
          Leave();
      }
      else
      {
          cout<<"Error: That is not a valid menu selection.\n";
          cout<<"Please enter a valid integer, 1-6.\n\n";
          
      }
    
    
    }
}

//Function adds number to binary Tree
void AddNumber(DataTree &TreeOne)
{
    int addInt=0;
    string integer="";
    cout<<"Please enter the digit you would like to add to the tree. \n";
    getline(cin,integer);
    addInt=stoi(integer);
    
    TreeOne.insertNode(addInt);
    cout<<"Your integer " << addInt << " has been added to the binary tree.\n\n";
}

//Function displays entire binary tree using inorder method
void DisplayTree(DataTree &TreeOne)
{
    cout<<"Here are the integers in your binary tree displayed in order.\n";
    cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    TreeOne.displayInOrder();
    cout<<endl;
}

//Function displays the leaf count 
void CountLeaves(DataTree &TreeOne)
{
    cout<<"The number of leaves in the binary tree is " << TreeOne.numberLeaves()<< ".\n\n";
}

//Function displays the tree height
void DisplayHeight(DataTree &TreeOne)
{
    cout<<"The height of the binary tree is " << TreeOne.getHeightFinal() <<".\n\n";
}

//Function displays the tree width
void DisplayWidth(DataTree &TreeOne)
{
    cout<<"The width of the binary tree is " << TreeOne.getWidthFinal()<<".\n\n";
}

//Last function displays a farewell message
void Leave()
{
    cout<<"Thanks for using the Chapter 21 Programming Assignment!\n";
}