## 運算式簡介
- 根據運算子在運算式中的位置，我們可以將運算式分為以下三種表示法
    - 中序法 (infix)：運算子位於兩個運算元中間。例如 A + B、(A + B) * (C + D) 等都屬於中序表示法。
    - 前序法 (prefix)：運算子位於運算元的前面。例如 +AB、* + AB + CD 等都屬於前序表示法。
    - 後序法 (postfix)：運算子位於運算元的後面。例如 AB+、AB+CD+* 等都屬於後序表示法。

## 運算式分類
- 根據運算元的個數可分為三種：
- 一元運算式：包含一個運算元並由一元運算子操作。例如 -100 (負數)、tmp-- (遞減)、sum++ (遞增) 等。
- 二元運算式：包含兩個運算元並由二元運算子操作。例如 A + B、A == 10 (判斷相等)、x += y (累加) 等。
- 三元運算式：包含三個運算元，使用條件運算子 ? 和 :。例如 a > b ? 'Y' : 'N'，這種運算式的形式也被稱為條件運算式。

## 各類運算子
### 指定運算子
### 算術運算子
### 關係運算子
- 大於、小於...
### 邏輯運算子
- AND：`&&`
- OR：`||`
- NOT：`!`
### 位元運算子

## if
```c
// 計算停車費用，40/hr且>1hr才開始收費
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int t, total;
    printf("If parking exceeds one hour, the fee is 40 dollars per hour.\n");
    printf("Please enter the number of hours parked: ");
    scanf("%d", &t); // Input hours
    if (t >= 1){
        total = t * 40; // Calculate the total cost
        printf("Parking time: %d hours, Total cost: %d dollars\n", t, total);
    }
    return 0;
}
```



```c
// 判斷為2為3但不為6倍數之整數
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int value;
    printf("Please enter an integer: ");
    scanf("%d", &value); // Input any integer

    if ((value % 2 == 0) || (value % 3 == 0)) {
        if (value % 6 == 0)
            printf("The condition is met.\n");
        else
            printf("Does not meet the specified condition.\n"); // A multiple of 2 or 3, but not 6
    }
    else
        printf("Does not meet the specified condition.\n"); // Not divisible by 2 or 3
    return 0;
}
```

```c
// 依照不同消費金額給折扣
// 10萬元 -> 15%
// 5萬元 -> 10%
// 2萬元以下 -> 5%

#include <stdio.h>
#include <stdlib.h>

int main(){
    float cost = 0; // Declare a float variable
    printf("Please enter the total consumption amount: ");
    scanf("%f", &cost);
    if (cost >= 100000)
        cost = cost * 0.85; // 15% discount for cost above 100,000
    else if (cost >= 50000)
        cost = cost * 0.9; // 10% discount for cost between 50,000 and 100,000
    else
        cost = cost * 0.95; // 5% discount for cost below 50,000

    printf("The actual total cost: %.1f dollars\n", cost);
    return 0;
}
```

## switch
```c
// 根據使用者輸入的數字，輸出相應的星期幾名稱。
#include <stdio.h>

int main()
{
    int day;

    // 提示使用者輸入星期幾
    printf("Enter a number (1-7) to display the day of the week: ");
    scanf("%d", &day);

    // 使用 switch 判斷輸入的數字
    switch (day)
    {
    case 1:
        printf("Monday\n");
        break;
    case 2:
        printf("Tuesday\n");
        break;
    case 3:
        printf("Wednesday\n");
        break;
    case 4:
        printf("Thursday\n");
        break;
    case 5:
        printf("Friday\n");
        break;
    case 6:
        printf("Saturday\n");
        break;
    case 7:
        printf("Sunday\n");
        break;
    default:
        printf("Invalid input! Please enter a number between 1 and 7.\n");
        break;
    }
    return 0;
}
```

## for
```c
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int num;
    printf("enter a number ");
    scanf("%d", &num);
    for (int i = 0; i < num; i++)
    {
        printf("%d", i);
    }
    
    return 0;
}
```

```c
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n;
    printf("enter a number ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++){
        for (int j = 0; j <= i; j++){
            printf("%d ", j);
        }
        printf("\n");
    }
    
    return 0;
}
```

## while
```c
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n = 1;
    while(n<10){
        printf("*");
        n++;
    }
    return 0;
}
```

```c
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i=0;
    printf("enter a number of star you want to see.\t");
    scanf("%d", &n);
    while(i<n){
        printf("*");
        i++;
    }
    return 0;
}
```

- 計算輸入的成績總和及其平均值，當用戶輸入 -1 時停止輸入。
```c
int main()
{
    int grade;
    int totalSum = 0, gradesCount = 0;

    printf("Please enter your grades or '-1' to stop: ");
    scanf("%d", &grade);

    while (grade != -1)
    {
        totalSum = totalSum + grade;
        gradesCount++;
        printf("Please enter your grades or '-1' to stop: ");
        scanf("%d", &grade);
    }

    if (gradesCount > 0)
    {
        float average = (float)totalSum / gradesCount;
        printf("You've entered %d grades! \n", gradesCount);
        printf("And your AVERAGE GRADE is %.2f\n", average);
    }
    else
    {
        printf("No grades were entered.\n");
    }

    return 0;
}
```



## break&continue
```c
#include <stdio.h>
#include <stdlib.h>

int main(){
    int i = 0;
    while(i<10){
        if(i==5)
            break;
        printf("%d ", i);
        i++;
    }
    return 0;
}
```

```c
#include <stdio.h>
#include <stdlib.h>

int main(){
    int i = 0;
    while(i < 10){
        if(i == 5){
            i++;         // 先增量，然後再跳過當前迴圈
            continue;
        }
        printf("%d ", i);
        i++;
    }
    return 0;
}
```
