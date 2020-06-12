//
// Created by Dany Jacob on 25/5/20.
//
#pragma once
#ifndef FIRSTPROGRAM_STREAM_H
#define FIRSTPROGRAM_STREAM_H
#include <string>
#include <iostream>

class Stream {
    std::string m_Filename;
public:
    Stream(const std::string& name): m_Filename(name){
        std::cout << "Stream(const std::string& name)" << std::endl;
    }
    const std::string& GetFileName() const;
    ~Stream();
};

class InputStream: virtual public Stream{
public:

    InputStream(const std::string &name, std::istream &input);
    std::istream& operator >> (std::string &data);

private:
    std::istream& input;

};

class OutputStream: virtual public Stream{
public:
    OutputStream(const std::string &name, std::ostream &output);
    std::ostream& operator << (const std::string &data);

private:
    std::ostream& output;

};

class IOStream: public InputStream, public OutputStream {
public:

    IOStream(const std::string &filename): InputStream(filename,std::cin),
                                           OutputStream(filename,std::cout),
                                           Stream(filename) {

        std::cout << "IOStream" << std::endl;
    }
    ~IOStream();
};


#endif //FIRSTPROGRAM_STREAM_H
