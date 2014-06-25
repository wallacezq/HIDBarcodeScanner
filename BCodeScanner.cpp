/* ---------
Description: This is an Arduino library for USB HID Barcode Scanner by Wallace Lee.
			 This library only work with x86 based machine such as Intel(r) Galileo.

MIT License
-----------*/

#include "BCodeScanner.h"
#include <linux/input.h>
#include <string>
#include <fcntl.h>


bool
BCodeScanner::isValid()
{
	return (fd != -1);
}

const char*
BCodeScanner::readBC()
{
	struct input_event ev[64];
	int rd, value, size = sizeof (struct input_event);
	std::string barcode="";
	while (1)
	{
		if ((rd = read (fd, ev, size * 64)) < size)
			exit(1);

		for(int i=0; i < rd / sizeof(struct input_event); i++)
		{
			if(ev[i].type == 1 && ev[i].value == 1 && ev[i].code != 42) { // scancode 42 is LSHIFT key
				if(ev[i].code != 28) {
					barcode += keycode[ev[i].code];
				}
				else {
					return barcode.c_str();
				}
			}
		}
	}
}

void
BCodeScanner::begin()
{
	if ((fd = open (dev_path, O_RDONLY)) != -1)
	{
		ioctl (fd, EVIOCGNAME (sizeof (dev_name)), dev_name);
	}
}

BCodeScanner::~BCodeScanner()
{
	if(fd != -1) {
		close(fd);
	}
}

BCodeScanner::BCodeScanner(char *path)
{
	unsigned int len = strlen(path);
	memset(dev_path, 0, 1024);
	memcpy(dev_path, path, len);
}

char*
BCodeScanner::GetDeviceName()
{
	return dev_name;
}

