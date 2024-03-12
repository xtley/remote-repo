#include <stdio.h>
#include <stdlib.h>

// ѧ����Ϣ
struct student {
    int Num;
    float score; // �ɼ�
    struct student* next;
};

struct student* create();
float average(struct student* head);
struct student* excellent(struct student* head, float ave);
int main() {
    struct student* head = create(),*excellent_head;
    head=create();
    excellent_head = excellent(head, average(head));
    pr(excellent_head);
    return 0;
}

struct student* create() {
    // ʵ�ֹ���: �Ӽ������� 20 ��ѧ������Ϣ����β�巨����������������ͷ��
    struct student* head = NULL;
    struct student* tail = NULL;
    int i;
    for (i = 0; i < 20; i++) {
        struct student* stu = (struct student*)malloc(sizeof(struct student));
        printf("������ѧ�� [%d] ��ѧ�ţ�", i + 1);
        scanf("%d", &(stu->Num));
        printf("������ѧ�� [%d] �ĳɼ���", i + 1);
        scanf("%f", &(stu->score));
        stu->next = NULL;
        
        if (head == NULL) {
            head = stu;
            tail = stu;
        } else {
            tail->next = stu;
            tail = stu;
        }
    }
    
    return head;
}

float average(struct student* head) {
    // head Ϊ����ͷ���������� create ��������
    // ʵ�ֹ���: ��������������ѧ����ƽ���ɼ������ظóɼ�
    int count = 0;
    float sum = 0;
    struct student* current = head;
    
    while (current != NULL) {
        count++;
        sum += current->score;
        current = current->next;
    }
    
    return sum / count;
}

struct student* excellent(struct student* head, float ave) {
    // head Ϊ����ͷ��ave Ϊѧ��ƽ���ɼ�
    // ʵ�ֹ���: �Ӹ��������ҳ����г���ƽ���ɼ�������ѧ�������ɼ��Ӹߵ��͵�˳�򴴽�һ������������ͷָ��ɼ���ߵ�ѧ����������������ͷ��
    struct student* excellent_head = NULL;
    struct student* excellent_tail = NULL;
    struct student* current = head;
    
    while (current != NULL) {
        if (current->score > ave) {
            struct student* stu = (struct student*)malloc(sizeof(struct student));
            stu->Num = current->Num;
            stu->score = current->score;
            stu->next = NULL;
            
            if (excellent_head == NULL) {
                excellent_head = stu;
                excellent_tail = stu;
            } else {
                struct student* temp = excellent_head;
                struct student* prev = NULL;
                
                while (temp != NULL && temp->score > stu->score) {
                    prev = temp;
                    temp = temp->next;
                }
                
                if (prev == NULL) {
                    excellent_head = stu;
                } else {
                    prev->next = stu;
                }
                
                stu->next = temp;
            }
        }
        current = current->next;
    }
    
    return excellent_head;    
}



