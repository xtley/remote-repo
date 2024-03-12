#include <stdio.h>
#include <stdlib.h>

// 学生信息
struct student {
    int Num;
    float score; // 成绩
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
    // 实现功能: 从键盘输入 20 个学生的信息，用尾插法创建链表并返回链表头。
    struct student* head = NULL;
    struct student* tail = NULL;
    int i;
    for (i = 0; i < 20; i++) {
        struct student* stu = (struct student*)malloc(sizeof(struct student));
        printf("请输入学生 [%d] 的学号：", i + 1);
        scanf("%d", &(stu->Num));
        printf("请输入学生 [%d] 的成绩：", i + 1);
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
    // head 为链表头，该链表由 create 函数建立
    // 实现功能: 计算链表中所有学生的平均成绩并返回该成绩
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
    // head 为链表头，ave 为学生平均成绩
    // 实现功能: 从该链表中找出所有超过平均成绩的优秀学生，按成绩从高到低的顺序创建一个新链表，链表头指向成绩最高的学生，并返回新链表头。
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



