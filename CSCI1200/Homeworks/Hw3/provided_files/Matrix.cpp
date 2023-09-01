#include "Matrix.h"

using namespace std;

Matrix::Matrix() {
    rows_count = 0;        
    columns_count = 0;
    //below we have a nullptr so we can set it to something later
    p = nullptr;
}

Matrix::Matrix(unsigned int r, unsigned int c, double fill) {
    rows_count = r;
    columns_count = c;

    //here we set the pointer and start the matrix by creating an array of pointers
    p = new double*[rows_count];

    //below we iterate through rows count because the array of pointers is of size rows count
    //for each index of p we create an array to successfully create our 2-d array
    for (unsigned int i = 0; i < rows_count; i++) {                 
        p[i] = new double[columns_count];
}

//right here we iterate through each pointer and each array filling it with the array index
for (unsigned int r = 0; r < rows_count; r++) {
        for (unsigned int c = 0; c < columns_count; c++) {
            p[r][c] = fill;
        }
    }
}

Matrix::Matrix(const Matrix&newmatrix) {
    copy(newmatrix);    //this is a constructor in case we need to make a copy or create a matrix
}

//setters

void Matrix::clear() {
    for (unsigned int i = 0; i < rows_count; i++) {
        //here we iterate through the array of pointers deleting the arrays they point to
        delete []p[i]; 
    }
    delete []p; //this will delete the pointer to make sure we dont have a lose pointer
    rows_count = 0;
    columns_count = 0;
    p = nullptr;
}
bool Matrix::set(unsigned int row, unsigned int col, double stored_value) {
    if (row < rows_count && col < columns_count) { 
        //we check here to make sure that the row and col we are setting is 
        //within the matrix boundaries
        p[row][col] = stored_value; 
        return true;
    }
    return false;
}

void Matrix::multiply_by_coeficcient(double coef) {
    for (unsigned int r = 0; r < rows_count; r++) {
        for (unsigned int c = 0; c < columns_count; c++) { 
            p[r][c] *= coef; 
            
        }
    }
}

bool Matrix::swap_row(unsigned int indexrow1, unsigned int indexrow2) {
    if (indexrow1 < rows_count && indexrow2 < rows_count) {     
        double temp;
        for (unsigned int r = 0; r < columns_count; r++) {
            temp = p[indexrow1][r]; //this is meant to hold the row being swapped
            p[indexrow1][r] = p[indexrow2][r]; //here we swap out the values in the rows
            p[indexrow2][r] = temp; //we then set the second row equal to the row we are swapping out
        }
        return true;
    }
    return false;
}
void Matrix::transpose() {
    double** copy = new double*[columns_count];

    for (unsigned int i = 0; i < columns_count; i++) {                 
        copy[i] = new double[rows_count];
    }
    for (unsigned int r = 0; r < columns_count; r++) {
        for (unsigned int c = 0; c < rows_count; c++) {
            copy[c][r] = p[r][c];

        }
    }
    for (unsigned int i = 0; i < rows_count; i++) { 
        //we clear out the pointer to make sure no leaks or errors occur
        delete []p[i];
    }
    delete []p;
    p = copy;
    delete copy;
}
bool Matrix::add( Matrix &matrix) {
    if ((matrix.rows_count == rows_count) && (matrix.columns_count == columns_count)) {
        for (unsigned int r = 0; r < rows_count; r++) {
            for (unsigned int c = 0; c < columns_count; c++) {
                double value;
                matrix.get(r,c,value);
                p[r][c] += value;
            }
        }
     return true;
    }
    return false;
}

bool Matrix::subtract( Matrix &matrix) {
    if ((matrix.rows_count == rows_count) && (matrix.columns_count == columns_count)) {
        for (unsigned int r = 0; r < rows_count; r++) {
            for (unsigned int c = 0; c < columns_count; c++) {
                double value;
                matrix.get(r,c,value);
                p[r][c] -= value;
            }
        }
     return true;
    }
    return false;
}
void Matrix::copy(const Matrix &matrix) {
    rows_count = matrix.rows_count;
    columns_count = matrix.columns_count;
    p = new double*[rows_count];
    for (unsigned int i = 0; i < rows_count; i++) {               
        p[i] = new double[columns_count];
    }

    for (unsigned int r = 0; r < rows_count; r++) {
        for (unsigned int c = 0; c < columns_count; c++) {
            p[r][c] = matrix.p[r][c];
        }
    }
    

}

Matrix::~Matrix() {
    clear();
}

//getters
unsigned int Matrix::num_rows() {return rows_count;}
unsigned int Matrix::num_cols() { return columns_count;}

bool Matrix::get(unsigned int row, unsigned int col, double &stored_value) {
    if ((row < rows_count) && (col < columns_count)) {
    stored_value = p[row][col];
    return true;
    }

    return false;
}

double* Matrix::get_row(unsigned int index_of_row_to_retrieve) {
    if (index_of_row_to_retrieve < rows_count) {
        double* rowpointer = *&p[index_of_row_to_retrieve]; 
        return rowpointer;
    }

    double* rowpointer = NULL;
    return rowpointer;
}

double* Matrix::get_col(unsigned int index_of_col_to_retrieve) {
    if (index_of_col_to_retrieve > columns_count) {
        transpose();
        double* colpointer = *&p[index_of_col_to_retrieve]; 
        transpose();
        return colpointer;
    }

    double* colpointer = NULL;
    return colpointer;
}

Matrix* Matrix::quarter() { 
    unsigned int quarter_rows = rows_count/2;
    unsigned int quarter_columns = columns_count/2;
    if (rows_count % 2 != 0) {
        quarter_rows+=1;
    }
    if (columns_count % 2 != 0) {
        quarter_columns+=1;
    }

    Matrix *matrixes = new Matrix[4];

    Matrix upper_left(quarter_rows,quarter_columns,0);
    for (unsigned int i = 0; i < quarter_rows; i++) {
        for (unsigned int c = 0; c < quarter_columns; c++) {
            upper_left.p[i][c] = p[i][c];
        }
    }

    matrixes[0] = upper_left; 

    Matrix upper_right(quarter_rows,quarter_columns,0);
    for (unsigned int i = 0; i < quarter_rows; i++) {
        for (unsigned int c = 0; c < quarter_columns; c++) {
            upper_right.p[i][c] = p[i][c+quarter_columns];
        }
    }

    matrixes[1] = upper_right;

    Matrix lower_left(quarter_rows,quarter_columns,0);
    for (unsigned int i = quarter_rows-1; i < quarter_rows; i++) {
        for (unsigned int c = 0; c < quarter_columns; c++) {
            lower_left.p[i-1][c] = p[i][c];
        }
    }

     matrixes[2] = lower_left;

    Matrix lower_right(quarter_rows,quarter_columns,0);
    for (unsigned int i = quarter_rows-1; i < quarter_rows; i++) {
        for (unsigned int c = quarter_columns; c < quarter_columns; c++) {
            lower_right.p[i-1][c-quarter_columns] = p[i][c];
        }
    }

    matrixes[3] = lower_right;
    
    
    return matrixes;
}

std::ostream& operator<< (std::ostream& output, Matrix& m) {
    output<<endl<<m.num_rows()<<" x "<<m.num_cols()<<" matrix:"<<endl;
    output<<"[";
    for (unsigned int r = 0; r < m.num_rows(); r++) {
        for (unsigned int c = 0; c < m.num_cols(); c++) {
            double value;
            m.get(r,c, value);
            output<<" "<< value;
        }
        if (r != m.num_rows()-1) {
        output<<endl<<" ";
        }
    }
    output<<" ]"<<endl;

    return output;
}

bool Matrix :: operator== (const Matrix& m2) {
    if (rows_count != m2.rows_count || columns_count != m2.columns_count) {
        return false;
    }
    for (unsigned int r = 0; r < rows_count; r++) {
        for (unsigned int c = 0; c < columns_count; c++) {
            double value1 = p[r][c];
            double value2 = m2.p[r][c];
            if (value1 != value2) {
                return false;

            }
        }
    }
    return true;
}

bool Matrix :: operator!= (const Matrix& m2) {
    if (rows_count != m2.rows_count || columns_count != m2.columns_count) {
        return true;
    }
    for (unsigned int r = 0; r < rows_count; r++) {
        for (unsigned int c = 0; c < columns_count; c++) {
            double value1 = p[r][c];
            double value2 = m2.p[r][c];
            if (value1 != value2) {
                return true;

            }
        }
    }
    return false;
}

Matrix& Matrix :: operator= (const Matrix& ogmatrix) {
    clear();
    copy(ogmatrix);
    return *this;
}