- 占有一塊連續的記憶體空間

## initialization
```c
int arr[3] = {5,7,10}; // array of int
float arr[3] = {5.1,7.1,10.1}; // array of float
char arr[3] = {'a', 'b', 'c'}; // array of charts

int arr[5] = {0}; //相當於{0,0,0,0,0}
int arr[5] = {1,2}; //相當於{1,2,0,0,0}
```

```c
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int Score[5] = {87, 66, 90, 65, 70}; // Define an integer array Score[5] and assign scores
    int i = 0;
    float Total = 0;

    for (i = 0; i < 5; i++) {
        printf("The score of student %d is: %d\n", i + 1, Score[i]);
        Total += Score[i]; // Calculate total score
    }

    printf("Total: %.1f   Average: %.1f\n", Total, Total / 5); // Output total and average score
    return 0;
}
```

## Element Accessing
```c
#include <stdio.h>
#include <stdlib.h>

int main(){
    int grades[5];
    int low_grage;
    for(int i=0;i<5;i++){
        printf("enter grade no.%d\t", i);
        scanf("%d", &grades[i]);
    }

    low_grage = grades[0];
    for(int i=0;i<5;i++){
        if(grades[i]<low_grage)
            low_grage = grades[i];
    }
    printf("low grade: %d", low_grage);
    return 0;
}
```

## 超出邊界
```c
#include <stdio.h>
#include <stdlib.h>

int main(){
    int arr[3] = {1,2,3,};
    for (int i = 0; i < 5; i++){
        printf("arr num: %d\n", arr[i]);
    }
    return 0;
}
// arr num: 1
// arr num: 2
// arr num: 3
// arr num: 3
// arr num: 4194432
```

## 查看arr的記憶體空間與長度
```c
#include <stdio.h>
#include <stdlib.h>

int main(){
    int arr1[1];
    float arr2[1];
    char arr3[1];
    printf("%d\n", sizeof(arr1));
    printf("%d\n", sizeof(arr2));
    printf("%d\n", sizeof(arr3));
    return 0;
}
// 4
// 4
// 1
```