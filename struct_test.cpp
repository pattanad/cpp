#include <iostream>
#include <string>
#include <cstring>

using namespace std; 

typedef struct _SatcomTcpDataPacketHdr
{
    unsigned int totalLen;    // Total length of the data: header + payload;
    unsigned short hdrLen;      // Header length;
    unsigned short status;      // ctCoreRC code to indicate the status of the processing; 
    unsigned short version;     // Protocol version, starting with 1;
    unsigned short payloadType; // 1: request, payload; 2: response status, data is ctCoreRC code in 
                          // "status" field;
                          // 3: set log level request, new log level is specified in "status" 
                          // field;
    unsigned int timestamp;   // Timestamp;
    unsigned int sequenceNum; // Request sequence number. Set by request and returned in response for
                          // correlation;
    unsigned int reserved1;   // Reserved field for future use;
} SatcomTcpDataPacketHdr;

typedef struct _SatcomTcpDataPacket
{
    SatcomTcpDataPacketHdr hdr;        // Header;
    char                   payload[1]; // Payload in bytes.
} SatcomTcpDataPacket;



int main () {
	cout << sizeof(SatcomTcpDataPacketHdr) << endl;
	SatcomTcpDataPacket packet; 

	string payload = "This is a test message"; 

	char* message = (char *)payload.c_str(); 
	memcpy(packet.payload, message, payload.size()); 

	cout << packet.payload << endl; 
	return 0;
}