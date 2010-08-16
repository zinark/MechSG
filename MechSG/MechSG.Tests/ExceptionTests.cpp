#include <gtest/gtest.h>
#include <exception>
#include <string>
using namespace std;

TEST (Exceptional, Line)
{
    try
    {
        ostringstream stream;
        stream << "Source : " << __FILE__ << endl << "Line : " <<  __LINE__ << endl;
        string msg = stream.str();
        throw exception (msg.c_str());
    }
    catch (exception& e)
    {
    	cout << e.what () << endl;
    }
}