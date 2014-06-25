/* ---------
Description: This is an Arduino library for USB HID Barcode Scanner by Wallace Lee.
			 This library only work with x86 based machine such as Intel(r) Galileo.

MIT License
-----------*/

#ifndef _BCODESCANNER_H_
#define _BOCDESCANNER_H_

#if ARDUINO >= 100
 #include "Arduino.h"
#else
 //#include "WProgram.h"
  #error "Not Supported Version"
#endif

class BCodeScanner {
public:
	BCodeScanner(char *path);
	~BCodeScanner();
	void begin(void);
	const char *readBC();
	bool isValid();
	char *GetDeviceName();

private:
	char dev_path[1024];
	char dev_name[256];
	char *keycode[256] = { "", "<esc>", "1", "2", "3", "4", "5", "6", "7", "8", "9", "0",
	"-", "=", "<backspace>",
	"<tab>", "q", "w", "e", "r", "t", "y", "u", "i", "o", "p", "[",
	"]", "\n", "<control>", "a", "s", "d", "f", "g",
	"h", "j", "k", "l", ";", "'", "", "<shift>",
	"\\", "z", "x", "c", "v", "b", "n", "m", ",", ".",
	"/", "<shift>", "", "<alt>", " ", "<capslock>", "<f1>",
	"<f2>", "<f3>", "<f4>", "<f5>", "<f6>", "<f7>", "<f8>", "<f9>",
	"<f10>", "<numlock>", "<scrolllock>", "", "", "", "", "", "", "",
	"", "", "", "\\", "f11", "f12", "", "", "", "", "", "",
	"", "", "<control>", "", "<sysrq>"
	};
	char buf[1024];
	int fd=-1;
};

#endif