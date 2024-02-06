/*
 * Thread to take messages from the other modules and display them on 
 * the screen or lcd or whatever.
 */
//#define VT100
//#define POOR_MANS
#define UTF8 
#include "mbed.h"
#include "display.h"
#include "config.h"
#include "vt100.h"



int stringcpy(char* b, char* a) { // local version of strcpy
    int i = 0;
    while (a[i] != NULL) {
        b[i] = a[i];
        i++;
    }
    return i;
}

void displayPanel() {
    HOME;
    ThisThread::sleep_for(10);
    
    printf("┌──────────────────────────────────────────────────────────────────────┐\n");
    printf("│                                                                      │\n");
    printf("├──────────────────────┬───────────┬───────────────────────┬───────────┤\n");
    printf("│ Temperature Reading  │           │                       │           │\n");
    printf("├──────────────────────┼───────────┼───────────────────────┼───────────┤\n");
    printf("│ Temperature Setting  │           │                       │           │\n");
    printf("├──────────────────────┼───────────┼───────────────────────┼───────────┤\n");
    printf("│ Heater State         │           │                       │           │\n");
    printf("└──────────────────────┴───────────┴───────────────────────┴───────────┘\n");

    printf("\033[4;2HTemperature Reading:");
    printf("\033[6;2HTemperature Setting:");
    printf("\033[8;2HHeater State:");
    printf("\033[4;38HLight Level:");
    printf("\033[6;38HLight Setting:");
    printf("\033[8;38HLight State:");


}

static MemoryPool<message_t, 32> mpool;
static Queue<message_t, 32> queue;

void queueMessage(message_t msg){
    message_t *message = mpool.alloc();
    if(message) {
        stringcpy (message->buffer, msg.buffer);
        message->displayType = msg.displayType;
        queue.put(message);
    }
}    

void displayTask() {
    CLS;
    ThisThread::sleep_for(10);
    displayPanel();
    BLUE_BOLD;
    UNDERLINE;
    printf("\033[2;20HCITY1082 Telemetry");
    NORMAL;
    HIDE_CURSOR;
    WHITE_TEXT;

    while (true) {
        osEvent evt = queue.get();
        if (evt.status == osEventMessage) {
            message_t *message = (message_t*)evt.value.p;
            switch(message->displayType) {
                case TEMP_DISPLAY: {
                    printf("\033[4;28H");
                    printf("%s", message->buffer);
                    break;
                }
                case TEMP_SET: {
                    printf("\033[6;28H");
                    printf("%s", message->buffer);
                    break;
                }
                case HEATER_ON: {
                    printf("\033[8;28H");
                    printf("%s", message->buffer);
                    break;
                }
                case LIGHT_DISPLAY: {
                    printf("\033[4;64H");
                    printf("%s", message->buffer);
                    break;
                }
                case LIGHT_SET: {
                    printf("\033[6;64H");
                    printf("%s", message->buffer);
                    break;
                }
                case LIGHT_ON: {
                    printf("\033[8;64H");
                    printf("%s", message->buffer);
                    break;
                }
                default:
                    break;
            }
//            printf("%d %s\n", message->displayType, message->buffer);
            mpool.free(message);
        }
    }
}