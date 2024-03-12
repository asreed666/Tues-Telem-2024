#ifndef DISPLAY
#define DISPLAY

typedef struct {
    char buffer[80]; // ascii string of data to be displayed
    int displayType; // this lets display task know the requester (temp, light, etc)
} message_t;

void displayTask();
void displayPanel();
int stringcpy(char*, char*);
int nstringcpy(char*, char*, int);
int stringlen(char*);
void queueMessage(message_t);
#endif