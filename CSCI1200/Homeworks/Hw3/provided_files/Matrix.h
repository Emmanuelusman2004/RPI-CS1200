#include <iostream>

using namespace std;

class Matrix {
public:
    //these are constructors
    Matrix();
    Matrix(unsigned int rows_count, unsigned int columns_count, double fill); 
    Matrix(const Matrix& newmatrix);
    //these are setters
    void clear();
    bool set(unsigned int row, unsigned int col, double stored_value); 
    void multiply_by_coeficcient(double coef);

    bool swap_row(unsigned int indexrow1, unsigned int indexrow2);

    void transpose();

    bool add( Matrix &matrix);
    bool subtract( Matrix &matrix);
    
    ~Matrix();



    //there are getters
    unsigned int num_rows(); 
    unsigned int num_cols();

    bool get(unsigned int row, unsigned int col, double &stored_value); 

    double* get_row(unsigned int index_of_row_to_retrieve);
    double* get_col(unsigned int index_of_col_to_retrieve);

    Matrix* quarter();

    bool operator== (const Matrix& m2);

    bool operator!= (const Matrix& m2);
    
    Matrix& operator= (const Matrix& ogmatrix);

private:
    unsigned int rows_count;
    unsigned int columns_count;       
    double** p;

    void copy(const Matrix&matrix);
};

std::ostream& operator<< (std::ostream& out, Matrix& m);

