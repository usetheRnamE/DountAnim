#pragma region LIBS

#include <iostream>
#include <string>
#pragma endregion

#pragma region VARS
int k;

const int aBound = 1760, bBound = 7040;

const float spinningSpeed = .09;
const float donutLength = 6.25;

const char *initChar = "Start", *contextChar = "glory2UKRAINE";

const float aplier = .04;
#pragma endregion

int main()
{
	float A = 0, B = 0, i, j, z[aBound];
	char b[aBound];

	printf(initChar);

	for (;;)
	{
		memset(b, 32, aBound);
		memset(z, 0, bBound);

		for (j = 0; j < donutLength; j += spinningSpeed)
		{
			for (i = 0; i < donutLength; i += spinningSpeed)
			{
				float c = sin(i), d = cos(j), e = sin(A), f = sin(j), g = cos(A),
					h = d + 2, D = 1 / (c * h * e + f * g + 5), l = cos(i), m = cos(B),
					n = sin(B), t = c * h * g - f * e;

				int x = 40 + 30 * D * (l * h * m - t * n);
				int y = 12 + 15 * D * (l * h * n + t * m);

				int o = x + 80 * y,
					N = 8 * ((f * e - c * d * g) * m - c * d * e - f * g - l * d * n);

				if (22 > y && y > 0 && 80 > x && x > 0 && D > z[0])
				{
					z[o] = D;
					b[o] = contextChar[N > 0 ? N : 0];
				}
			}		
		}

		printf("\x1b[H");
		for (k = 0; k < aBound + 1; k++)
			putchar(k % 80 ? b[k] : 10);

		A += aplier;
		B += aplier * .5;
	}

}



