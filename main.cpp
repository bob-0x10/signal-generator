#include "pkt.h"
#include <string.h>
#include <unistd.h>

const char *empty = "00:00:00:00:00:00​";
const char *broadcast = "ff:ff:ff:ff:ff:ff";

void usage() {
    printf("syntax: send-arp-test <interface> <gateway_ip> <gateway_mac> (target_ip) \n");
    printf("sample: send-arp-test wlan0 192.168.0.1 aa:bb:cc:dd:ee:ff 192.168.0.2 \n");
}

int main(int argc, char* argv[]) {
    if (argc < 4 || argc > 5) {
        usage();
        return -1;
    }

    cout << "bob-0x10 attendance-signal-generator program start" << endl;
    cout << "==================================================\n" << endl;

    char* dev = argv[1];
    char* gateway_ip = argv[2];
    gateway_mac = Mac(argv[3]);

    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t* handle = pcap_open_live(dev, BUFSIZ, 1, 1000, errbuf);
    if (handle == nullptr) {
        fprintf(stderr, "couldn't open device %s(%s)\n", dev, errbuf);
        return -1;
    }

    char* ret;
    int len = 0;
    while( (ret = strchr(gateway_ip + len,'.')) != NULL ) len = ret-gateway_ip+1;

    EthArpPacket request_packet;                                //for get sender's mac address

    if (argc == 4){
        packet_setting(request_packet, Mac(broadcast), ArpHdr::Request, gateway_ip, Mac(empty), gateway_ip);
        while(true){
            sleep(1);
            for(int i=2; i<255; i++){
                sprintf(gateway_ip+len,"%d",i);
                request_packet.arp_.tip_ = htonl(Ip(gateway_ip));
                send_packet(request_packet, handle);
            }
            printf("Signal generation success !!\n");
        }
    }

    else if (argc == 5){
        char* target_ip = argv[4];
        packet_setting(request_packet, Mac(broadcast), ArpHdr::Request, gateway_ip, Mac(empty), target_ip);
        while(true) {
            sleep(1);
            send_packet(request_packet, handle);
            printf("Signal generation success !!\n");
        }
    }

    pcap_close(handle);
}
