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

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////// STRUCTURES DEFINITION //////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*-------------------------------------------------------------------------------------------------------------------*/


struct Node {
  int data;
  Node *next;
};


struct DNode {
  int data;
  DNode *next;
  DNode *prev;
};


struct BstNode {
  int data;
  BstNode *left;
  BstNode *right;
};


/////////////////////


struct LL {
  Node *head;
  int size;
};


struct DLL {
  DNode *head;
  DNode *tail;
  int size;
};


struct Stack {
  Node *top;
  int size;
};


struct Queue {
  Node *front;
  Node *rear;
  int size;
};


struct BST {
  BstNode *root;
  int size;
  int height;
};


/*------------------------------------------------------------------------------------------------------------------*/
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////// SINGLY LINKED LISTS ///////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


LL* createLL() {
  LL *buf = new LL();
  buf->head = NULL;
  buf->size = 0;
  
  return buf;
}

////////////////////////////////////

Node* createNode(int x) {
  Node *buf = new Node();
  buf->data = x;
  buf->next = NULL;

  return buf;
}

////////////////////////////////////

int searchLL(LL *A, int x) {
  if (A->size == 0)
    return -1;
  
  int a = 1, f = 0;
  Node *buf = A->head;
  while(buf) {
    if (buf->data == x) {
      f = 1;
      break;
    }
    a++;
    buf = buf->next;
  }

  if (f) return a;
  else return -1;
}

////////////////////////////////////

void insertLL(LL *A, int x, int n=-1) {
  Node *buf = createNode(x);

  if (!A->size) {
    A->head = buf;
    A->size = 1;
  
  } else {
    Node *buf1 = A->head;
    if (n == -1 || n > A->size) {
      while(buf1->next)
        buf1 = buf1->next;
      buf1->next = buf;
    } else {
      if (n == 1) {
        buf->next = A->head;
        A->head = buf;
      } else {
        int p = 1;
        while(++p < n)
          buf1 = buf1->next;
        buf->next = buf1->next;
        buf1->next = buf;
      }
    }
    A->size++;
  }
}

///////////////////////////////////

void removeLL(LL *A, int n=-1, int x=INT_MIN, bool all=false) {
  if (n == -1 && x != INT_MIN) {
    Node *buf = A->head;
    Node *buf1 = buf->next;
    if (all) {
      while(buf1) {
        if (buf1->data == x) {
          if (buf1->next) {
            if (buf1->next->data != x) {
              buf->next = buf1->next;
              buf = buf->next;
              buf1 = buf->next;
            } else {
              buf1 = buf1->next;
            }
          } else {
            buf->next = NULL;
            buf1 = NULL;
          }
          A->size--;
        } else {
          buf1 = buf1->next;
          buf = buf->next;
        }
      }
      if (A->head->data == x) {
        if (A->size == 1) {
          A->head = NULL;
          cout << "The List is now empty.\n";
        } else {
          A->head = A->head->next;
        }
        A->size--;
      }
    } else { // !all
      if (A->head->data == x) {
        if (A->size == 1) {
          A->head = NULL;
          cout << "The List is now empty.\n";
        } else {
          A->head = A->head->next;
        }
        A->size--;
      } else {
        Node *buf = A->head;
        while(buf->next) {
          cout << buf->next->data << endl;
          if (buf->next->data == x) {
            buf->next = buf->next->next;
            A->size--;
            break;
          } else {
            buf = buf->next;
          }
        }
      }
    }
  } else if (1 <= n && n <= A->size) {
    if (n == 1) {
      if (A->size == 1) {
        A->head = NULL;
        cout << "The list is now empty.\n";
      } else {
        A->head = A->head->next;
      }
    } else {
      Node *buf = A->head;
      for (int i = 1; i < n-1; i++)
        buf = buf->next;
      buf->next = buf->next->next;
    }
    A->size--;
  }
}

/////////////////////////////////

void sortLL(LL* A) {
  int N = A->size;
  for (int i = 0; i < N-1; i++) {
    Node *buf = A->head;
    while (buf->next) {
      if (buf->data > buf->next->data) {
        int tmp = buf->data;
        buf->data = buf->next->data;
        buf->next->data = tmp;
      }
      buf = buf->next;
    }
  }
}

/////////////////////////////////

void reverseLL(LL *A) {
  if (!A || A->size == 0)
    return;

  Node *buf = A->head;
  Node *buf1 = buf->next;
  Node *buf2 = buf1;
  A->head->next = NULL;

  while(buf1) {
    buf2 = buf1->next;
    buf1->next = buf;
    buf = buf1;
    buf1 = buf2;
  }
  A->head = buf;
}

/////////////////////////////////

LL* generateLL(int n, int a = -4096, int b = 4096) {
  srand(time(NULL));
  LL *A = createLL();
  if (!n)
    return A;

  if (b < a) {
    cout << endl << "[a, b]  |  b should be greater than or equal to a." << endl;
    cout << "No values can be generated in this case." << endl;
    return A;
  }

  Node *buf = createNode(rand() % (b-a+1) + a);
  A->head = buf;
  for (int i = 1; i < n; i++) {
    buf->next = createNode(rand()%(b-a+1) + a);
    buf = buf->next;
  }

  A->size = n;
  return A;
}

/////////////////////////////////

void displayLL(LL *A) {
  if (!A->size) cout << "\nThe list is empty." << endl;
  else {
    cout << "\nSingly Linked List of size: " << A->size << endl;
    Node *buf = A->head;
    cout << buf->data;

    while (buf->next) {
      buf = buf->next;
      cout << " -> " << buf->data;
    }
    cout << endl;
  }
}

////////////////////////////////

void deleteLL(LL **A) { 
  Node *buf = (*A)->head;
  Node *buf1;
  while (buf) {
    buf1 = buf->next;
    delete buf;
    buf = buf1;
  
  }
  (*A)->size = 0;
  delete *A;
}

///////////////// Recursively


void revDisplayLL(Node *foo) {
  if (foo) {
    revDisplayLL(foo->next);
    cout << foo->data << " <- ";
  }
}

/*
void revLL(LL *A, Node *foo) {
  if (!foo->next) {
    A->head = foo;
    return;
  }
  revLL(A, foo->next);
  foo->next->next = foo;
  foo->next = NULL;
}
*/

/*------------------------------------------------------------------------------------------------------------------*/
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////// DOUBLY LINKED LISTS ///////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


DLL* createDLL() {
  DLL *buf = new DLL();
  buf->head = NULL;
  buf->tail = NULL;
  buf->size = 0;
  
  return buf;
}

////////////////////////////////

DNode* createDNode(int x) {
  DNode *buf = new DNode();
  buf->data = x;
  buf->next = NULL;
  buf->prev = NULL;

  return buf;
}

/////////////////////////////////

int searchDLL(DLL *A, int x) {
  if (A->size == 0)
    return -1;

  int a = 1, f = 0;
  DNode *buf = A->head;
  while(buf) {
    if (buf->data == x) {
      f = 1;
      break;
    }
    a++;
    buf = buf->next;
  }

  if (f) return a;
  else return -1;
}

/////////////////////////////////

void insertDLL(DLL *A, int x, int n=-1) {
  DNode *buf = createDNode(x);

  if (!A->size) {
    A->head = buf;
    A->tail = buf;
    A->size = 1;

  } else {
    DNode *buf1 = A->head;
    if (n == -1 || n > A->size) {
      while(buf1->next)
        buf1 = buf1->next;
      buf1->next = buf;
      buf->prev = buf1;
      A->tail = buf;
   } else {
      if (n == 1) {
        buf->next = A->head;
        A->head->prev = buf;
        A->head = buf;
        if (A->size == 1)
          A->tail = buf->next;
      } else {
        int p = 1;
        while(++p < n)
          buf1 = buf1->next;
        buf->next = buf1->next;
        buf->prev = buf1;
        buf1->next->prev = buf;
        buf1->next = buf;
      }
    }
    A->size++;
  }
}

//////////////////////////////////

void removeDLL(DLL *A, int n=-1, int x=INT_MIN, bool all=false) {
  DNode *buf = A->head;
  if (n == -1 && x != INT_MIN) {
    DNode *buf1 = buf->next;
    if (all) {
      while(buf1) {
        if (buf1->data == x) {
          if (buf1->next) {
            if (buf1->next->data != x) {
              buf->next = buf1->next;
              buf1->next->prev = buf;
              buf = buf->next;
              buf1 = buf->next;
            } else {
              buf1 = buf1->next;
            }
          } else {
            buf->next = NULL;
            buf1 = NULL;
            A->tail = buf;
          }
          A->size--;
        } else {
          buf1 = buf1->next;
          buf = buf->next;
        }
      }
      if (A->head->data == x) {
        if (A->size == 1) {
          A->head = NULL;
          A->tail = NULL;
          cout << "The List is now empty.\n";
        } else {
          A->head->next->prev = NULL;
          A->head = A->head->next;
        }
        A->size--;
      }
    } else { // !all
      if (A->head->data == x) {
        if (A->size == 1) {
          A->head = NULL;
          A->tail = NULL;
          cout << "The List is now empty.\n";
        } else {
          A->head->next->prev = NULL;
          A->head = A->head->next;
        }
        A->size--;
      } else {
        while(buf->next) {
          if (buf->next->data == x) {
            if (buf->next->next)
              buf->next->next->prev = buf;
            else
              A->tail = buf;
            buf->next = buf->next->next;
            A->size--;
            break;
          } else {
            buf = buf->next;
          }
        }
      }
    }
  } else if (1 <= n && n <= A->size) {
    if (n == 1) {
      if (A->size == 1) {
        A->head = NULL;
        A->tail = NULL;
        cout << "The list is now empty.\n";
      } else {
        A->head->next->prev = NULL;
        A->head = A->head->next;
      }
    } else {
      for (int i = 1; i < n-1; i++)
        buf = buf->next;
      if (buf->next->next)
        buf->next->next->prev = buf;
      else
        A->tail = buf;
      buf->next = buf->next->next;
    }
    A->size--;
  }
}

////////////////////////////////

void sortDLL(DLL* A) {
  int N = A->size;
  for (int i = 0; i < N-1; i++) {
    DNode *buf = A->head;
    while (buf->next) {
      if (buf->data > buf->next->data) {
        int tmp = buf->data;
        buf->data = buf->next->data;
        buf->next->data = tmp;
      }
      buf = buf->next;
    }
  }
}

/////////////////////////////////

void reverseDLL(DLL *A) {
  if (!A || A->size == 0)
     return;


  DNode *buf = A->head;
  DNode *buf1 = buf->next;
  DNode *buf2 = buf1;
  
  A->tail = A->head;
  A->tail->next = NULL;

  while(buf1) {
    buf2 = buf1->next;
    buf1->next = buf;
    buf->prev = buf1;
    buf = buf1;
    buf1 = buf2;
  }
  A->head = buf;
  A->head->prev = NULL;
}

/////////////////////////////////

DLL* generateDLL(int n, int a = -4096, int b = 4096) {
  srand(time(NULL));
  DLL *A = createDLL();
  if (!n)
    return A;

  if (b < a) {
    cout << endl << "[a, b]  |  b should be greater than or equal to a." << endl;
    cout << "No values can be generated in this case." << endl;
    return A;
  }

  DNode *buf = createDNode(rand() % (b-a+1) + a);
  A->head = buf;
  for (int i = 1; i < n; i++) {
    buf->next = createDNode(rand()%(b-a+1) + a);
    buf->next->prev = buf;
    buf = buf->next;
  }
  A->tail = buf;

  A->size = n;
  return A;
}

////////////////////////////////

void deleteDLL(DLL **A) { 
  DNode *buf = (*A)->head;
  DNode *buf1;
  while (buf) {
    buf1 = buf->next;
    delete buf;
    buf = buf1;
  }
  (*A)->size = 0;
  delete *A;
}

////////////////////////////////

void displayDLL(DLL *A) {
  if (!A->size) cout << "\nThe list is empty." << endl;
  else {
    cout << "\nDoubly Linked List of size: " << A->size << endl;
    DNode *buf = A->head;
    cout << buf->data;

    while (buf->next) {
      buf = buf->next;
      cout << " <-> " << buf->data;
    }
    cout << endl;
  } 
}

void revDisplayDLL(DLL *A) {
  if (!A->size) cout << "\nThe list is empty." << endl;
  else {
    cout << "\nDoubly Linked List of size: " << A->size << endl;
    DNode *buf = A->tail;
    cout << buf->data;

    while (buf->prev) {
      buf = buf->prev;
      cout << " <-> " << buf->data;
    }
    cout << endl;
  } 
}


/*------------------------------------------------------------------------------------------------------------------*/
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////// STACKS ////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


Stack* createSt() {
  Stack *S = new Stack();
  S->top = NULL;
  S->size = 0;

  return S;
}

// CreateNode is the same as the linked list

void PushSt(Stack *S, int x) {
  Node *buf = createNode(x);
  buf->next = S->top; 
  S->top = buf;
  S->size++;
}

/////////////////////////////

int TopSt(Stack *S) {
  if (!S->top) {
    cout << "Attempting to get the top of the stack when it's emtpy.\n";
  }
  return S->top->data;
}

int PopSt(Stack *S) {
  if (!S->top) {
    cout << "Attempting to pop the stack while it's empty.\n";
  }
  int a = S->top->data;
  S->top = S->top->next;
  S->size--;
  return a;
}

/////////////////////////////

void deleteSt(Stack **S) {
  Node *buf = (*S)->top;
  Node *buf1;
  while (buf) {
    buf1 = buf->next;
    delete buf;
    buf = buf1;
  }
  (*S)->size = 0;
  delete *S;
}

/////////////////////////////

void displaySt(Stack *S) {
  int N = S->size;
  if (N == 0) {
    cout << "The stack is empty." << endl;
    return;
  }
  Node *buf = S->top;
  cout << "\nThe stack has " << N << " elements: \n <- ";
  for (int i = 0; i < N; i++) {
    cout << buf->data << " | ";
    buf = buf->next;
  }
  cout << endl;
}

/*
    Infix notation   : (a+b)*c-d^f/g*h+i+j-x      
    Prefix notation  : -*+abc/^df*gh-++ijx        Polish                   
    Postfix notation : ab+c*df^g/h*-ij+x-         Reverse Polish
*/

bool isOP(char c) {
  if (c == '+' || c == '-' || c == '*' || c == '/')
    return true; 
  
  return false;
}

int evalOP(int a, char c, int b) {
  switch(c) {
    case '+': return a+b;
    case '-': return a-b;
    case '*': return a*b;
    case '/':
      if (!b) {
        cerr << "Attempting to divide by 0.\nValue defaulted to -1.\n";
        return -1;
      } else {
        return a/b;
      }
  }

  cerr << "Not a valid operation.\nValue defaulted to -1.\n";
  return -1;
}

bool higherPrec(char a, char b) { // Check whether operator {a} has higher precedence than {b}
  if (a == '^' || b == '+' || b == '-')
    return true;
  
  return false;
}


///////////////////////////////////////

string infToPost(string s) {
  string ans = "";
  stack<char> foo;
  
  for (char c : s) {
    if (isalnum(c)) {
      ans += c;
    } else if (c == '(') {
      foo.push(c);
    } else if (c == ')') {
      while(!foo.empty() && foo.top() != '(') {
        ans += foo.top();
        foo.pop();
      }
      foo.pop();
    } else {
      while(!foo.empty() && foo.top() != '(' && higherPrec(foo.top(), c)) {
        ans += foo.top();
        foo.pop();
      }
      foo.push(c);
    }
  }
  while(!foo.empty()) {
    ans += foo.top();
    foo.pop();
  }

  return ans;
}

///////////////////////////////////////

int evalEXP(string s, string t) { // evaluate infix, prefix or postfix depending on the expression type
  if (t == "infix") {
    return evalEXP(infToPost(s), "postfix");

  } else if (t == "prefix") {
    Stack *foo = createSt();
    int a = -1, b = -1;
    for (int i = s.length()-1; i >= 0; i--) {
      if (isOP(s[i])) {
        a = PopSt(foo);
        b = PopSt(foo);
        PushSt(foo, evalOP(a, s[i], b));
      }
      else if (1 <= s[i]-'0' && s[i]-'0' <= 9)
        PushSt(foo, s[i]-'0');
    }
    return PopSt(foo);
  
  } else if (t == "postfix") {
    Stack *foo = createSt();
    int a = -1, b = -1;
    for (int i = 0; i < s.length(); i++) {
      if (isOP(s[i])) {
        b = PopSt(foo);
        a = PopSt(foo);
        PushSt(foo, evalOP(a, s[i], b));
      }
      else if (1 <= s[i]-'0' && s[i]-'0' <= 9)
        PushSt(foo, s[i]-'0');
    }
    return PopSt(foo);
  }

  cout << "\nNo expression type was provided, the return will be defaulted to -1.\n";
  return -1;
}


/*------------------------------------------------------------------------------------------------------------------*/
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////// QUEUES ////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


Queue* createQe() {
  Queue *buf = new Queue();
  buf->front = NULL;
  buf->rear = NULL;
  buf->size = 0;

  return buf;
}

///////////////////////////////

void Enqueue(Queue *q, int x) {
  Node *buf = createNode(x) ;
  if (q->size == 0) {
    q->front = buf;
    q->rear = buf;
    q->size = 1;
    return;
  }
  q->rear->next = buf;
  q->rear = buf;
  q->size++;
}

//////////////////////////////

int Dequeue(Queue *q) { 
  if (q->size == 0) {
    cout << "Attempting to dequeue when the queue is empty.\n";
  }
  int a = q->front->data;
  if (q->size == 1) {
    q->front = NULL;
    q->rear = NULL;

  } else {
    Node *temp = q->front;
    q->front = q->front->next;
    delete temp;
  }
  q->size--;
  return a;
}

/////////////////////////////

void deleteQe(Queue **q) {
  Node *buf = (*q)->front;
  Node *buf1;
  while (buf) {
    buf1 = buf->next;
    delete buf;
    buf = buf1;
  }
  (*q)->size = 0;
  delete *q;
}

/////////////////////////////

void displayQe(Queue *q) {
  int N = q->size;
  if (N == 0) {
    cout << "The queue is empty." << endl;
    return;
  }
  Node *buf = q->front;
  cout << "\nThe queue has " << N << " elements:\n<- ";
  for (int i = 0; i < N; i++) {
    cout << "| " << buf->data << " ";
    buf = buf->next;
  }
  cout << "<- " << endl;
}



/*------------------------------------------------------------------------------------------------------------------*/
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////// BINARY SEARCH TREES ///////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


BST* createBST() {
  BST *buf = new BST();
  buf->root = NULL;
  buf->size = 0;
  buf->height = -1;

  return buf;
}

/////////////////////////////////

BstNode* createBstNode(int x) {
  BstNode *buf = new BstNode();
  buf->data = x;
  buf->left = NULL;
  buf->right = NULL;

  return buf;
}

/////////////////////////////////

bool searchBST(BstNode *root, int x) {
  if (!root) return false;
  if (root->data == x) return true;
  
  if (x <= root->data)
    return searchBST(root->left, x);
  else
    return searchBST(root->right, x);
}

/////////////

BstNode* findBST(BstNode *root, int x) {
  if (!root) return NULL;
  if (root->data == x) return root;

  if (x <= root->data)
    return findBST(root->left, x);
  else
    return findBST(root->right, x);
}

/////////////////////////////////

int calcHeight(BstNode *buf) {
  if (!buf) {
    return -1;
  }

  return 1 + max(calcHeight(buf->left), calcHeight(buf->right));
}

/////////////////////////////////

BstNode* insertBST(BST *T, BstNode *root, int x) {
  if (!root) {
    root = createBstNode(x);
    T->size++;
  }
  else if (x <= root->data)
    root->left = insertBST(T, root->left, x);
  else
    root->right = insertBST(T, root->right, x);
  
  T->height = calcHeight(T->root);
  return root;
}

/////////////////////////////////

int minBST(BstNode *root) {
  if (!root) 
    cout << "Attempting to get min of an empty tree.\n";
  
  while (root->left) 
    root = root->left;
  
  return root->data;
}
  
/////////////

int maxBST(BstNode *root) {
  if (!root)
    cout << "Attempting to get max of an empty tree.\n";

  while (root->right)
    root = root->right;

  return root->data;
}

/////////////////////////////////
/// Breadth-first traversal

void LevelOrderTrav(BST *T) {
  if (!T->root) {
    cout << "Tree is empty, nothing to display.\n";
    return;
  }
  // If we use 2 queues here, we can display each level of nodes in a new line
  // Such that whenever a queue is empty, we cout << endl, and we push the children to the other queue
  
  queue<BstNode*> q;
  q.push(T->root);
  while (!q.empty()) {
    BstNode *buf = q.front();
    q.pop();
    cout << buf->data << " ";
    if (buf->left)
      q.push(buf->left);
    if (buf->right)
      q.push(buf->right);
  }
  cout << endl;
}

////////////////////////////////
/// Deapth-first traversal

void PreorderTrav(BstNode *root) {
  if (!root)
    return;

  cout << root->data << " ";
  PreorderTrav(root->left);
  PreorderTrav(root->right);
}

//////

void InorderTrav(BstNode *root) {
  if (!root)
    return;

  InorderTrav(root->left);
  cout << root->data << " ";
  InorderTrav(root->right);
}

//////

void PostorderTrav(BstNode *root) {
  if (!root)
    return;

  PostorderTrav(root->left);
  PostorderTrav(root->right);
  cout << root->data << " ";
}

////////////////////////////////////

BstNode* InorderSuccessor(BST *T, int x) {
  if (!T->root)
    return NULL;
 
  BstNode *buf = findBST(T->root, x);
  if (!buf) return NULL;
  
  if (buf->right) {
    buf = buf->right;
    while (buf->left)
      buf = buf->left;
    return buf;

  } else {
    BstNode *ancestor = T->root;
    BstNode *successor = NULL;
    while (x != ancestor->data) {
      if (x < ancestor->data) {
        successor = ancestor;
        ancestor = ancestor->left;
      } else {
        ancestor = ancestor->right;
      }
    }
    return successor;
  }
}

////////////////////////////////////

bool checkBST(BST *T) {
  if (!T->root) {
    cout << "Tree is empty.\n";
    return true;
  }
  
  bool valid = true;
  queue<BstNode*> q;
  q.push(T->root);

  while (!q.empty() && valid) {
    BstNode *buf = q.front();
    if (buf->left) {
      if (buf->left->data > buf->data)
        valid = false;
      else
        q.push(buf->left);
    }
    if (buf->right) {
      if (buf->right->data < buf->data)
        valid = false;
      else
        q.push(buf->right);
    }
    q.pop();
  }

  return valid;
}

///////////////////////////////////

BstNode* removeBst(BST *T, BstNode *root, int x) {
  if (!root) return NULL;
  if (x < root->data)
    root->left = removeBst(T, root->left, x);
  else if (x > root->data)
    root->right = removeBst(T, root->right, x);

  // x == root->data
  
  else if (!root->left && !root->right) {
    delete root;
    root = NULL;
    T->size--;
  }
  else if (!root->left) {
    BstNode *buf = root;
    root = root->right;
    delete buf;
    T->size--;
  }
  else if (!root->right) {
    BstNode *buf = root;
    root = root->left;
    delete buf;
    T->size--;
  }
  else {
    int mn = minBST(root->right);
    root->data = mn;
    root->right = removeBst(T, root->right, mn); 
  }
    
  return root;
}

//////////////////////////////////

void deleteBST(BST **T) {
  if (!(*T)->root) {
    delete (*T)->root;
    return;
  }

  queue<BstNode*> q;
  q.push((*T)->root);
  while (!q.empty()) {
    BstNode *buf = q.front();
    if (buf->left)
      q.push(buf->left);
    if (buf->right)
      q.push(buf->right);
    
    q.pop();
    delete buf;
  }
  (*T)->size = (*T)->height = 0;
  (*T)->root = NULL;
  delete *T;
}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*------------------------------------------------------------------------------------------------------------------*/
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#endif
