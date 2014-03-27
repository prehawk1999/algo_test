/*
 * chap3.hpp
 *
 *  Created on: Mar 18, 2014
 *      Author: prehawk
 */

#ifndef CHAP3_HPP_
#define CHAP3_HPP_
#include "../algo_test.h"


const char * tails[] = {
		"etic", "alistic", "stic", "ptic", "lytic", "otic",
		"antic", "ntic", "ctic", "atic", "hnic", "nic", "mic",
		"llic", "blic", "clic", "lic", "hic", "fic", "dic", "bic",
		"aic", "mac", "iac"
};

const int tails_l = 24;


string getsuffix(string input){

	string tail;
	for(int i=0; i<24; ++i){
		tail = tails[i];
		//int s = find(input.begin(), input.end(), tails[i]);
		if(1){
			cout << tail << endl;
		}
	}
	return input;
}

void test(){

	getsuffix("ethnic");

}


void test_main(){
	test();
}

#endif /* CHAP3_HPP_ */
