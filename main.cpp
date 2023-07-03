#include <stdio.h>
#include <iostream>
#include <vector>
#include <map>

std::vector<std::string> matching_words(std::string digits);

void ger_words(std::map<int,std::string> &mapping,std::string digits,std::vector<std::string> &all_words,std::string word);

int main()
{
	 /* ?\n;||(or) e &&(and)*/

	std::string digits = "8733";
	std::vector<std::string> words = matching_words(digits);

	for(int i = 0;i < words.size();i++){
		for(int j = 0;j < words[i].size();j++){
			std::cout << words[i][j];
		}
		std::cout << '\n';
	}



	return 0;
}


void ger_words(std::map<int,std::string> &mapping,std::string digits,std::vector<std::string> &all_words,std::string word){

	if(digits.size() == 0){
		all_words.push_back(word);
		return;
	}

	int x = digits[0] - '0';

	std::string digits_seq = "";
	digits_seq.append(digits);
	digits_seq.replace(0,1,"");

	std::string paths = mapping[x];

	for(int i = 0;i < paths.size();i++){
		word += paths[i];
		ger_words(mapping,digits_seq,all_words,word);
		word.replace(word.size()-1,1,"");
	}


}

std::vector<std::string> matching_words(std::string digits){

	std::map<int,std::string> mapping;
	mapping.insert(std::pair<int,std::string>(0,""));
	mapping.insert(std::pair<int,std::string>(1," "));
	mapping.insert(std::pair<int,std::string>(2,"abc"));
	mapping.insert(std::pair<int,std::string>(3,"def"));
	mapping.insert(std::pair<int,std::string>(4,"ghi"));
	mapping.insert(std::pair<int,std::string>(5,"jkl"));
	mapping.insert(std::pair<int,std::string>(6,"mno"));
	mapping.insert(std::pair<int,std::string>(7,"pqrs"));
	mapping.insert(std::pair<int,std::string>(8,"tuv"));
	mapping.insert(std::pair<int,std::string>(9,"wxyz"));

	std::vector<std::string> all_words;
	std::string word = "";
	ger_words(mapping,digits,all_words,word);
	return all_words;


}
