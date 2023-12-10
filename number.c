#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // 產生隨機數種子
    srand(time(NULL));

    // 生成一個 1 到 100 之間的隨機數
    int secretNumber = rand() % 100 + 1;
    int guess, attempts = 0;

    printf("歡迎來到猜數字遊戲！\n");

    do {
        printf("請輸入一個猜測的數字 (1-100): ");
        scanf("%d", &guess);
        attempts++;

        if (guess == secretNumber) {
            printf("恭喜你，猜對了！你用了 %d 次嘗試。\n", attempts);
        } else if (guess < secretNumber) {
            printf("猜的數字太小了，再試一次。\n");
        } else {
            printf("猜的數字太大了，再試一次。\n");
        }
    } while (guess != secretNumber);

    return 0;
}
