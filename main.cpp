#include <iostream>

int** make_mtx(int r, int c);
void output(const int* const* mtx);
void rm(int** mtx, int r);

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
  mtx = make_mtx(rows, cols);
  output(mtx);
  rm(mtx, rows, cols);
}

void rm (int** mtx, int r)
{
  for (size_t i; i < r; ++i)
  {
    delete[] mtx[i];
  }
}