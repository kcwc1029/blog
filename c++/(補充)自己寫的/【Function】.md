![upgit_20241002_1727846450.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/10/upgit_20241002_1727846450.png)

## 基本使用
```c
#include <stdio.h>
#include <stdlib.h>
void greeting(){
    printf("hello\n");
    printf("this is function\n");
    printf("\n");
}

int main()
{
    greeting();
    return 0;
}
```

```c
#include <stdio.h>
#include <stdlib.h>
void printMinMax(int n1, int n2){
    if(n1>=n2)
        printf("max num is %d, min num is %d", n1, n2);
    else
        printf("max num is %d, min num is %d", n2, n1);
}

int main()
{
    int a = 10;
    int b = 20;
    printMinMax(a,b);

    return 0;
}
```

```c
#include <stdio.h>
#include <stdlib.h>
float findAve(int g1, int g2, int g3){
    float avg;
    avg = (g1+g2+g3)/3;
    return avg;
}

int main()
{
    int g1 = 95;
    int g2 = 83;
    int g3 = 74;
    printf("avg =  %f\n", findAve(g1,g2,g3));
    return 0;
}
```

## 內建參數
### rand()
- 在`<stdlib.h>`內定義
```c
#include <stdio.h>
#include <stdlib.h>

int main(){
    int r;
    int rand_max = RAND_MAX; // 隨機數之規範最大質 -> 32767
    printf("rand max: %d\n", rand_max);

    for (int i = 0; i < 5; i++){
        r = rand();
        printf("rand num: %d\n", r);
    }
    return 0;
}
```

### srand()
- 可以搭配seed
```c
#include <stdio.h>
#include <stdlib.h>

int main(){
    int r;
    srand(42);
    for (int i = 0; i < 5; i++){
        r = rand();
        printf("rand num: %d\n", r);
    }
    return 0;
}
```

- 範圍內取隨機(以取1-6為例)
```c
#include <stdio.h>
#include <stdlib.h>

int main(){
    int r;
    srand(42);
    for (int i = 0; i < 5; i++){
        r = rand()%6+1;
        printf("rand num: %d\n", r);
    }
    return 0;
}
```