//
// Created by kamr on 9/3/2021.
//


#ifndef GNU_LINK_H
#define GNU_LINK_H

template <typename E>
class Link {
public:
    E data;
    Link *next;

    Link(const E &val = E{}, Link *n = nullptr) : data{val}, next{n} {}

    Link(Link *n = NULL) : next{n} {}
};

#endif