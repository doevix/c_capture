#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "capture.h"

int main(void)
{
	// Just take user input and display it.
	size_t N = 0;
	char **names = captureInput(&N, numericPrompt);

	for (int i = 0; i < N; i++) printf("%s\n", names[i]);

	clear_ar(names, N);

	return 0;
}
