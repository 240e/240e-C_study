#include <stdio.h>

void print_decimal_cycle(int n, int d) {
    // 化简分数（找最大公约数，这里为了简单不写GCD，直接用你化简后的 570 和 257）
    // 如果分母只有2和5的因子，就是有限小数，否则是无限循环小数
    
    printf("%d.", n / d);  // 打印整数部分
    
    int remainder = n % d; // 首次余数
    
    // 创建一个数组，记录每个余数第一次出现的位置
    // 因为分母是 257，余数最多只有 257 种情况，开个 10000 的数组绝对够用
    int rem_pos[10000];
    for (int i = 0; i < 10000; i++) {
        rem_pos[i] = -1; // -1 表示还没出现过
    }
    
    int digits[10000]; // 记录每一位小数
    int idx = 0;       // 当前是第几位小数
    
    while (remainder != 0 && rem_pos[remainder] == -1) {
        rem_pos[remainder] = idx; // 记录这个余数第一次出现的位置
        
        remainder *= 10;          // 余数乘10，模拟借位
        digits[idx] = remainder / d; // 计算当前位的数字
        remainder = remainder % d;   // 计算新的余数
        idx++;
    }
    
    if (remainder == 0) {
        // 余数为0，说明是有限小数
        printf("(有限小数，无循环节)\n");
        for (int i = 0; i < idx; i++) printf("%d", digits[i]);
        printf("\n");
    } else {
        // 余数重复了！开始打印循环节
        int start = rem_pos[remainder]; // 循环节从第几位开始
        
        for (int i = 0; i < start; i++) {
            printf("%d", digits[i]);    // 打印不循环的部分
        }
        printf("(");
        for (int i = start; i < idx; i++) {
            printf("%d", digits[i]);    // 打印循环节部分
        }
        printf(")\n");
    }
}

int main(void) {
    // 11.4 / 5.14 = 1140 / 514 = 570 / 257
    printf("570 / 257 = ");
    print_decimal_cycle(570, 257);
    
    // 试试经典的 1/3
    printf("1 / 3 = ");
    print_decimal_cycle(1, 3);
    
    return 0;
}