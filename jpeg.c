#include <stdio.h>
#include <stdlib.h>
#include <jpeglib.h>

int loadImg(char* FileName){
    char *arrayptr[1]; //single element array pointer for scanlines
    char * rgbArr;
    struct jpeg_decompress_struct cinfo; //compression object
	  struct jpeg_error_mgr jerr; //error handler
	
    FILE* imgfile = fopen(imgName, "r"); //open the image
    cinfo.err = jpeg_std_error(&jerr); //store a pointer to error handler
	  jpeg_create_decompress(&cinfo); //initialise the object
    
    //let us know if there is an error opening image
    if (imgfile==NULL){
        fprintf(stderr, "Can't open the image file %s.\n", imgName);
        exit(1);
    }
    jpeg_stdio_dest(&cinfo, imgfile);
    
    jpeg_read_header(&cinfo, TRUE); //get image info
    jpeg_start_decompress(&cinfo); //begin decompressing
    
    int W = cinfo.output_width; //get width of array
    int H = cinfo.output_height; //get height of array 
    int dataSize = W*H*3;
    
    rgbArr = (char *)malloc(dataSize); //allocate memory
    
    //while there are still lines to be read
    while(cinfo.output_height > cinfo.output_scanline){
        //read them
        arrayptr[0]=(char *)rgbArr+(3*cinfo.output_width*cinfo.output_scanline);
        jpeg_read_scanlines(&cinfo, arrayptr, 1);
    }
    jpeg_finish_decompress(&cinfo); //complete decompression cycle
    jpeg_destroy_decompress(&cinfo); //release the decompression object
    fclose(imgfile); //close img
    free (rgbArr); //free memory
}

int main(){
    return 0;
} 
