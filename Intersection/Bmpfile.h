#ifndef __BMPFILE_H
#define __BMPFILE_H

#include <string>

class BMPFile
{
    public:

		/*
			Save image in BMP (Windows Bitmap) format
			
			fileName : full path (with bmp extension) of the target file
			img : color buffer (each color in BGR format)
			w : width
			h : height
			
			ex : SaveBmp("c:\mydir\mypic.bmp",colorBuffer,1024,768);
		*/
		static void SaveBmp(std::string fileName, unsigned char *img, unsigned int w, unsigned int h);
		
		//unsigned char *BMPFile::LoadBitmapFile(std::string filename, BITMAPINFOHEADER *bitmapInfoHeader);
};

#endif
