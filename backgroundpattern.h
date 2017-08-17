#include <avr/pgmspace.h>

class Pattern
{
	public:
		virtual void drawPattern(Adafruit_NeoPixel& strip, int *color) = 0;
};

class Pattern_full : public Pattern
{
	public:
		void drawPattern(Adafruit_NeoPixel& strip, int* color)
		{
			for(int i = 0; i < strip.numPixels(); i++)
				strip.setPixelColor(i, color[0], color[1], color[2]);
		}
};

// class Pattern_test01 : public Pattern
// {
	// public:
		// const uint8_t pos_16514816[4]  = {3, 57, 56, 63    };
		// const uint8_t pos_16748544[4]  = {3, 26, 27, 28    };
		// const uint8_t pos_16744704[4]  = {3, 51, 52, 55    };
		// const uint8_t pos_16768000[4]  = {3, 13, 22, 25    };
		// const uint8_t pos_16766976[5]  = {4, 86, 87, 93, 92}; 
		// const uint8_t pos_65401[2]     = {1, 50};
		// const uint8_t pos_786176[4]    = {3, 10, 9, 8     };
		// const uint8_t pos_16711708[4]  = {3, 7, 16, 19    };
		// const uint8_t pos_14679808[5]  = {4, 14, 15, 21, 20};
		
		// static const uint8_t size_color = 9;
		// const uint32_t color[size_color] = {16514816, 16748544, 16744704, 16768000, 16766976, 65401, 786176, 16711708, 14679808};
		// void drawPattern(Adafruit_NeoPixel& strip, int* color)
		// {
			// const uint8_t* pos_arr[9] = {pos_16514816, pos_16748544, pos_16744704, pos_16768000, pos_16766976, pos_65401, pos_786176, pos_16711708, pos_14679808};
			// strip.clear();
			// for(int i = 0; i < size_color; i++)
			// {
				// for(int j = 0; j < pos_arr[i][0]; j++)
					// strip.setPixelColor(pos_arr[i][j+1], color[i]);
			// }
		// }
// };

class Pattern_core : public Pattern
{
	const uint8_t pos_43011[17] = {16,50,51,57,56,86,87,93,92,122,123,129,128,158,159,165,164};
	const uint8_t pos_2424576[49] = {48,46,45,44,43,49,52,58,55,61,62,63,64,82,81,80,79,85,88,94,91,97,98,99,100,118,117,116,115,121,124,130,127,133,134,135,136,154,153,152,151,157,160,166,163,169,170,171,172};
	static const uint8_t size_color = 2;
	const uint32_t color[size_color] = {43011, 2424576};
	void drawPattern(Adafruit_NeoPixel& strip, int* color)
	{
		const uint8_t* pos_arr[2] = {pos_2424576, pos_43011};
		strip.clear();
		for(int i = 0; i < size_color; i++)
		{
			for(int j = 0; j < pos_arr[i][0]; j++)
				strip.setPixelColor(pos_arr[i][j+1], color[0] << (i<<2), color[1] << (i<<2), color[2] << (i<<2));
		}
	}
};

class Pattern_tree : public Pattern 
{
	const uint8_t pos_16711680[41] = {40,14,15,21,20,50,51,57,56,81,80,85,88,94,91,98,99,117,116,121,122,123,124,130,129,128,127,134,135,153,152,157,160,166,163,170,171,194,195,201,200};
	static const uint8_t size_color = 1;
	const uint32_t color[size_color] = {16711680};
	void drawPattern(Adafruit_NeoPixel& strip, int* color)
	{
		strip.clear();
		for(int i = 0; i < pos_16711680[0]; i++)
			strip.setPixelColor(pos_16711680[i+1], color[0], color[1], color[2]);
	}
};

//const Pattern_full pattern_full PROGMEM;
//const Pattern_core pattern_core PROGMEM;


