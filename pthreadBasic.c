#include<pthread.h>
#include<stdio.h>

struct char_print_params
{
    // The character to print.
    char character;

    // The number of times to print
    int count;
};

void *char_print(void *paramters)
{
    // Cast the void pointer to the right type.
    struct char_print_params *p = (struct char_print_params *)paramters;
    int i;

    for(i = 0; i < p->count; ++i)
    {
        fputc(p->character, stderr);
    }
    return NULL;
}

int main()
{
    pthread_t thread1_id;
    pthread_t thread2_id;

    struct char_print_params thread1_args;
    struct char_print_params thread2_args;

    thread1_args.character = 'x';
    thread1_args.count = 1000;
    pthread_create(&thread1_id, NULL, char_print, &thread1_args);

    thread2_args.character = 'o';
    thread2_args.count = 1000;
    pthread_create(&thread2_id, NULL, char_print, &thread2_args);

    pthread_join(thread1_id, NULL);
    pthread_join(thread2_id, NULL);    
    return 0;
}
