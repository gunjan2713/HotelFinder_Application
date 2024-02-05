/**
 * @file lab8.cpp
 * @author Khalid Mengal
 * @description BST Tree implementation in C++
 * @date 2022-11-03
 */
#ifndef BST_HPP
#define BST_HPP
#pragma once
#include<iostream>
#include<cstdlib>
#include<sstream>
#include<iomanip>
#include<math.h>
#include<queue>
#include<vector>
#include "hotel.hpp"

using namespace std;
template <typename T1, typename T2>
class Node
{
	private:
		T1 key;					//city name
		vector<T2> value;		//list of hotels in the city
		Node<T1,T2>* left;		//left child
		Node<T1,T2>* right;		//right child
		Node<T1,T2>* parent;	//pointer to the parent node
	
	public:
		Node(T1 key): key(key),left(nullptr),right(nullptr), parent(nullptr) 
		{}
		void print(string stars="")	//print all or only those hotels with specific stars.
		{
			int counter=0;
			cout<<std::left<<setw(50)<<"Name"<<" "<<setw(10)<<"City"<<" "<<setw(5)<<"Stars"<<" "<<setw(10)<<"Price"<<" "<<setw(20)<<"Country"<<" "<<"Address"<<endl;
			cout<<"------------------------------------------------------------------------------------------------------------"<<endl;

			for(auto it:value)
				if(stars=="" or stars==it->getStars())
				{
					it->print2();
					counter++;
				}
			
			cout<<"------------------------------------------------------------------------------------------------------------"<<endl;
			cout<<counter<<" records found."<<endl;
		}

		template<typename,typename> friend class BST;
};
//=============================================================================
template <typename T1, typename T2>
class BST
{
	private:
		Node<T1,T2> *root;
	public:
		BST();									//constructor
		~BST();									//destructor
		Node<T1,T2>* getRoot();						//returns the root of the Tree
		void insert(Node<T1,T2>* ptr,T1 key, T2 value);			//Insert key into tree/subtree with root ptr
		int height(Node<T1,T2> *ptr);				    //Find the height of a tree/subtree with root ptr
		Node<T1,T2>* find(Node<T1,T2> *ptr,T1 key,string stars);		//Find and returns the node with key
		Node<T1,T2>* findMin(Node<T1,T2> *ptr);				//Find and return the Node<T1,T2> with minimum key value from a tree/subtree with root ptr
		void remove(Node<T1,T2> *ptr,T1 key, T2 value);			//Remove a node with key from the tree/subtree with root
		void deleteTree(Node<T1, T2>* root) ;
};
//=====================================================================
//write implementation of all methods below
#endif