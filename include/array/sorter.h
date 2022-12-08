/* -------------------------------------------------------
    Code from https://www.geeksforgeeks.org/bubble-sort/
   ------------------------------------------------------- */

#ifndef __SORTER_H__
#define __SORTER_H__

class Sorter
{
public:
    void bubbleSort(int arr[], int n);

private:
    void swap(int *xp, int *yp);
};

#endif