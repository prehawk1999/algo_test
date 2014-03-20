/*
 * chap11.hpp
 *
 *  Created on: Mar 20, 2014
 *      Author: prehawk
 */

#ifndef CHAP11_HPP_
#define CHAP11_HPP_

#include "../algo_test.h"



/*
 * pre. quicksort
 * $1: begin iter, $2: end iter that point over the end of vector
 * @return void
 * */
template<typename Type>
void _innerQsort1(typename Type::iterator l, typename Type::iterator u){

	if(l >= u) return;

	vi::iterator m = l ;
	for(vi::iterator it = m+1; it != u; ++it){
		if( (*it) < (*l) ){
			std::swap( *++m, *it );
		}
	}
	swap( *l, *m );
	_innerQsort1< Type >(l, m);
	_innerQsort1< Type >(m+1, u);
}


/*
 * P112 example
 * pre. user define sort method
 * $1: input unsort array vector<int>
 * @return: no return
 * */
template<typename Type>
Type mysort(Type x){

	boost::timer::auto_cpu_timer t;
	_innerQsort1< Type >(x.begin(), x.end());
	return x;
}

/*
 * pre. A function that make a vector of unsort numbers
 * $1: the size of the vector
 * @return a vector<int>
 *
 * */


vi getunsort(int num){

	std::vector<int> test;
	for(int i=0; i<num; ++i) test.push_back(i);
	std::srand ( unsigned ( std::time(0) ) );
	std::random_shuffle(test.begin(), test.end());

	return test;
}

void assertsorted(vi sorted ){

	int i = 0;
	for(vi::iterator it=sorted.begin(); it!=sorted.end(); ++it){
		assert(i <= *it);
		i = *it;
	}
}

void test_main(){

	for(int i = 1; i<=1000000; i *= 10){

		assertsorted( mysort< vi >(getunsort(i)) );
		std::cout << i << "\telements sorted!" << std::endl << std::endl;
	}
}

#endif /* CHAP11_HPP_ */
