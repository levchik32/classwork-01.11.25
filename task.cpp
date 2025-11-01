#include <iostream>

int** convert(const int* t, size_t n, const size_t* lns, size_t rows);
int** make(int r, int c);
void rm(int** mtx, int r);

int main()
{

}

int** convert(const int* t, size_t n, const size_t* lns, size_t rows)
{
  
}

int** make(size_t r, size_t* lns)
{
  int** mtx = new int* [r];
  for (size_t i = 0; i < r; ++i)
  {
    try
    {
      mtx[i] = new int[lns[i]];
    }
    catch(const std::bad_alloc&e)
    {
      rm(mtx, i);
      throw;
    }
  }
  return mtx;
}

void rm (int** mtx, int r)
{
  for (size_t i = 0; i < r; ++i)
  {
    delete[] mtx[i];
  }
  delete[] mtx;
}