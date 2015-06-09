//a simple matrix class representing a set of integers
//implement basic arithmetic and logical functions
class Matrix
{
private:
	int *pElems;
	int _rows;
	int _cols;
public:
	Matrix();
	Matrix(int rows, int cols);
	Matrix(Matrix &mtx);
	~Matrix();

	void setElem(int row, int col, int value);

	int getRows();
	int getCols();
	int getElem(int row, int col);

	void add(Matrix &mtx);
	void subtract(Matrix &mtx);
	bool equal(Matrix &mtx);
};