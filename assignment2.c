#include <stdio.h> 
#include <stdlib.h>

  int f1(int segment, char ring) {
    int throwPoint = 0;
    if (ring == 'D')
      throwPoint = segment * 2;
    else if (ring == 'S')
      throwPoint = segment;
    else if (ring == 'T')
      throwPoint = segment * 3;
    else if (ring == 'O')
      throwPoint = 25;
    else if (ring == 'I')
      throwPoint = 50;
    return throwPoint;
  }

int f2(int segment, char ring, int totalPoints) {
  int throwPoint = f1(segment, ring);
  totalPoints = totalPoints - throwPoint;
  return totalPoints;
}

int main() {

  char ring;
  int segment;
  int totalPoints;

  printf("Target: ");
  scanf("%d", & totalPoints);
  printf("\nThrow: ");

  while (ring != 'D') {
    scanf("%d\n", & segment);
    scanf("%c", & ring);
    if (ring == 'D') {
      totalPoints = f2(segment, ring, totalPoints);
      printf("Points: %d\n", totalPoints);
      break;
    }
    printf("Points: %d\n", totalPoints);
    printf("Throw: ");
  }

  while (totalPoints > 0) {
    printf("Throw: ");
    scanf("%d\n", & segment);
    scanf("%c", & ring);
    if (f2(segment, ring, totalPoints) == 0 && ring != 'D') {
      totalPoints = totalPoints;
    } else if (f2(segment, ring, totalPoints) < 0) {
      totalPoints = totalPoints;
    } else if (f2(segment, ring, totalPoints) == 1) {
      totalPoints = totalPoints;

    } else {
      totalPoints = f2(segment, ring, totalPoints);
    }
    printf("Points: %d\n", totalPoints);
  }

  return EXIT_SUCCESS;
}
