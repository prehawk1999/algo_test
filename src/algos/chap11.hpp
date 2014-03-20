/*
 * chap11.hpp
 *
 *  Created on: Mar 20, 2014
 *      Author: prehawk
 *
 *
 *
 *      usage: change the mysort func. with different _innerQsort method and test it
 */

#ifndef CHAP11_HPP_
#define CHAP11_HPP_

#include "../algo_test.h"

#include <random>

#include <cstdlib>


std::mt19937 generator;

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
	std::swap( *l, *m );
	_innerQsort1< Type >(l, m);
	_innerQsort1< Type >(m+1, u);
}

/*
 * pre. quicksort version 2, scan from two directions, better perf. in sorting same elem.
 * $1: begin iter, $2: end iter that point over the end of vector
 * @return void
 * */
template<typename Type>
void _innerQsort2(typename Type::iterator l, typename Type::iterator u){

	if(l >= u) return;

	vi::iterator i(l);
	vi::iterator j(u);
	int t = *l;

	while(1){
		do i++; while( i <= u && *i < t);
		do j--; while( j == u || *j > t);
		if( i > j )
			break;
		std::swap(*i, *j);
	}
	std::swap(*l, *j);
	_innerQsort2< Type >(l, j);
	_innerQsort2< Type >(j+1, u);
}


/*
 * pre. quicksort version 32, scan from two directions, better perf. in sorting same elem.
 * with random characteristic, better perf. in sorting invert vectors.
 * $1: begin iter, $2: end iter that point over the end of vector
 * @return void
 * */
template<typename Type>
void _innerQsort3(typename Type::iterator l, typename Type::iterator u){

	if(l >= u) return;

	std::uniform_int_distribution<int> dis( 0, u - l - 1);
	vi::iterator next = l + dis(generator);
	swap(*l, *next );

	vi::iterator i(l);
	vi::iterator j(u);
	int t = *l;

	while(1){
		do i++; while( i <= u && *i < t);
		do j--; while( j == u || *j > t);
		if( i > j )
			break;
		std::swap(*i, *j);
	}
	std::swap(*l, *j);
	_innerQsort3< Type >(l, j);
	_innerQsort3< Type >(j+1, u);
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


	_innerQsort3< Type >(x.begin(), x.end());
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

vi getsame(int num){

	std::vector<int> test;
	for(int i=0; i<num; ++i) test.push_back(0);
	return test;
}

vi getsorted(int num){

	std::vector<int> test;
	for(int i=num; i>=0; --i){
		test.push_back(i);
	}
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

	std::cout << "******Testing non-value******" << std::endl;
	assertsorted( mysort< vi >( getunsort(0) ));
	std::cout << std::endl << std::endl;

	std::cout << "******Testing unsorted array******" << std::endl;
	for(int i = 1; i<=1000000; i *= 10){

		assertsorted( mysort< vi >( getunsort(i) ) );
		std::cout << i << "\telements sorted!" << std::endl << std::endl;
	}

	std::cout << "******Testing same elem array******" << std::endl;
	for(int i = 1; i<=10000; i *= 10){

		assertsorted( mysort< vi >( getsame(i) ) );
		std::cout << i << "\telements sorted!" << std::endl << std::endl;
	}

	std::cout << "******Testing descending elem array******" << std::endl;
	for(int i = 1; i<=10000; i *= 10){

		assertsorted( mysort< vi >( getsorted(i) ) );
		std::cout << i << "\telements sorted!" << std::endl << std::endl;
	}

	std::cout << "======All tests have been passed======" << std::endl;
}

#endif /* CHAP11_HPP_ */
