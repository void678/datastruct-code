#include <iostream>
using namespace std;

typedef int ElemType;
 
typedef struct LNode {
    ElemType data;       
    struct LNode* next;    
}LNode, *LinkList;


//Function1:初始化链表
void InitList(LinkList &L) {
    L = NULL;
}

// 头插法建立单链表
void LinkedListCreateHeadInsert(LinkList &L, int n) {

    printf("输入节点数据(头插法): ");
    for (int i = 0; i < n; ++i) {
        LNode* p;
        p = new LNode; 
       
        cin >> p->data;   
        p->next = L;           
        L = p;             
    }
}


//尾插法建立单链表
void LinkedListCreateTailInsert(LinkList &L, int n) {


    LNode *p;
    p=L;
    printf("输入节点数据(尾插法): ");
    for (int i = 0; i < n; i++) {
        LNode *s;
        s=new LNode;
        if (s == NULL) {
            exit(1); 
        }
     
        cin>>s->data;
        s->next=NULL;
        if (L == nullptr) { // 如果链表为空
            L = s; // 将新节点设为链表的头
            p = s; // 更新尾节点
        } else {
            p->next = s; // 将当前尾节点的next指向新节点
            p = s; // 更新尾节点为新节点
        }  
    }
}


//Function2:摧毁该链表
void DestroyList(LinkList &L) {
    LNode* p;
    while (L != NULL) {
        p = L;          // 保存当前节点
        L = L->next;   // 移动到下一个节点
        delete p;      // 释放当前节点的内存
    }
}


//Function3：清空该链表
void ClearList(LinkList &L) {
    LNode* p;
    while (L != NULL) {
        p = L;          // 保存当前节点
        L = L->next;   // 移动到下一个节点
        delete p;      // 释放当前节点的内存
    }
    L = NULL;
}



//Function 4 :判定是否为空链表
bool ListEmpty(LinkList L){

    return (L==NULL);

}



//Function 5:返回链表长度
int ListLength(LinkList L) {
    int cou = 0;  // 初始化长度为0
    LNode* p = L; // 指向当前节点

    while (p != NULL) {
        cou++;      // 每遇到一个节点，长度加1
        p = p->next; // 移动到下一个节点
    }

    return cou;   // 返回链表长度
}


//Function 6:返回第i个结点的元素值,并用e返回
bool GetElem(LinkList L, int i, int &e) {

    int cou = 1; // 从 1 开始计数
    LNode* q;
    q = L; // 指向当前节点

    // 遍历链表
    while (q != NULL && cou < i) {
        q = q->next; // 移动到下一个节点
        cou++; // 更新计数
    }

    
    if (q != NULL) {
        e = q->data; // 获取节点的元素值
        return 1; // 找到并成功返回
    } else {
        cout<<"NULL"<<endl;
        return 0; // 未找到第 i 个节点
    }
}


//Function7：返回元素e所在的位置
int LocateElem(LinkList L, int e) {
    int cou = 1; // 从 1 开始计数
    LNode* q;
    q = L; // 指向当前节点

    // 遍历链表
    while (q != NULL) {
        if (q->data == e) {
            return cou; // 找到元素，返回其位置
        }
        q = q->next; // 移动到下一个节点
        cou++; // 更新索引
    }

    return 0; 
}


//Function8: 返回cur_e的直接前驱元素,并用pre_e返回
bool PriorElem(LinkList L, int cur_e, int& pre_e) {
    if (L == NULL || L->next == NULL) {
        return false; // 链表为空或只有一个元素，没有前驱
    }

    LNode* q = L->next; // 从第一个元素开始遍历
    LNode* pre = L;       // 之前的节点初始化为头结点

    // 遍历链表
    while (q != NULL) {
        if (q->data == cur_e) {
            pre_e = pre->data; // 找到前驱元素
            return true; // 返回成功
        }
        pre = q; // 移动 previous 到当前节点
        q = q->next; // 移动 current 到下一个节点
    }

    return false; // 如果未找到 cur_e
}


//Function9:返回cur_e的直接后驱元素,并用next_e返回
bool NextElem(LinkList L, int cur_e, int& next_e) {
    if (L == NULL || L->next == NULL) {
        return false; // 链表为空或只有一个元素，没有后驱
    }

    LNode* q = L->next; // 从第一个元素开始遍历

    // 遍历链表
    while (q != NULL) {
        if (q->data == cur_e) {
            if (q->next != NULL) {
                next_e = q->next->data; // 找到后驱元素
                return true; // 返回成功
            } else {
                return false; // cur_e 是最后一个元素，没有后驱
            }
        }
        q = q->next; // 移动到下一个节点
    }

    return false; // 如果未找到 cur_e
}





//Function10:在第i个结点前/后插入元素e
bool ListInsert(LinkList &L, int i, int e) {
    if (i < 1) return false; 

    LNode* q = new LNode;
    q->data=e;
    q->next=NULL;

    if (i == 1) { // 如果在第一个节点前插入
        q->next = L; // 新节点指向原头节点
        L = q; // 更新头节点
        return true;
    }

    LNode* p = L;
    for (int j = 1; j < i - 1; ++j) {
        if (p == NULL) return false; // i 超出链表长度
        p = p->next;
    }

    if (p == NULL) return false; // i 超出链表长度

    q->next = p->next; // 新节点指向当前节点的下一个节点
    p->next = q; // 当前节点指向新节点

    return true;
}

// 在第 i 个节点后插入 e
bool ListInsert1(LinkList &L, int i, int e) {
    if (i < 1) return false; // i 必须大于等于 1

    LNode* q = new LNode;
    q->data=e;
    q->next=NULL;

    LNode* p = L;
    for (int j = 1; j < i; ++j) {
        if (p == NULL) return 0; // i 超出链表长度
        p = p->next;
    }

    if (p == NULL) return 0; // i 超出链表长度

    q->next = p->next; // 新节点指向当前节点的下一个节点
    p->next = q; // 当前节点指向新节点

    return 1;
}

//Function11: 删除第i个结点,并用e返回其元素值
bool ListDelete(LinkList &L, int i, int &e) {
    if (i < 1 || L == NULL) return false; // i 必须大于等于 1 且链表非空

    LNode* p = L;

    if (i == 1) { // 删除第一个节点
        e = L->data; // 保存要删除的节点值
        L = L->next; // 更新头节点
        delete p; // 释放被删除节点的内存
        return 1;
    }

    LNode* prev = NULL;
    for (int j = 1; j < i; ++j) {
        if (p == NULL) return 0; // i 超出链表长度
        prev = p; // 保存前驱节点
        p = p->next; // 移动到下一个节点
    }

    if (p == NULL) return 0; // i 超出链表长度

    e = p->data; // 保存要删除的节点值
    prev->next = p->next; // 前驱节点指向被删除节点的下一个节点
    delete p; // 释放被删除节点的内存

    return 1;
}



//Function 12:打印链表
void ListTraverse(LinkList L) {
    LNode* p = L;
    while (p != NULL) {
        cout << p->data << " -> ";
        p = p->next;
    }
    cout<<"NULL"<<endl;
}
