## 字元陣列

```c
// 字元陣列
char arr[] = {'A', 'B', 'C'};
// string
char name[] = "TA"; // 相當於 {"T", "A", "\0"};
```

- 使用fget跟puts
```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    char str[100];
    printf("input string\t");
    fgets(str, sizeof(str), stdin); // 讀取字串，包括換行符

    puts(str);       // 輸出字串，會包含輸入中的換行符，並且puts()再加一個換行
    puts(&str[4]);   // 從索引 4 開始輸出，若字串仍有換行符也會輸出
    puts(str + 4);   // 與 puts(&str[4]) 一樣
    return 0;
}
// TA123

// 3

// 3
// 
```

## 字串處裡相關函數
- `#include <string.h>`

### strcat()
- 字串合併
```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char s1[100] = "NCKU";
    char s2[100] = "Department of Engineering Science";

    strcat(s1, "--");
    strcat(s1, s2);
    puts(s1);
    return 0;
}
```

### strcmp()
- compare the size of s1 s2
    - s1 < s2：-1
    - s1 = s2：0
    - s1 > s2：1
```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char s1[100] = "NCKU";
    char s2[100] = "Department of Engineering Science";
    int i = strcmp(s1, s2);
    printf("%d", i);

    return 0;
}
```

### strcpy()
- copy string
```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char s1[100] = "NCKU";
    char s2[100] = "Department of Engineering Science";
    strcpy(s1, s2);
    puts(s1);
    puts(s2);
    return 0;
}
// Department of Engineering Science
// Department of Engineering Science
```
### strlen()
- return the size of string
```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char s1[100] = "NCKU";
    int i = strlen(s1);
    printf("%d", i);
    return 0;
}
// 4
```

### Convert to uppercase/lowercase
```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char s1[100] = "Department of Engineering Science";
    strupr(s1);
    puts(s1);
    strlwr(s1);
    puts(s1);
    return 0;
}
// DEPARTMENT OF ENGINEERING SCIENCE
// department of engineering science
```

### strrev()
- reversr string
```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char s1[100] = "Department of Engineering Science";
    strrev(s1);
    puts(s1);
    return 0;
}
// ecneicS gnireenignE fo tnemtrapeD
```

## 字串陣列
```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char s[3][100];
    for(int i=0;i<3;i++){
        puts("input fruit");
        fgets(s[i], sizeof(s[i]), stdin);
    }
    
    for(int i=0;i<3;i++){
        printf("%s", s[i]);
    }
    return 0;
}
```