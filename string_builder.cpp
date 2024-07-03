#include <vector>
#include <limits.h>
#include <stdexcept>
#include <iostream>

class StringBuilder {
    size_t x;
    std::vector<std::string> m_strs;

public:
    StringBuilder(size_t x): x(x), m_strs() {}
    char* build_c_string();
    void append(std::string word);
};


void StringBuilder::append(std::string str) {
    if (str.length() != this->x) {
	throw std::runtime_error("Invalid string length!");
    }
    this->m_strs.push_back(str);
}

char* StringBuilder::build_c_string() {
    char* res = new char[this->x * this->m_strs.size()];
    size_t c = 0;
    for (std::string i : this->m_strs) { 	// O(n)
	for (int j = 0; j < x; j++) {		// O(x)
	    res[c] = i[j];
	    c++;
	}
    }
    res[c] = '\0';
    return res;
}

int main(void) {
    StringBuilder b = StringBuilder(3);
    b.append("abc");
    b.append("def");
    b.append("ghi");
    char* r = b.build_c_string();
    std::cout << r << std::endl;
    delete r;
}
