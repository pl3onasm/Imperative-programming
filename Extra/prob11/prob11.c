/* file: prob11.c
  author: David De Potter
  description: extra, problem 11, segments
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))

typedef struct {
  int start, end;
} Seg;

void *safeMalloc (int n) {
  /* checks if memory has been allocated successfully */
  void *p = malloc(n);
  if (p == NULL) {
    printf("Error: malloc(%d) failed. Out of memory?\n", n);
    exit(EXIT_FAILURE);
  }
  return p;
}

Seg* readInput (int len) {
  /* reads the input and stores it as an array of segments */
  Seg *segments = safeMalloc(len*sizeof(Seg));
  for (int i = 0; i < len; ++i)
    (void)! scanf("[%d,%d),", &segments[i].start, &segments[i].end);
  return segments;
}

Seg *copySubArray(int left, int right, Seg *arr) {
  /* copies a part of a given segment array from the left
   * index to the right one */
  int i;
  Seg *copy;
  copy = safeMalloc((right - left)*sizeof(Seg));
  for (i=left; i < right; i++)
    copy[i - left] = arr[i];
  return copy;
}

void mergeSort(int length, Seg *arr) {
  /* sorts the array in increasing order on the value of the
   * start field of each segment */
  int l, r, mid, idx;
  Seg *left, *right;
  if (length <= 1) {
    return;
  }
  mid = length/2;
  left = copySubArray(0, mid, arr);
  right = copySubArray(mid, length, arr);
  mergeSort(mid, left);
  mergeSort(length - mid, right);
  idx = l = r = 0;
  while ((l < mid) && (r < length - mid)) {
    if (left[l].start < right[r].start) {
      arr[idx] = left[l];
      l++;
    } else {
      arr[idx] = right[r];
      r++;
    }
    idx++;
  }
  while (l < mid) {
    arr[idx] = left[l];
    idx++;
    l++;
  }
  while (r < length - mid) {
    arr[idx] = right[r];
    idx++;
    r++;
  }
  free(left);
  free(right);
}

void printSegments (Seg *segments, int n) {
  /* prints the segments in the array */
  for (int i = 0; i <= n; ++i) {
    printf("[%d,%d)", segments[i].start, segments[i].end);
    printf(i == n ? "\n" : ",");
  }
}

void mergeSegments(Seg *segments, int n) {
  /* checks each segment pair and merges them as long as
   * the value of the end field of the current segment
   * overlaps the start field's value of the next */
  int curr = 0; // index of current segment in the merged array
  Seg a, b;

  for (int i = 1; i < n; ++i) {
    a = segments[curr], b = segments[i];
    if (a.end >= b.start) {   
      // merge segments
      segments[curr].end = MAX (a.end, b.end);
      segments[curr].start = MIN (a.start, b.start);
    } else segments[++curr] = segments[i];
  }
  printSegments (segments, curr);
}

int main() {
  int n;
  (void)! scanf("%d:", &n);

  Seg *segments = readInput (n);

  mergeSort (n, segments);

  mergeSegments(segments, n);

  free(segments);

  return 0;
}