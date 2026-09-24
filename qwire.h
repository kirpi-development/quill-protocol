#include <stdint.h>
#include <stdio.h>


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