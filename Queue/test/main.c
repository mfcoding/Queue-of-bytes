#include <stdio.h>
#include <stdlib.h>
#include <cstring.h>
#include "queue.h"

int main()
{
    queue qu = new queue(null); 

    int operation = 1;
    
    while (operation > 0 && operation < 7)
    {
        printf("%s", "\n\033[0;33m");
        puts("Select one of these operations below\n"
        " 1  to add an item to the queue.\n"
        " 2  to remove an item from the queue.\n"
        " 3  to print number of the elements in the queue.\n"
        " 4  to show content of the queue.\n"
        " 5  to shrink the capacity of the queue to fit its content.\n"
        " 6  to remove the entire queue from memory.\n"
        " 0  to exit the program.\033[0m\n");  

        printf("Enter operation code: ");
        scanf("%i", &operation);

        switch (operation)
        {
            case 1:
                printf("%s", "Enter a character to add to queue: ");
                char item;
                scanf(" %c", &item);
                enqueue(&qu, item);
             /* // Also try function enqueue_more() to enqueue multiple items via keyboard as follows
                getchar();
                qu = enqueue_more();
                // and don't forget to comment these lines above from 31 to 33 */
                break;
            case 2:
                if(!empty(&qu.queue))
                {
                    printf("\nThe dequeued character is %c\n", *begin(&qu.queue)); 
                    dequeue(&qu); 
                }
                else
                {
                    puts("Queue is empty.");
                }
                break;
            case 3:
                printf("The queue is holding %llu items (characters).\n", que_count(&qu));
                break;
            case 4:
                if(!empty(&qu.queue))
                {
                    printf("Content of queue: ");
                    que_show(&qu);
                    putchar('\n');
                }
                else
                {
                    puts("Queue is empty.");
                }
                break;
            case 5:
                que_fit(&qu);
                puts("Queue fitted its content successfully."); 
                break;
            case 6:
                que_destroy(&qu);
                puts("Queue removed successfully.");
             /* // Also try function que_clear() as follows
                que_clear(&qu);
                puts("Queue cleared successfully."); 
                // and don't forget to comment these lines 70 and 71 */
                break;
            case 0:
                return 0;
            default:
                printf("Not valid op code.");
                break;
        }
    }
    
    return 0;
}
