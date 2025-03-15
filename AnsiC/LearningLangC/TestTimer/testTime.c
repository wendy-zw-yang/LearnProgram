#include <stdio.h>
#include <unistd.h>
#include <conio.h> // 包含 _kbhit 和 _getch 函数

int main() {
    printf("Press 'esc' to exit the dead loop\n");
    int runing=1;
    while (runing) {
        // 执行特定任务
        printf("Execute task...\n");

        for(int i=0;i<5;i++)
        {
            // 检查是否按下了键
            if (_kbhit()) {
                // 获取按下的键
                char ch = _getch();
                // ASCII 27 是 'esc' 键
                if (ch == 27) {
                    printf("Detected 'esc', program been terminated\n");
                    runing=0;
                    break;
                }
            }

            // 休眠一段时间，避免CPU占用过高
            sleep(1); // 单位：秒，这里设置为5秒
        }
    }

    return 0;
}