//
// Created by Dany Jacob on 25/5/20.
//

#include "Stream.h"

const std::string& Stream::GetFileName() const {
    return m_Filename;
}

Stream::~Stream() {
    std::cout << "~Stream()" << std::endl;
}

InputStream::InputStream(const std::string &name, std::istream &input) : Stream(name), input(input) {
    std::cout << "InputStream()" << std::endl;
}

std::istream& InputStream::operator>>(std::string &data) {
    input >> data;
    return input;
}

OutputStream::OutputStream(const std::string &name, std::ostream &output) : Stream(name), output(output) {
    std::cout << "OutputStream()" << std::endl;
}

std::ostream& OutputStream::operator<<(const std::string &data) {
    output << data;
    return output;
}

IOStream::~IOStream() {

}
