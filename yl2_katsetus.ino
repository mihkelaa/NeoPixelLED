#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
 #include <avr/power.h> // Required for 16 MHz Adafruit Trinket
#endif

// Which pin on the Arduino is connected to the NeoPixels?
#define PIN        6 // On Trinket or Gemma, suggest changing this to 1

// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS 16 // Popular NeoPixel ring size

// When setting up the NeoPixel library, we tell it how many pixels,
// and which pin to use to send signals. Note that for older NeoPixel
// strips you might need to change the third parameter -- see the
// strandtest example for more information on possible values.
Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

#define DELAYVAL 200 // Time (in milliseconds) to pause between pixels
long loendur=0;
void setup() {
  // These lines are specifically to support the Adafruit Trinket 5V 16 MHz.
  // Any other board, you can remove this part (but no harm leaving it):
#if defined(__AVR_ATtiny85__) && (F_CPU == 16000000)
  clock_prescale_set(clock_div_1);
#endif
  // END of Trinket-specific code.
  pixels.begin();
  pixels.setPixelColor(0,pixels.Color(255,0,0));
  pixels.show();
  pixels.setPixelColor(1,pixels.Color(0,255,0));
  pixels.show();
  pixels.setPixelColor(2,pixels.Color(0,0,255));
  pixels.show();
}

void loop() {
  
  pixels.clear();
  loendur++;
  int num=loendur%NUMPIXELS;
  VahetaVarvi(num,loendur%3);
  VahetaVarvi(num+1,loendur%3);
  VahetaVarvi(num+2,loendur%3);
  pixels.clear();
  delay(DELAYVAL);
  
  
  
    
/*int j=1;
int l=2;
for(int i=0;i<NUMPIXELS;i++){
  pixels.setPixelColor(i,pixels.Color(255,0,0));
  pixels.setPixelColor(j,pixels.Color(0,255,0));
  pixels.setPixelColor(l,pixels.Color(0,0,255));
  pixels.show();
  pixels.clear();
  j+=1;
  l+=1;
  delay(DELAYVAL);
}
pixels.clear();
delay(DELAYVAL);*/

}

int VahetaVarvi(int num,int varv){
  if(varv==0){
    pixels.setPixelColor(num,pixels.Color(255,0,0));
    pixels.show();
  }
  else if(varv==1){
    pixels.setPixelColor(num,pixels.Color(0,255,0));
    pixels.show();
    }
  else{
    pixels.setPixelColor(num,pixels.Color(0,0,255));
    pixels.show();
  }
}

