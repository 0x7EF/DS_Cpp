#ifndef MYLIB_DS
#define MYLIB_DS

#include <iostream>
#include <algorithm>
#include <cctype>
#include <cstddef>
#include <climits>
#include <cstdlib>
#include <ctime>
#include <stack>
#include <queue>
using namespace std;

// STRUCTURES DEFINITION

struct Node;
struct DNode;
struct BstNode;
struct LL;
struct DLL;
struct Stack;
struct Queue;
struct BST;

// SINGLY LINKED LISTS

LL* createLL();
Node* createNode(int x);
int searchLL(LL *A, int x);
void insertLL(LL *A, int x, int n=-1);
void removeLL(LL *A, int n=-1, int x=INT_MIN, bool all=false);
void sortLL(LL* A);
void reverseLL(LL *A);
LL* generateLL(int n, int a = -4096, int b = 4096);
void displayLL(LL *A);
void deleteLL(LL **A);
void revDisplayLL(Node *foo);

// DOUBLY LINKED LISTS

DLL* createDLL();
DNode* createDNode(int x);
int searchDLL(DLL *A, int x);
void insertDLL(DLL *A, int x, int n=-1);
void removeDLL(DLL *A, int n=-1, int x=INT_MIN, bool all=false);
void sortDLL(DLL* A);
void reverseDLL(DLL *A);
DLL* generateDLL(int n, int a = -4096, int b = 4096);
void displayDLL(DLL *A);
void revDisplayDLL(DLL *A);

// STACKS

Stack* createSt();
void PushSt(Stack *S, int x);
int TopSt(Stack *S);
int PopSt(Stack *S);
void deleteSt(Stack **S);
void displaySt(Stack *S);
bool isOP(char c);
int evalOP(int a, char c, int b);
bool higherPrec(char a, char b);
string infToPost(string s);
int evalEXP(string s, string t);

// QUEUES

Queue* createQe();
void Enqueue(Queue *q, int x);
int Dequeue(Queue *q);
void deleteQe(Queue **q);
void displayQe(Queue *q);

// BINARY SEARCH TREES

BST* createBST();
BstNode* createBstNode(int x);
bool searchBST(BstNode *root, int x);
BstNode* findBST(BstNode *root, int x);
BstNode* insertBST(BST *T, BstNode *root, int x);
int minBST(BstNode *root);
int maxBST(BstNode *root);
void LevelOrderTrav(BST *T);
void PreorderTrav(BstNode *root);
void InorderTrav(BstNode *root);
void PostorderTrav(BstNode *root);
BstNode* InorderSuccessor(BST *T, int x);
bool checkBST(BST *T);
BstNode* removeBst(BST *T, BstNode *root, int x);
void deleteBST(BST **T);

#endif
