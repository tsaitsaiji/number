#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // �����H���ƺؤl
    srand(time(NULL));

    // �ͦ��@�� 1 �� 100 �������H����
    int secretNumber = rand() % 100 + 1;
    int guess, attempts = 0;

    printf("�w��Ө�q�Ʀr�C���I\n");

    do {
        printf("�п�J�@�Ӳq�����Ʀr (1-100): ");
        scanf("%d", &guess);
        attempts++;

        if (guess == secretNumber) {
            printf("���ߧA�A�q��F�I�A�ΤF %d �����աC\n", attempts);
        } else if (guess < secretNumber) {
            printf("�q���Ʀr�Ӥp�F�A�A�դ@���C\n");
        } else {
            printf("�q���Ʀr�Ӥj�F�A�A�դ@���C\n");
        }
    } while (guess != secretNumber);

    return 0;
}
