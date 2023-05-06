#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// Made by Husain Abugosh / 2023 

/*  single linked list  chain of nodes each nodes have :
1- place to save the data.
2- place to save the address of the next node< that points on it> .

1stNode| DATA /  Potiner(next node addres)|  >>> 2ndNode| DATA /  Potiner(next node addres)|  >>>  and so on....
the node will be shows as a struct and the struct will conatain data as any type  , next as the struct datatype

the linked list will have node called Head that has null data in it and points on address ( the fist node)
the linked list will have node called tail that has data in it but point on null and that how we could know its the last node.
*/ 


// to make a shortcut of data we can uSE typedef KeyWord:
// typedef struct Node* List   >>>  now List = struct node*
// typedef List Postion >>>>  now  Postion = List = struct node*



// the struct(we can say its class in java hava atributes and we can make an object from this struct):
typedef struct  Node{
    int data;              // <<<  will store the data in the node.
    struct Node* next;    // <<<  will store the address of the next node (points on the NEXT NODE thats why its data is struct node).

}Node;

// to create a Node(object of struct):
Node* create_node(int data){

    /*
    first we will search about empty space in the memo of Node size 
    and then store the addres of this space in Node pointer var call 
    newNode
    */ 
    Node* newNode = (Node*)malloc(sizeof(Node));

    // if there is no space in the memo:
    if(newNode == NULL){
      printf("Out of memory!\n");
    }else{
    // to insert the data and set up the pointers:
        newNode -> data = data;
        newNode -> next = NULL;
        return newNode;
    }
}


// to insert a data in the linked list:
void insert(Node** head, int data){

    /*
    *head will point on the first node:
    This is necessary when inserting the first element in the list, as the head pointer needs to be updated to point to the new nod.

    if the *head(first node in the list) is null that meant there is no first node and the list is empty
    so here will make a new node using create_node(data) function else (if the first node is not null , there is value)
    so we will keep searching for a node the next of this node is empty that mean we reach the end of the list (tail)
    and we will insert the new node after the tail.
    */ 

    Node* new_node = create_node(data);
    if (*head == NULL){
        *head = new_node;
    }else{
        Node* current_node = *head;
        while (current_node->next !=NULL){
           current_node = current_node->next;
        }
        current_node->next = new_node;
    }
}


// to find an element in the list:
Node* find(Node* head, int target){
    Node* current_node = head;
    while (head != NULL && current_node->data != target){
        current_node = current_node->next;
    }
    return current_node;
}

// to find the previous node of the target:
Node* findPrevious(Node* head, int target){
  Node* prev = head;
  while (prev != NULL && prev->next->data != target){
    prev = prev->next;
  }

  // If the target node is not found, return NULL
  if (prev->next == NULL) {
        return NULL;
  }

  return prev;
}

// to dispaly the list :
void display(Node* head){

    // while is the current_node is not null then print the data that store in this node.
    Node*  current_node = head;
    while (current_node != NULL){
        printf("%d -> ", current_node->data);
        current_node = current_node->next;
    }
    printf("NULL \n");
}

// to find the size of List
int sizeOf(Node *head){
     // while is the current_node is not null then increase the size
    Node* current_node = head;
    int size = 0;
    while (current_node != NULL){
        size++;
        current_node = current_node->next;
    }
    return size;
}

// to Checks if the list is empty:
int isEmpty(Node* head){
    return head == NULL;
}

// to Checks if a given node is the last node in the linked list:
int isLast(Node* node) {
    return node->next == NULL;
}


// to delete an element from list:
void delete(Node** head, int target) {
    Node* current_node = *head;

    // Check if the list is empty
    if (isEmpty(*head)) {
        printf("List is empty. Cannot delete the target.\n");
        return;
    }

    // If the node to delete is the head node
    if (current_node->data == target) {
        Node* node_to_delete = current_node;
        *head = current_node->next; // Update the head pointer
        free(node_to_delete);
        return;
    }

    Node* prev = findPrevious(*head, target);

    // If the target node is not found
    if (prev == NULL) {
        printf("Node not found. Cannot delete the target.\n");
        return;
    }

    Node* node_to_delete = prev->next;
    prev->next = node_to_delete->next;
    free(node_to_delete);
}


// to delete all the list:
void deleteList(Node** head) {
    
    Node* current_node = *head;
    Node* next_node;

    while (current_node != NULL) {
        next_node = current_node->next; // Save the next node before deleting the current node
        free(current_node); // Free the memory allocated for the current node
        current_node = next_node; // Move to the next node in the list
    }

    *head = NULL; // Set the head pointer to NULL, indicating the list is empty
}


///////////////////// end of single linked list //////////////////////



/*    
doubly linked list: its a list of node each node have 3 spaces in it :

  data: space to store the data in it;
  next: pointer thats point to the next node;
  prev: pointer thats point to the previous node;

          Head👇🏽       |            Nodes👇🏽                      |  tail 👇🏽
  |null/data/next| ->  <_|prev/data/next| -> <_|prev/data/next| ->   <_ |prev/data/null|

  disadvantages?  >yes its take more space than the single linked list cuse of the prev pointer.
*/ 



typedef struct dNode{

    int data;
    struct dNode* next;
    struct dNode* prev;

}dNode;


dNode* create_Dnode(int data){

    // TO find a space in memo to create a node:
    dNode* newNode  = (dNode*)(malloc(sizeof(dNode)));

    // if there is no space in the memo:
    if(newNode == NULL){
      printf("Out of memory!\n");
    }
    // to insert the data and set up the pointers
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

void insertD(dNode **head, int data){

    dNode* new_node = create_Dnode(data);
    if (*head == NULL){
      *head = new_node;
    }else{

      dNode* current_node = *head;
      while (current_node->next != NULL){
        current_node = current_node->next;
      }

      current_node->next = new_node;
      new_node->prev = current_node;
    }
}


void displayd(dNode* head){

  dNode *current_node = head;
  while (current_node != NULL){
     printf("%d > ", current_node->data);
     current_node = current_node->next;
  }
  printf("\n");
}


////////////////////// end of double linked list ///////////////




// linked list Questions:

/*
Q1: Write a function that takes two sorted linked lists and return true
 if the lists are disjoin lists (meaning they have no common elements).
  Use iterations to solve this question.
*/


// if the lists are Not sorted use this function:
int areDisjoint(Node* head1, Node* head2) {

    Node* current_node1 = head1;
    Node* current_node2;

    while (current_node1 != NULL) {
        current_node2 = head2;

        while (current_node2 != NULL) {
            if (current_node1->data == current_node2->data) {
                return 0; // Found a common data  so >>> return false (not disjoint)
            }
            current_node2 = current_node2->next;
        }

        current_node1 = current_node1->next;
    }

    return 1; // Checked all nodes and found no common value between the two lists (disjoint)
}



// if the lists ARE SORTEF use this function:
int areSortedDisjoint(Node* head1, Node* head2) {

    Node* current_node1 = head1;
    Node* current_node2 = head2;

    while (current_node1 != NULL && current_node1 != NULL){

        if (current_node1->data == current_node2->data){
            return 0;
        }

        if(current_node1->data < current_node2->data){
            current_node1 = current_node1->next;
        }else{
            current_node2 = current_node2->next;
        }
    }

    return 1;
}

/*
Q2:Write a recursive function that takes two sorted linked lists and return true if the lists are disjoin lists 
(meaning they have no common elements). Your algorithm should be O(n).
*/
int recursionDisjoint(Node* head1,  Node* head2){

    //base cases:
    if (head1 == NULL || head2 == NULL){
        // if one from the 2 lists are null that mean there is no common values
        return 1;
    }
    if (head1->data == head2->data){
        return 0;
    }
    
    // Move the pointer in the list to the node with the smaller element.
    if (head1->data < head2->data){
        return recursionDisjoint(head1->next, head2);
    }else{
         return recursionDisjoint(head1, head2->next);
    }
}


/*
 Question 3) Write a function to reverse a given doubly linked list.
 */

dNode* reverse(dNode* head){

    dNode* current_node = head;
    dNode* temp = NULL;

    while (current_node != NULL){

        temp = current_node->prev;
        current_node->prev = current_node->next;
        current_node->next = temp;
        current_node = current_node->prev;
    }

    // Update the head of the reversed list
    if (temp != NULL) {
        head = temp->prev;
    }

    return head;
}

/*
 Question 4) Write a function called concat() that receives two lists
 and append the first one to the second.
*/

Node* concat(Node* list1, Node* list2){

    //if the first listis null(no element in it) then just return the second list:
    if(list1 ==  NULL){
        return list2;
    }
    // if the second list is null(no element in it) then just return the first list:
    if(list2 ==  NULL){
        return list1;
    }
    /*we want to find the tail(when the next of the node = Null) of the first list
    and let the next of it point to the head  of the second list.
    */ 
    Node* tail = list1;
    // thats mean keep moving for the next node until we reach the tail
    while (tail->next != NULL){
        tail = tail->next;
    }
    //after we reach the tail (the last node of list1):
    tail->next = list2;
    return list1;
}


/*
Q5) Given a singly linked list, write a function to swap elements pairwise.
For example, if the linked list is 1->2->3->4->5 
then the function should change it to 2->1->4->3->5,
 and if the linked list is 1->2->3->4->5->6 
then the function should change it to 2->1->4->3->6->5.
*/
Node* swap(Node* head){

    // cheack if the head or 2nd node are null if it is we acnt swap:
    if(head == NULL || head->next == NULL){
        return head;
    }

    Node* current_node = head;
    Node* next_node;
    while (current_node != NULL && current_node->next != NULL){

        next_node = current_node->next;
        // crate a temp var to save the data of the current node to not lose it, then swap the data
        int temp = current_node->data;
        current_node->data = next_node->data;
        next_node->data = temp;
        // move the current node 2 steps forward:
        current_node = next_node->next;
    }

     return head;
}
    

/*
Question 6) Write a function called RemoveDuplicates() 
that takes a list sorted in increasing order and deletes any duplicate nodes from the list.
*/


void RemoveDuplicates(Node* head) {

//Since the list is sorted in increasing order, the duplicate elements will always be consecutive
    Node* current_node = head;
    Node* next_node;
    Node* temp;

    while (current_node != NULL && current_node->next != NULL) {
        next_node = current_node->next;

        if (current_node->data == next_node->data) {
            temp = next_node;
            current_node->next = next_node->next;
            free(temp);
        } else {
            current_node = current_node->next;
        }
    }
}






int main(void){

 // declear a LinkeList:
    Node* myList = NULL;

    insert(&myList, 1);
    insert(&myList, 1);
    insert(&myList, 2);
    insert(&myList, 3);
    insert(&myList, 3);
    insert(&myList, 4);
    insert(&myList, 5);
    insert(&myList, 1);
    insert(&myList, 5);
    insert(&myList, 6);

    printf("Original list:\n");
    display(myList);

    RemoveDuplicates(myList);

    printf("List after removing duplicates:\n");
    display(myList);

return 0;

}
