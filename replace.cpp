#include <iostream>
using namespace std;
#include <vector>
#include <string>
#include <algorithm>
 
/*
 *Find all positions of the a SubString in given String
 */
void findAllOccurances(std::vector<int> & vec, std::string data, std::string toSearch)
{
	// Get the first occurrence
	size_t pos = data.find(toSearch);
 
	// Repeat till end is reached
	while( pos != std::string::npos)
	{
		// Add position to the vector
		vec.push_back(pos);
 
		// Get the next occurrence from the current position
		pos =data.find(toSearch, pos + toSearch.size());
	}
}

void replaceall(string &src,string dst, string repl)
{
   size_t pos  = src.find(dst);
   while (pos != string::npos)
   {
       src.replace(pos,dst.length(),repl);
       pos  = src.find(dst,pos+dst.length());
   }

}
 
int main()
{
	std::string data = "Hi this is a Sample string, 'iS' is here 3 times";
    string str = "is";
    string repl = "are";
    transform(data.begin(),data.end(),data.begin(),::tolower);
	std::vector<int> vec;
    
	// Get All occurrences of the 'is' in the vector 'vec'
	findAllOccurances(vec, data , str);
 
	std::cout<<"All Index Position of 'is' in given string are,"<<std::endl;
 
for (int i = 0; i<vec.size();i++)
		std::cout<<vec[i]<<std::endl;
 
    cout<<"string is "<<data<<endl;
    replaceall(data,"is",repl);
    cout<<"string is "<<data<<endl;
	return 0;
}