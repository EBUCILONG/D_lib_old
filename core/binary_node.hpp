//
// Created by Oruqimaru on 18/7/2020.
//
#pragma once

#include <cstddef>

template <class T, class NodeT>
class BinaryNode {
public:
    BinaryNode(T value, NodeT* parent):_value(value),_parent(parent),_left_child(NULL),_right_child(NULL){
    }

    void SetValue(T key){
        _value = key;
    }

    inline void SetLeft(NodeT* node){
        _left_child = node;
    }

    inline void SetRight(NodeT* node){
        _right_child = node;
    }

    inline void SetParent(NodeT* node){
        _parent = node;
    }

    inline T GetValue() const{
        return _value;
    }

    inline NodeT* LeftChild() {
        return _left_child;
    }

    inline NodeT* RightChild() {
        return _right_child;
    }

    inline NodeT* Parent() {
        return _parent;
    }

    bool operator>(const BinaryNode& b){
        return _value > b.GetValue();
    }

    bool operator<(const BinaryNode& b){
        return _value < b.GetValue();
    }

    bool operator>=(const BinaryNode& b){
        return _value >= b.GetValue();
    }

    bool operator<=(const BinaryNode& b){
        return _value <= b.GetValue();
    }

//protected:
    T _value;
//private:
    NodeT *_parent;
    NodeT *_left_child;
    NodeT *_right_child;
};
