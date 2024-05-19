/*
	36. Program that determines in which quadrant an angle lies
*/
#include <stdio.h>
#include <math.h>
int angleQuad(int angle)
{
	// Normalize the angle to be within [-360, 360] degrees
	angle = fmod(angle, 360.0);
	// Normalize negative angles
	if (angle < 0)
	{
		angle += 360.0;
	}
	if (angle >= 0 && angle < 90)
	{
		return 1;
	}
	if (angle >= 90 && angle < 180)
	{
		return 2;
	}
	if (angle >= 180 && angle < 270)
	{
		return 3;
	}
	if (angle >= 270 && angle < 360)
	{
		return 4;
	}
}
int main()
{
	int n = 1, angle;
	while (n <= 4)
	{
		printf("Enter the angle : ");
		scanf("%d", &angle);
		printf("%d ° ANGLE LIES IN %d QUADRANT\n", angle, angleQuad(angle));
		n++;
	}
	return 0;
}