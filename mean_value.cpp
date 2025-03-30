#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

// define the requested function
// The linear transformation required is: f(x) = 3/4 * x - 7/4
double fun(double num)
{
	return 0.75 * num - 1.75;
}

int main()
{
	// Create an input file stream
	ifstream ifstr("data.txt");
	
	// Check if the file was opened correctly
	if(ifstr.fail())
	{
		cerr << "File not found." << endl;
		return 1;
	}

	// Create an output file stream
	ofstream ofstr("result.txt");

	// Check if the file was opened/created correctly
	if(ofstr.fail())
	{
		cerr << "File cannot be created." << endl;
		return 1;
	}
	
	// Initialize variables
	double val;
	double cum_sum = 0;
	int i = 1;

	// Write the first line of the output file
	ofstr << "# N Mean" << endl;

	// Read from the input file, computations, write on the output file
	while(ifstr >> val)
	{
	val = fun(val); // apply the transformation
	cum_sum += val; // update cumulative sum
	ofstr << defaultfloat << i << " " // write the index
		  << setprecision(16) << scientific << cum_sum / i << endl; // write the value
	i++; // increase the index
	}
	
	// Close the files
	ifstr.close();
    ofstr.close();
																																																																																																														
    return 0;
}