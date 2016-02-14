package net.alhazmy13.imagefilter;

import android.graphics.Bitmap;

class GothamFilter {
	static {
		System.loadLibrary("ImageFilter");
	}
	
	public static Bitmap changeToGotham(Bitmap bitmap) {
		int width = bitmap.getWidth();
		int height = bitmap.getHeight();
		
		int[] pixels = new int[width * height];
		bitmap.getPixels(pixels, 0, width, 0, 0, width, height);
		
		int[] returnPixles = NativeFilterFunc.gothamFilter(pixels, width, height);
		Bitmap returnBitmap = Bitmap.createBitmap(returnPixles, width, height, Bitmap.Config.ARGB_8888);
		
		return returnBitmap;
	}
}