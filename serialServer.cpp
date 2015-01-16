#include "serialServer.h"

void SerialServer::begin(unsigned long int baudrate) {
	Serial.begin(baudrate);
}

#define CMD_SIZE 10

char *SerialServer::getCmd(void) {
	int c;
	int static index;
	char static cmd[CMD_SIZE+1];

	if ((c = Serial.read()) != -1) {
		if (index && ((char) c == '\r')) {
			cmd[index] = '\0';
			index = 0;
			return cmd;
		}
		else {
			if (index < CMD_SIZE)
				cmd[index++] = (char) c;
			return 0;
		}
	}
	return 0;
}

void SerialServer::sendMsg(const char *msg) {
	Serial.println(msg);
}


