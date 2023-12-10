#include <stdio.h>
#include <string.h>

// 定義學生結構
struct Student {
    char name[50];
    int studentID;
    float grade;
};

// 函數聲明
void addStudent(struct Student students[], int *studentCount);
void displayAllStudents(const struct Student students[], int studentCount);
void queryStudent(const struct Student students[], int studentCount);
void editStudent(struct Student students[], int studentCount);

int main() {
    struct Student students[100]; // 最多存儲100名學生
    int studentCount = 0; // 學生數量

    int choice;

    do {
        // 顯示菜單
        printf("\n----- 學生管理系統 -----");
        printf("\n1. 添加學生");
        printf("\n2. 顯示所有學生");
        printf("\n3. 查詢學生");
        printf("\n4. 編輯學生信息");
        printf("\n5. 退出");
        printf("\n請選擇操作（1-5）: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStudent(students, &studentCount);
                break;
            case 2:
                displayAllStudents(students, studentCount);
                break;
            case 3:
                queryStudent(students, studentCount);
                break;
            case 4:
                editStudent(students, studentCount);
                break;
            case 5:
                printf("感謝使用，再見！\n");
                break;
            default:
                printf("無效選項，請重新選擇。\n");
        }
    } while (choice != 5);

    return 0;
}

void addStudent(struct Student students[], int *studentCount) {
    // 添加學生信息
    struct Student newStudent;

    printf("\n請輸入學生姓名: ");
    scanf("%s", newStudent.name);

    printf("請輸入學生學號: ");
    scanf("%d", &newStudent.studentID);

    printf("請輸入學生成績: ");
    scanf("%f", &newStudent.grade);

    // 添加到學生陣列
    students[*studentCount] = newStudent;
    (*studentCount)++;

    printf("學生添加成功！\n");
}

void displayAllStudents(const struct Student students[], int studentCount) {
    // 顯示所有學生信息
    printf("\n----- 所有學生 -----");
    for (int i = 0; i < studentCount; i++) {
        printf("\n姓名: %s, 學號: %d, 成績: %.2f", students[i].name, students[i].studentID, students[i].grade);
    }
    printf("\n");
}

void queryStudent(const struct Student students[], int studentCount) {
    // 查詢學生信息
    int queryID;
    printf("\n請輸入要查詢的學生學號: ");
    scanf("%d", &queryID);

    int found = 0;

    for (int i = 0; i < studentCount; i++) {
        if (students[i].studentID == queryID) {
            printf("姓名: %s, 學號: %d, 成績: %.2f\n", students[i].name, students[i].studentID, students[i].grade);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("未找到學號為 %d 的學生。\n", queryID);
    }
}

void editStudent(struct Student students[], int studentCount) {
    // 編輯學生信息
    int editID;
    printf("\n請輸入要編輯的學生學號: ");
    scanf("%d", &editID);

    int found = 0;

    for (int i = 0; i < studentCount; i++) {
        if (students[i].studentID == editID) {
            printf("當前信息：姓名: %s, 學號: %d, 成績: %.2f\n", students[i].name, students[i].studentID, students[i].grade);

            printf("請輸入新的學生姓名: ");
            scanf("%s", students[i].name);

            printf("請輸入新的學生成績: ");
            scanf("%f", &students[i].grade);

            printf("學生信息編輯成功！\n");
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("未找到學號為 %d 的學生。\n", editID);
    }
}
