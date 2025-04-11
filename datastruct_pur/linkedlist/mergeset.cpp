#include <stdio.h>
#include <stdlib.h>

// 定义结点结构体
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// 创建一个新的节点
Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// 创建一个空的循环有序链表（带头结点）
Node* createCircularList() {
    Node* head = createNode(0);  // 头结点不存数据
    head->next = head;  // 头结点指向自己，形成循环
    return head;
}

// 向循环有序链表中插入元素，保持有序性
void insertOrdered(Node* head, int value) {
    Node* newNode = createNode(value);
    Node* current = head;
    
    // 找到插入位置，保证有序性
    while (current->next != head && current->next->data < value) {
        current = current->next;
    }
    
    // 插入新节点
    newNode->next = current->next;
    current->next = newNode;
}

// 打印循环有序链表
void printList(Node* head) {
    Node* current = head->next;
    if (current == head) {
        printf("List is empty.\n");
        return;
    }
    
    while (current != head) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// 合并两个循环有序链表，构造集合C
Node* mergeSets(Node* A, Node* B) {
    Node* C = createCircularList();  // 创建空的集合C
    Node* pA = A->next;
    Node* pB = B->next;
    Node* last = C;  // C的尾部节点，开始时是头结点
    
    // 合并A和B中的元素
    while (pA != A || pB != B) {
        if (pA == A) {  // 如果A已经遍历完，将B的剩余元素添加到C
            last->next = pB;
            break;
        }
        if (pB == B) {  // 如果B已经遍历完，将A的剩余元素添加到C
            last->next = pA;
            break;
        }
        
        // 比较A和B的当前元素，选择较小的插入到C中
        if (pA->data < pB->data) {
            last->next = pA;
            last = pA;
            pA = pA->next;
        } else if (pA->data > pB->data) {
            last->next = pB;
            last = pB;
            pB = pB->next;
        } else {  // 如果元素相等，选择其中一个并跳过重复的元素
            last->next = pA;
            last = pA;
            pA = pA->next;
            pB = pB->next;
        }
    }
    
    // 让C的尾部指向头结点，保持循环链表的结构
    last->next = C;
    
    // 释放原链表A和B的头结点
    A->next = A;
    B->next = B;
    
    return C;
}

int main() {
    Node* A = createCircularList();
    Node* B = createCircularList();
    
    // 初始化集合A
    insertOrdered(A, 1);
    insertOrdered(A, 3);
    insertOrdered(A, 5);
    insertOrdered(A, 7);
    
    // 初始化集合B
    insertOrdered(B, 2);
    insertOrdered(B, 4);
    insertOrdered(B, 6);
    insertOrdered(B, 7);  // 包含重复元素

    printf("集合A: ");
    printList(A);
    
    printf("集合B: ");
    printList(B);
    
    // 合并A和B到C
    Node* C = mergeSets(A, B);
    
    printf("集合C (A∪B): ");
    printList(C);
    
    return 0;
}
