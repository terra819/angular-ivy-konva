
/*
  Sketch generated by the Arduino IoT Cloud Thing "Untitled"
  https://create.arduino.cc/cloud/things/09d2f4e5-99d8-4b13-a243-042a628b8555

  Arduino IoT Cloud Variables description

  The following variables are automatically generated and updated when changes are made to the Thing

  String currentMode;

  Variables which are marked as READ/WRITE in the Cloud Thing will also have functions
  which are called when their values are changed from the Dashboard.
  These functions are generated with the Thing and added at the end of this sketch.
*/

#include "thingProperties.h"
#include <Adafruit_NeoPixel.h>

#define PINA 7   // input pin Neopixel is attached to
#define PINB 2   // input pin Neopixel is attached to
#define PINC 4   // input pin Neopixel is attached to
#define NUMPIXELS 100  // number of neopixels

const uint8_t PROGMEM gamma8[] = {
  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  1,  1,  1,
  1,  1,  1,  1,  1,  1,  1,  1,  1,  2,  2,  2,  2,  2,  2,  2,
  2,  3,  3,  3,  3,  3,  3,  3,  4,  4,  4,  4,  4,  5,  5,  5,
  5,  6,  6,  6,  6,  7,  7,  7,  7,  8,  8,  8,  9,  9,  9, 10,
  10, 10, 11, 11, 11, 12, 12, 13, 13, 13, 14, 14, 15, 15, 16, 16,
  17, 17, 18, 18, 19, 19, 20, 20, 21, 21, 22, 22, 23, 24, 24, 25,
  25, 26, 27, 27, 28, 29, 29, 30, 31, 32, 32, 33, 34, 35, 35, 36,
  37, 38, 39, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 50,
  51, 52, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 66, 67, 68,
  69, 70, 72, 73, 74, 75, 77, 78, 79, 81, 82, 83, 85, 86, 87, 89,
  90, 92, 93, 95, 96, 98, 99, 101, 102, 104, 105, 107, 109, 110, 112, 114,
  115, 117, 119, 120, 122, 124, 126, 127, 129, 131, 133, 135, 137, 138, 140, 142,
  144, 146, 148, 150, 152, 154, 156, 158, 160, 162, 164, 167, 169, 171, 173, 175,
  177, 180, 182, 184, 186, 189, 191, 193, 196, 198, 200, 203, 205, 208, 210, 213,
  215, 218, 220, 223, 225, 228, 231, 233, 236, 239, 241, 244, 247, 249, 252, 255
};

Adafruit_NeoPixel pixelsA = Adafruit_NeoPixel(NUMPIXELS, PINA, NEO_RGB + NEO_KHZ800);
Adafruit_NeoPixel pixelsB = Adafruit_NeoPixel(NUMPIXELS, PINB, NEO_RGB + NEO_KHZ800);
Adafruit_NeoPixel pixelsC = Adafruit_NeoPixel(NUMPIXELS, PINC, NEO_RGB + NEO_KHZ800);
String mode = "Dark";

void setup() {
  // Initialize serial and wait for port to open:
  Serial.begin(9600);
  // This delay gives the chance to wait for a Serial Monitor without blocking if none is found
  delay(1500);

  // Defined in thingProperties.h
  initProperties();

  // Connect to Arduino IoT Cloud
  ArduinoCloud.begin(ArduinoIoTPreferredConnection);

  /*
     The following function allows you to obtain more information
     related to the state of network and IoT Cloud connection and errors
     the higher number the more granular information you’ll get.
     The default is 0 (only errors).
     Maximum is 4
  */
  setDebugMessageLevel(2);
  ArduinoCloud.printDebugInfo();
  pixelsA.begin(); // Initializes the NeoPixel library.
  pixelsB.begin(); // Initializes the NeoPixel library.
  pixelsC.begin(); // Initializes the NeoPixel library.
}

void loop() {
  ArduinoCloud.update();
  // Your code here
}


/*
  Since CurrentMode is READ_WRITE variable, onCurrentModeChange() is
  executed every time a new value is received from IoT Cloud.
*/
void onCurrentModeChange()  {
  // Add your code here to act upon CurrentMode change
  Serial.print(currentMode);
  mode = currentMode;
  Serial.print("\n");
  if (currentMode == "Test") {
    runTest();
  }
  if (currentMode == "Dark") {
int stripA000Frame1[99] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,49,50,51,52,53,54,55,56,57,58,59,60,61,62,63,64,65,66,67,68,69,70,71,74,72,73,75,76,77,78,79,80,81,82,83,84,85,86,87,88,91,89,90,92,93,94,95,96,97,98,99};
setStripAColor(stripA000Frame1, 99, 0,0,0);
int stripB000Frame1[99] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60,61,62,63,64,65,66,69,67,68,70,71,72,73,74,75,76,77,78,79,80,81,82,83,84,85,86,87,88,89,90,91,92,93,94,95,96,97,99};
setStripBColor(stripB000Frame1, 99, 0,0,0);
int stripC000Frame1[100] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,19,17,18,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60,61,62,63,64,65,66,67,68,69,70,71,72,73,74,75,76,77,78,79,80,81,82,83,84,85,86,87,88,89,90,91,92,93,94,95,96,97,98,99};
setStripCColor(stripC000Frame1, 100, 0,0,0);
  }
  if (currentMode == "GreenTrinity") {
    runGreenTrinity();
  }
  if (currentMode == "PinkLotus"){
    runPinkLotus();
  }
  if(currentMode == "PurpleFlower"){
    runPurpleFlower();
  }
   if(currentMode == "WaterFlower"){
    runWaterFlower();
  }
  if(currentMode == "Sunflower"){
    runSunflower();
  }
  if(currentMode == "UmbrellaCorp"){
    runUmbrellaCorp();
  }
  if(currentMode == "AquaFriday"){
    runAquaFriday();
  }
}

void runTest() {
int stripA255255255Frame1[4] = {0,1,2,3};
setStripAColor(stripA255255255Frame1, 4, 255,255,255);
int stripB255255255Frame1[2] = {0,1};
setStripBColor(stripB255255255Frame1, 2, 255,255,255);
int stripC255255255Frame1[4] = {0,1,2,3};
setStripCColor(stripC255255255Frame1, 4, 255,255,255);
int stripA2446754Frame1[16] = {4,10,13,26,29,42,45,51,53,61,72,73,77,78,86,87};
setStripAColor(stripA2446754Frame1, 16, 244,67,54);
int stripB2446754Frame1[16] = {3,8,11,18,24,28,29,36,41,52,58,67,68,72,73,94};
setStripBColor(stripB2446754Frame1, 16, 244,67,54);
int stripC2446754Frame1[16] = {4,10,17,18,22,23,44,50,60,67,68,72,76,82,88,98};
setStripCColor(stripC2446754Frame1, 16, 244,67,54);
int stripA25516738Frame1[16] = {5,11,20,28,31,40,43,54,58,62,63,66,75,76,81,82};
setStripAColor(stripA25516738Frame1, 16, 255,167,38);
int stripB25516738Frame1[16] = {6,9,12,21,25,26,35,38,51,53,59,70,71,76,77,93};
setStripBColor(stripB25516738Frame1, 16, 255,167,38);
int stripC25516738Frame1[16] = {5,11,20,21,26,27,43,49,55,61,70,71,75,81,89,97};
setStripCColor(stripC25516738Frame1, 16, 255,167,38);
int stripA25523888Frame1[16] = {6,18,21,30,32,38,41,46,55,59,60,67,79,80,88,91};
setStripAColor(stripA25523888Frame1, 16, 255,238,88);
int stripB25523888Frame1[16] = {7,10,15,22,23,32,37,44,50,54,60,74,75,80,81,92};
setStripBColor(stripB25523888Frame1, 16, 255,238,88);
int stripC25523888Frame1[16] = {6,12,24,25,30,31,42,48,54,56,62,73,74,80,90,96};
setStripCColor(stripC25523888Frame1, 16, 255,238,88);
int stripA13919574Frame1[15] = {7,16,19,22,33,36,39,56,57,65,68,89,90,94,95};
setStripAColor(stripA13919574Frame1, 15, 139,195,74);
int stripB13919574Frame1[17] = {13,16,31,34,43,46,49,55,63,78,79,84,85,90,91,97,99};
setStripBColor(stripB13919574Frame1, 17, 139,195,74);
int stripC13919574Frame1[17] = {7,13,28,29,34,35,40,41,47,53,57,63,79,83,85,91,95};
setStripCColor(stripC13919574Frame1, 17, 139,195,74);
int stripA66165245Frame1[16] = {8,14,17,23,25,34,37,47,50,69,70,85,92,93,98,99};
setStripAColor(stripA66165245Frame1, 16, 66,165,245);
int stripB66165245Frame1[16] = {4,14,19,30,33,40,45,48,56,64,65,82,83,88,89,96};
setStripBColor(stripB66165245Frame1, 16, 66,165,245);
int stripC66165245Frame1[16] = {8,14,15,32,33,38,39,46,52,58,64,78,84,86,92,94};
setStripCColor(stripC66165245Frame1, 16, 66,165,245);
int stripA12687194Frame1[16] = {9,12,15,24,27,35,44,49,52,64,71,74,83,84,96,97};
setStripAColor(stripA12687194Frame1, 16, 126,87,194);
int stripB12687194Frame1[16] = {2,5,17,20,27,39,42,47,57,61,62,66,69,86,87,95};
setStripBColor(stripB12687194Frame1, 16, 126,87,194);
int stripC12687194Frame1[15] = {9,16,19,36,37,45,51,59,65,66,69,77,87,93,99};
setStripCColor(stripC12687194Frame1, 15, 126,87,194);
}

void runPinkLotus(){
int stripA252228236Frame1[4] = {0,1,2,3};
setStripAColor(stripA252228236Frame1, 4, 252,228,236);
int stripB252228236Frame1[2] = {0,1};
setStripBColor(stripB252228236Frame1, 2, 252,228,236);
int stripC252228236Frame1[4] = {0,1,2,3};
setStripCColor(stripC252228236Frame1, 4, 252,228,236);
int stripA248187208Frame1[1] = {4};
setStripAColor(stripA248187208Frame1, 1, 248,187,208);
int stripA000Frame1[44] = {5,7,9,10,11,14,15,18,19,20,22,24,28,29,32,33,34,35,38,39,40,43,44,49,53,54,55,56,57,58,62,63,64,65,66,68,75,76,83,84,89,90,96,97};
setStripAColor(stripA000Frame1, 44, 0,0,0);
int stripB000Frame1[42] = {2,5,6,9,12,13,16,17,20,21,25,26,27,30,31,34,35,38,39,42,43,46,47,49,51,53,55,57,61,62,70,71,78,79,86,87,90,91,93,95,97,99};
setStripBColor(stripB000Frame1, 42, 0,0,0);
int stripC000Frame1[41] = {20,21,28,29,36,37,40,41,42,43,44,45,46,47,49,51,53,55,56,57,58,59,60,61,62,63,64,65,66,70,71,72,83,84,93,94,95,96,97,98,99};
setStripCColor(stripC000Frame1, 41, 0,0,0);
int stripA244143177Frame1[7] = {6,16,17,21,25,26,27};
setStripAColor(stripA244143177Frame1, 7, 244,143,177);
int stripB244143177Frame1[2] = {3,4};
setStripBColor(stripB244143177Frame1, 2, 244,143,177);
int stripA24098146Frame1[13] = {8,12,13,23,30,31,36,37,41,42,50,51,52};
setStripAColor(stripA24098146Frame1, 13, 240,98,146);
int stripB24098146Frame1[4] = {7,8,48,50};
setStripBColor(stripB24098146Frame1, 4, 240,98,146);
int stripA23664122Frame1[8] = {45,46,47,59,60,61,98,99};
setStripAColor(stripA23664122Frame1, 8, 236,64,122);
int stripB23664122Frame1[6] = {10,11,44,45,52,96};
setStripBColor(stripB23664122Frame1, 6, 236,64,122);
int stripC23664122Frame1[16] = {4,5,6,7,8,9,10,11,12,13,14,15,16,19,17,18};
setStripCColor(stripC23664122Frame1, 16, 236,64,122);
int stripA2333099Frame1[10] = {67,85,86,87,88,91,92,93,94,95};
setStripAColor(stripA2333099Frame1, 10, 233,30,99);
int stripB2333099Frame1[6] = {14,15,40,41,54,94};
setStripBColor(stripB2333099Frame1, 6, 233,30,99);
int stripC2333099Frame1[20] = {22,23,24,25,26,27,50,52,54,67,68,69,85,86,87,88,89,90,91,92};
setStripCColor(stripC2333099Frame1, 20, 233,30,99);
int stripA2162796Frame1[8] = {69,70,77,78,79,80,81,82};
setStripAColor(stripA2162796Frame1, 8, 216,27,96);
int stripB2162796Frame1[6] = {18,19,36,37,56,92};
setStripBColor(stripB2162796Frame1, 6, 216,27,96);
int stripC2162796Frame1[17] = {30,31,32,33,34,35,48,73,74,75,76,77,78,79,80,81,82};
setStripCColor(stripC2162796Frame1, 17, 216,27,96);
int stripA1942491Frame1[4] = {71,74,72,73};
setStripAColor(stripA1942491Frame1, 4, 194,24,91);
int stripB1942491Frame1[17] = {22,23,24,32,33,58,59,60,63,64,65,66,69,67,68,88,89};
setStripBColor(stripB1942491Frame1, 17, 194,24,91);
int stripC1942491Frame1[2] = {38,39};
setStripCColor(stripC1942491Frame1, 2, 194,24,91);
int stripB1732087Frame1[14] = {28,29,72,73,74,75,76,77,80,81,82,83,84,85};
setStripBColor(stripB1732087Frame1, 14, 173,20,87);
}

void runGreenTrinity(){
  int stripA227242253Frame1[5] = {0,1,2,3,4};
setStripAColor(stripA227242253Frame1, 5, 227,242,253);
int stripB227242253Frame1[3] = {0,1,52};
setStripBColor(stripB227242253Frame1, 3, 227,242,253);
int stripC227242253Frame1[5] = {0,1,2,3,4};
setStripCColor(stripC227242253Frame1, 5, 227,242,253);
int stripA179229252Frame1[5] = {5,9,18,19,20};
setStripAColor(stripA179229252Frame1, 5, 179,229,252);
int stripB179229252Frame1[5] = {2,43,44,51,53};
setStripBColor(stripB179229252Frame1, 5, 179,229,252);
int stripC179229252Frame1[5] = {5,51,55,56,57};
setStripCColor(stripC179229252Frame1, 5, 179,229,252);
int stripA128222234Frame1[9] = {6,8,10,16,17,21,25,26,27};
setStripAColor(stripA128222234Frame1, 9, 128,222,234);
int stripB128222234Frame1[9] = {3,4,40,41,42,45,46,50,54};
setStripBColor(stripB128222234Frame1, 9, 128,222,234);
int stripC128222234Frame1[9] = {6,50,52,54,58,85,86,87,88};
setStripCColor(stripC128222234Frame1, 9, 128,222,234);
int stripA77182172Frame1[12] = {7,11,12,14,15,22,24,28,29,38,39,40};
setStripAColor(stripA77182172Frame1, 12, 77,182,172);
int stripB77182172Frame1[12] = {5,6,11,12,15,16,38,39,47,48,49,55};
setStripBColor(stripB77182172Frame1, 12, 77,182,172);
int stripC77182172Frame1[12] = {7,49,53,59,83,84,89,95,96,97,98,99};
setStripCColor(stripC77182172Frame1, 12, 77,182,172);
int stripA102187106Frame1[12] = {13,23,30,31,32,36,37,41,42,50,51,52};
setStripAColor(stripA102187106Frame1, 12, 102,187,106);
int stripB102187106Frame1[12] = {7,8,9,10,13,14,17,18,19,36,37,56};
setStripBColor(stripB102187106Frame1, 12, 102,187,106);
int stripC102187106Frame1[12] = {8,48,60,76,77,78,79,80,81,82,90,94};
setStripCColor(stripC102187106Frame1, 12, 102,187,106);
int stripA13919574Frame1[12] = {33,34,35,43,44,49,53,54,55,56,57,58};
setStripAColor(stripA13919574Frame1, 12, 139,195,74);
int stripB13919574Frame1[14] = {20,21,34,35,57,90,91,92,93,94,95,96,97,99};
setStripBColor(stripB13919574Frame1, 14, 139,195,74);
int stripC13919574Frame1[13] = {9,40,41,42,43,44,45,46,47,61,75,91,93};
setStripCColor(stripC13919574Frame1, 13, 139,195,74);
int stripA19220251Frame1[17] = {45,46,47,59,60,61,66,67,68,69,70,71,74,72,73,98,99};
setStripAColor(stripA19220251Frame1, 17, 192,202,51);
int stripB19220251Frame1[17] = {22,23,24,32,33,58,59,60,63,64,65,66,69,67,68,88,89};
setStripBColor(stripB19220251Frame1, 17, 192,202,51);
int stripC19220251Frame1[17] = {10,11,12,13,14,15,16,19,17,18,38,39,62,72,73,74,92};
setStripCColor(stripC19220251Frame1, 17, 192,202,51);
int stripA25119245Frame1[15] = {62,63,64,65,75,76,77,78,83,84,85,94,95,96,97};
setStripAColor(stripA25119245Frame1, 15, 251,192,45);
int stripB25119245Frame1[15] = {25,26,27,30,31,61,62,70,71,72,73,84,85,86,87};
setStripBColor(stripB25119245Frame1, 15, 251,192,45);
int stripC25119245Frame1[15] = {20,21,22,23,34,35,36,37,63,64,65,66,69,70,71};
setStripCColor(stripC25119245Frame1, 15, 251,192,45);
int stripA2551430Frame1[10] = {79,80,81,82,86,87,88,91,92,93};
setStripAColor(stripA2551430Frame1, 10, 255,143,0);
int stripB2551430Frame1[10] = {28,29,74,75,76,77,80,81,82,83};
setStripBColor(stripB2551430Frame1, 10, 255,143,0);
int stripC2551430Frame1[10] = {24,25,26,27,30,31,32,33,67,68};
setStripCColor(stripC2551430Frame1, 10, 255,143,0);
int stripA2391080Frame1[2] = {89,90};
setStripAColor(stripA2391080Frame1, 2, 239,108,0);
int stripB2391080Frame1[2] = {78,79};
setStripBColor(stripB2391080Frame1, 2, 239,108,0);
int stripC2391080Frame1[2] = {28,29};
setStripCColor(stripC2391080Frame1, 2, 239,108,0);
}

void runPurpleFlower(){
  int stripA237231246Frame1[16] = {0,1,2,3,22,23,24,28,29,30,34,38,39,40,44,45};
setStripAColor(stripA237231246Frame1, 16, 237,231,246);
int stripB237231246Frame1[14] = {0,1,10,11,12,15,16,38,39,55,56,57,58,96};
setStripBColor(stripB237231246Frame1, 14, 237,231,246);
int stripC237231246Frame1[16] = {0,1,2,3,7,8,9,10,46,59,80,89,95,96,97,98};
setStripCColor(stripC237231246Frame1, 16, 237,231,246);
int stripA209196233Frame1[2] = {4,7};
setStripAColor(stripA209196233Frame1, 2, 209,196,233);
int stripB209196233Frame1[2] = {49,52};
setStripBColor(stripB209196233Frame1, 2, 209,196,233);
int stripC209196233Frame1[2] = {4,53};
setStripCColor(stripC209196233Frame1, 2, 209,196,233);
int stripA12687194Frame1[22] = {5,6,8,9,12,14,18,19,20,47,49,53,54,55,56,57,58,64,67,85,86,87};
setStripAColor(stripA12687194Frame1, 22, 126,87,194);
int stripB12687194Frame1[25] = {2,4,5,8,20,21,27,28,29,30,33,34,43,44,48,50,51,53,60,90,91,92,93,94,99};
setStripBColor(stripB12687194Frame1, 25, 126,87,194);
int stripC12687194Frame1[24] = {5,12,40,41,42,43,44,51,52,54,55,56,57,64,67,68,69,75,82,83,84,91,92,93};
setStripCColor(stripC12687194Frame1, 24, 126,87,194);
int stripA6939160Frame1[34] = {10,11,15,16,17,21,25,26,27,31,32,33,59,60,61,62,63,68,69,70,71,74,72,73,81,82,83,84,88,91,89,90,98,99};
setStripAColor(stripA6939160Frame1, 34, 69,39,160);
int stripB6939160Frame1[34] = {3,6,7,9,22,23,24,25,26,40,41,42,45,46,47,54,61,62,63,64,65,66,69,67,68,76,77,78,79,80,81,88,89,97};
setStripBColor(stripB6939160Frame1, 34, 69,39,160);
int stripC6939160Frame1[34] = {6,13,14,15,16,19,17,18,26,27,28,29,30,31,38,39,47,48,49,50,58,65,66,70,71,72,73,74,81,85,86,87,88,99};
setStripCColor(stripC6939160Frame1, 34, 69,39,160);
int stripA179157219Frame1[13] = {13,35,36,37,41,42,43,46,50,51,52,65,66};
setStripAColor(stripA179157219Frame1, 13, 179,157,219);
int stripB179157219Frame1[12] = {13,14,17,18,19,31,32,35,36,37,59,95};
setStripBColor(stripB179157219Frame1, 12, 179,157,219);
int stripC179157219Frame1[12] = {11,45,60,61,62,63,76,77,78,79,90,94};
setStripCColor(stripC179157219Frame1, 12, 179,157,219);
int stripA4612550Frame1[8] = {75,76,79,80,92,93,96,97};
setStripAColor(stripA4612550Frame1, 8, 46,125,50);
int stripB4612550Frame1[8] = {70,71,74,75,82,83,86,87};
setStripBColor(stripB4612550Frame1, 8, 46,125,50);
int stripC4612550Frame1[8] = {20,21,24,25,32,33,36,37};
setStripCColor(stripC4612550Frame1, 8, 46,125,50);
int stripA129199132Frame1[4] = {77,78,94,95};
setStripAColor(stripA129199132Frame1, 4, 129,199,132);
int stripB129199132Frame1[4] = {72,73,84,85};
setStripBColor(stripB129199132Frame1, 4, 129,199,132);
int stripC129199132Frame1[4] = {22,23,34,35};
setStripCColor(stripC129199132Frame1, 4, 129,199,132);
}

void runWaterFlower(){
 int stripA77208225Frame1[20] = {0,1,2,3,45,46,47,59,60,61,65,69,70,77,78,83,84,85,98,99};
setStripAColor(stripA77208225Frame1, 20, 77,208,225);
int stripB77208225Frame1[27] = {0,1,10,11,12,15,16,18,19,20,24,25,26,44,45,52,61,62,63,76,77,78,79,80,81,92,96};
setStripBColor(stripB77208225Frame1, 27, 77,208,225);
int stripC77208225Frame1[39] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,19,17,18,34,35,43,52,63,69,70,71,73,74,75,76,77,78,79,80,81,82,83};
setStripCColor(stripC77208225Frame1, 39, 77,208,225);
int stripA255255255Frame1[22] = {4,5,6,7,14,15,16,17,18,19,20,21,22,24,25,26,27,28,29,38,39,40};
setStripAColor(stripA255255255Frame1, 22, 255,255,255);
int stripB255255255Frame1[13] = {2,3,4,5,6,13,49,53,54,55,56,57,58};
setStripBColor(stripB255255255Frame1, 13, 255,255,255);
int stripC255255255Frame1[12] = {46,47,48,49,50,51,55,56,57,58,59,60};
setStripCColor(stripC255255255Frame1, 12, 255,255,255);
int stripA224247250Frame1[13] = {8,12,13,23,30,31,36,37,41,42,50,51,52};
setStripAColor(stripA224247250Frame1, 13, 224,247,250);
int stripB224247250Frame1[15] = {7,8,14,31,32,35,36,39,40,43,48,50,59,94,95};
setStripBColor(stripB224247250Frame1, 15, 224,247,250);
int stripC224247250Frame1[10] = {45,54,61,85,86,87,88,89,90,91};
setStripCColor(stripC224247250Frame1, 10, 224,247,250);
int stripA178235242Frame1[19] = {9,10,11,32,33,34,35,43,44,49,53,54,55,56,57,58,66,67,68};
setStripAColor(stripA178235242Frame1, 19, 178,235,242);
int stripB178235242Frame1[19] = {9,17,27,28,29,30,33,34,37,38,41,42,46,47,51,60,93,97,99};
setStripBColor(stripB178235242Frame1, 19, 178,235,242);
int stripC178235242Frame1[13] = {44,53,62,72,84,92,93,94,95,96,97,98,99};
setStripCColor(stripC178235242Frame1, 13, 178,235,242);
int stripA0172193Frame1[17] = {62,63,64,71,74,75,76,79,80,81,82,86,87,94,95,96,97};
setStripAColor(stripA0172193Frame1, 17, 0,172,193);
int stripB0172193Frame1[15] = {21,22,23,64,65,72,73,74,75,82,83,84,85,90,91};
setStripBColor(stripB0172193Frame1, 15, 0,172,193);
int stripC0172193Frame1[20] = {20,21,22,23,30,31,32,33,36,37,38,39,40,41,42,64,65,66,67,68};
setStripCColor(stripC0172193Frame1, 20, 0,172,193);
int stripA0131143Frame1[8] = {72,73,88,91,89,90,92,93};
setStripAColor(stripA0131143Frame1, 8, 0,131,143);
int stripB0131143Frame1[10] = {66,69,67,68,70,71,86,87,88,89};
setStripBColor(stripB0131143Frame1, 10, 0,131,143);
int stripC0131143Frame1[6] = {24,25,26,27,28,29};
setStripCColor(stripC0131143Frame1, 6, 0,131,143);
}

void runSunflower(){
  int stripA255253231Frame1[4] = {0,1,2,3};
setStripAColor(stripA255253231Frame1, 4, 255,253,231);
int stripB255253231Frame1[2] = {0,1};
setStripBColor(stripB255253231Frame1, 2, 255,253,231);
int stripC255253231Frame1[4] = {0,1,2,3};
setStripCColor(stripC255253231Frame1, 4, 255,253,231);
int stripA255249196Frame1[2] = {4,7};
setStripAColor(stripA255249196Frame1, 2, 255,249,196);
int stripB255249196Frame1[2] = {49,52};
setStripBColor(stripB255249196Frame1, 2, 255,249,196);
int stripC255249196Frame1[2] = {4,53};
setStripCColor(stripC255249196Frame1, 2, 255,249,196);
int stripA255245157Frame1[10] = {5,6,8,9,12,13,14,18,19,20};
setStripAColor(stripA255245157Frame1, 10, 255,245,157);
int stripB255245157Frame1[10] = {2,4,5,8,43,44,48,50,51,53};
setStripBColor(stripB255245157Frame1, 10, 255,245,157);
int stripC255245157Frame1[10] = {5,51,52,54,55,56,57,82,83,84};
setStripCColor(stripC255245157Frame1, 10, 255,245,157);
int stripA255241118Frame1[12] = {10,11,15,16,17,21,25,26,27,31,32,33};
setStripAColor(stripA255241118Frame1, 12, 255,241,118);
int stripB255241118Frame1[12] = {3,6,7,9,40,41,42,45,46,47,54,97};
setStripBColor(stripB255241118Frame1, 12, 255,241,118);
int stripC255241118Frame1[12] = {6,47,48,49,50,58,81,85,86,87,88,99};
setStripCColor(stripC255241118Frame1, 12, 255,241,118);
int stripA25523888Frame1[12] = {22,23,24,28,29,30,34,38,39,40,44,45};
setStripAColor(stripA25523888Frame1, 12, 255,238,88);
int stripB25523888Frame1[12] = {10,11,12,15,16,38,39,55,56,57,58,96};
setStripBColor(stripB25523888Frame1, 12, 255,238,88);
int stripC25523888Frame1[12] = {7,8,9,10,46,59,80,89,95,96,97,98};
setStripCColor(stripC25523888Frame1, 12, 255,238,88);
int stripA25523559Frame1[12] = {35,36,37,41,42,43,46,50,51,52,65,66};
setStripAColor(stripA25523559Frame1, 12, 255,235,59);
int stripB25523559Frame1[12] = {13,14,17,18,19,31,32,35,36,37,59,95};
setStripBColor(stripB25523559Frame1, 12, 255,235,59);
int stripC25523559Frame1[12] = {11,45,60,61,62,63,76,77,78,79,90,94};
setStripCColor(stripC25523559Frame1, 12, 255,235,59);
int stripA25321653Frame1[13] = {47,49,53,54,55,56,57,58,64,67,85,86,87};
setStripAColor(stripA25321653Frame1, 13, 253,216,53);
int stripB25321653Frame1[15] = {20,21,27,28,29,30,33,34,60,90,91,92,93,94,99};
setStripBColor(stripB25321653Frame1, 15, 253,216,53);
int stripC25321653Frame1[14] = {12,40,41,42,43,44,64,67,68,69,75,91,92,93};
setStripCColor(stripC25321653Frame1, 14, 253,216,53);
int stripA25119245Frame1[22] = {59,60,61,62,63,68,69,70,71,74,72,73,81,82,83,84,88,91,89,90,98,99};
setStripAColor(stripA25119245Frame1, 22, 251,192,45);
int stripB25119245Frame1[22] = {22,23,24,25,26,61,62,63,64,65,66,69,67,68,76,77,78,79,80,81,88,89};
setStripBColor(stripB25119245Frame1, 22, 251,192,45);
int stripC25119245Frame1[22] = {13,14,15,16,19,17,18,26,27,28,29,30,31,38,39,65,66,70,71,72,73,74};
setStripCColor(stripC25119245Frame1, 22, 251,192,45);
int stripA24916837Frame1[12] = {75,76,77,78,79,80,92,93,94,95,96,97};
setStripAColor(stripA24916837Frame1, 12, 249,168,37);
int stripB24916837Frame1[12] = {70,71,72,73,74,75,82,83,84,85,86,87};
setStripBColor(stripB24916837Frame1, 12, 249,168,37);
int stripC24916837Frame1[12] = {20,21,22,23,24,25,32,33,34,35,36,37};
setStripCColor(stripC24916837Frame1, 12, 249,168,37);
}

void runUmbrellaCorp(){
int stripA2295753Frame1[48] = {0,1,2,3,4,5,8,9,10,11,17,18,19,20,25,26,27,28,37,38,39,40,50,51,52,54,55,56,57,58,66,67,68,69,70,75,76,77,78,79,80,81,82,83,84,85,98,99};
setStripAColor(stripA2295753Frame1, 48, 229,57,53);
int stripB2295753Frame1[40] = {0,1,9,10,11,12,13,14,25,26,27,28,29,30,31,32,33,35,45,46,47,48,50,51,56,57,58,59,76,77,78,79,80,81,82,83,93,94,95,96};
setStripBColor(stripB2295753Frame1, 40, 229,57,53);
int stripC2295753Frame1[50] = {0,1,2,3,5,6,7,8,14,15,16,19,17,18,20,21,32,33,34,35,36,37,38,39,46,47,48,49,52,53,58,59,60,61,70,71,72,73,74,75,81,82,83,84,89,90,91,92,93,94};
setStripCColor(stripC2295753Frame1, 50, 229,57,53);
int stripA176190197Frame1[51] = {6,7,12,13,14,15,16,21,22,23,24,29,30,31,32,33,34,35,36,41,42,43,44,45,46,47,49,53,59,60,61,62,63,64,65,71,74,72,73,86,87,88,91,89,90,92,93,94,95,96,97};
setStripAColor(stripA176190197Frame1, 51, 176,190,197);
int stripB176190197Frame1[59] = {2,3,4,5,6,7,8,15,16,17,18,19,20,21,22,23,24,34,36,37,38,39,40,41,42,43,44,49,52,53,54,55,60,61,62,63,64,65,66,69,67,68,70,71,72,73,74,75,84,85,86,87,88,89,90,91,92,97,99};
setStripBColor(stripB176190197Frame1, 59, 176,190,197);
int stripC176190197Frame1[50] = {4,9,10,11,12,13,22,23,24,25,26,27,28,29,30,31,40,41,42,43,44,45,50,51,54,55,56,57,62,63,64,65,66,67,68,69,76,77,78,79,80,85,86,87,88,95,96,97,98,99};
setStripCColor(stripC176190197Frame1, 50, 176,190,197);
}

void runAquaFriday(){
  int stripA2119189Frame1[10] = {0,1,2,3,22,25,27,29,31,32};
setStripAColor(stripA2119189Frame1, 10, 2,119,189);
int stripB2119189Frame1[8] = {0,1,7,9,11,40,42,55};
setStripBColor(stripB2119189Frame1, 8, 2,119,189);
int stripC2119189Frame1[10] = {0,1,2,3,7,48,58,81,87,98};
setStripCColor(stripC2119189Frame1, 10, 2,119,189);
int stripA0188212Frame1[54] = {4,5,6,7,8,9,11,13,15,17,19,21,23,24,26,28,30,33,35,37,39,41,43,45,47,49,51,54,56,57,59,60,62,63,65,67,69,70,72,73,75,76,79,80,83,84,86,87,89,90,92,93,96,97};
setStripAColor(stripA0188212Frame1, 54, 0,188,212);
int stripB0188212Frame1[54] = {2,4,6,8,10,12,14,16,18,20,22,23,25,26,28,29,31,33,35,37,39,41,43,45,47,49,50,51,52,54,56,58,60,61,62,64,65,67,68,70,71,74,75,78,79,82,83,86,87,90,91,93,95,97};
setStripBColor(stripB0188212Frame1, 54, 0,188,212);
int stripC0188212Frame1[54] = {4,6,8,10,12,14,15,17,18,20,21,24,25,28,29,32,33,36,37,40,41,43,45,47,49,51,52,53,54,55,57,59,61,63,65,66,67,68,70,71,73,74,76,78,80,82,86,88,90,92,93,95,97,99};
setStripCColor(stripC0188212Frame1, 54, 0,188,212);
int stripA129212250Frame1[6] = {10,12,14,16,18,20};
setStripAColor(stripA129212250Frame1, 6, 129,212,250);
int stripB129212250Frame1[6] = {3,5,44,46,48,53};
setStripBColor(stripB129212250Frame1, 6, 129,212,250);
int stripC129212250Frame1[6] = {5,50,56,83,84,85};
setStripCColor(stripC129212250Frame1, 6, 129,212,250);
int stripA178235242Frame1[29] = {34,36,38,40,42,44,46,50,52,53,55,58,61,64,66,68,71,74,77,78,81,82,85,88,91,94,95,98,99};
setStripAColor(stripA178235242Frame1, 29, 178,235,242);
int stripB178235242Frame1[31] = {13,15,17,19,21,24,27,30,32,34,36,38,57,59,63,66,69,72,73,76,77,80,81,84,85,88,89,92,94,96,99};
setStripBColor(stripB178235242Frame1, 31, 178,235,242);
int stripC178235242Frame1[30] = {9,11,13,16,19,22,23,26,27,30,31,34,35,38,39,42,44,46,60,62,64,69,72,75,77,79,89,91,94,96};
setStripCColor(stripC178235242Frame1, 30, 178,235,242);
}

void setStripAColor(int pixels[], int size, int r, int g, int b) {
  for (int i = 0; i < size; i++) {
    setPixelAColor(pixels[i], r, g, b);
  }
  pixelsA.show();
}

void setStripBColor(int pixels[], int size, int r, int g, int b) {
  for (int i = 0; i < size; i++) {
    setPixelBColor(pixels[i], r, g, b);
  }
  pixelsB.show();
}

void setStripCColor(int pixels[], int size, int r, int g, int b) {
  for (int i = 0; i < size; i++) {
    setPixelCColor(pixels[i], r, g, b);
  }
  pixelsC.show();
}

void setPixelAColor(int index, int r, int g, int b) {
  pixelsA.setPixelColor(index, pgm_read_byte(&gamma8[r]), pgm_read_byte(&gamma8[g]), pgm_read_byte(&gamma8[b]));
}

void setPixelBColor(int index, int r, int g, int b) {
  pixelsB.setPixelColor(index, pgm_read_byte(&gamma8[r]), pgm_read_byte(&gamma8[g]), pgm_read_byte(&gamma8[b]));
}

void setPixelCColor(int index, int r, int g, int b) {
  pixelsC.setPixelColor(index, pgm_read_byte(&gamma8[r]), pgm_read_byte(&gamma8[g]), pgm_read_byte(&gamma8[b]));
}
