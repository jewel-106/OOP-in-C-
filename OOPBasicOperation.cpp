#include<bits/stdc++.h>
using namespace std;

// class Book

class Book{
    public:
        string title;
        string author;
        string ISBN;
    public:
        // Constructor
        Book(string t, string a, string isbn): title(t),author(a),ISBN(isbn)
        {}

        // Displat method
        void display() const{
            cout<<"Title: "<<title<<" ,Author: "<<author<<" , ISBN: "<<ISBN<<endl;
        }

        // Getters ( to be used by other classes)
        string getTitle() const { return title;}
        string getISBN() const { return ISBN;}
};

// class Member
class Member{
    public:
        string memberName;
        vector<Book> borrowedBooks;
    public:
        // constructor
        Member(string name): memberName(name){}

        /// Borrow book method
        void borrowBook(const Book &book){
            borrowedBooks.push_back(book);
            cout<<memberName<<" borrowed "<<book.getTitle()<<endl;
        }

        // Return book method (overloaded)
        void returnBook(const string &isbn){
            for(size_t i = 0; i< borrowedBooks.size();++i){
                if(borrowedBooks[i].getISBN() == isbn){
                    cout<<memberName<<" returned "<<borrowedBooks[i].getTitle()<<endl;
                    borrowedBooks.erase(borrowedBooks.begin() + i);
                    return;
                }
            }
            cout<<"Book with ISBN "<<isbn<<" not found."<<endl;
        }

        // return book method (overloaded)
        void returnBook(const Book &book){
            returnBook(book.getISBN());
        }

        // Show Borrowed books
        void showBorrowedBooks() const{
            cout<<memberName<<" has borrowed the following books: "<<endl;
            for(const auto &book: borrowedBooks){
                book.display();
            }
        }
};

// Class Library inherits from Member
class Library: public Member {
    private:
        vector<Member> members;

    public:
        // constructor
        Library():Member("") {}

        // Add a new member to the library
        void addMember(const Member &member){
            members.push_back(member);
            cout<<" Added member: "<<member.memberName<<endl;
        }

        // Borrow book for a specific member
        void borrowBookForMember(const string &memberName, const Book &book){
            for(auto &member: members){
                if(member.memberName == memberName){
                    member.borrowBook(book);
                    return;
                }
            }
            cout<<"Member "<<memberName<<" not found."<<endl;
        }

        // return book for a specific member
        void returnBookForMember(const string &memberName, const string &isbn){
            for(auto &member: members){
                if(member.memberName == memberName){
                    member.returnBook(isbn);
                    return;
                }
            }
            cout<<"Member "<<memberName<<" not found."<<endl;
        }

        // show all members and their borrowed books
        void showAllMembers() const{
            for(const auto &member: members){
                member.showBorrowedBooks();
            }
        }

};

// function overloading for borrowing books
void borrowBooks(Member &member, const vector<Book> &books){
    for(const auto &book: books){
        member.borrowBook(book);
    }
}

int main()
{
    // create some book
    Book book1("eB","R. rana","344-444-44");
    Book book2("ee","kkk","sssd");
    Book book3("dd","dd","dd");

    // Create a member
    Member member1("Jewel Rana");
    member1.borrowBook(book1);
    member1.borrowBook(book2);

    // Show boorowed books
    member1.showBorrowedBooks();

    // Return a book
    member1.returnBook("344-444-44");
    member1.showBorrowedBooks();

    // Create a Library
    Library library;
    library.addMember(member1);

    // Borrow a book for a member
    library.borrowBookForMember("Jewel Rana",book3);
    library.showAllMembers();

}