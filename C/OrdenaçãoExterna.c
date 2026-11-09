#define _GNU_SOURCE 
#include <stdio.h>
#include <stdlib.h>

int count = 0;
char *file[] = {"file1.txt", "file2.txt",
                    "res1.txt", "res2.txt"};
  /* display the contents of the file */
  int showData(char *filename) {
        FILE *fp;
        int val, i = 0;

        fp = fopen(filename, "r");
        while (fscanf(fp, "%d", &val) != EOF) {
                printf("%4d ", val);
                i++;
                if (i && i % 8 == 0)
                        printf("\n");
        }
        return (i);
  }

  /*
   * Write half of the data in input file to "file1.txt"
   * and remaining half to "file2.txt"
   */
  

  /* Perform External Sorting */
  void sortData(char *filename) {
        FILE *fp[4];
        int i, flg1, flg2, count1, count2, val, val1, val2, n = 1;

        while (1) {
                for (i = 0; i < 4; i++) {
                        /* file[0] & file[1]  are read only files */
                        if (i < 2) {
                                fp[i] = fopen(file[i], "r");
                                if (fp[i]) {
                                        if (fscanf(fp[i], "%d", &val) == EOF)
                                                goto out;
                                        else
                                                rewind(fp[i]);
                                }
                        } else {
                                /* file[2] & file[3] - open in write mode */
                                fp[i] = fopen(file[i], "w");
                        }
                        if (!fp[i]) {
                                fcloseall();
                                printf("sortData-fopen(%s) failed\n", file[i]);
                                exit(0);
                        }
                }

                i = 2;
                flg1 = flg2 = 1;
                count1 = count2 = 0;

                for (;;) {
                        if (flg1) {
                                /*
                                 * if file[0] reached EOF, then write the contents
                                 * other file file[2] to the output file
                                 */
                                if (fscanf(fp[0], "%d", &val1) == EOF) {
                                        while (fscanf(fp[1], "%d", &val2) != EOF) {
                                                fprintf(fp[i], "%d ", val2);
                                        }
                                        break;
                                }
                        }

                        if (flg2) {
                                /*
                                 * if file[1] reached EOF, then write the contents of
                                 * file[0] to the output file
                                 */
                                if (fscanf(fp[1], "%d", &val2) == EOF) {
                                        while (fscanf(fp[0], "%d", &val1) != EOF) {
                                                fprintf(fp[i], "%d ", val1);
                                        }
                                        break;
                                }
                        }

                        /*
                         * if val1 from file[0] is greater than the value val2,
                         * then write val2 to output file.  Otherwise, write val1
                         * to output file.
                         */
                        if (val1 > val2)  {
                                flg1 = 0;
                                flg2 = 1;
                                count2++;
                                fprintf(fp[i], "%d ", val2);
                        } else {
                                flg1 = 1;
                                flg2 = 0;
                                count1++;
                                fprintf(fp[i], "%d ", val1);
                        }

                        /*
                         * n is an incrementer. If count1 equals n, then write val2
                         * to output file, increment count2 (written value from file[1]
                         * to the output file).  Value of i is changed inorder to 
                         * use other file (file[1]/file[2]) for proximo iteration.
                         */
                        if (count1 == n) {
                                fprintf(fp[i], "%d ", val2);
                                count2++;
                                while (count2 < n) {
                                        if (fscanf(fp[1], "%d", &val2) != EOF)
                                                fprintf(fp[i], "%d ", val2);
                                        count2++;
                                }
                                flg1 = flg2 = 1;
                                count1 = count2 = 0;
                                i = (i == 2) ? 3 : 2;
                        }
                        if (count2 == n) {
                                fprintf(fp[i], "%d ", val1);
                                count1 = count1 + 1;
                                while (count1 < n) {
                                        if (fscanf(fp[0], "%d", &val1) != EOF)
                                        fprintf(fp[i], "%d ", val1);
                                        count1++;
                                }
                                flg1 = flg2 = 1;
                                count1 = count2 = 0;
                                i = (i == 2) ? 3 : 2;
                        }
                }
                fcloseall();
                unlink(file[0]);
                unlink(file[1]);
                /* move contents of file[2] to file[0] */
                rename(file[2], file[0]);
                /* move contents of file[3] to file[1] */
                rename(file[3], file[1]);
                n = n * 2;
        }
        out:
                fcloseall();
                unlink(filename);
                /* move contents of file[0] to output file */
                rename(file[0], filename);
                unlink(file[1]);
  }
void splitData(char *filename) {
        FILE *fp[3];
        int i, val;
        fp[2] = fopen(filename, "r");
        if (!fp[2]) {
                printf("splitData-fopen failed- %s\n", filename);
                exit(0);
        }

        fp[0] = fopen(file[0], "w");
        fp[1] = fopen(file[1], "w");

        if (!fp[0] || !fp[1]) {
                fcloseall();
                printf("splitData - fopen failed\n");
                exit(1);
        }

        for (i = 0; i < count/2; i++) {
                fscanf(fp[2], "%d", &val);
                fprintf(fp[0], "%d ", val);
        }

        for (i = count/2; i < count; i++) {
                fscanf(fp[2], "%d", &val);
                fprintf(fp[1], "%d ", val);
        }
        fcloseall();
        return;
  }
  int main(int argc, char **argv) {
        printf("Data before sorting:\n");
        count = showData(argv[1]);
        printf("\nNo of elements in file: %d\n\n", count);
        printf("Data after split operation:\n");
        splitData(argv[1]);
        printf("Data in file 1:\n");
        showData(file[0]);
        printf("\n");
        printf("Data in file 2:\n");
        showData(file[1]);
        printf("\n");
        sortData(argv[1]);
        printf("\nAfter Sorting:\n");
        showData(argv[1]);
        printf("\n");
        return 0;
  }