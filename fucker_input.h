/*
	头文件名字：fucker_input; 
	开发者：sliperman
	所属工作室：不刘名科创
	版本：0.1.0 
	食用方法： 
		#include"fucker_input.h"
		using fucker_io::你要食用的函数名;
	如有问题，请问我
	QQ：798500620
*/
#pragma once
#include<stdexcept>
#include<iterator>
#include<ios>
#include<iostream>
namespace fucker_input {

template<typename _Tp>
struct input_sequence{
  _Tp operator()(_Tp& __x){ 
    using std::cin;
  	typename _Tp::iterator it;
  	for(it=__x.begin();it!=__x.end();++it){
  		if(!(cin>>*it)){
  			throw std::runtime_error("input_sequence:runtime error");
		}
	  }
  	return __x; 
  }
};
template<typename cont>
cont ips(cont& c){
	using std::cin;
	for(auto &x:c){
		if(!(cin>>x)){
  			throw std::runtime_error("ips:runtime error");
		}
	}
	return c;
}
template<typename itera>
void input_range(itera fs,itera ls){
	using std::cin;
	for(;fs!=ls;++fs){
  		if(!(cin>>*fs)){
  			throw std::runtime_error("input_range:runtime error");
		}
	}
}

template<typename T>
T input_nt(){
	using std::cin;
	T ge;
	if(!(cin>>ge)){
  			throw std::runtime_error("input_nt:runtime error");
		}
	return ge;
}

template<typename T,typename F>
T input_cus(F&& functor){
	T ge;functor(ge);
	return ge;
}

}//namespace fuck io




