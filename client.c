#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

int main() {
    int sock;
    struct sockaddr_in server_addr;
    char* message = "Merhaba, ben NeuroLink Sentinel ajani!";
//hedef belirledim
    sock = socket(AF_INET, SOCK_STREAM, 0);

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(8080); //Ağ Bayt Sırası (Network Byte Order) standartları gereğince veriler Büyük Uçlu (Big-Endian) kodlanmalıdır
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
     if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) 
     {
        printf("Sunucuya bağlanılamadı.\n");
        return -1;
     }
     printf("Sunucuya bağlanıldı.\n");
    send(sock, message, strlen(message), 0);
    printf("Mesaj gönderildi: %s\n", message);
    close(sock);
    return 0;
}

