#include "util.h"

void quicksort(int *params, int iLOW, int iHIGH)
{
	if (iLOW < iHIGH)
	{
		// Pivot
		int pivot = params[iHIGH];
		// Temporary pivot index
		int p = iLOW - 1;
		int i;
		for (i = iLOW; i < iHIGH; ++i)
		{
			if (params[i] <= pivot)
			{
				p++;
				SWAP(params, p, i);
			}
		}
		++p;
		SWAP(params, p, iHIGH);
		// Recursive, yay
		quicksort(params, iLOW, i - 1);
		quicksort(params, i + 1, iHIGH);
	}
}
