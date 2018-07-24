#include <mbed.h>

namespace {
  Serial pc(USBTX, USBRX);
  PwmOut edf(D5);
  float speed = 0;
}

int main(){
  wait(0.5);
  pc.printf("Start\n");
  while (true) {
    while (pc.readable()){
      pc.scanf("%f", &speed);
      pc.printf("Set %f\n", speed);
      edf.write(speed);
    }
  }
}
