/*
 *
 *  Written by Alhazmy13  <http://alhazmy13.net>, 2016/2
 *
 *  This file is part of ImageFilter
 *  Licensed under the Apache License, Version 2.0
 *
 */
#include "LightFilter.h"

LightFilter::LightFilter(int *_pixels, int _width, int _height):
	ImageFilter(_pixels, _width, _height) {
	centerX = width / 2;
	centerY = height / 2;
	radius = min(centerX, centerY);
}

LightFilter::LightFilter(int *_pixels, int _width, int _height, LightFilterOptions options):
	ImageFilter(_pixels, _width, _height),
	centerX(options.centerX),
	centerY(options.centerY),
	radius(options.radius) {

}

int* LightFilter::procImage() {
	int pixR, pixG, pixB;
	int newR, newG, newB;

	float strength = 150;
	int pos = 0;

	for (int i = 0; i < height; i++) {
		for (int k = 0; k < width; k++) {
			pos = i * width + k;
			if (pos < width * height) {
				Color pixelColor = Color(pixels[pos]);

				pixR = pixelColor.R();
				pixG = pixelColor.G();
				pixB = pixelColor.B();

				newR = pixR;
				newG = pixG;
				newB = pixB;

				int distance = (int) (pow((centerY - i), 2) + pow(centerX - k, 2));
				if (distance < radius * radius) {
					int result = (int) (strength * (1.0 - sqrt(distance) / radius));
					newR = pixR + result;
					newG = pixG + result;
					newB = pixB + result;
				}
				newR = min(255, max(0, newR));
				newG = min(255, max(0, newG));
				newB = min(255, max(0, newB));

				pixels[pos] = ARGB2Color(255, newR, newG, newB);
			}
		}
	}
	return pixels;
}
