# Attendance Signal Generator


🎬 **프로젝트 소개 영상**  
[▶️ 영상 재생](https://youtu.be/O_hrUZvAq4c)


## 📋 프로젝트 개요
범위 내의 모든 무선기기에서 패킷 발생을 유도하는 신호생성기 입니다.

주요 특징:
- 특정 네트워크 내 장치에서 패킷 발생 유도
- 반복적이고 주기적인 패킷 전송
- 단일 IP 혹은 IP 범위 전송 지원
- libpcap 기반 패킷 전송
  
## 💻 빌드 및 설치 및 사용법

```bash
# libpcap 설치 (Ubuntu 기준)
sudo apt-get install libpcap-dev

# 빌드
make

# 빌드 후 실행
# IP 범위 전송 (192.168.0.1 ~ 192.168.0.254)
./signal-generator <interface> <gateway_ip> <gateway_mac>

# 단일 IP 전송 (예: 192.168.0.2)
./signal-generator <interface> <gateway_ip> <gateway_mac> <target_ip>

# 빌드 결과 및 객체 파일 삭제
make clean
