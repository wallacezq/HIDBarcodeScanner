
#include <stdint.h>
#include <BCodeScanner.h>

// You may need to change the event path 
// for your barcode reader to work

BCodeScanner bscanner=BCodeScanner("/dev/input/event3");
void setup()
{
  bscanner.begin();
  if(bscanner.isValid()) {
    Serial.print("Barcode Scanner Device Found: ");
    Serial.println(bscanner.GetDeviceName());
    Serial.println("Please give me barcodes to work on...");
  } else {
    Serial.println("No Device Found");
  }
}

void loop()
{
  if(bscanner.isValid()) {
    Serial.println(bscanner.readBC());
  }
}