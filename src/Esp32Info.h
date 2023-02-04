#ifndef _Esp32Info_H__
#define _Esp32Info_H__

#include <Arduino.h>

class Esp32Info
{
  public:
    Esp32Info();
    ~Esp32Info();

    const char * ChipModel;                  
    uint8_t ChipRevision;
    uint8_t ChipCores;
    uint32_t ChipId = 0;
    uint32_t CpuFreqMHz;

    uint32_t HeapSize;
    uint32_t FreeHeap;
    uint32_t MinFreeHeap;
    uint32_t MaxAllocHeap;

    uint32_t PsramSize;
    uint32_t FreePsram;
    uint32_t MinFreePsram;
    uint32_t MaxAllocPsram;

    uint32_t FlashChipSize;
    uint32_t FlashChipSpeed;
    int8_t FlashChipMode;
    const char * FlashMode;

    uint32_t SketchSize;
    uint32_t FreeSketchSpace;

    void Update();
    const char * GetInfo();

  private: 
    const char * FlashModeToChar(FlashMode_t flashMode);
    FlashMode_t flashMode;

    const char* __QIO = "QIO";
    const char* __QOUT  = "QOUT";
    const char* __DIO = "DIO";
    const char* __DOUT = "DOUT";
    const char* __FAST_READ = "FAST_READ";
    const char* __SLOW_READ = "SLOW_READ";
    const char* __UNKNOWN = "UNKNOWN";
};

#endif
