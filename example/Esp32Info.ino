#include "Arduino.h"
#include "Esp32Info.h"

Esp32Info esp32Info;

void setup() 
{
  Serial.begin(115200);
}

void loop() 
{
  esp32Info.Update();
  
  Serial.println("---");
  Serial.printf("Model %s \n", esp32Info.ChipModel);
  Serial.printf("MHz %i\n", esp32Info.CpuFreqMHz);
  Serial.printf("Core %i\n", esp32Info.ChipCores);

  /*
  list values
  ChipModel;                  
  ChipRevision;
  ChipCores;
  ChipId = 0;
  CpuFreqMHz;

  HeapSize;
  FreeHeap;
  MinFreeHeap;
  MaxAllocHeap;

  PsramSize;
  FreePsram;
  MinFreePsram;
  MaxAllocPsram;

  FlashChipSize;
  FlashChipSpeed;
  FlashChipMode;
  FlashMode;

  SketchSize;
  FreeSketchSpace;
  */


  Serial.println("---");
  Serial.print(esp32Info.GetInfo());

	delay(3000);

}
