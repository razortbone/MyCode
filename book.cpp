#include <iostream>
using namespace std;
#include <string>

class Author
{public:
    string authorname;
    Author( string s)
    {
        authorname = s;
    }
  string getAuthorName()
  {
      return authorname;

  }  
  void setAuthorName(string s)
  {
      authorname = s;
      
  }
};

class AuthorIterator
{
   public:
   int *pos;
   int& operator *() const
   {
      return *pos;
   }  




};

class Book {
  struct AuthorListNode {
     int data;
     AuthorListNode* next;
  };
public:
  Book (std::string theTitle,
        Author theAuthor, 
        std::string theIdentifier);

  Book (std::string theTitle, int numberOfAuthors,
        Author* theAuthors, std::string theIdentifier);

  Book (const Book& b);

  ~Book();

  Book& operator= (const Book&);

  typedef AuthorIterator iterator;
  //typedef ConstAuthorIterator const_iterator;

  std::string getTitle() const        {return title;}
  void putTitle(std::string theTitle) {title = theTitle;}

  int getNumberOfAuthors() const {return numAuthors;}

  void addAuthor (Author);
  void removeAuthor (Author);

  std::string getIdentifier() const   {return identifier;}
  void putIdentifier(std::string id)  {identifier = id;}


  iterator begin();
  //const_iterator begin() const;
//
  iterator end();
 // const_iterator end() const;


private:
  std::string title;
  int numAuthors;

  AuthorListNode* authors;  // linked list of pointers to authors
  std::string identifier;
  //friend class AuthorIterator;
 // friend class ConstAuthorIterator;
};

