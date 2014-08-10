#include <png++/png.hpp>
#include <iostream>
#include <string.h>
#include <fstream>
#include <stdlib.h>
#include <png++/image.hpp>
#include <png++/tRNS.hpp>
#include <png++/rgb_pixel.hpp>
#include <math.h>
#include <vector>

using namespace std;
using namespace png;

#define PI 3.14159265

int main()

try {
size_t x,y=0;
int angle=45;
float u,v=0;
 image< rgb_pixel > image("image.png");


 png::image< png::rgb_pixel > image1(2000,2000);//(/*image.get_width(),image.get_height()*/);


 for ( y=0; y < image.get_height(); ++y)
 {
     for (x=0; x < image.get_width(); ++x)
     {
	u = 600 + x * cos(-angle * PI/180.0) + y * sin(-angle * PI/180.0);
	v = 600 + y * cos(-angle * PI/180.0) - x * sin(-angle * PI/180.0);
	if (/*u>=image.get_width()||v>=image.get_height()||*/u<0||v<0) {break;
	cout<<"am intrerupt"<<"\n"; }	
	else {
	rgb_pixel pixel=image.get_pixel(x,y);
	image1.set_pixel(round(u),round(v),pixel);
	}
	cout<<"u="<<round(u)<<" v="<<round(v)<<"\n";
	
        ///////////rgb_pixel pixel=image.get_pixel(x,y);
	//////////////image.set_pixel(x/2,y/2,pixel);
	
	//cout<<"inaltimea imagini: "<< x <<"\n";
	//image[y][x] = rgb_pixel(x, y, x + y);
         // non-checking equivalent of image.set_pixel(x, y, ...);
     }
 }
	
	//tRNS transparency = image.get_tRNS();
	
	//if (transparency.size()) {image.set_tRNS(transparency);cout<<transparency.size()<<"\n";}
	//if (transparency.size() > 0) {
						//if (transparency[0] != 0) {
						//	cout<<"Bad image format"<<x<<"\n";
						//}
					//}

//image1< rgb_pixel > image("image1.png");
//image.set_tRNS(transparency);


/*tRNS trns(255);
for (size_t i = 0; i < trns.size(); ++i)
    {
        trns[i] = i;
    }
    image.set_tRNS(trns);*/

 image1.write("rgb2.png");
}
catch (std::exception const& error)
{
    std::cerr << "generate_palette: " << error.what() << std::endl;
    return EXIT_FAILURE;
}


