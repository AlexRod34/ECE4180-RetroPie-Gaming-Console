 #include "mbed.h"

    // outputs 
    DigitalOut up(p30);
    DigitalOut down(p29);
    DigitalOut left(p28);
    DigitalOut right(p27);


    // inputs 
    AnalogIn analogUpDown(p20);
    AnalogIn analogLeftRight(p19);

    Serial pc(USBTX, USBRX);

    int main() {
        while(1) {
            float UD = analogUpDown.read();
            float LR = analogLeftRight.read();
            // D -> A 
            if (UD <= 1.0 && UD > 0.55) {
                down = 0;
                up = 1;
    //            pc.printf("DOWN");
            } else if (UD < .45 && UD >= 0.0) {
                up = 0;
                down = 1;
    //            pc.printf("UP");
            } //else {
    //            up = 1;
    //            down = 1;
    ////            pc.printf("NEUTRAL1"); 
    //        }
            if (LR <= 1.0 && LR > 0.55) {
                right = 0;
                left = 1;
    //            pc.printf("RIGHT");
            } else if (LR < 0.45 && LR >= 0.0) {
                left = 0;
                right = 1;  
    //            pc.printf("LEFT"); 
            } //else {
    //            left = 1;
    //            right = 1;
    ////            pc.printf("NEUTRAL2"); 
    //        }
    //        pc.printf("LR: %.6f\n", LR);
    //        wait(0.5);
        }
    }
