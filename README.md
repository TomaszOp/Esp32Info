Info Esp32 Library
tested arduino 2.0.4

use:

Esp32Info esp32Info;
esp32Info.Update();
  
  Serial.println("---");
  Serial.printf("Model %s \n", esp32Info.ChipModel);
  Serial.printf("MHz %i\n", esp32Info.CpuFreqMHz);
  Serial.printf("Core %i\n", esp32Info.ChipCores);

  /*
  list values <br>
  ChipModel; <br>                  
  ChipRevision; <br>
  ChipCores; <br>
  ChipId = 0; <br>
  CpuFreqMHz; <br>
 <br>
  HeapSize; <br>
  FreeHeap; <br>
  MinFreeHeap; <br>
  MaxAllocHeap; <br>
 <br>
  PsramSize; <br>
  FreePsram; <br>
  MinFreePsram; <br>
  MaxAllocPsram; <br>
 <br>
  FlashChipSize; <br>
  FlashChipSpeed; <br>
  FlashChipMode; <br>
  FlashMode; <br>
 <br>
  SketchSize; <br>
  FreeSketchSpace; <br>
  */ <br>
 <br>
 <br>
  Serial.println("---"); <br>
  Serial.print(esp32Info.GetInfo()); 
