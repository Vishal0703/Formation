#include<iostream>
#include<algorithm>
#include<vector>

int BOT_ID;
int BOT_DEST;

struct map
{
  int bot_id;
  float dist;
  int fig_id;
};

typedef map* heap;

void min_heapify(map a[],int i,int n)
{
  int j;
  map temp;
  temp = a[i];
  j = 2*i;
  while (j <= n)
    {
      if (j < n && a[j+1].dist < a[j].dist)
        j = j + 1;
      if (temp.dist < a[j].dist)
        break;
      else if (temp.dist >= a[j].dist)
        {
          a[j/2] = a[j];
          j = 2*j;
        }
    }
  a[j/2] = temp;
  return;
}

void build_minheap(map a[], int n)
{
  int i;
  for(i = n/2; i >= 1; i--)
    {
      min_heapify(a,i,n);
    }
}

void assignment(heap h, heap arr[], int n)
{
  std::vector<int> table (n,0);
  map test;
  for(int i=0; i<n*n; i++)
    {
      test=pop(h);
      if(table[test.fig_id]==0)
        {
          table[test.fig_id]=1;
          if(test.bot_id==BOT_ID)
            {
              BOT_DEST=test.fig_id;
              exit(-1);
            }
        }
      else if(table[test.fig_id]==1)
        {
          push(h, pop(arr[test.bot_id]));
        }

    }
}
