const net = require('net');

const server = net.createServer((socket) => {
    console.log('🟢 Yeni bir cihaz (Sentinel) bağlandı!');

    // C kodundan bir veri (mesaj) geldiğinde burası çalışır
    socket.on('data', (data) => {
        console.log('📩 Gelen mesaj:', data.toString());
    });

    // C kodu bağlantıyı kestiğinde (close fonksiyonu çalıştığında) burası çalışır
    socket.on('end', () => {
        console.log('🔴 Cihaz bağlantıyı kesti.\n');
    });
});

// Sunucuyu 8080 portunda dinlemeye başlatıyoruz
server.listen(8080, '127.0.0.1', () => {
    console.log('🚀 NeuroLink Core TCP Sunucusu 8080 portunda dinleniyor...');
});