/*   ch21_13.c                 */
#include <stdlib.h>
#include <stdio.h>
struct list            /* ���V�쵲��C�ŧi */ 
{
    int data;
    struct list *front;  /* ���V�U���Ӹ`�I */ 
    struct list *back;   /* ���V�e���Ӹ`�I */ 
};
typedef struct list node;
int main()
{
/* cur�O�ثe�`�I����         */
/* ptr�O�T�w�b�Ĥ@�Ӹ`�I���� */ 
    node  *cur, *ptr, *newnode;
    int   num, i;
    
    printf("�п�J 3 ����� \n");
    for ( i = 0; i < 3; i++ )
    {
    	newnode = (node *) malloc(sizeof(node));
    	scanf("%d",&num);
    	if (i == 0) 		/* �إ߲Ĥ@�Ӹ`�I        */ 
    	{	
    		newnode->back = NULL;
    		newnode->front = NULL;
    		newnode->data = num;
    		cur = newnode;   /* �ثe���Ц�m 		 */
			ptr = newnode; 	 /* �T�w���ܦ�C�}�l��m */ 
		} 
       	if ( i > 0 ) 		 /* �إߨ�L�`�I         */ 
       	{
          	newnode->front = cur;
          	newnode->back = NULL;
          	newnode->data = num;
          	cur->back = newnode;
          	cur = newnode;  /* cur ���V�ҫت��`�I */ 
       	}
    }
    printf("�ϦV�C�L���V�쵲��C\n");
    while ( cur ) 			/* cur �����e��X     */ 
    {
       printf("��C�� ==> %d\n",cur->data);
       cur = cur->front;
    }
    printf("���ǦC�L���V�쵲��C\n");
    cur = ptr; 				/* cur ����̫e�`�I */ 
    while ( cur )
    {
       printf("��C�� ==> %d\n",cur->data);
       cur = cur->back;
    }
    system("pause");
    return 0;
}


