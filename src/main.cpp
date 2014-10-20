#include <conio.h>
#include <iostream>
#include "AVLTree.h"
//#include "AVLTree.cpp"


using namespace std;

void clr();
void p();

int main(){
    bool quit = false;
    char input = 'p';

    AVLTree* tree = new AVLTree;
    //avltree->insert('a');


    //BinaryTree* tree = new BinaryTree;
    while (!quit)
    {
        //clr();
        cout<<"1 = insert char\n2 = print pre order\n3 = print post order\n4 = print in order\n";
        cout<<"5 = Display AVLTree\nq = quit\n";
        input = getch();
        switch (input)
        {
            case 'q' :
                quit = true;
            break;
            case '1' :
                clr();
                cout << "Enter char to add to tree:";
                //char tempChar = 'p';
                input = getch();
                tree->InsertNode(input);
                clr();
            break;
            case '2' :
                clr();
                cout << "-- Pre Order --\n\n";
                tree->PreOrder(tree->GetRoot());
                p();
            break;
            case '3' :
                clr();
                cout << "-- Post Order --\n\n";
                tree->PostOrder(tree->GetRoot());
                p();
            break;
            case '4' :
                clr();
                cout << "-- In Order --\n\n";
                tree->InOrder(tree->GetRoot());
                p();
            break;
            case '5' :
                clr();
                cout << "-- AVLTree --\n\n";
                tree->Display();
                p();
            break;
            default :
                clr();
                cout << " Invalid Input\n\n";
                p();clr();
        }

    }
    return 0;
}

void clr()
    {
    cout << string( 100, '\n' );
    }

void p()
{
    char temp = 'p';
    cout << "\nPress a key to continue .. ";
    temp = getch();
    clr();
}
