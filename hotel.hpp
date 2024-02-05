//============================================================================
// Name         : hotel.hpp
// Author       : Khalid Mengal
// Version      : 1.0
// Date Created : 25-04-2023
// Date Modified: 23-08-2023 
// Description  : 
//============================================================================
#ifndef HOTEL_HPP
#define HOTEL_HPP
#pragma once
#include<iostream>
#include<string>
using namespace std;

class Hotel
{
	private:
		string name;	//name of the hotel	
		string city;	//city of the hotel
		string stars;	//starts of the hotel
		string price;	//price per night
		string country;	//country
		string address;	//full address of the hotel
	public:
		Hotel(string name,string city, string stars,string price,string country,string address);	//constructor
		string getName();	
		string getCity();	
		string getStars();
		string getPrice();
		string getCountry();
		string getAddress();
		string toString();
		void print();
		void print2();
};
//==========================================================
//implement the methods list above in a file called hotel.cpp
#endif