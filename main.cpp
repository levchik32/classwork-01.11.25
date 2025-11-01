#include <iostream>

int** make_mtx(int r, int c);
void output(int** mtx, int r, int c);
void rm(int** mtx, int r);
void input_mtx(int** mtx, int r, int c);

int main()
{
  int rows;
  int cols;
  std::cin >> rows >> cols;
  if (std::cin.fail())
  {
    return 1;
  }

  int** mtx = nullptr;
  try
  {
    mtx = make_mtx(rows, cols);
  }
  catch (const std::bad_alloc&e)
  {
    return 2;
  }

  input_mtx(mtx, rows, cols);
  if (std::cin.fail())
  {
    rm(mtx, rows);
    return 1;
  }

  output(mtx, rows, cols);

  rm(mtx, rows);
}

void rm (int** mtx, int r)
{
  for (size_t i = 0; i < r; ++i)
  {
    delete[] mtx[i];
  }
  delete[] mtx;
}

int** make_mtx(int r, int c)
{
  int** mtx = new int* [r];
  for (size_t i = 0; i < r; ++i)
  {
    try
    {
      mtx[i] = new int[c];
    }
    catch(const std::bad_alloc&e)
    {
      rm(mtx, i);
      throw;
    }
  }
  return mtx;
}

void input_mtx(int** mtx, int r, int c)
{
  for (size_t i = 0; i < r; ++i)
  {
    for (size_t j = 0; j < c; ++j)
    {
      std::cin >> mtx[i][j];
    }
  }
}


void output(int** mtx, int r, int c)
{
  for (size_t i = 0; i < r; ++i)
  {
    for (size_t j = 0; j < c - 1; ++j)
    {
      std::cout << mtx[i][j] << " ";
    }
    std::cout << mtx[i][c - 1] << "\n";
  }
}