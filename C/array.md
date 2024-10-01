- 占有一塊連續的記憶體空間

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

```c

```

```c

```

```c

```

```c

```

```c

```

```c

```

```c

```

```c

```

```c

```

```c

```

```c

```