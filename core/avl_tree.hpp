//
// Created by Oruqimaru on 18/7/2020.
//

#pragma once

#include "binary_tree.hpp"
#include "avl_node.hpp"
#include <iostream>
#include <queue>
#include <vector>
#include <stdlib.h>

using namespace std;

template <class T>
class AvlTree : BinaryTree<AvlNode<T> >{
public:
#define right_navi 1
#define left_navi 0

    //DEBUG: for debug use
    clock_t trace_time;
    int repair_time;
//    int** path_height_L;
//    int** path_height_R;
    int** path_height;
//    AvlNode<T>** updater;
//    int* navigator;
    int* path_key;


    //Main code
    AvlTree():repair_time(0), trace_time(0){
        BinaryTree<AvlNode<T> >();
//        path_height_L = (int**) malloc(sizeof(int*) * 50);
//        path_height_R = (int**) malloc(sizeof(int*) * 50);
//        updater = (AvlNode<T>**) malloc(sizeof(AvlNode<T>*) * 50);
//        navigator = (int*) malloc(sizeof(int) * 50);
    }

    //TODO: clean the tree when destroyed
    ~AvlTree(){

    }

//    void ShowTree(){
//        AvlNode<T>* pivot = this->_root;
//
//        queue<AvlNode<T>*> pipe;
//        pipe.push(pivot);
//        if(pivot == NULL)
//            return;
//        while(true){
//            if(pipe.size() == 0)
//                return;
//
//            pivot = pipe.front();
//            cout << pivot->ToString() << endl;
//            pipe.pop();
//            if(pivot->LeftChild() != NULL)
//                pipe.push(pivot->LeftChild());
//
//            if(pivot->RightChild() != NULL)
//                pipe.push(pivot->RightChild());
//        }
//    }

//    int GetHeight(){
//        int left = *(this->_root->GetChildHeight());
//        int right = *(this->_root->GetChildHeight()+1);
//        return left > right ? left : right;
//
////        return this->_height;
//    }

    //TODO: insert the point, repair the tree, then update the height
    void Insert(int key){
        if(this->_root == NULL){
            AvlNode<T>* new_node = new AvlNode<T>(key, NULL, -1);
            this->_root = new_node;
            return;
        }

        AvlNode<T>* new_node = insertTrace(key/*, path_heights, navigator, updater*/);
        repairTree(new_node/*, path_heights, navigator, updater*/);
    }

    void Query(int key){

    }

protected:
    /*
     * Only handle when root is not null. Insert the new key and reture a
     * trace vector for repair use
     *
     * Trace to the leaf that we going to insert the node and record the
     * child heights in the path. Using copy constructor to do the insert
     * of the vector. Maybe slow in this part.
     *
     * return value is the height of the path
     */
    AvlNode<T>* insertTrace(int key/*, vector<pair<int, int> >& path_heights, vector<int>& navigator, vector<AvlNode<T>*>& updater*/){
        AvlNode<T>* pivot = this->_root;

//        updater[height]=pivot;

        while(true){
            int node_value=pivot->GetValue();

                if(key > node_value){
                    AvlNode<T>* right_node = pivot->RightChild();
                    if(right_node==NULL){
                        AvlNode<T>* new_node = new AvlNode<T>(key, pivot, right_navi);
                        pivot->SetRight(new_node);
                        return new_node;
                    }else {
                        pivot = right_node;
                    }
                } else{
                    AvlNode<T>* left_node = pivot->LeftChild();
                    if(left_node == NULL){
                        AvlNode<T>* new_node = new AvlNode<T>(key, pivot, left_navi);
                        pivot->SetLeft(new_node);
                        return new_node;
                    }else {
                        pivot = left_node;
                    }
                }
        }

    }

    /*
     * all the rotation function will rotate the tree and update the child
     * heights in the real nodes
     */
    inline void rotationRR(AvlNode<T>* pivot/*, vector<pair<int, int> >& path_heights, vector<AvlNode<T>*>& updater, vector<int>& navigator*/){


//        AvlNode<T>* A = pivot;
        int A_navi = pivot->GetNavi();
        AvlNode<T>* Pare = pivot->Parent();
        AvlNode<T>* B = pivot->RightChild();
        AvlNode<T>* Y = B->LeftChild();
        pivot->SetRight(Y);
        pivot->SetParent(B);
        pivot->SetCode(0);
        pivot->SetNavi(left_navi);
        B->SetLeft(pivot);
        B->SetCode(0);
        if(Y!=NULL) {
            Y->SetNavi(right_navi);
            Y->SetParent(pivot);
        }
        if(Pare == NULL){
            this->SetRoot(B);
            B->SetParent(NULL);
        } else {
            B->SetNavi(A_navi);
            B->SetParent(Pare);
            if(A_navi == right_navi)
                Pare->SetRight(B);
            else
                Pare->SetLeft(B);
        }

    }

    inline void rotationRL(AvlNode<T>* pivot/*, vector<pair<int, int> >& path_heights, vector<AvlNode<T>*>& updater, vector<int>& navigator*/){

//        AvlNode<T>* A = updater[pivot];
        AvlNode<T>* Pare = pivot->Parent();
        int A_navi = pivot->GetNavi();
        AvlNode<T>* B = pivot->RightChild();
        AvlNode<T>* C = B->LeftChild();
        AvlNode<T>* Y = C->LeftChild();
        AvlNode<T>* W = C->RightChild();
        int C_code = C->GetCode();
        C->SetLeft(pivot);
        C->SetRight(B);
        C->SetCode(0);
        pivot->SetRight(Y);
        pivot->SetNavi(left_navi);
        pivot->SetParent(C);
        if(Y!=NULL) {
            Y->SetNavi(right_navi);
            Y->SetParent(pivot);
        }
        if(W!=NULL) {
            W->SetNavi(left_navi);
            W->SetParent(B);
        }
        B->SetLeft(W);
        B->SetParent(C);
        switch(C_code){
            case 0:
                pivot->SetCode(0);
                B->SetCode(0);
                break;
            case 1:
                pivot->SetCode(0);
                B->SetCode(-1);
                break;
            case -1:
                pivot->SetCode(1);
                B->SetCode(0);
                break;
        }

        if(Pare == NULL){
            this->SetRoot(C);
            C->SetParent(NULL);
        } else {
            C->SetNavi(A_navi);
            C->SetParent(Pare);
            if(A_navi == right_navi)
                Pare->SetRight(C);
            else
                Pare->SetLeft(C);
        }
    }

    inline void rotationLR(AvlNode<T>* pivot/*, vector<pair<int, int> >& path_heights, vector<AvlNode<T>*>& updater, vector<int>& navigator*/){

//        AvlNode<T>* A = updater[pivot];

        AvlNode<T>* Pare = pivot->Parent();
        int A_navi = pivot->GetNavi();
        AvlNode<T>* B = pivot->LeftChild();
        AvlNode<T>* C = B->RightChild();
        AvlNode<T>* W = C->LeftChild();
        AvlNode<T>* Y = C->RightChild();
        int C_code = C->GetCode();
        C->SetLeft(B);
        C->SetRight(pivot);
        C->SetCode(0);
        pivot->SetNavi(right_navi);
        pivot->SetLeft(Y);
        pivot->SetParent(C);
        if(W!=NULL) {
            W->SetNavi(right_navi);
            W->SetParent(B);
        }
        if(Y!=NULL) {
            Y->SetNavi(left_navi);
            Y->SetParent(pivot);
        }
        B->SetRight(W);
        B->SetParent(C);
        switch(C_code){
            case 0:
                pivot->SetCode(0);
                B->SetCode(0);
                break;
            case 1:
                pivot->SetCode(0);
                B->SetCode(1);
                break;
            case -1:
                pivot->SetCode(-1);
                B->SetCode(0);
                break;
        }

        if(Pare == NULL){
            this->SetRoot(C);
            C->SetParent(NULL);
        } else {
            C->SetNavi(A_navi);
            C->SetParent(Pare);
            if(A_navi == right_navi)
                Pare->SetRight(C);
            else
                Pare->SetLeft(C);
        }
    }

    inline void rotationLL(AvlNode<T>* pivot/*, vector<pair<int, int> >& path_heights, vector<AvlNode<T>*>& updater, vector<int>& navigator*/){
        int A_navi = pivot->GetNavi();
        AvlNode<T>* Pare = pivot->Parent();
        AvlNode<T>* B = pivot->LeftChild();
        AvlNode<T>* Y = B->RightChild();
        pivot->SetNavi(right_navi);
        pivot->SetLeft(Y);
        pivot->SetCode(0);
        pivot->SetParent(B);
        B->SetRight(pivot);
        B->SetCode(0);
        if(Y!=NULL) {
            Y->SetNavi(left_navi);
            Y->SetParent(pivot);
        }



        if(Pare == NULL){
            this->SetRoot(B);
            B->SetParent(NULL);
        } else {
            B->SetNavi(A_navi);
            B->SetParent(Pare);
            if(A_navi == right_navi)
                Pare->SetRight(B);
            else
                Pare->SetLeft(B);
        }
    }

    /*
     * Repairt the tree after a insertion, two step
     * 1. Check whether need rotation, if not,
     */
    void repairTree(AvlNode<T>* pivot/*, vector<pair<int, int> >& path_heights, vector<int>& navigator, vector<AvlNode<T>*>& updater*/){
//        if(len != updater.size() || len != path_heights.size() || (len - 1) != navigator.size()){
//            cout << "[error#] Unexpected error, length of input vector doesn't suit in repair step!\n" << endl;
//            cout << "input len: " << len << "  " << "path_heights size: " << path_heights.size() << "  navi size: " << navigator.size() << " updater size: " << updater.size() ;
//            assert(0);
//        }

        int status;
        int new_navigator = pivot->GetNavi();
        int old_navigator;
        pivot = pivot->Parent();


        while(pivot != NULL) {
            status = pivot->RepairCode(new_navigator);
            if (status == 0) {
                return;
            } else if (status == -1 || status == 1) {
                old_navigator = new_navigator;
                new_navigator = pivot->GetNavi();
                pivot = pivot->Parent();
            } else {
                if (new_navigator == right_navi) {
                    if (old_navigator == right_navi) {
                        rotationRR(pivot/*, path_heights, updater, navigator*/);
                    } else {
                        rotationRL(pivot/*, path_heights, updater, navigator*/);
                    }
                } else {
                    if (old_navigator == right_navi) {
                        rotationLR(pivot/*, path_heights, updater, navigator*/);
                    } else {
                        rotationLL(pivot/*, path_heights, updater, navigator*/);
                    }
                }
                return;
            }
        }

    }


private:
};
