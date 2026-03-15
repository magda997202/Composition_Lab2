#include <iostream>
#include <string>

// The following classes are declared inline for students to refactor
// into separate header and implementation files.

class Page {
public:
    Page() : pageNumber(0), content("Empty Page") {}
    Page(int num, const std::string& text) : pageNumber(num), content(text) {}

    void setPageNumber(int num) {
        pageNumber = num;
    }

    int getPageNumber() const {
        return pageNumber;
    }

    void setContent(const std::string& text) {
        content = text;
    }

    std::string getContent() const {
        return content;
    }

private:
    int pageNumber;
    std::string content;
};

class Book {
public:
    Book() : title("Untitled"), author("Unknown") {}
    Book(const std::string& t, const std::string& a) : title(t), author(a) {}

    void setTitle(const std::string& t) {
        title = t;
    }

    std::string getTitle() const {
        return title;
    }

    void setAuthor(const std::string& a) {
        author = a;
    }

    std::string getAuthor() const {
        return author;
    }

    // Aggregation: Book contains a Page
    void setPageDetails(int pageNum, const std::string& pageContent) {
        currentPage.setPageNumber(pageNum);
        currentPage.setContent(pageContent);
    }

    int getCurrentPageNumber() const {
        return currentPage.getPageNumber();
    }

    std::string getCurrentPageContent() const {
        return currentPage.getContent();
    }

private:
    std::string title;
    std::string author;
    Page currentPage; // Aggregation
};


int main() {
    std::cout << "--- Original Inline Class Example ---" << std::endl;

    // Demonstrate Page class
    Page p1(1, "Introduction to C++.");
    std::cout << "Page " << p1.getPageNumber() << ": " << p1.getContent() << std::endl;

    // Demonstrate Book class with an aggregated Page
    Book myBook("The C++ Journey", "Bjarne Stroustrup");
    myBook.setPageDetails(42, "Classes and Objects.");

    std::cout << "\nBook Title: " << myBook.getTitle() << std::endl;
    std::cout << "Book Author: " << myBook.getAuthor() << std::endl;
    std::cout << "Current Page: " << myBook.getCurrentPageNumber() << std::endl;
    std::cout << "Page Content: " << myBook.getCurrentPageContent() << std::endl;

    std::cout << "\nYour task is to refactor the 'Page' and 'Book' classes "
              << "into their own header (.h) and implementation (.cpp) files." << std::endl;
    std::cout << "Remember to update this main.cpp file to include the new headers." << std::endl;

    return 0;
}