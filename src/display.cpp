/*
 * Thread to take messages from the other modules and display them on 
 * the screen or lcd or whatever.
 */

#include "mbed.h"
#include "display.h"
#include "config.h"
#include "string.h"
char* strcpy(char*, char*);  // fool syntax checker


static MemoryPool<message_t, 32> mpool;
static Queue<message_t, 32> queue;

void queueMessage(message_t msg){
    message_t *message = mpool.alloc();
    strcpy ( message->buffer, msg.buffer);
    message->displayType = msg.displayType;
    if(message) {
        queue.put(message);
    }
}    

void displayTask() {
    while (true) {
        osEvent evt = queue.get();
        if (evt.status == osEventMessage) {
            message_t *message = (message_t*)evt.value.p;
            printf("%d %s\n", message->displayType, message->buffer);
            mpool.free(message);
        }
    }
}