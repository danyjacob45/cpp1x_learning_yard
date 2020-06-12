//
// Created by Dany Jacob on 25/5/20.
//

#include "Document.h"

void Text::serialize() const {
    std::cout << "Text serialize" << std::endl;
}

void RichText::serialize() const {
    std::cout << "RichText serialize" << std::endl;
}

void XML::serialize() const {
    std::cout << "XML serialize" << std::endl;
}
