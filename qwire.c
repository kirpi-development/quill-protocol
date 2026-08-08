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
        printf("HATA: Q-Wire basligi gonderilemedi!\n");
        return -1;
    }

    printf("Q-Wire basligi firlatildi! (%d byte)\n", sent_bytes);
    return 0;
}