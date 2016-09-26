#include <stdio.h>
#include <math.h>

double ToRad(double deg)
{
	return (deg * 3.14159265359f) / 180.0f;
}

int main()
{
	//Constants
	int canvasWidth = 200;
	int canvasHeight = 200;
	
	int clockRadius = 2 * canvasWidth / 5;
	
	int bigLineStartDist = clockRadius * 0.75f;
	int bigLineEndDist = clockRadius;
	int smallLineStartDist = clockRadius * 7 / 8;
	int smallLineEndDist = clockRadius;
	int bigLineThickness = 3;
	int smallLineThickness = 1;
	
	int hourArmLength = clockRadius * 0.5;
	int minuteArmLength = clockRadius * 0.7f;
	int secondArmLength = clockRadius * 0.8f;
	
	int hourArmThickness = 5;
	int minuteArmThickness = 3;
	int secondArmThickness = 1;
	
	
	//Print header, background and circles
	printf("<svg width=\"%d\" height=\"%d\"  xmlns=\"http://www.w3.org/2000/svg\" version=\"1.1\">\n", canvasWidth, canvasHeight);
	printf("\t<rect x=\"0\" y=\"0\" width=\"%d\" height=\"%d\" fill=\"#DDDDDD\" />\n", canvasWidth, canvasHeight);
	printf("\t<circle cx=\"%d\" cy=\"%d\" r=\"%d\" stroke=\"black\" fill=\"#F0F0F0\" />\n", canvasWidth / 2, canvasHeight / 2, clockRadius);
	printf("\t<circle cx=\"%d\" cy=\"%d\" r=\"%d\" stroke=\"black\" fill=\"white\"/>\n", canvasWidth / 2, canvasHeight / 2, 5);
	
	//Print spacing
	int deg;
	for(deg = 0; deg < 360; deg += (360 / 60)) 
	{
		int lineStartDist = smallLineStartDist;
		int lineEndDist = smallLineEndDist;
		int lineThickness = smallLineThickness;
		if((deg % (360 / 12)) == 0)
		{
			lineStartDist = bigLineStartDist;
			lineEndDist = bigLineEndDist;
			lineThickness = bigLineThickness;
		}
		int lineStartX = floor(canvasWidth / 2 + cos(ToRad(deg)) * lineStartDist);  
		int lineStartY = floor(canvasWidth / 2 + sin(ToRad(deg)) * lineStartDist);
		int lineEndX = floor(canvasWidth / 2 + cos(ToRad(deg)) * lineEndDist);
		int lineEndY = floor(canvasWidth / 2 + sin(ToRad(deg)) * lineEndDist);
		printf("\t<line x1=\"%d\" y1=\"%d\" x2=\"%d\" y2=\"%d\" stroke=\"black\" stroke-width=\"%d\"/>\n", lineStartX, lineStartY, lineEndX, lineEndY, lineThickness);
	}
	
	
	//Read time values from the user (no output indicating expected data so it doesn't mess up the svg file)
	int hour;
	int minute;
	int second;
	scanf("%d", &hour);
	scanf("%d", &minute);
	scanf("%d", &second);
	
	//Draw second arm
	int lineEndX = floor(canvasWidth / 2 + cos(ToRad(second * 6 - 90)) * secondArmLength);
	int lineEndY = floor(canvasWidth / 2 + sin(ToRad(second * 6 - 90)) * secondArmLength);
	printf("\t<line x1=\"%d\" y1=\"%d\" x2=\"%d\" y2=\"%d\" stroke=\"black\" stroke-width=\"%d\"/>\n", canvasWidth / 2, canvasHeight / 2, lineEndX, lineEndY, secondArmThickness);
	
	//Draw minute arm
	lineEndX = floor(canvasWidth / 2 + cos(ToRad(minute * 6 + second * 0.1f - 90)) * minuteArmLength);
	lineEndY = floor(canvasWidth / 2 + sin(ToRad(minute * 6 + second * 0.1f - 90)) * minuteArmLength);
	printf("\t<line x1=\"%d\" y1=\"%d\" x2=\"%d\" y2=\"%d\" stroke=\"black\" stroke-width=\"%d\"/>\n", canvasWidth / 2, canvasHeight / 2, lineEndX, lineEndY, minuteArmThickness);
	
	//Draw hour arm
	lineEndX = floor(canvasWidth / 2 + cos(ToRad(hour * 30 + minute * 0.5f - 90)) * hourArmLength);
	lineEndY = floor(canvasWidth / 2 + sin(ToRad(hour * 30 + minute * 0.5f - 90)) * hourArmLength);
	printf("\t<line x1=\"%d\" y1=\"%d\" x2=\"%d\" y2=\"%d\" stroke=\"black\" stroke-width=\"%d\"/>\n", canvasWidth / 2, canvasHeight / 2, lineEndX, lineEndY, hourArmThickness);
	
	//Close svg file
	printf("</svg>");
	return 0;
}
