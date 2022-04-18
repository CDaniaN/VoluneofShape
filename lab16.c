/*
Dania Nasereddin
4-14-21
This program uses function pointers that allows the user to enter Length, Width and Height.
Then the user selects which geometrical shape to find the volume of with the given parameters.
*/
#include <stdio.h>
//declaring functions
float rectPrismVol(float length, float width, float height);
float pwramidVol(float length, float width, float height);
float EllipsoidVol(float length, float width, float height);

int main()
{
  int choice;
  float (*volumeFunc[3])(float, float, float); //pointer function array
  float length, width, height, volume;

  volumeFunc[0] = rectPrismVol; //functions to call
  volumeFunc[1] = pwramidVol;
  volumeFunc[2] = EllipsoidVol;

  printf("Enter the length: "); //user input for length
  scanf("%f", &length);
  printf("Enter the width: "); //user input for width
  scanf("%f", &width);
  printf("Enter the height: "); //user input for height
  scanf("%f", &height);
  //menu for user to pick what shape to find the volume for
  printf("Choose what shape you would like the volume of: \n");
  printf("1. Rectangular prism\n");
  printf("2. Pyramid\n");
  printf("3. Ellipsoid\n");
  scanf("%d", &choice); //stores choice
  //calls to volume function to find volume for the shape chosen
  volume = volumeFunc[choice-1](length, width, height);
  printf("The volume of this shape is %f \n", volume); //prints out volume

  return 0;
}

//function definitions
float rectPrismVol(float length, float width, float height)
{
  float volume;
  volume = length * width * height;
  return volume;
}

float pwramidVol(float length, float width, float height)
{
  float volume;
  volume = length * width * height * 1/3;
  return volume;
}

float EllipsoidVol(float length, float width, float height)
{
  float volume;
  volume = 4/3 * 3.14 * length * width * height;
  return volume;
}
