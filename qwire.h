#include <stdint.h>
#include <stdio.h>
#include <string.h>


    #pragma pack(push, 1)

struct QWireHeader {
    uint16_t magic;
    uint8_t version;
    uint8_t opcode;
    uint32_t payload_len;
    uint16_t checksum;
    };
    #pragma pack(pop)

    int receive_qwire_response(int sock);

    int send_qwire_message(int sock, uint8_t opcode, uint32_t payload_length, const void *message);

    int socket_connect(const char *ip, int port);