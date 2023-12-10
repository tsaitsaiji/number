#include <stdio.h>
#include <string.h>

// �w�q�ǥ͵��c
struct Student {
    char name[50];
    int studentID;
    float grade;
};

// ����n��
void addStudent(struct Student students[], int *studentCount);
void displayAllStudents(const struct Student students[], int studentCount);
void queryStudent(const struct Student students[], int studentCount);
void editStudent(struct Student students[], int studentCount);

int main() {
    struct Student students[100]; // �̦h�s�x100�W�ǥ�
    int studentCount = 0; // �ǥͼƶq

    int choice;

    do {
        // ��ܵ��
        printf("\n----- �ǥͺ޲z�t�� -----");
        printf("\n1. �K�[�ǥ�");
        printf("\n2. ��ܩҦ��ǥ�");
        printf("\n3. �d�߾ǥ�");
        printf("\n4. �s��ǥͫH��");
        printf("\n5. �h�X");
        printf("\n�п�ܾާ@�]1-5�^: ");
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
                printf("�P�¨ϥΡA�A���I\n");
                break;
            default:
                printf("�L�Ŀﶵ�A�Э��s��ܡC\n");
        }
    } while (choice != 5);

    return 0;
}

void addStudent(struct Student students[], int *studentCount) {
    // �K�[�ǥͫH��
    struct Student newStudent;

    printf("\n�п�J�ǥͩm�W: ");
    scanf("%s", newStudent.name);

    printf("�п�J�ǥ;Ǹ�: ");
    scanf("%d", &newStudent.studentID);

    printf("�п�J�ǥͦ��Z: ");
    scanf("%f", &newStudent.grade);

    // �K�[��ǥͰ}�C
    students[*studentCount] = newStudent;
    (*studentCount)++;

    printf("�ǥͲK�[���\�I\n");
}

void displayAllStudents(const struct Student students[], int studentCount) {
    // ��ܩҦ��ǥͫH��
    printf("\n----- �Ҧ��ǥ� -----");
    for (int i = 0; i < studentCount; i++) {
        printf("\n�m�W: %s, �Ǹ�: %d, ���Z: %.2f", students[i].name, students[i].studentID, students[i].grade);
    }
    printf("\n");
}

void queryStudent(const struct Student students[], int studentCount) {
    // �d�߾ǥͫH��
    int queryID;
    printf("\n�п�J�n�d�ߪ��ǥ;Ǹ�: ");
    scanf("%d", &queryID);

    int found = 0;

    for (int i = 0; i < studentCount; i++) {
        if (students[i].studentID == queryID) {
            printf("�m�W: %s, �Ǹ�: %d, ���Z: %.2f\n", students[i].name, students[i].studentID, students[i].grade);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("�����Ǹ��� %d ���ǥ͡C\n", queryID);
    }
}

void editStudent(struct Student students[], int studentCount) {
    // �s��ǥͫH��
    int editID;
    printf("\n�п�J�n�s�誺�ǥ;Ǹ�: ");
    scanf("%d", &editID);

    int found = 0;

    for (int i = 0; i < studentCount; i++) {
        if (students[i].studentID == editID) {
            printf("��e�H���G�m�W: %s, �Ǹ�: %d, ���Z: %.2f\n", students[i].name, students[i].studentID, students[i].grade);

            printf("�п�J�s���ǥͩm�W: ");
            scanf("%s", students[i].name);

            printf("�п�J�s���ǥͦ��Z: ");
            scanf("%f", &students[i].grade);

            printf("�ǥͫH���s�覨�\�I\n");
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("�����Ǹ��� %d ���ǥ͡C\n", editID);
    }
}
