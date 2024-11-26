/**
* @file Node.hpp
* @description Bu dosya Node yapısını ve bu yapının içindeki değişkenleri içerir.
* @course 2. Öğretim A Grubu
* @assignment 1. Ödev
* @date 17.11.2024
* @author Emir Ali Duman G231210004 emir.duman@sakarya.edu.tr
*/
#ifndef NODE_HPP
#define NODE_HPP

#include <string>

struct Node {
    std::string data;
    Node* next;
    Node* prev;    
};

#endif