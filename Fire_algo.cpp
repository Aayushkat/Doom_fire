#include <vector>
#include <iostream>

namespace ray{
    #include <raylib.h> 
}
const int FireWidth=200;
const int FireHeight=200;


std::vector <int> FirePixel;



//the Color struct defines a 32-bit RGBA color using four 8-bit unsigned characters (unsigned char), with values ranging from 0 to 255
ray::Color fireColors[] = {
    {0, 0, 0, 255},      {7, 7, 7, 255},       {31, 7, 7, 255},      {47, 15, 7, 255},     {71, 15, 7, 255},     {87, 23, 7, 255},     {103, 31, 7, 255},
    {119, 31, 7, 255},   {143, 39, 7, 255},    {159, 47, 7, 255},    {175, 63, 7, 255},    {191, 71, 7, 255},    {199, 71, 7, 255},    {223, 79, 7, 255},
    {223, 87, 7, 255},   {223, 87, 7, 255},    {215, 95, 7, 255},    {215, 95, 7, 255},    {215, 103, 15, 255},  {207, 111, 15, 255},  {207, 119, 15, 255},
    {207, 127, 15, 255}, {207, 135, 23, 255},  {199, 135, 23, 255},  {199, 143, 23, 255},  {199, 151, 31, 255},  {191, 159, 31, 255},
    {191, 159, 31, 255}, {191, 167, 39, 255},  {191, 167, 39, 255},  {191, 175, 47, 255},  {183, 175, 47, 255},  {183, 183, 47, 255},
    {183, 183, 55, 255}, {207, 207, 111, 255}, {223, 223, 159, 255}, {239, 239, 199, 255},
};

void createFireDataStructure(){
const int numpixel=FireHeight*FireWidth;
FirePixel.resize(numpixel);
for(int i=0;i<numpixel;i++){
    FirePixel[i]=0;
}
}


void Update_Fire_Intensity_per_pixel(int current_pixel_index){
    const int belowPixelIndex = current_pixel_index+FireWidth;


    //Bound Checking
    if(belowPixelIndex>= FireHeight*FireWidth){return; }

    int decay=ray::GetRandomValue(0,1);
    const int belowPixelFireIntensity=FirePixel[belowPixelIndex];

    int newFireIntensity=(belowPixelFireIntensity-decay)>=0?belowPixelFireIntensity-decay:0;    //subtracts the decay, and clamps at 0 so it never goes negative. This is just max(below - decay, 0).

    int newIndex= current_pixel_index-decay;//  Instead of writing the new intensity into the current pixel, it writes it into current_pixel_index - decay:

    if (newIndex>=0){
        FirePixel[newIndex]=newFireIntensity;  // If decay == 0, it writes straight up into the current pixel, so the heat rises vertically.
                                            // If decay == 1, it writes one pixel to the left, so the heat drifts sideways as it rises.
    }
}


void renderFire(){
    for (int row=0;row<FireHeight:row++){
            for (int column=0;column<FireWidth;column++){
                const int pixelIndex = column +(FireWidth*row);
                const int FireIntensity=FirePixel[pixelIndex];
                DrawRectangle(column*3,row*3,3,3,fireColors[FireIntensity]);
            }
    }
}

void CalculateFirePropogation(){
     for(int column = 0; column < fireWidth; column++ ){
        for(int row = fireHeight - 1; row >= 0; row--){
            int pixelIndex = column + (fireWidth * row);

            Update_Fire_Intensity_per_pixel(pixelIndex);   
}}}

void CreatesourceFire(){
    for(int column = 0; column < fireWidth; column++){
        const int overflowPixelIndex = fireWidth * fireHeight;
        const int pixelIndex = (overflowPixelIndex - fireWidth) + column;

        firePixel[pixelIndex] = 36;
    }
}

int main(){
    ray::InitWindow(FireWidth*3,FireHeight*3,"DOOM FIRE");
    createFireDataStructure();
    CreatesourceFire();
    while(!ray::WindowShouldClose()){
        ray::beginDrawing();
        ray::ClearBackground(ray::BLACK);
        CalculateFirePropogation();
        ray::EndDrawing();
    }
    ray::CloseWindow();
    return 0;
}


