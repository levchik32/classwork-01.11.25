#include <iostream>

int** convert(const int* t, size_t n, const size_t* lns, size_t rows);
int** make(int r, const size_t* lns);
void rm(int** mtx, int r);
void output(int** mtx, int r, const size_t* lns);

int main()
{

}

int** convert(const int* t, size_t n, const size_t* lns, size_t rows)
{
  int** mtx = make(rows, lns);

  size_t k = 0;
  for (size_t i; i < rows; ++i)
  {
    size_t cols = lns[i];
    for (size_t j; j < cols; ++j)
    {
      mtx[i][j] = t[k];
      k += 1;
    }
  }

  return mtx;
}

int** make(size_t r, const size_t* lns)
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

void output(int** mtx, int r, const size_t* lns)
{
  for (size_t i = 0; i < r; ++i)
  {
    size_t c = lns[i];
    for (size_t j = 0; j < c - 1; ++j)
    {
      std::cout << mtx[i][j] << " ";
    }
    std::cout << mtx[i][c - 1] << "\n";
  }
}