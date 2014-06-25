Barcode Scanner Library - Arduino x86
=====================================

This library is created for Intel Galileo by Wallace Lee.

The library uses Linux input event interface; therefore, it will not work with ARM/ATMEL uC based Arduino devices.

To use this library in your Sketch, copy the HIDBarcodeScanner library into **[arduinosketchfolder]**/*libraries* and restart your IDE.

An example is included in this library under *File->Examples->BarcodeScanner->BarcodeTest*.

You may need to change the device path (*/dev/input/eventX*) to point to your USB HID barcode reader for it to work.

```code
...
// the device number may differ from one system to another. 
// Replace X with the device number assigned by kernel.
BCodeScanner bscanner=BCodeScanner("/dev/input/eventX");
void setup()
{
...
}
...

```

Feel free to enhance this library by adding support for USB CDC / RS232 based Barcode Scanner.
