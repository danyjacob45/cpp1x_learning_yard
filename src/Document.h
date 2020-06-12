//
// Created by Dany Jacob on 25/5/20.
//

#ifndef FIRSTPROGRAM_DOCUMENT_H
#define FIRSTPROGRAM_DOCUMENT_H
#include <iostream>

class Document {
public:
    virtual void serialize() const = 0;

};

class Text: public Document {
public:
    void serialize() const override final;

};

class RichText: public Document {
public:
    void serialize() const override;

};

class XML: public Document{
public:
    void serialize() const override;
};

#endif //FIRSTPROGRAM_DOCUMENT_H
