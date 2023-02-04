#include "Arduino.h"
#include "Esp32Info.h"


Esp32Info::Esp32Info()
{
}

Esp32Info::~Esp32Info()
{
}

const char * Esp32Info::FlashModeToChar(FlashMode_t flashMode)
{
    if(flashMode == FM_QIO)
      return this->__QIO;
    else if(flashMode == FM_QOUT)
      return this->__QOUT;
    else if(flashMode == FM_DIO )
      return this->__DIO;
    else if(flashMode == FM_DOUT )
      return this->__DOUT;
    else if(flashMode == FM_FAST_READ )
      return this->__FAST_READ;
    else if(flashMode == FM_SLOW_READ )
      return this->__SLOW_READ;

    return this->__UNKNOWN;
};

void Esp32Info::Update()
{
  for(int i=0; i<17; i=i+8) 
  {
	  ChipId |= ((ESP.getEfuseMac() >> (40 - i)) & 0xff) << i;
	}

  this->ChipModel = (char*)ESP.getChipModel();
  this->ChipRevision = ESP.getChipRevision();
	this->ChipCores = ESP.getChipCores();

  
  this->CpuFreqMHz = ESP.getCpuFreqMHz(); 

  this->HeapSize = ESP.getHeapSize();
  this->FreeHeap = ESP.getFreeHeap();
  this->MinFreeHeap = ESP.getMinFreeHeap();
  this->MaxAllocHeap = ESP.getMaxAllocHeap();

  this->FlashChipSize = ESP.getFlashChipSize();
  this->FlashChipSpeed = ESP.getFlashChipSpeed();

  this->flashMode = ESP.getFlashChipMode();
  this->FlashChipMode = (int8_t)this->flashMode;

  this->FlashMode = FlashModeToChar(this->flashMode);

  this->PsramSize = ESP.getPsramSize();
  this->FreePsram = ESP.getFreePsram();
  this->MinFreePsram = ESP.getMinFreePsram();
  this->MaxAllocPsram = ESP.getMaxAllocPsram();

  this->SketchSize = ESP.getSketchSize();
  this->FreeSketchSpace = ESP.getFreeSketchSpace();
};

const char * Esp32Info::GetInfo()
{
  String info = 
    "ESP32 Chip model " + String(this->ChipModel) + " Rev. " + this->ChipRevision + "\n" +
    "This chip has " + this->ChipCores + " cores\n" +
    "Chip ID: " + this->ChipId + "\n" +

    "Cpu MHz: " + this->CpuFreqMHz +"\n" +

    "Heap size: " + this->HeapSize + "\n" +
    "Free heap: " + this->FreeHeap + "\n" +
    "Min free heap: " + this->MinFreeHeap + "\n" +
    "Max alloc heap: " + this->MaxAllocHeap +"\n" +
  
    "Flash chip size: " + this->FlashChipSize + "\n" +
    "Flash chip speed: " + this->FlashChipSpeed + "\n"
    "Flash chip mode : " + this->FlashMode + " - " + FlashModeToChar(this->flashMode) + "\n"

    "Psram size: " + this->PsramSize + "\n"
    "Free psram: " + this->FreePsram + "\n"
    "Min free psram: " + this->MinFreePsram + "\n"
    "Max alloc psram: " + this->MaxAllocPsram + "\n"

    "Sketch size: " + this->SketchSize + "\n"
    "Free sketch space: " + this->FreeSketchSpace + "\n"
    ;

  return info.c_str();
}
