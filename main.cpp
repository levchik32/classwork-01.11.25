#include <iostream>

int** make_mtx(int rows, int cols);
void output(const int* const* mtx);
void rm(int** mtx);

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
  rm(mtx);
}
