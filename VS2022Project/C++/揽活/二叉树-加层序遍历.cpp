#include <stdio.h>
#include <stdlib.h>

#define MaxSize 100
typedef char DataType;
typedef struct BitNode {
    DataType date;
    struct BitNode* lchild, * rchild;
}BitNode;


typedef struct {
    BitNode* Date[MaxSize];
    int front;
    int back;
} Queue;
int empty(Queue* Q)
{
    if (Q->front == Q->back)
        return 1;
    else
        return 0;
}
void push(Queue* Q, BitNode* item)
{
    if ((Q->back + 1) % MaxSize == Q->front) {
        printf("������\n");
        return;
    }
    else {
        Q->back = (Q->back + 1) % MaxSize;
        Q->Date[Q->back] = item;
    }

}
BitNode* pop(Queue* Q)
{
    if (Q->back == Q->front) {
        printf("���ѿ�\n");
        return NULL;
    }
    else {
        Q->front = (Q->front + 1) % MaxSize;
        return Q->Date[Q->front];
    }
}





BitNode* ByPre(BitNode* root) {
    char ch;
    scanf("%c", &ch);
    if (ch == '#') root = NULL;
    else {
        root = (BitNode*)malloc(sizeof(BitNode));
        root->date = ch;
        root->lchild = ByPre(root->lchild);
        root->rchild = ByPre(root->rchild);
    }
    return root;
}
BitNode* ByInPost(int* in, int* post, int n) {
    if (n == 0) return NULL;
    int i = 0;
    while (i < n && in[i] != post[n - 1]) i++;
    BitNode* node = (BitNode*)malloc(sizeof(BitNode));
    node->date = post[n - 1];
    node->lchild = ByInPost(&in[0], &post[0], i);
    node->rchild = ByInPost(&in[i + 1], &post[i], n - i - 1);
    return node;
}
BitNode* ByPreIn(char* pre, char* in, int n) {
    if (n == 0) return NULL;
    int i = 0;
    while (i < n && in[i] != pre[0]) i++;
    BitNode* node = (BitNode*)malloc(sizeof(BitNode));
    node->date = pre[0];
    node->lchild = ByPreIn(&pre[1], &in[0], i);
    node->rchild = ByPreIn(&pre[i + 1], &in[i + 1], n - i - 1);
    return node;
}
void PreOrder(BitNode* root) {
    if (root == NULL) return;
    else {
        printf("%c ", root->date);
        PreOrder(root->lchild);
        PreOrder(root->rchild);
    }
}
void InOrder(BitNode* root) {
    if (root == NULL) return;
    else {
        InOrder(root->lchild);
        printf("%c ", root->date);
        InOrder(root->rchild);
    }
}
void PostOrder(BitNode* root) {
    if (root == NULL) return;
    else {
        PostOrder(root->lchild);
        PostOrder(root->rchild);
        printf("%c ", root->date);
    }
}

BitNode* CreataBinTree(BitNode* T)
{
    char Date;
    Queue Queue, * Q;
    Q = &Queue;
    Q->front = Q->back = 0;
    BitNode* BT;
    scanf("%c", &Date);
    if (Date != '#') {
        BT = (BitNode*)malloc(sizeof(BitNode));
        BT->date = Date;
        push(Q, BT);
    }
    else
        return NULL;
    while (!empty(Q)) {
        T = pop(Q);
        scanf("%c", &Date);
        if (Date == '#')
            T->lchild = NULL;
        else {
            T->lchild = (BitNode*)malloc(sizeof(BitNode));
            T->lchild->date = Date;
            push(Q, T->lchild);
        }
        scanf("%c", &Date);
        if (Date == '#')
            T->rchild = NULL;
        else {
            T->rchild = (BitNode*)malloc(sizeof(BitNode));
            T->rchild->date = Date;
            push(Q, T->rchild);
        }
    }
    return BT;
}


int main() {

    int flag;
    int n;
    char pre[100];
    char in[100];
    while (1) {
        printf("������ѡ��˵������\n");
        printf("1��������������������У�����������(�սڵ���#��ʾ)\n");
        printf("2���ò�α������������У�����������(�սڵ���#��ʾ)\n");
        printf("3�������������������������У�����������(�սڵ㲻������Ϣ)\n");
        printf("4���˳�\n\n");
        scanf("%d", &flag);
        getchar();
        BitNode* root = NULL;
        if (flag == 1) {
            printf("����������������������У�");
            root = ByPre(root);
            //getchar();
            printf("�ö������������������Ϊ��"); PreOrder(root); printf("\n");
            printf("�ö������������������Ϊ��"); InOrder(root); printf("\n");
            printf("�ö������ĺ����������Ϊ��"); PostOrder(root); printf("\n");
            printf("\n");
        }
        else if (flag == 2) {
            printf("���������������������У�");
            root = CreataBinTree(root);
            printf("�ö������������������Ϊ��"); PreOrder(root); printf("\n");
            printf("�ö������������������Ϊ��"); InOrder(root); printf("\n");
            printf("�ö������ĺ����������Ϊ��"); PostOrder(root); printf("\n");
            printf("\n");
        }
        else if (flag == 3) {
            printf("������������ڵ������");
            scanf("%d", &n);
            getchar();
            printf("����������������������У�");
            scanf("%s", pre);
            getchar();
            printf("����������������������У�");
            scanf("%s", in);
            root = ByPreIn(pre, in, n);
            printf("�ö������������������Ϊ��"); PreOrder(root); printf("\n");
            printf("�ö������������������Ϊ��"); InOrder(root); printf("\n");
            printf("�ö������ĺ����������Ϊ��"); PostOrder(root); printf("\n");
            printf("\n");

        }
        else {
            printf("�˳�\n");
            break;
        }
    }


    return 0;
}
