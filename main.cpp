#include <stdio.h>
#include <Windows.h>
#include <time.h>
#include <functional>

// 結果表示関数（コールバックとして使用）
void DispResult(int* dummy, int* userChoice) {
    int dice = rand() % 2; // 0: 丁（偶数）、1: 半（奇数）

    if (dice == *userChoice) {
        if (dice == 0)
            printf("%dで丁(偶数)でした。当たり！\n", dice);
        else
            printf("%dで半(奇数)でした。当たり！\n", dice);
    }
    else {
        if (dice == 0)
            printf("%dで丁(偶数)でした。はずれ！\n", dice);
        else
            printf("%dで半(奇数)でした。はずれ！\n", dice);
    }
}

// 一定時間待ってからコールバックを呼ぶ（ラムダ不可）
void setTimeout(std::function<void(int*, int*)> callback, int second, int key) {
    for (int i = 0; i < second; ++i) {
        Sleep(1000);
        printf("%d...\n", second - i);
    }

    int dummy = 0; // 意味はないが、関数引数を満たすため
    callback(&dummy, &key);
}

int main() {
    int userInput;

    srand(static_cast<unsigned int>(time(NULL)));

    printf("丁(偶数)なら0、半(奇数)なら1を入力してください: ");
    scanf_s("%d", &userInput);

    if (userInput == 0) {
        puts("あなたは丁(偶数)を選びました。");
    }
    else {
        puts("あなたは半(奇数)を選びました。");
    }

    // ラムダ式でユーザー入力をキャプチャし、コールバック関数を作成
    std::function<void(int*, int*)> callback = [=](int* s, int* k) {
        DispResult(s, k);
        };

    // SetTimeout関数で3秒待ってから結果を表示
    setTimeout(callback, 3, userInput);

    return 0;
}
