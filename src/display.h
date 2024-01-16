#ifndef DISPLAY
#define DISPLAY

typedef struct {
    char buffer[80]; // ascii string of data to be displayed
    int displayType; // this lets display task know the requester (temp, light, etc)
} message_t;

void displayTask();
void queueMessage(message_t);
#endif