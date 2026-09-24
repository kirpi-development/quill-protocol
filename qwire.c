#include <stdio.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <stdint.h>
#include "qwire.h"


int send_qwire_header(int sock, uint8_t opcode, uint32_t payload_length) {
    
    
    struct QWireHeader paket;

    
    paket.magic = htons(0xCAFE);
    paket.version = 0x01; 
    paket.opcode = opcode;
    paket.payload_len = htonl(payload_length);
    paket.checksum = htons(0); 

    
    int sent_bytes = send(sock, &paket, sizeof(paket), 0);
    
    if (sent_bytes < 0) {
        printf("ERROR: QWire header could not be sent!\n");
        return -1;
    }

    printf("Q-Wire header sent! (%d byte)\n", sent_bytes);
    return 0;

}

    int receive_qwire_response(int sock){
            uint8_t incoming_data[1024];

    int readed_bytes = recv(sock, incoming_data, sizeof(incoming_data), 0);
    if (readed_bytes < 0) {
        perror("recv failed");
        close(sock);
        exit(1);
    }
    
    if(incoming_data[3]== 0x02) {
        printf("Received QWire Header with opcode: %d\n", incoming_data[3]);
    } 
    else {
        printf("Received unexpected data\n");
    }
    return 0;
    }

