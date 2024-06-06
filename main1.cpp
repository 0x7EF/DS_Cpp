#include "DS_LibC++.hpp" 

int main() {
    // Testing Singly Linked Lists
    LL* list = createLL();
    insertLL(list, 5);
    insertLL(list, 10);
    insertLL(list, 15);
    displayLL(list);
    cout << "Element 10 is at position: " << searchLL(list, 10) << endl;
    removeLL(list, 2);
    displayLL(list);
    deleteLL(&list);

    // Testing Doubly Linked Lists
    DLL* dList = createDLL();
    insertDLL(dList, 5);
    insertDLL(dList, 10);
    insertDLL(dList, 15);
    displayDLL(dList);
    cout << "Element 10 is at position: " << searchDLL(dList, 10) << endl;
    removeDLL(dList, 2);
    displayDLL(dList);
    deleteDLL(&dList);

    // Testing Stacks
    Stack* stack = createSt();
    PushSt(stack, 5);
    PushSt(stack, 10);
    PushSt(stack, 15);
    displaySt(stack);
    cout << "Top element of the stack: " << TopSt(stack) << endl;
    PopSt(stack);
    displaySt(stack);
    deleteSt(&stack);

    // Testing Queues
    Queue* queue = createQe();
    Enqueue(queue, 5);
    Enqueue(queue, 10);
    Enqueue(queue, 15);
    displayQe(queue);
    cout << "Dequeued element: " << Dequeue(queue) << endl;
    displayQe(queue);
    deleteQe(&queue);

    // Testing Binary Search Trees
    BST* bst = createBST();
    bst->root = insertBST(bst, bst->root, 50);
    insertBST(bst, bst->root, 30);
    insertBST(bst, bst->root, 70);
    insertBST(bst, bst->root, 20);
    insertBST(bst, bst->root, 40);
    insertBST(bst, bst->root, 60);
    insertBST(bst, bst->root, 80);
    LevelOrderTrav(bst);
    cout << "Min element in the BST: " << minBST(bst->root) << endl;
    cout << "Max element in the BST: " << maxBST(bst->root) << endl;
    cout << "Is BST valid? " << checkBST(bst) << endl;
    bst->root = removeBst(bst, bst->root, 30);
    LevelOrderTrav(bst);
    deleteBST(&bst);

    return 0;
}

