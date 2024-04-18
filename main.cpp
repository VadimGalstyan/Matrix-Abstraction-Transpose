#include <iostream>

class Matrix{
public:
Matrix(const int& n,const int& m){
      if (n > 0)
      {
        row = n;
      }else{
        throw std::runtime_error("The number(n) cannot be negative!");
      }
      
      if (m > 0)
      {
        column = m;
      }else{
        throw std::runtime_error("The number(m) cannot be negative!");
      }

      matrix = (int**)malloc(row * sizeof(int*));

      if (matrix == NULL)
      {
        throw std::bad_alloc();
      }

      for (size_t i = 0; i < row; ++i)
      {
        matrix[i] = (int*)malloc(column * sizeof(int));
        if (matrix[i] == NULL)
        {
        throw std::bad_alloc();
        }
      }

}

~Matrix(){
    for (size_t i = 0; i < row; ++i)
    {
        free(matrix[i]);
        matrix[i] = nullptr;
    }
    matrix = nullptr;
}

public:
unsigned getRow() const {
    return row;
}

unsigned getColumn() const {
    return column;
}

void matrixInitRandomNums(){
    for (size_t i = 0; i < row; ++i)
    {
        
        for (size_t j = 0; j < column; ++j)
        {
            matrix[i][j] = rand() % 10;
            
        }
        
    }
}

void matrixInitInputNums(){
  std::cout<<"Fill Matrix:"<<std::endl;
    for (size_t i = 0; i < row; ++i)
    {
        for (size_t j = 0; j < column; ++j)
        {
            std::cin>>matrix[i][j];
            
        }
        
    }
}

void printMatrix() const {
  for (size_t i = 0; i < row; ++i)
    {
        for (size_t j = 0; j < column; ++j)
        {
            std::cout<<matrix[i][j]<<" ";
        }
        std::cout<<std::endl;
    }
}

void rotateMatrix(){
    if (row == column)
    {

       for (size_t i = 0; i < row; ++i)
    {
        for (size_t j = i; j < column ; ++j)
        {
            std::swap(matrix[i][j],matrix[j][i]);

        }
        
    }

    }
    else
    {


      int** ptr = (int**)malloc(column * sizeof(int*));
    if (ptr == NULL)
    {
       throw std::bad_alloc();
    }

    for (size_t i = 0; i < column; ++i)
    {
      ptr[i] = (int*)malloc(row * sizeof(int));
      if (ptr[i] == NULL)
        {
        throw std::bad_alloc();
        }
    }

    for (size_t i = 0; i < column; ++i)
    {
       for (size_t j = 0; j < row; ++j)
    {
        ptr[i][j] = matrix[j][i];
    }
        
    }

    for (size_t i = 0; i < row; ++i)
    {
      free(matrix[i]);
    }
      free(matrix);
      
    matrix = ptr;
    std::swap(row,column);

    }
    

    
}

private:
 int row = 0;
 int column = 0;
 int** matrix = nullptr;
};

int main(int argc,char* argv[]){
  Matrix matrix(3,3);

  std::cout<<matrix.getColumn()<<std::endl;
  std::cout<<matrix.getRow()<<std::endl;

  matrix.matrixInitRandomNums();
  matrix.printMatrix();

  std::cout<<std::endl;

  matrix.rotateMatrix();
  matrix.printMatrix();

    return 0;
}
